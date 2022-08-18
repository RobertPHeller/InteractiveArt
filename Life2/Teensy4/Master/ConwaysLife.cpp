// -!- C++ -!- //////////////////////////////////////////////////////////////
//
//  System        : 
//  Module        : 
//  Object Name   : $RCSfile$
//  Revision      : $Revision$
//  Date          : $Date$
//  Author        : $Author$
//  Created By    : Robert Heller
//  Created       : Thu Sep 26 19:54:29 2019
//  Last Modified : <190928.2301>
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

#include "ConwaysLife.h"

BitMatrix::BitMatrix(int width, int height,const unsigned char *bits)
{
    _width = width;
    _height = height;
    _bytewidth = (width+7)/8;
    _bytecount = _bytewidth*_height;
    _bits = new unsigned char[_bytecount];
    if (bits == NULL) {
        for (int ibyte=0;ibyte<_bytecount;ibyte++) _bits[ibyte] = 0;
    } else {
        for (int ibyte=0;ibyte<_bytecount;ibyte++) _bits[ibyte] = bits[ibyte];
    }
}

BitMatrix::BitMatrix(int width, int height,std::initializer_list<const unsigned char> bits)
{
    using initializer_type = std::initializer_list<const unsigned char>;
    _width = width;
    _height = height;
    _bytewidth = (width+7)/8;
    _bytecount = _bytewidth*_height;
    _bits = new unsigned char[_bytecount];
    int ibyte = 0;
    for (initializer_type::const_iterator abyte = bits.begin();
         abyte < bits.end();
         abyte++) _bits[ibyte++] = *abyte;
}


BitMatrix::BitMatrix(const BitMatrix &otherMatrix)
{
    _width = otherMatrix._width;
    _height = otherMatrix._height;
    _bytewidth = otherMatrix._bytewidth;
    _bits = new unsigned char[_bytecount];
    for (int ibyte=0;ibyte<_bytecount;ibyte++) 
        _bits[ibyte] = otherMatrix._bits[ibyte];
}

BitMatrix::BitMatrix(const BitMatrix *otherMatrix)
{
    _width = otherMatrix->_width;
    _height = otherMatrix->_height;
    _bytewidth = otherMatrix->_bytewidth;
    _bits = new unsigned char[_bytecount];
    for (int ibyte=0;ibyte<_bytecount;ibyte++) 
        _bits[ibyte] = otherMatrix->_bits[ibyte];
}

BitMatrix::~BitMatrix()
{
    delete _bits;
}

BitMatrix& BitMatrix::operator = (const BitMatrix &otherMatrix)
{
    if (this != &otherMatrix) {
        delete _bits;
        _width = otherMatrix._width;
        _height = otherMatrix._height;
        _bytewidth = otherMatrix._bytewidth;
        _bits = new unsigned char[_bytecount];
        for (int ibyte=0;ibyte<_bytecount;ibyte++) 
            _bits[ibyte] = otherMatrix._bits[ibyte];
    }
    return *this;
}

bool BitMatrix::getbit(int i,int j) const
{
    bool result = false;
    if (i < 0 || i >= _width) return result;
    if (j < 0 || j >= _height) return result;
    int byteoffset = j*_bytewidth;
    int byteno = i >> 3;
    int bitno  = i &  0x07;
    unsigned char byte = _bits[byteoffset+byteno];
    return ((byte >> bitno)&1) == 1;
}

void BitMatrix::setbit(int i,int j,bool bitval)
{
    if (i < 0 || i >= _width) return;
    if (j < 0 || j >= _height) return;
    int byteoffset = j*_bytewidth;
    int byteno = i >> 3;
    int bitno  = i &  0x07;
    unsigned char *byte = &(_bits[byteoffset+byteno]);
    if (bitval) {
        *byte |= 1 << bitno;
    } else {
        *byte &= ~(1 << bitno);
    }
}

void Life::lifeCycle()
{
    BitMatrix temp = *_lifeMatrix;
    for (int i = 0;i < temp.Width();i++) {
        for (int j = 0;i < temp.Height();j++) {
            int alive = _countBitsAt(i,j,temp);
            if (temp(i,j)) {
                if (alive < 2 || alive > 3) {
                    _lifeMatrix->setbit(i,j,false);
                }
            } else {
                if (alive == 3) {
                    _lifeMatrix->setbit(i,j,true);
                }
            }
        }
    }
}

int Life::_countBitsAt(int i, int j, const BitMatrix &m) const
{
    int alive = 0;
    for (int ii = -1;ii <= 1;ii++) {
        if (ii == 0) continue;
        for (int jj = -1;jj <= 1;jj++) {
            if (jj == 0) continue;
            if (m(i+ii,j+jj)) alive++;
        }
    }
    return alive;
}

bool Life::allDeadP() const
{
    for (int i = 0; i < _lifeMatrix->Width(); i++) {
        for (int j = 0; j < _lifeMatrix->Height(); j++) {
            if ((*_lifeMatrix)(i,j)) return false;
        }
    }
    return (true);
}
