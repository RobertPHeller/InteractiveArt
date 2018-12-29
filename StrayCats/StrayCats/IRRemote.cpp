// -!- C++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : Robert Heller
//  Created       : Fri Dec 28 11:50:49 2018
//  Last Modified : <181228.1440>
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

static const char rcsid[] = "@(#) : $Id$";

#include <Arduino.h>
#include "IRRemote.h"
#include <SD.h>
#include <string.h>

static RemoteButton<10> VolM('v',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> PlayPause('p',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> VolP('V',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Setup('s',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Prev('<',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Stop('S',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> ChM('c',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Enter('e',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> ChP('C',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Zero('0',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Next('>',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Back('b',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> One('1',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Two('2',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Three('3',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Four('4',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Five('5',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Six('6',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Seven('7',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Eight('8',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});
static RemoteButton<10> Nine('9',{1,2,3,4,5,6,7,8,9,0,0,9,8,7,6,5,4,3,2,1});


RemoteControl::RemoteControl() {
    buttons[0] = &VolM;
    buttons[1] = &PlayPause;
    buttons[2] = &VolP;
    buttons[3] = &Setup;
    buttons[4] = &Prev;
    buttons[5] = &Stop;
    buttons[6] = &ChM;
    buttons[7] = &Enter;
    buttons[8] = &ChP;
    buttons[9] = &Zero;
    buttons[10] = &Next;
    buttons[11] = &Back;
    buttons[12] = &One;
    buttons[13] = &Two;
    buttons[14] = &Three;
    buttons[15] = &Four;
    buttons[16] = &Five;
    buttons[17] = &Six;
    buttons[18] = &Seven;
    buttons[19] = &Eight;
    buttons[20] = &Nine;
    pinMode(IRPin,INPUT);
}


int RemoteControl::listen()
{
    currentpulse = 0;
    while (1) {
        uint16_t highpulse, lowpulse; // temporary storage timing
        highpulse = lowpulse = 0; // start out with no pulse length
        
        // while (digitalRead(IRpin)) { // this is too slow!
        while (IRPinPort & IRPinMask) {
            // pin is still HIGH
            
            // count off another few microseconds
            highpulse++;
            delayMicroseconds(RESOLUTION);
            
            // If the pulse is too long, we 'timed out' - either nothing
            // was received or the code is finished, so print what
            // we've grabbed so far, and then reset
            if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
                
                break;
            }
        }
        // we didn't time out so lets stash the reading
        HighPulse(currentpulse) = highpulse;
        
        // same as above
        while (! (IRPinPort & IRPinMask)) {
            
            // pin is still LOW
            lowpulse++;
            delayMicroseconds(RESOLUTION);
            if ((lowpulse >= MAXPULSE) && (currentpulse != 0)) {
                
                break;
            }
        }
        LowPulse(currentpulse) = lowpulse;
        
        // we read one high-low pulse successfully, continue!
        currentpulse++;
    }

    for (int ib = 0; ib < 21; ib++) {
        if (buttons[ib]->Compare(pulses,currentpulse)) {
            return buttons[ib]->Value();
        }
    }
    return -1;
}

void RemoteControl::printPulses()
{
    currentpulse = 0;
    while (1) {
        uint16_t highpulse, lowpulse; // temporary storage timing
        highpulse = lowpulse = 0; // start out with no pulse length
        
        // while (digitalRead(IRpin)) { // this is too slow!
        while (IRPinPort & IRPinMask) {
            // pin is still HIGH
            
            // count off another few microseconds
            highpulse++;
            delayMicroseconds(RESOLUTION);
            
            // If the pulse is too long, we 'timed out' - either nothing
            // was received or the code is finished, so print what
            // we've grabbed so far, and then reset
            if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
                
                break;
            }
        }
        // we didn't time out so lets stash the reading
        HighPulse(currentpulse) = highpulse;
        
        // same as above
        while (! (IRPinPort & IRPinMask)) {
            
            // pin is still LOW
            lowpulse++;
            delayMicroseconds(RESOLUTION);
            if ((lowpulse >= MAXPULSE) && (currentpulse != 0)) {
                
                break;
            }
        }
        LowPulse(currentpulse) = lowpulse;
        
        // we read one high-low pulse successfully, continue!
        currentpulse++;
    }
    
    Serial.print("Heard ");
    Serial.print(currentpulse);
    Serial.println("-pulse long IR signal");
    
    for (int i=0; i< currentpulse-1; i++) {
        int oncode = HighPulse(i) * RESOLUTION / 10;
        int offcode = LowPulse(i) * RESOLUTION / 10;
        
        Serial.print(oncode); // the ON signal we heard
        
        Serial.print(" \t"); // tab
        
        Serial.print(offcode); // the OFF signal we heard
        
        Serial.println();
    }
    
}

void RemoteControl::storePulses(char *name, uint8_t ch)
{
    char filename[30];
    
    Serial.print("Press the button for ");Serial.println(name);
    currentpulse = 0;
    while (1) {
        uint16_t highpulse, lowpulse; // temporary storage timing
        highpulse = lowpulse = 0; // start out with no pulse length
        
        // while (digitalRead(IRpin)) { // this is too slow!
        while (IRPinPort & IRPinMask) {
            // pin is still HIGH
            
            // count off another few microseconds
            highpulse++;
            delayMicroseconds(RESOLUTION);
            
            // If the pulse is too long, we 'timed out' - either nothing
            // was received or the code is finished, so print what
            // we've grabbed so far, and then reset
            if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
                
                break;
            }
        }
        // we didn't time out so lets stash the reading
        HighPulse(currentpulse) = highpulse;
        
        // same as above
        while (! (IRPinPort & IRPinMask)) {
            
            // pin is still LOW
            lowpulse++;
            delayMicroseconds(RESOLUTION);
            if ((lowpulse >= MAXPULSE) && (currentpulse != 0)) {
                
                break;
            }
        }
        LowPulse(currentpulse) = lowpulse;
        
        // we read one high-low pulse successfully, continue!
        currentpulse++;
    }
    
    Serial.print("Heard ");
    Serial.print(currentpulse);
    Serial.println("-pulse long IR signal");
    
    strcpy(filename,name);
    strcat(filename,".h");
    File myFile = SD.open(filename,FILE_WRITE);
    myFile.print("static RemoteButton<");
    myFile.print(currentpulse-1);
    myFile.print("> ");
    myFile.print(name);
    myFile.print("('");
    myFile.print(ch);
    myFile.println("',{");
    for (int i=0; i < currentpulse-1; i++) {
        myFile.print("\t");
        myFile.print(HighPulse(i));
        myFile.print(",");
        myFile.print(LowPulse(i));
        if (i < currentpulse-2) myFile.println(",");
        else myFile.println("});");
    }
    myFile.close();
}

