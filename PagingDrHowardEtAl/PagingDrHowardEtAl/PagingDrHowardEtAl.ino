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
//  Last Modified : <190828.1514>
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

// Pulse input on A0
const int PULSE_INPUT = A0;

// Pulse sensor
PulseSensorPlayground pulseSensor;

// LED Backpacks:
// Beats per minute
Adafruit_7segment bpmDisplay;
// Graphical pulse
Adafruit_24bargraph pulseBar;


//****************************************
//* Setup: Initialize everything         *
//*   Bind pulse input to a pulse sensor *
//*   Wait for pulse sensor to init and  *
//*   settle.                            *
//*   Start up LED Backpack displays.    *
//*   Initialize displays to a zero state*
//****************************************
void setup() {
    analogReference(EXTERNAL);
    pulseSensor.analogInput(PULSE_INPUT);  // Connect sensor
    if (!pulseSensor.begin()) {            // Start sensing
        for(;;) {
            // Flash the led to show things didn't work.
            digitalWrite(13, LOW);
            delay(50);
            digitalWrite(13, HIGH);
            delay(50);
        }
    }
    bpmDisplay.begin(0x70);     // Connect to Beats per Minute display
    pulseBar.begin(0x71);       // Connect to Graphical pulse display
    bpmDisplay.print(0,DEC);    // Display zero Beats per Minute
    bpmDisplay.writeDisplay();
    pulseBar.setBar(23,LED_OFF); // Display no pulse
    pulseBar.writeDisplay();
}

//****************************************
//* Main loop:                           *
//*    Delay to get a reading            *
//*    Get a sample, display sample on   *
//*    bargraph.                         *
//*    Get BPM, display on Beats per     *
//*    Minute display.                   *
//****************************************
void loop() {
    uint16_t sample;
    uint16_t bpm;
    
    delay(20);
    sample = pulseSensor.getLatestSample(); // Get sample
    pulseBar.setBar((int)((sample / 1023.0)*23),LED_GREEN); // Display sample
    pulseBar.writeDisplay();
    bpm = pulseSensor.getBeatsPerMinute(); // Get BPM
    bpmDisplay.print(bpm,DEC);             // Display BPM
    bpmDisplay.writeDisplay();
}
