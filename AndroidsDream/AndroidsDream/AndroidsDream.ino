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
//  Last Modified : <181104.2029>
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

Servo head;
Servo tail;

int16_t headPosition;
int16_t tailPosition;

#define HeadServo 10
#define TailServo 9

#define HeadLDR A0
#define BackLDR A1
#define TailLDR A2

bool sleeping;

void setup() {
    head.attach(HeadServo);
    tail.attach(TailServo);
    headPosition = 0;
    head.write(headPosition);
    tailPosition = 0;
    tail.write(tailPosition);
    sleeping = true;
}

void loop() {
    uint16_t head_reading = analogRead(HeadLDR);
    uint16_t back_reading = analogRead(BackLDR);
    uint16_t tail_reading = analogRead(TailLDR);
    
    if (sleeping) {
        if (head_reading > 800 ||
            back_reading > 800 ||
            tail_reading > 800) {
            sleeping = false;
            headPosition = 90;
            head.write(headPosition);
            tailPosition = 90;
            tail.write(tailPosition);
        } else {
            delay(60000);
        }
    } else {
        if (head_reading < 400 &&
            back_reading < 400 &&
            tail_reading < 400) {
            headPosition = 0;
            tailPosition = 0;
            head.write(headPosition);
            tail.write(tailPosition);
            sleeping = true;
        } else {
            if (head_reading < 800) {
                headPosition = 180;
                head.write(headPosition);
            } else if (headPosition != 0) {
                headPosition = 0;
                head.write(headPosition);
            }
            if (tail_reading < 800) {
                tailPosition = 180;
                tail.write(tailPosition);
                delay(20);
                tailPosition = 0;
                tail.write(tailPosition);
                delay(20);
                tailPosition = 180;
                tail.write(tailPosition);
                delay(20);
                tailPosition = 0;
                tail.write(tailPosition);
                delay(20);
                tailPosition = 180;
                tail.write(tailPosition);
                delay(20);
                tailPosition = 0;
                tail.write(tailPosition);
                delay(20);
            }
        }
        delay(1000);
    }
}
