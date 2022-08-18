##-*- makefile -*-############################################################
#
#  System        : 
#  Module        : 
#  Object Name   : $RCSfile$
#  Revision      : $Revision$
#  Date          : $Date$
#  Author        : $Author$
#  Created By    : Robert Heller
#  Created       : Thu Aug 18 08:01:41 2022
#  Last Modified : <220818.1619>
#
#  Description	
#
#  Notes
#
#  History
#	
#  $Log$
#
##############################################################################
#
#    Copyright (C) 2022  Robert Heller D/B/A Deepwoods Software
#			51 Locke Hill Road
#			Wendell, MA 01379-9728
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
# 
#
##############################################################################


SUBDIRS = Teensy4 SmartMatrix SD Wire

all: libteensy4.a libsmartmat.a libsd.a libwire.a libadafruitgfx.a \
	libadafruitssd1306.a libadafruitbusio.a

libteensy4.a: FORCE
	$(MAKE) -C Teensy4 libteensy4.a
	mv Teensy4/libteensy4.a ./
	
libsmartmat.a: FORCE
	$(MAKE) -C SmartMatrix libsmartmat.a
	mv SmartMatrix/libsmartmat.a ./

libsd.a: FORCE
	$(MAKE) -C SD libsd.a
	mv SD/libsd.a ./

libwire.a: FORCE
	$(MAKE) -C Wire libwire.a
	mv Wire/libwire.a ./

libadafruitgfx.a: FORCE
	$(MAKE) -C Adafruit_GFX libadafruitgfx.a
	mv Adafruit_GFX/libadafruitgfx.a ./
	
libadafruitssd1306.a: FORCE
	$(MAKE) -C Adafruit_SSD1306 libadafruitssd1306.a
	mv Adafruit_SSD1306/libadafruitssd1306.a ./

libadafruitbusio.a: FORCE
	$(MAKE) -C Adafruit_BusIO libadafruitbusio.a
	mv Adafruit_BusIO/libadafruitbusio.a ./

FORCE:


clean:
	rm -f *.a
	$(MAKE) -C Teensy4 clean
	$(MAKE) -C SmartMatrix clean
	$(MAKE) -C SD clean
	$(MAKE) -C Wire clean
	$(MAKE) -C Adafruit_GFX clean
	$(MAKE) -C Adafruit_SSD1306 clean
	$(MAKE) -C Adafruit_BusIO clean
