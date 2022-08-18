##-*- makefile -*-############################################################
#
#  System        : 
#  Module        : 
#  Object Name   : $RCSfile$
#  Revision      : $Revision$
#  Date          : $Date$
#  Author        : $Author$
#  Created By    : Robert Heller
#  Created       : Wed Aug 17 17:19:31 2022
#  Last Modified : <220818.0936>
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


SUBDIRS = Master Slave

all: Master/main.hex Slave/main.hex

FlashMaster: Master/main.hex
	$(MAKE) -C Master Flash

FlashSlave: Slave/main.hex
	$(MAKE) -C Slave Flash

Master/main.hex: FORCE
	$(MAKE) -C Master
	
Slave/main.hex: FORCE
	$(MAKE) -C Slave 

clean:
	$(MAKE) -C Master clean
	$(MAKE) -C Slave clean
FORCE:
