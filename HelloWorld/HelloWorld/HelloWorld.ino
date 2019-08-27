// -!- C++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : Robert Heller
//  Created       : Wed Oct 24 09:00:51 2018
//  Last Modified : <190826.2016>
//
//  Description	
//
//  Notes
//
//  History
//	
/////////////////////////////////////////////////////////////////////////////
//
//    Copyright (C) 2018  Robert Heller D/B/A Deepwoods Software
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
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Adafruit_MPR121.h>
#include <HelloWorld.h>
#include <Adafruit_NeoPixel.h>
static const char rcsid[] = "@(#) : $Id$";

Adafruit_NeoPixel neo(1,8);

// Touch sensor breakout
Adafruit_MPR121 cap = Adafruit_MPR121();
// Small monochrome display
Adafruit_PCD8544 display = Adafruit_PCD8544(11,10,6);

int Backlight = 5; // Backlight LED
int persist = 0;   // Persistance value

int Votes[12];

static const CountryCode TouchMap[] = {
    in, jp, fr, cn, ko, na, ru, de, it, br, mx, us};

//**********************************************************
//* Map touch sensors to countries                         *
//**********************************************************
CountryCode CountryTouched () {
    int touched = cap.touched();
    if (touched & (1 << 11)) return us;
    else if (touched & (1 << 10)) return mx;
    else if (touched & (1 <<  9)) return br;
    else if (touched & (1 <<  8)) return it;
    else if (touched & (1 <<  7)) return de;
    else if (touched & (1 <<  6)) return ru;
    else if (touched & (1 <<  5)) return na;
    else if (touched & (1 <<  4)) return ko;
    else if (touched & (1 <<  3)) return cn;
    else if (touched & (1 <<  2)) return fr;
    else if (touched & (1 <<  1)) return jp;
    else if (touched & (1 <<  0)) return in;
    else return NONE;
}

//***********************************************************
//* Touch voting                                            *
//***********************************************************

void TouchVote () {
    int touched = cap.touched();
    for (int i=0; i < 12; i++) {
        if (touched & 1) Votes[i]++;
        touched = touched >> 1;
    }
}

//**********************************************************
//*  Certify a winner                                      *
//**********************************************************

CountryCode VoteWinner () {
    int maxVotes = 0;
    CountryCode winner = NONE;
    for (int i = 0; i < 12; i++) {
        if (Votes[i] > maxVotes) {
            maxVotes = Votes[i];
            winner = TouchMap[i];
        }
    }
    return winner;
}

int VoteCount = 0;
#define NumberVotes 10

//**********************************************************
//* Setup: Connect to touch sensor, set pinmode of the     *
//*        backlight, clear display.                       *
//**********************************************************
void setup() {
    Serial.begin(9600);
    //while (!Serial) {
    //    delay(10);
    //}
    neo.begin();
    neo.setPixelColor(0,255,255,255);
    neo.show();
    Serial.println("Hello World startup");
    if (!cap.begin(0x5A)) {
        neo.setPixelColor(0,255,0,0);
        neo.show();
        while (1) {
            Serial.println("MPR121 not found, check wiring?");
            
        }
    }
    neo.setPixelColor(0,0,255,255);
    neo.show();
    Serial.println("MPR121 found!");
    //cap.setThreshholds(6, 6);
    pinMode(Backlight,OUTPUT);
    display.begin();
    display.clearDisplay();
    display.fillScreen(WHITE);
    display.setContrast(64);
    for (int i=0; i < 12; i++) Votes[i] = 0;
    neo.clear();
    neo.show();
}


//***********************************************************
//* Main loop: read touch sensor and get the country touched*
//*            If a country touched, display Hello World in *
//*            that country's language.                     *
//***********************************************************
void loop() {
    TouchVote();
    VoteCount++;
    if (VoteCount == NumberVotes) {
        neo.setPixelColor(0,0,0,255);
        neo.show(); 
        // Read sensor and map to a country
        CountryCode touched = VoteWinner();
        neo.setPixelColor(0,0,((int)touched)*20,255);
        VoteCount = 0;
        for (int i=0; i < 12; i++) Votes[i] = 0;
        // If an actual country was touched, light up the display and display
        // the proper graphics for Hello World in the selected language.
        if (touched != NONE) {
            Serial.print(touched); Serial.println(" touched");
            persist = 255;
            display.clearDisplay();
            display.fillScreen(WHITE);
            // Fan out on selected language
            switch (touched) {
            case us:
                display.drawXBitmap(0,0,(const uint8_t*) us_bits,us_width,us_height,BLACK);
                break;
            case mx:
                display.drawXBitmap(0,0,(const uint8_t*) mx_bits,mx_width,mx_height,BLACK);
                break;
            case br:
                display.drawXBitmap(0,0,(const uint8_t*) br_bits,br_width,br_height,BLACK);
                break;
            case it:
                display.drawXBitmap(0,0,(const uint8_t*) it_bits,it_width,it_height,BLACK);
                break;
            case de:
                display.drawXBitmap(0,0,(const uint8_t*) de_bits,de_width,de_height,BLACK);
                break;
            case ru:
                display.drawXBitmap(0,0,(const uint8_t*) ru_bits,ru_width,ru_height,BLACK);
                break;
            case na:
                display.drawXBitmap(0,0,(const uint8_t*) na_bits,na_width,na_height,BLACK);
                break;
            case ko:
                display.drawXBitmap(0,0,(const uint8_t*) ko_bits,ko_width,ko_height,BLACK);
                break;
            case cn:
                display.drawXBitmap(0,0,(const uint8_t*) cn_bits,cn_width,cn_height,BLACK);
                break;
            case fr:
                display.drawXBitmap(0,0,(const uint8_t*) fr_bits,fr_width,fr_height,BLACK);
                break;
            case jp:
                display.drawXBitmap(0,0,(const uint8_t*) jp_bits,jp_width,jp_height,BLACK);
                break;
            case in:
                display.drawXBitmap(0,0,(const uint8_t*) in_bits,in_width,in_height,BLACK);
                break;
            default:
                break;
            }
            // Write to display and show it.
            display.display();
        }
    }
    // Persistance countdown.  Fade the display out from full brightness to 
    // dark
    if (persist > 0) {
        Serial.print("Persist is "); Serial.println(persist);
        persist--; persist--;
        if (persist == 0) {
            // Full dark, clear display.
            display.clearDisplay();
            display.fillScreen(WHITE);
            display.display();
            analogWrite(Backlight,0);
            neo.clear();
            neo.show();
        } else {
            // Update backlight.
            analogWrite(Backlight,persist);
        }
    }
    delay(100);
}
