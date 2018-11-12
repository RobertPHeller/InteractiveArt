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
//  Last Modified : <181111.2025>
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

#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

// Traffic light LEDS
const int TRAFFIC_RED = 12;
const int TRAFFIC_YELLOW = 11;
const int TRAFFIC_GREEN = 10;
// Walk button
const int WALK_BUTTON = 9;

int crossTime = 5000;  //time for pedestrians to pass unsigned
long changeTime; //time that the button is pressed

// Bitmaps for the Pedestrian Signal (an 8x8 BiColor matrix)
static const uint8_t PROGMEM
   hand_bmp[] = { 0x06, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x06 },
   Chicken_bmp[] = { 0x18, 0x3c, 0x18, 0x08, 0x1c, 0x3e, 0x1c, 0x22 };


Adafruit_BicolorMatrix pedestrianSignal = Adafruit_BicolorMatrix();

//***************************************************************
//* Setup: Set pinmodes and initialize the traffic light. Then  *
//*        connect to the pedestrian signal and initialzie it to*
//*        a red hand (means "don't cross").                    *
//***************************************************************
void setup() {
    pinMode(TRAFFIC_RED,OUTPUT);
    pinMode(TRAFFIC_YELLOW,OUTPUT);
    pinMode(TRAFFIC_GREEN,OUTPUT);
    pinMode(WALK_BUTTON,INPUT_PULLUP);
    digitalWrite(TRAFFIC_RED,LOW);
    digitalWrite(TRAFFIC_YELLOW,LOW);
    digitalWrite(TRAFFIC_GREEN,HIGH);
    pedestrianSignal.begin(0x70);
    pedestrianSignal.clear();
    pedestrianSignal.drawBitmap(0,0,hand_bmp,8,8,LED_RED);
    pedestrianSignal.writeDisplay();
    changeTime = millis();
}

// Forward declaration
void changeLights();

//***************************************************************
//* Main loop: Check walk button and if pressed and enough time *
//*            has passed since the last change (5 seconds),    *
//*            change the lights.                               *
//***************************************************************
void loop() {
    int state = digitalRead(WALK_BUTTON);
    if (state == LOW && (millis() - changeTime) > 5000) {
        changeLights();
    }
}

//***************************************************************
//* changeLight(): Process the walk button.  First change from  *
//* green to yellow, then wait 2 seconds.  Then change to red   *
//* and wait one additional second.  Then display a green       *
//* chicken on the pedestrian signal.  Now wait for crossing    *
//* time.  Then blink the red hand on the pedestrian signal for *
//* 10 blinks of one second each.  Then go to a fixed red hand  *
//* wait 1/2 of a second and display a green signal for the     *
//* cars, then capture the change time.                         *
//***************************************************************
void changeLights() {
    digitalWrite(TRAFFIC_GREEN,LOW); // Green off
    digitalWrite(TRAFFIC_YELLOW,HIGH); // Yellow on
    delay(2000); // 2 seconds
    digitalWrite(TRAFFIC_YELLOW,LOW); // Yellow off
    digitalWrite(TRAFFIC_RED,HIGH); // Red on
    delay(1000); // 1 second
    
    // Display a chicken in green
    pedestrianSignal.clear();
    pedestrianSignal.drawBitmap(0,0,Chicken_bmp,8,8,LED_GREEN);
    pedestrianSignal.writeDisplay();
    delay(crossTime); // Crossing time
    //blink red hand on pedestrian signal to notify pedestrians to pass so
    for (int x=0; x<10; x++) {
        
        pedestrianSignal.clear(); // Off
        pedestrianSignal.writeDisplay(); 
        delay(500); // 1/2 second
        pedestrianSignal.drawBitmap(0,0,hand_bmp,8,8,LED_RED); // Red hand
        pedestrianSignal.writeDisplay();
        delay(500); // 1/2 second
    }
    pedestrianSignal.drawBitmap(0,0,hand_bmp,8,8,LED_RED); // Red hand
    pedestrianSignal.writeDisplay();
    delay(500); // 1/2 second
    digitalWrite(TRAFFIC_RED,LOW); // Red off
    digitalWrite(TRAFFIC_YELLOW,LOW); // Yellow off
    digitalWrite(TRAFFIC_GREEN,HIGH); // Green on
    changeTime = millis(); // Capture time
}

    
    
