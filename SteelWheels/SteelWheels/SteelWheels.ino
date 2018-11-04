// -!- C++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : $USER_NAME$
//  Created       : $ASCII_TIME$
//  Last Modified : <181104.0954>
//
//  Description	
//
//  Notes
//
//  History
//	
/////////////////////////////////////////////////////////////////////////////
//
//    Copyright (C) $YEAR$  Robert Heller D/B/A Deepwoods Software
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
#include <Adafruit_NeoPixel.h>

#define NeoPixelPin 6

// Small wheels: 1643: twelve pixels each (2 wheels)
#define SmallWheels 12
// Large wheels: 1586: twenty four pixels each (2 wheels)
#define LargeWheels 24
// Smoke: 1768: 1/4 60 pixel ring (1)
#define Smoke 15


#define totalPixels ((SmallWheels*2)+(LargeWheels*2)+Smoke)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(totalPixels,NeoPixelPin, NEO_GRB + NEO_KHZ800);

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if(WheelPos < 85) {
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if(WheelPos < 170) {
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

#define ThrottlePin A0

#define MAXCYCLE 40
uint16_t cyclecount = MAXCYCLE;
uint16_t icycle = MAXCYCLE;

uint8_t  iphase = 0;
uint8_t  iwheelColor = 0;

void wheelInit(int offset, int wheelsize)
{
    for (uint16_t i=offset; i < wheelsize; i+=3) {
        strip.setPixelColor(i+iphase, Wheel( (i+iwheelColor)  % 255));    //turn every third pixel on
    }
}
void clearWheel(int offset, int wheelsize)
{
    for (uint16_t i=offset; i < wheelsize; i+=3) {
        strip.setPixelColor(i+iphase, 0);
    }
}

#define SMOKEOFF ((SmallWheels*2)+(LargeWheels*2))
#define SMOKELEN 15

void smokeInit()
{
    for (uint16_t i=SMOKEOFF; i < SMOKELEN; i+=3) {
        strip.setPixelColor(i+iphase, strip.Color(127, 127, 127));
    }
}

void clearSmoke()
{
    for (uint16_t i=SMOKEOFF; i < SMOKELEN; i+=3) {
        strip.setPixelColor(i+iphase, 0);
    }
}

void setup() {
    strip.begin();
    wheelInit(0,SmallWheels); 
    wheelInit(SmallWheels,SmallWheels);
    wheelInit(SmallWheels*2,LargeWheels);
    wheelInit((SmallWheels*2)+LargeWheels,LargeWheels);
    smokeInit();
    strip.show();
    analogReference(EXTERNAL);
}

void loop() {
    uint16_t ithrottle = analogRead(ThrottlePin);
    cyclecount = (int)(((4096-ithrottle)/4096.0)*MAXCYCLE);
    icycle--;
    if (icycle == 0) {
        if (ithrottle > 0) {
            clearWheel(0,SmallWheels); 
            clearWheel(SmallWheels,SmallWheels);
            clearWheel(SmallWheels*2,LargeWheels);
            clearWheel((SmallWheels*2)+LargeWheels,LargeWheels); 
        }
        clearSmoke();
        strip.show();
        delay(25);
        iphase++;
        if (iphase >= 3) iphase = 0;
        iwheelColor++;
        icycle = cyclecount;
        if (ithrottle > 0) {
            wheelInit(0,SmallWheels); 
            wheelInit(SmallWheels,SmallWheels);
            wheelInit(SmallWheels*2,LargeWheels);
            wheelInit((SmallWheels*2)+LargeWheels,LargeWheels);
        }
        smokeInit();
        strip.show();
    }
    delay(25);
}
