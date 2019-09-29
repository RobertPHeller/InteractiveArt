// -!- C++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : Robert Heller
//  Created       : Sat Sep 28 19:04:38 2019
//  Last Modified : <190928.2027>
//
//  Description	
//
//  Notes
//
//  History
//	
/////////////////////////////////////////////////////////////////////////////
//
//    Copyright (C) 2019  Robert Heller D/B/A Deepwoods Software
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
#include <Adafruit_GFX.h>
#include <cstdlib>
#include "ScreenSaver.h"

void ScreenSaver::NextScreen()
{
    if (_currentSaver == None) {
        _nextSaver();
    }
    _screen.fillRect(_xpos,_ypos,_w,_h,0); // Clear old
    _xpos += _incrX;
    _ypos += _incrY;
    if ((_incrX > 0 && _xpos > _screen.width())  ||
        (_incrX < 0 && _xpos+_w < 0)             ||
        (_incrY > 0 && _ypos > _screen.height()) ||
        (_incrY < 0 && _ypos+_h < 0) ) {
        _currentSaver == None;
    } else {
        _screen.drawRGBBitmap(_xpos,_ypos,_bitmap,_w,_h);
    }
}

void ScreenSaver::_nextSaver ()
{
    _currentSaver = (saverType) ((int) (rand()*((int)Marvin)) + 1);
    _xpos = (int16_t) (rand()*_screen.width());
    if (_xpos == 0 || _xpos == _screen.width()-1) {
        _ypos = (int16_t) (rand()*_screen.height());
    } else {
        if (rand() > .5) {
            _ypos = 0;
        } else {
            _ypos = _screen.height()-1;
        }
    }
    do {
        if (_xpos == 0) {
            _incrX = (int16_t) (rand()*4);
        } else {
            _incrX = -(int16_t) (rand()*4);
        }
        if (_ypos == 0) {
            _incrY = (int16_t) (rand()*4);
        } else {
            _incrY = -(int16_t) (rand()*4);
        }
    } while (_incrX == 0 && _incrY == 0);
    _loadNewBitmap();
}

void ScreenSaver::_loadNewBitmap()
{
}
