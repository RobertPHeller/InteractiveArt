// -!- C++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : Robert Heller
//  Created       : Wed Aug 17 17:39:54 2022
//  Last Modified : <220819.1340>
//
//  Description	
//
//  Notes
//
//  History
//	
/////////////////////////////////////////////////////////////////////////////
//
//    Copyright (C) 2022  Robert Heller D/B/A Deepwoods Software
//			51 Locke Hill Road
//			Wendell, MA 01379-9728
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
// 
//
//////////////////////////////////////////////////////////////////////////////

static const char rcsid[] = "@(#) : $Id$";

#include <Arduino.h>

#include <MatrixHardware_Teensy4_ShieldV5.h>
#include <SmartMatrix.h>
#include <HardwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "DirectoryList.h"
#include "ConwaysLife.h"
#include "Button.h"

#define IPCChannel Serial1

#define COLOR_DEPTH 24
const uint16_t kMatrixWidth = 128;
const uint16_t kMatrixHeight = 64;
const uint8_t kRefreshDepth = 36;
const uint8_t kDmaBufferRows = 4;
const uint8_t kPanelType = SM_PANELTYPE_HUB75_64ROW_MOD32SCAN;
const uint32_t kMatrixOptions = (SM_HUB75_OPTIONS_NONE); 
const uint8_t kBackgroundLayerOptions = (SM_BACKGROUND_OPTIONS_NONE);

SMARTMATRIX_ALLOCATE_BUFFERS(matrix, kMatrixWidth, kMatrixHeight, 
                             kRefreshDepth, kDmaBufferRows, kPanelType, 
                             kMatrixOptions);
SMARTMATRIX_ALLOCATE_BACKGROUND_LAYER(backgroundLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kBackgroundLayerOptions);

Life life(128,128);

static char LineBuffer[512];

void DrawUpperHalf()
{
    int x, y;
    uint8_t bit;
    
    for (y = 0; y < 64; x++)
    {
        for (x = 0; x < 128; x++)
        {
            bit = life.currentLife()->getbit(x,y);
            SM_RGB pixel = backgroundLayer.readPixel(x,y);
            if (bit)
            {
                if (pixel.red > 128) 
                {
                    pixel.red--;
                }
                else if (pixel.green > 128)
                {
                    pixel.green--;
                }
                else if (pixel.blue > 128)
                {
                    pixel.blue--;
                }
                else
                {
                    pixel.red = 255;
                    pixel.green = 255;
                    pixel.blue = 255;
                }
            }
            else
            {
                pixel.red = 0;
                pixel.green = 0;
                pixel.blue = 0;
            }
            backgroundLayer.drawPixel(x,y,pixel);
        }
    }
        
}

void SendLowerHalf()
{
    int x, y;
    uint8_t bit, ibit, byte;
    char *p;
    size_t l;
    char AckBuffer[16];
    
    for (y = 64; y < 128; x++)
    {
        p = LineBuffer;
        l = sizeof(LineBuffer);
        int wrote = snprintf(p,l,"%02x%02x: ",0,y-64);
        p += wrote; l -= wrote;
        ibit = 0;
        byte = 0;
        for (x = 0; x < 128; x++)
        {
            bit = life.currentLife()->getbit(x,y);
            byte |= (bit << ibit);
            ibit++;
            if (ibit >= 8) {
                int wrote = snprintf(p,l,"%02x",byte);
                p += wrote; l -= wrote;
                byte = 0;
                ibit = 0;
            }
        }
        *p++ = '\n';
        l--;
        IPCChannel.write(LineBuffer,sizeof(LineBuffer)-l);
        while (IPCChannel.available() < 1)
        {
            yield();
        }
        /*size_t len = */ IPCChannel.readBytesUntil('\n',AckBuffer,sizeof(AckBuffer));
        
            
    }
}

const int SDchipSelect = BUILTIN_SDCARD;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOWER  20
#define MIDDLE 21
#define UPPER  22

Button Lower(LOWER);
Button Middle(MIDDLE);
Button Upper(UPPER);

void LoadNewLife(const char * lifefile, Life &life);

extern "C" int main(void)
{
    Serial.begin(115200);
    Serial.print("Initializing MATRIX...");
    matrix.addLayer(&backgroundLayer);
    matrix.begin();
    backgroundLayer.fillScreen({0,0,0});
    backgroundLayer.swapBuffers();
    Serial.println("initialization done.");
    Serial.print("Initializing SD card...");
    if (!SD.begin(SDchipSelect)) 
    {
        Serial.println("initialization failed!");
        return 99;
    }
    Serial.println("initialization done.");
    Serial.print("Initializing IPCChannel...");
    IPCChannel.begin(230400);
    yield_active_check_flags |= YIELD_CHECK_HARDWARE_SERIAL;
    Serial.println("initialization done.");
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        return 99;
    }
    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display.display();
    delay(2000); // Pause for 2 seconds
    // Clear the buffer
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    DirectoryList dirList(SD.open("/"));
    size_t curIndex = 0;
    size_t curTop   = 0;
    size_t lines    = 4;
    dirList.showFiles(display,curTop,lines,curIndex);
    Lower.begin();
    Middle.begin();
    Upper.begin();
    while(1)
    {
        bool updateDisplay = false;
        if (Upper.pressed())
        {
            if (curIndex > 0)
            {
                curIndex--;
                if (curIndex < curTop)
                {
                    curTop--;
                }
                updateDisplay = true;
            }
        }
        if (Lower.pressed())
        {
            if ((curIndex+1) < (curTop+lines))
            {
                curIndex++;
                if (curIndex >= (curTop+lines))
                {
                    curTop++;
                }
                updateDisplay = true;
            }
        }
        if (updateDisplay) dirList.showFiles(display,curTop,lines,curIndex);
        if (Middle.pressed())
        {
            LoadNewLife(dirList[curIndex],life);
            DrawUpperHalf();
            SendLowerHalf();
        } else if (!life.allDeadP()) 
        {
            life.lifeCycle();
            DrawUpperHalf();
            SendLowerHalf();
        }
        yield();
    }
}    
