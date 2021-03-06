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
//  Last Modified : <190729.0003>
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

// SR04 Data pins
const int TRIG_PIN = 8;
const int ECHO_PIN = 7;
// LEDs pin
const int LEDS     = 5;


// Anything over 400 cm (23200 us pulse) is "out of range"
const unsigned int MAX_DIST = 23200;

// Distance thresholds
const float CLOSE_INCHES = 2.5;
const float NEAR_INCHES  = 5.0;
const float FAR_INCHES   = 10.0;
const float VERY_FAR_INCHES = 15.0;
const float DISTANT_INCHES  = 30.0;


//**************************************************************
//* Setup: set pinmodes, turn off LEDs                         *
//**************************************************************
void setup() {
    Serial.begin(9600);
    // The Trigger pin will tell the sensor to range find
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    digitalWrite(TRIG_PIN, LOW);
    
    pinMode(LEDS, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    //digitalWrite(LEDS,0);
    analogWrite(LEDS,0);
}

//**************************************************************
//* Main Loop:  Trigger the sensor and retreive a result pulse *
//*             Compute the pulse width to measure the distance*
//*             Compare the measured distance to the thresholds*
//*             and light the LEDs to the selected brightness. *
//**************************************************************
void loop() {
    unsigned long t1;
    unsigned long t2;
    unsigned long pulse_width;
    float cm;
    float inches;
    
    // Hold the trigger pin high for at least 10 us
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    // Wait for pulse on echo pin
    while ( digitalRead(ECHO_PIN) == 0 );
    
    // Measure how long the echo pin was held high (pulse width)
    // Note: the micros() counter will overflow after ~70 min
    t1 = micros();
    while ( digitalRead(ECHO_PIN) == 1);
    t2 = micros();
    pulse_width = t2 - t1;
    
    //Serial.print("*** pulse_width = ");Serial.println(pulse_width);
    // Calculate distance in centimeters and inches. The constants
    // are found in the datasheet, and calculated from the assumed speed 
    //of sound in air at sea level (~340 m/s).
    inches = pulse_width / 148.0;
    
    //Serial.print("*** inch = ");Serial.println(inches);
    // Measure thresholds and light the LEDs to the brightness called for.
    if (inches < CLOSE_INCHES) {
        //digitalWrite(LEDS,1);
        digitalWrite(LED_BUILTIN,1);
        Serial.println("CLOSE_INCHES");
        analogWrite(LEDS,255); // Very close, full brightness
    } else if (inches < NEAR_INCHES) {
        //digitalWrite(LEDS,1);
        digitalWrite(LED_BUILTIN,1);
        Serial.println("NEAR_INCHES");
        analogWrite(LEDS,192); // Pretty near, medium bright
    } else if (inches < FAR_INCHES) {
        Serial.println("FAR_INCHES");
        analogWrite(LEDS,128); // Fairly far, low brightness
    } else if (inches < VERY_FAR_INCHES) {
        Serial.println("VERY_FAR_INCHES");
        analogWrite(LEDS,64); // Very far, dim
    } else if (inches < DISTANT_INCHES) {
        Serial.println("DISTANT_INCHES");
        analogWrite(LEDS,32); // Very, very far very dim
    } else {
        Serial.println("Beyond DISTANT_INCHES");
        //digitalWrite(LEDS,0);
        digitalWrite(LED_BUILTIN,0);
        analogWrite(LEDS,0);  // Too far, totally dark
    }
    delay(100); // Check again in a 1/10 of a second.
}
