// -!- c++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : Robert Heller
//  Created       : Thu Sep 26 19:54:06 2019
//  Last Modified : <190927.0925>
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

#ifndef __CONWAYSLIFE_H
#define __CONWAYSLIFE_H

#include <Arduino.h>

#include <initializer_list>


class BitMatrix {
public:
    BitMatrix(int width=16, int height=16, const unsigned char *bits = NULL);
    BitMatrix(int width, int height, std::initializer_list<const unsigned char> bits);
    BitMatrix(const BitMatrix &otherMatrix);
    BitMatrix& operator = (const BitMatrix &otherMatrix);
    ~BitMatrix();
    bool getbit(int i,int j) const;
    void setbit(int i,int j,bool bitval);
    inline bool operator()(int i,int j) const {return getbit(i,j);}
    inline int Width() const {return _width;}
    inline int Height() const {return _height;}
private:
    unsigned char *_bits;
    int _width;
    int _height;
    int _bytewidth;
    int _bytecount;
};


class Life  {
public:
    Life (const BitMatrix &initialLife) {
        _lifeMatrix = new BitMatrix(initialLife);
    }
    Life (int width=16, int height=16, const unsigned char *bits = NULL) {
        _lifeMatrix = new BitMatrix(width,height, bits);
    }
    Life(int width, int height, std::initializer_list<const unsigned char> bits) {
        _lifeMatrix = new BitMatrix(width,height, bits);
    }
    ~Life() {
        delete _lifeMatrix;
    }
    void SetLife(const BitMatrix &initialLife) {
        delete _lifeMatrix;
        _lifeMatrix = new BitMatrix(initialLife);
    }
    void SetLife(int width, int height, const unsigned char *bits) {
        delete _lifeMatrix;
        _lifeMatrix = new BitMatrix(width,height, bits);
    }
    void SetLife(int width, int height, std::initializer_list<const unsigned char> bits) {
        delete _lifeMatrix;
        _lifeMatrix = new BitMatrix(width,height, bits);
    }
    void lifeCycle();
    const BitMatrix *currentLife() const {return _lifeMatrix;}
private:
    BitMatrix *_lifeMatrix;
    int _countBitsAt(int i, int j, const BitMatrix &m) const;
};

#endif // __CONWAYSLIFE_H

