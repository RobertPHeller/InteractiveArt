// -!- C++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : Robert Heller
//  Created       : Wed Aug 17 17:40:55 2022
//  Last Modified : <220818.1337>
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

static char LineBuffer[512];

void WriteLine(char *buffer,size_t l)
{
    char *p;
    int x, y;
    uint8_t bit, ibit;
    int byte;
    
    if (sscanf(buffer,"%02x%02x: ",&x,&y) == 2)
    {
        p = buffer + 6;
        l -= 6;
        while (l > 2)
        {
            if (sscanf(p,"%02x", &byte) == 1)
            {
                p += 2; l -= 2;
                for (ibit = 0; ibit < 8; ibit++)
                {
                    bit = (byte >> ibit) & 1;
                    SM_RGB pixel = {bit,bit,bit};
                    backgroundLayer.drawPixel(x,y,pixel);
                    x++;
                    if (x >= kMatrixWidth)
                    {
                        x = 0; y++;
                        if (y >= kMatrixHeight)
                        {
                            return;
                        }
                    }
                }
            }
        }
    }
}


extern "C" int main(void)
{
    matrix.addLayer(&backgroundLayer);
    matrix.begin();
    IPCChannel.begin(230400);
    yield_active_check_flags |= YIELD_CHECK_HARDWARE_SERIAL;
    backgroundLayer.fillScreen({0,0,0});
    backgroundLayer.swapBuffers();
    while(1)
    {
        while (IPCChannel.available() > 0)
        {
            size_t len = IPCChannel.readBytesUntil('\n',LineBuffer,sizeof(LineBuffer));
            WriteLine(LineBuffer,len);
            IPCChannel.println("ACK");
            yield();
        }
        backgroundLayer.swapBuffers();
        yield();
    }
    
}

