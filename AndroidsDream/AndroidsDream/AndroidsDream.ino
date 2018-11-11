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
//  Last Modified : <181111.1411>
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

#include <Servo.h>

// Servo object instances
Servo head;
Servo tail;

// Servo positions
int16_t headPosition;
int16_t tailPosition;

// Servo pin numbers
#define HeadServo 10
#define TailServo 9

// LDR inputs
#define HeadLDR A0
#define BackLDR A1
#define TailLDR A2

// Sleeping flag
bool sleeping;

//*******************************************
//* Set things up:                          *
//* Attach and initialize servos            *
//* Enter sleep mode                        *
//*******************************************
void setup() {
    head.attach(HeadServo);
    tail.attach(TailServo);
    headPosition = 0;
    head.write(headPosition);
    tailPosition = 0;
    tail.write(tailPosition);
    sleeping = true;
}

//*******************************************
//* Main loop:                              *
//* If sleeping:                            *
//*    Check light levels and if it is light*
//*    exit sleep mode (wake up), raising   *
//*    head half way and raise tail half way*
//*    else if it is still dark, delay for  *
//*    one whole minute.                    *
//* Else if not sleeping:                   *
//*    If all LDRs are dark, lower head and *
//*    tail and enter sleep mode.           *
//*    Otherwise, if head LDR is dark raise *
//*    head and if head LDR is light return *
//*    head to "normal" position.  If tail  *
//*    LDR is dark, wag tail.               *
//*******************************************
void loop() {
    uint16_t head_reading = analogRead(HeadLDR); // Read head LDR
    uint16_t back_reading = analogRead(BackLDR); // Read back LDR
    uint16_t tail_reading = analogRead(TailLDR); // Read tail LDR
    
    // Sleeping?
    if (sleeping) {
        // Here comes the sun...
        if (head_reading > 800 ||
            back_reading > 800 ||
            tail_reading > 800) {
            sleeping = false; // Wakey wakey...
            headPosition = 90; // head up
            head.write(headPosition);
            tailPosition = 90; // tail up
            tail.write(tailPosition);
        } else {
            delay(60000); // zzzzzzzzzzzzzzzzz...
        }
    } else {
        // Nightfall?
        if (head_reading < 400 &&
            back_reading < 400 &&
            tail_reading < 400) {
            headPosition = 0; // Head down
            tailPosition = 0; // Tail down
            head.write(headPosition);
            tail.write(tailPosition);
            sleeping = true; // Nightie night...
        } else {
            // Petting head?
            if (head_reading < 800) {
                headPosition = 180; // Head up
                head.write(headPosition);
            } else if (headPosition != 90) {
                headPosition = 90; // Head lowered
                head.write(headPosition);
            }
            // Petting tail?
            if (tail_reading < 800) {
                tailPosition = 180; // wig
                tail.write(tailPosition);
                delay(20);
                tailPosition = 90; // wag
                tail.write(tailPosition);
                delay(20);
                tailPosition = 180; // wig
                tail.write(tailPosition);
                delay(20);
                tailPosition = 90; // wag
                tail.write(tailPosition);
                delay(20);
                tailPosition = 180; // wig
                tail.write(tailPosition);
                delay(20);
                tailPosition = 90; // wag
                tail.write(tailPosition);
                delay(20);
            }
        }
        delay(1000); // Check again in a second.
    }
}
