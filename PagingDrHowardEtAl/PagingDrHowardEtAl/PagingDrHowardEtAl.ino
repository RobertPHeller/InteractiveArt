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
//  Last Modified : <181105.0812>
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

#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>
#include <Adafruit_LEDBackpack.h>

const int PULSE_INPUT = A0;


PulseSensorPlayground pulseSensor;



void setup() {
    pulseSensor.analogInput(PULSE_INPUT);
    if (!pulseSensor.begin()) {
        for(;;) {
            // Flash the led to show things didn't work.
            digitalWrite(13, LOW);
            delay(50);
            digitalWrite(13, HIGH);
            delay(50);
        }
    }
    
}

void loop() {
  // put your main code here, to run repeatedly:

}
