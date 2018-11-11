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
//  Last Modified : <181111.1451>
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

// Neopixel data pin
#define NeoPixelPin 6

// Small wheels: 1643: twelve pixels each (2 wheels)
#define SmallWheels 12
// Large wheels: 1586: twenty four pixels each (2 wheels)
#define LargeWheels 24
// Smoke: 1768: 1/4 60 pixel ring (1)
#define Smoke 15

// Neopixel wiring order:
//
// Metromini Pin 6 => 1st small ring DIN 
// 1st small ring DOUT => 2nd small ring DIN
// 2nd small ring DOUT => 1st large ring DIN
// 1st large ring DOUT => 2nd large ring DIN
// 2nd large ring DOUT => 1/4 segment DIN
//

// Two small rings (12 pixels each), two large rings (24 pixels each), 
// 1 quarter segment (15 pixels)
#define totalPixels ((SmallWheels*2)+(LargeWheels*2)+Smoke)

// Create the strip.
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

// Throttle Pin
#define ThrottlePin A0

// Cycle counters.
#define MAXCYCLE 80
uint16_t cyclecount = MAXCYCLE;
uint16_t icycle = MAXCYCLE;

// Phase and color counters
uint8_t  iphase = 0;
uint8_t  iwheelColor = 0;

// Initialize a wheel
void wheelInit(int offset, int wheelsize)
{
    for (uint16_t i=offset; i < wheelsize; i+=3) {
        strip.setPixelColor(i+iphase, Wheel( (i+iwheelColor)  % 255));    //turn every third pixel on
    }
}

// Clear a wheel
void clearWheel(int offset, int wheelsize)
{
    for (uint16_t i=offset; i < wheelsize; i+=3) {
        strip.setPixelColor(i+iphase, 0);
    }
}

// Smoke offsets (only one smoke segement
#define SMOKEOFF ((SmallWheels*2)+(LargeWheels*2))
#define SMOKELEN 15

// Initialize the smoke puffs
void smokeInit()
{
    for (uint16_t i=SMOKEOFF; i < SMOKELEN; i+=3) {
        strip.setPixelColor(i+iphase, strip.Color(127, 127, 127));
    }
}

// Clear the smoke puffs
void clearSmoke()
{
    for (uint16_t i=SMOKEOFF; i < SMOKELEN; i+=3) {
        strip.setPixelColor(i+iphase, 0);
    }
}

//***************************************
//* Setup:                              *
//*    Initialize the neopixels         *
//*    Initialize the global variables  *
//*    Initialize the Wheels and smoke  *
//*    Light up the neopixels           *
//*    Set up the Analog input          *
//***************************************
void setup() {
    strip.begin();
    cyclecount = MAXCYCLE;
    icycle = MAXCYCLE;
    iphase = 0;
    iwheelColor = 0;
    wheelInit(0,SmallWheels); 
    wheelInit(SmallWheels,SmallWheels);
    wheelInit(SmallWheels*2,LargeWheels);
    wheelInit((SmallWheels*2)+LargeWheels,LargeWheels);
    smokeInit();
    strip.show();
    analogReference(EXTERNAL);
}

//***************************************
//* Main loop:                          *
//*   Read the throttle and update the  *
//*   cycle count.  Count the current   *
//*   cycle.  When the current cycle    *
//*   reaches zero, move things one step*
//*   If the throttle is not zero,      *
//*   move the wheels.  Always move the *
//*   smoke.                            *
//***************************************
void loop() {
    uint16_t ithrottle = analogRead(ThrottlePin); // Read throttle: 0-1023
    // Compute cyclecount: 1 == full speed (cycle time is 25ms), 80 == stopped
    // (cycle time is 2000ms).
    cyclecount = 1+(int)(((1023-ithrottle)/1023.0)*(MAXCYCLE-1));
    icycle--;          // Count down cycle
    if (icycle == 0) { // Bottom of cycle
        if (ithrottle > 0) { // If throttle is non-zero...
            // Clear wheels
            clearWheel(0,SmallWheels); 
            clearWheel(SmallWheels,SmallWheels);
            clearWheel(SmallWheels*2,LargeWheels);
            clearWheel((SmallWheels*2)+LargeWheels,LargeWheels); 
        }
        clearSmoke(); // Clear smoke
        strip.show(); // Show strip
        delay(25); // delay
        iphase++; // bump phase
        if (iphase >= 3) iphase = 0; // wrap around phase
        iwheelColor++; // bump wheel color (will automagically wrap around at 255
        icycle = cyclecount; // reset cycle count.
        if (ithrottle > 0) { // If throttle is non-zero...
            // Light wheels
            wheelInit(0,SmallWheels); 
            wheelInit(SmallWheels,SmallWheels);
            wheelInit(SmallWheels*2,LargeWheels);
            wheelInit((SmallWheels*2)+LargeWheels,LargeWheels);
        }
        smokeInit(); // Light smoke
        strip.show(); // show it
    }
    delay(25); // delay
}
