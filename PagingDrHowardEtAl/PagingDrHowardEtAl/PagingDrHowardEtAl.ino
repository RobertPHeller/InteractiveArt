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
//  Last Modified : <190829.1047>
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

#define DASHSEGMENT 0x40

void dashes() {
    bpmDisplay.writeDigitRaw(0,DASHSEGMENT);
    bpmDisplay.writeDigitRaw(1,DASHSEGMENT);
    bpmDisplay.writeDigitRaw(3,DASHSEGMENT);
    bpmDisplay.writeDigitRaw(4,DASHSEGMENT);
}    

void clearBar() {
    for (uint8_t b=0; b<24; b++) {
        pulseBar.setBar(b,LED_OFF);
    }
}

void drawBar(int length) {
    Serial.print("drawBar(): length is ");Serial.println(length);
    if (length > 24) length = 24;
    uint8_t b = 0;
    for (b=0; b<length; b++) {
        pulseBar.setBar(b,LED_GREEN);
    }
    for (;b<24;b++) {
        pulseBar.setBar(b,LED_OFF);
    }
}

#define THRESHOLD 0
#define SAMPLECOUNT 1
double samplesSum = 0;
int sampleCount = 0;

#define SETTLECOUNT 30
int settleBeats = 0;

//****************************************
//* Setup: Initialize everything         *
//*   Bind pulse input to a pulse sensor *
//*   Wait for pulse sensor to init and  *
//*   settle.                            *
//*   Start up LED Backpack displays.    *
//*   Initialize displays to a zero state*
//****************************************
void setup() {
    Serial.begin(9600);
    Serial.println("PagingDrHowardEtAl starting");
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
    dashes();    // Display zero Beats per Minute
    bpmDisplay.writeDisplay();
    clearBar(); // Display no pulse
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
    int16_t sample;
    uint16_t bpm;
    
    delay(20);
    bpm = pulseSensor.getBeatsPerMinute(); // Get BPM
    Serial.print("BPM is ");Serial.println(bpm);
    if (bpm == 0) {
        dashes();
        clearBar();
    } else {
        bpmDisplay.println(bpm,DEC);             // Display BPM
        if (pulseSensor.sawNewSample()) {
            sample = pulseSensor.getLatestSample() - THRESHOLD; // Get sample
            if (sample < 0) sample = 0;
            Serial.print("Raw Sample is ");Serial.println(sample);
            samplesSum += sample;
            Serial.print("samplesSum is ");Serial.println(samplesSum);
            Serial.print("sampleCount is ");Serial.println(sampleCount);
            if (++sampleCount < SAMPLECOUNT) return;
            Serial.print("samplesSum (final) is ");Serial.println(samplesSum);
            sample = samplesSum / SAMPLECOUNT;
            samplesSum = 0;
            sampleCount = 0;
            Serial.print("Averaged Sample is ");Serial.println(sample);
            double s1 = sample/1024.0;
            Serial.print("s1 is ");Serial.println(s1);
            int barlen = (int)(s1 * 24);
            Serial.print("barlen is ");Serial.println(barlen);
            drawBar(barlen); // Display sample
        }
    }
    bpmDisplay.writeDisplay();
    pulseBar.writeDisplay();
}
