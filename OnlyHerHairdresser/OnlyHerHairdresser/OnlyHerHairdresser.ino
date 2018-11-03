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
//  Last Modified : <181103.0739>
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

#include <Adafruit_TCS34725.h>

#define redpin 10
#define greenpin 6
#define bluepin 5

#define swpin 11

// our RGB -> eye-recognized gamma color
byte gammatable[256];


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);



void setup() {
    // use these three pins to drive LEDs (though driver transistors)
    pinMode(redpin, OUTPUT);
    pinMode(greenpin, OUTPUT);
    pinMode(bluepin, OUTPUT);
    // sample switch
    pinMode(swpin,INPUT_PULLUP);
    // thanks PhilB for this gamma table!
    // it helps convert RGB colors to what humans see
    for (int i=0; i<256; i++) {
        float x = i;
        x /= 255;
        x = pow(x, 2.5);
        x *= 255;
        
        gammatable[i] = x;      
    }
        
}

void loop() {
    uint16_t clear, red, green, blue;
    
    uint16_t count, lows;
    if (digitalRead(swpin) == LOW) {
        lows = 1;
        for (count = 0; count < 3; count++) {
            lows += (digitalRead(swpin) == LOW)?1:0;
        }
        if (lows > 2) {
            tcs.setInterrupt(false);      // turn on LED
            delay(60);  // takes 50ms to read 
            tcs.getRawData(&red, &green, &blue, &clear);
            tcs.setInterrupt(true);  // turn off LED
            uint32_t sum = clear;
            float r, g, b;
            r = red; r /= sum;
            g = green; g /= sum;
            b = blue; b /= sum;
            r *= 256; g *= 256; b *= 256;
            analogWrite(redpin, gammatable[(int)r]);
            analogWrite(greenpin, gammatable[(int)g]);
            analogWrite(bluepin, gammatable[(int)b]);
        }
    }
}
