// -!- C++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : Robert Heller
//  Created       : Thu Sep 26 19:49:59 2019
//  Last Modified : <190929.0848>
//
//  Description	
//
//  Notes
//
//  History
//	
/////////////////////////////////////////////////////////////////////////////
//
//    Copyright (C) 2019  Robert Heller D/B/A Deepwoods Software
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

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RGBmatrixPanel.h>
#include <Button.h>

static const char rcsid[] = "@(#) : $Id$";


#define CLK  8   // USE THIS ON ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
//#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "ConwaysLife.h"
#include "InitialLife.h"
#include "ScreenSaver.h"

Life life(Gosper_glider_gun);
ScreenSaver screenSaver(matrix);
enum {Sleep, Idle, Life} currentState;

Button Left(13);
Button Center(12);
Button Right(11);

int delayCount, cycleCount, selectedLifeIndex, displayedLifeIndex;

void setup() {
    Serial.begin(9600);
    matrix.begin();
    Left.begin();
    Center.begin();
    Right.begin();
    currentState = Idle;
    cycleCount = 0;
    delayCount = 0;
    selectedLifeIndex = 0;
    displayedLifeIndex = 0;
    
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
    
    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display.display();
    delay(2000); // Pause for 2 seconds
    
}

void displayCurrent(int index)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.cp437(true);
    
    display.println(InitialMatrixList[selectedLifeIndex].name);
    display.println("");
    display.println("Previous Select Next");
    
    display.display();
}
                
void loop() {
    if (currentState != Sleep) {
        delayCount++;
        if (delayCount = 10) {
            if (currentState == Life) {
                if (life.allDeadP()) {
                    life.SetLife(InitialMatrixList[selectedLifeIndex].bitmatrix);
                }
                matrix.drawBitmap(0,0,life.currentBits(),64,32,0xffff,0x0000);
                life.lifeCycle();
            } else if (currentState = Idle) {
                screenSaver.NextScreen();
            }
            delayCount = 0;
            cycleCount++;
            if (cycleCount > 1000) {
                cycleCount = 0;
                if (currentState == Life) {
                    currentState = Idle;
                } else if (currentState = Idle) {
                    currentState = Sleep;
                    matrix.fillScreen(0x0000);
                    display.clearDisplay();
                    display.display();
                }
            }
        }
    }
    switch (currentState) {
    case Sleep:
        if (Center.pressed()) {
            currentState = Idle;
            displayCurrent(displayedLifeIndex);
        }
    case Life:
    case Idle:
        if (Left.pressed()) {
            displayedLifeIndex--;
            if (displayedLifeIndex < 0) displayedLifeIndex = 0;
            displayCurrent(displayedLifeIndex);
        } else if (Right.pressed()) {
            displayedLifeIndex++;
            if (InitialMatrixList[displayedLifeIndex].bitmatrix == NULL) 
                displayedLifeIndex--;
            displayCurrent(displayedLifeIndex);
        } else if (Center.pressed()) {
            selectedLifeIndex = displayedLifeIndex;
            life.SetLife(InitialMatrixList[selectedLifeIndex].bitmatrix);
            currentState = Life;
            displayCurrent(displayedLifeIndex);
        }
    }
    delay(100);
}    
