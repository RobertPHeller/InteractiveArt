// -!- c++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : Robert Heller
//  Created       : Fri Dec 28 09:00:45 2018
//  Last Modified : <181228.1428>
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

#ifndef __IRREMOTE_H
#define __IRREMOTE_H

#include <Arduino.h>
#include <initializer_list>

// the maximum pulse we'll listen for - 65 milliseconds is a long time
#define MAXPULSE 65000
#define NUMPULSES 50

// what our timing resolution should be, larger is better
// as its more 'precise' - but too large and you wont get
// accurate timing
#define RESOLUTION 20

// What percent we will allow in variation to match the same code
#define FUZZINESS 20

template <int PULSES>class RemoteButton {
private:
    uint16_t signal[PULSES*2];
    uint8_t  value;
public:
    RemoteButton(uint8_t v, const std::initializer_list<uint16_t> &pulses) 
                : value(v)
    {
        int i = 0;
        for (std::initializer_list<uint16_t>::const_iterator ii = pulses.begin(); ii < pulses.end(); ii++) {
            signal[i++] = *ii;
        }
    }
    bool Compare (uint16_t pulses[], uint16_t numpulses) const
    {
        if (numpulses != PULSES) return false;
        for (int i=0; i < numpulses; i++) {
            int oncode = pulses[i*2] * RESOLUTION / 10;
            int offcode = pulses[(i*2)+1] * RESOLUTION / 10;
            // check to make sure the error is less than FUZZINESS percent
            if ( abs(oncode - signal[i*2 + 0]) <= (signal[i*2 + 0] * FUZZINESS / 100)) {
            } else {
                return false;
            }
            if ( abs(offcode - signal[i*2 + 1]) <= (signal[i*2 + 1] * FUZZINESS / 100)) {
            } else {
                return false;
            }
        }
        return true;
    }
    uint8_t Value () const {return value;}
};

#define IRPin 12
#define IRPinPort (digitalPinToPort(IRPin)->IN.reg)
#define IRPinMask digitalPinToBitMask(IRPin)

class RemoteControl {
private:
    RemoteButton<10> *buttons[21];
    uint16_t pulses[NUMPULSES*2];
#define HighPulse(i) pulses[((i)*2)+0]
#define LowPulse(i)  pulses[((i)*2)+1]
    uint16_t currentpulse;
public:
    RemoteControl();
    int listen();
    void printPulses();
    void storePulses(char *name, uint8_t ch);
};



#endif // __IRREMOTE_H

