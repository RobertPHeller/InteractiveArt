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
//  Last Modified : <181111.1557>
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

// Push button inputs
const int StartButton = 6;
const int StopButton  = 5;

// Factory state
bool factoryStarted = false;

// our servo # counter
uint8_t servonum = 0;

//*************************************
//* Setup: Initialize the servos      *
//*        Setup the button pins      *
//*************************************

void setup() {
    
    factoryFloor.begin();
    factoryFloor.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
    delay(10);
    pinMode(StartButton,INPUT_PULLUP);
    pinMode(StopButton,INPUT_PULLUP);
}

//****************************************************
//* Main loop:                                       *
//*   If factory is running, check stop button and   *
//*   if Stop pressed, stop the factory              *
//*   If factory is not running, check start  button *
//*   and if Start pressed, start the factory        *
//****************************************************

void loop() {
    int count;
    int lows;
    
    // Check if the factory is running.
    if (factoryStarted) {
        // Running: check for stop button
        if (digitalRead(StopButton) == LOW) {
            // stop button pressed -- debounce it.
            lows = 1;
            for (count = 0; count < 3; count++) {
                delay(30);
                lows += (digitalRead(StopButton) == LOW)?1:0;
            }
            if (lows > 2) {
                // yes really pressed
                factoryStarted = false; // Stop factory
            }
        }
    } else {
        // Not Running: check for start button
        if (digitalRead(StartButton) == LOW) {
            // start button pressed -- debounce it.
            lows = 1;
            for (count = 0; count < 3; count++) {
                delay(30);
                lows += (digitalRead(StartButton) == LOW)?1:0;
            }
            if (lows > 2) {
                // yes really pressed
                factoryStarted = true; // Stop factory
                servonum = 0;          // with the first servo
            }
        }
    }
    if (factoryStarted) {
        // Running: move the current servo
        for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
            factoryFloor.setPWM(servonum, 0, pulselen);
        }
        delay(500); // and 1/2 second later...
        // move the current servo back
        for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
            factoryFloor.setPWM(servonum, 0, pulselen);
        }
        delay(500); // 1/2 second wait
        
        servonum++; // Bump servo
        if (servonum > 7) servonum = 0; // Wrap around
    }
}
