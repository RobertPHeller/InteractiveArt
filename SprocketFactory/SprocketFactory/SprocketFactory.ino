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
//  Last Modified : <181029.1733>
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

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver factoryFloor = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

const int StartButton = 6;
const int StopButton  = 5;

bool factoryStarted = false;

// our servo # counter
uint8_t servonum = 0;

void setup() {
    
    factoryFloor.begin();
    factoryFloor.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
    delay(10);
    pinMode(StartButton,INPUT_PULLUP);
    pinMode(StopButton,INPUT_PULLUP);
}

void loop() {
    int count;
    int lows;
    
    if (factoryStarted) {
        if (digitalRead(StopButton) == LOW) {
            lows = 1;
            for (count = 0; count < 3; count++) {
                lows += (digitalRead(StopButton) == LOW)?1:0;
            }
            if (lows > 2) {
                factoryStarted = false;
            }
        }
    } else {
        if (digitalRead(StartButton) == LOW) {
            lows = 1;
            for (count = 0; count < 3; count++) {
                lows += (digitalRead(StartButton) == LOW)?1:0;
            }
            if (lows > 2) {
                factoryStarted = true;
                servonum = 0;
            }
        }
    }
    if (factoryStarted) {
        for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
            factoryFloor.setPWM(servonum, 0, pulselen);
        }
        
        delay(500);
        for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
            factoryFloor.setPWM(servonum, 0, pulselen);
        }
        
        delay(500);
        
        servonum ++;
        if (servonum > 7) servonum = 0;
    }
}
