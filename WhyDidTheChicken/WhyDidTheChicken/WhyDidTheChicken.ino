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
//  Last Modified : <181027.2001>
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

const int TRAFFIC_RED = 12;
const int TRAFFIC_YELLOW = 11;
const int TRAFFIC_GREEN = 10;
const int WALK_BUTTON = 9;
int crossTime = 5000;  //time for pedestrians to pass unsigned
long changeTime; //time that the button is pressed


static const uint8_t PROGMEM
   hand_bmp[] = { 0x06, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x06 },
   Chicken_bmp[] = { 0x18, 0x3c, 0x18, 0x08, 0x1c, 0x3e, 0x1c, 0x22 };


Adafruit_BicolorMatrix pedestrianSignal = Adafruit_BicolorMatrix();

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

void changeLights();

void loop() {
    int state = digitalRead(WALK_BUTTON);
    if (state == LOW && (millis() - changeTime) > 5000) {
        changeLights();
    }
}

void changeLights() {
    digitalWrite(TRAFFIC_GREEN,LOW);
    digitalWrite(TRAFFIC_YELLOW,HIGH);
    delay(2000);
    digitalWrite(TRAFFIC_YELLOW,LOW);
    digitalWrite(TRAFFIC_RED,HIGH);
    delay(1000);
    
    pedestrianSignal.clear();
    pedestrianSignal.drawBitmap(0,0,Chicken_bmp,8,8,LED_GREEN);
    pedestrianSignal.writeDisplay();
    delay(crossTime);
    //blink red pedestrian light to notify pedestrians to pass so
    for (int x=0; x<10; x++) {
        
        pedestrianSignal.clear();
        pedestrianSignal.writeDisplay(); 
        delay(500);
        pedestrianSignal.drawBitmap(0,0,hand_bmp,8,8,LED_RED);
        pedestrianSignal.writeDisplay();
        delay(500);
    }
    pedestrianSignal.drawBitmap(0,0,hand_bmp,8,8,LED_RED);
    pedestrianSignal.writeDisplay();
    delay(500);
    digitalWrite(TRAFFIC_RED,LOW);
    digitalWrite(TRAFFIC_YELLOW,LOW);
    digitalWrite(TRAFFIC_GREEN,HIGH);
    changeTime = millis();
}

    
    
