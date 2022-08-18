##-*- makefile -*-############################################################
#
#  System        : 
#  Module        : 
#  Object Name   : $RCSfile$
#  Revision      : $Revision$
#  Date          : $Date$
#  Author        : $Author$
#  Created By    : Robert Heller
#  Created       : Thu Aug 18 07:12:04 2022
#  Last Modified : <220818.1411>
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


ifndef ARDUINOPATH_MK
ARDUINOPATH_MK:=1

# Finds the first occurence of a file under a search path. Returns the first
# entry in the directories list that has file under it, or empty string if none
# found.
# $(1): file or dir to look for, $(2); list of paths
findfirst=$(firstword $(foreach dir,$(2),$(if $(wildcard $(dir)/$(1)),$(wildcard $(dir)))))

# Finds missing dependencies from a list.
#
# Accepts as $(1) a list of variable NAMEs. Returns a string containing the
# name of those variables that have no or empty value. Returns an empty string
# if all dependencies are met.
#
# Usage:
# DEPS += TOOLPATH FREERTOSPATH
# MISSING_DEPS:=$(call find_missing_deps,$(DEPS))
# ifneq (,$(MISSING_DEPS))
# all:
#       @echo missing dependencies: $(MISSING_DEPS)
# else
# all: build-deps
# endif
find_missing_deps=$(strip $(foreach depvar,$(1),$(if $(value $(depvar)),,$(depvar))))

################ shell ##################
# Various commands in the makefiles are using the bash syntax. We ignore the
# user's login shell preferences and use a specific shell instead.
export SHELL :=/bin/bash

ifndef ARDUINOPATH
SEARCHPATH := \
   /usr/local/arduino* \
   $(HOME)/Arduino/arduino*
   

TRYPATH:=$(call findfirst,arduino-builder,$(SEARCHPATH))
ifneq ($(TRYPATH),)
ARDUINOPATH:=$(abspath $(TRYPATH)/)
endif
   
endif

ifndef ARDUINOLIBPATHS
ARDUINOLIBPATHS := \
   $(ARDUINOPATH)/hardware/teensy/avr/libraries/ \
   $(HOME)/Arduino/libraries \
   $(ARDUINOPATH)/libraries 
endif

endif
