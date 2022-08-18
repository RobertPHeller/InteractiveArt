##-*- makefile -*-############################################################
#
#  System        : 
#  Module        : 
#  Object Name   : $RCSfile$
#  Revision      : $Revision$
#  Date          : $Date$
#  Author        : $Author$
#  Created By    : Robert Heller
#  Created       : Thu Aug 18 08:13:03 2022
#  Last Modified : <220818.1517>
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


# Teensyduino Core Library
# http://www.pjrc.com/teensy/
# Copyright (c) 2019 PJRC.COM, LLC.
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# 1. The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# 2. If the Software is incorporated into a build system that allows
# selection among a list of target devices, then similar target
# devices manufactured by PJRC.COM must be included in the list of
# target devices and selectable in the same manner.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
# BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
# ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# Use these lines for Teensy 4.0
#MCU = IMXRT1062
#MCU_LD = imxrt1062.ld
#MCU_DEF = ARDUINO_TEENSY40

# Use these lines for Teensy 4.1
MCU = IMXRT1062
MCU_LD = imxrt1062_t41.ld
MCU_DEF = ARDUINO_TEENSY41

# The name of this library
LIBNAME = libsd.a

# configurable options
OPTIONS = -DF_CPU=600000000 -DUSB_SERIAL -DLAYOUT_US_ENGLISH -DUSING_MAKEFILE
#
# USB Type configuration:
#   -DUSB_SERIAL
#   -DUSB_DUAL_SERIAL
#   -DUSB_TRIPLE_SERIAL
#   -DUSB_KEYBOARDONLY
#   -DUSB_TOUCHSCREEN
#   -DUSB_HID_TOUCHSCREEN
#   -DUSB_HID
#   -DUSB_SERIAL_HID
#   -DUSB_MIDI
#   -DUSB_MIDI4
#   -DUSB_MIDI16
#   -DUSB_MIDI_SERIAL
#   -DUSB_MIDI4_SERIAL
#   -DUSB_MIDI16_SERIAL
#   -DUSB_AUDIO
#   -DUSB_MIDI_AUDIO_SERIAL
#   -DUSB_MIDI16_AUDIO_SERIAL
#   -DUSB_MTPDISK
#   -DUSB_RAWHID
#   -DUSB_FLIGHTSIM
#   -DUSB_FLIGHTSIM_JOYSTICK

# options needed by many Arduino libraries to configure for Teensy model
OPTIONS += -D__$(MCU)__ -DARDUINO=10813 -DTEENSYDUINO=154 -D$(MCU_DEF)

# for Cortex M7 with single & double precision FPU
CPUOPTIONS = -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -mthumb

# use this for a smaller, no-float printf
#SPECS = --specs=nano.specs

# Other Makefiles and project templates for Teensy
#
# https://forum.pjrc.com/threads/57251?p=213332&viewfull=1#post213332
# https://github.com/apmorton/teensy-template
# https://github.com/xxxajk/Arduino_Makefile_master
# https://github.com/JonHylands/uCee


#************************************************************************
# Location of Teensyduino utilities, Toolchain, and Arduino Libraries.
# To use this makefile without Arduino, copy the resources from these
# locations and edit the pathnames.  The rest of Arduino is not needed.
#************************************************************************

include ../../../Common/ARDUINOPATH.mk

# Those that specify a NO_ARDUINO environment variable will
# be able to use this Makefile with no Arduino dependency.
# Please note that if ARDUINOPATH was set, it will override
# the NO_ARDUINO behaviour.
ifndef NO_ARDUINO
# Path to your arduino installation
ARDUINOPATH ?= ../../../../..
endif

ifdef ARDUINOPATH

# path location for Teensy Loader, teensy_post_compile and teensy_reboot (on Linux)
TOOLSPATH = $(abspath $(ARDUINOPATH)/hardware/tools)

# path location for Arduino libraries (currently not used)
LIBRARYPATH = $(abspath $(ARDUINOPATH)/libraries)

# path location for the arm-none-eabi compiler
COMPILERPATH = $(abspath $(ARDUINOPATH)/hardware/tools/arm/bin)

TEENSY4CORE = $(abspath $(ARDUINOPATH)/hardware/teensy/avr/cores/teensy4)

else
# Default to the normal GNU/Linux compiler path if NO_ARDUINO
# and ARDUINOPATH was not set.
COMPILERPATH ?= /usr/bin



endif

include ../../../Common/SD.mk
include ../../../Common/SdFat.mk
include ../../../Common/SPI.mk

SRCDIR := $(SDPATH)
SRCDIR2 := $(SDFATPATH)
SRCDIR3 := $(SPIPATH)
TGTDIR := 

INCLUDES=-I$(SRCDIR) -I$(SRCDIR2) -I$(SRCDIR3)


#************************************************************************
# Settings below this point usually do not need to be edited
#************************************************************************

# CPPFLAGS = compiler options for C and C++
CPPFLAGS = -Wall -g -O2 $(CPUOPTIONS) -MMD $(OPTIONS) -I. -I$(TEENSY4CORE) $(INCLUDES) -ffunction-sections -fdata-sections

# compiler options for C++ only
CXXFLAGS = -std=gnu++14 -felide-constructors -fno-exceptions -fpermissive -fno-rtti -Wno-error=narrowing

# compiler options for C only
CFLAGS =

# names for the compiler programs
CC = $(COMPILERPATH)/arm-none-eabi-gcc
CXX = $(COMPILERPATH)/arm-none-eabi-g++
AR  = $(COMPILERPATH)/arm-none-eabi-gcc-ar
RANLIB = $(COMPILERPATH)/arm-none-eabi-gcc-ranlib


# automatically create lists of the sources and objects
# TODO: this does not handle Arduino libraries yet...
C_FILES := $(wildcard $(SRCDIR)/*.c) 
CPP_FILES := $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR2)/*.cpp) \
	$(wildcard $(SRCDIR2)/common/*.cpp) \
	$(wildcard $(SRCDIR2)/ExFatLib/*.cpp) \
	$(wildcard $(SRCDIR2)/FatLib/*.cpp) \
	$(wildcard $(SRCDIR2)/FsLib/*.cpp) \
	$(wildcard $(SRCDIR2)/iostream/*.cpp) \
	$(wildcard $(SRCDIR2)/SdCard/*.cpp) \
	$(wildcard $(SRCDIR2)/SpiDriver/*.cpp) \
	$(wildcard $(SRCDIR3)/*.cpp)	
OBJS := $(notdir $(C_FILES:.c=.o)) $(notdir $(CPP_FILES:.cpp=.o))

%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ -c
	
%.o: $(SRCDIR2)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ -c

%.o: $(SRCDIR2)/common/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ -c

%.o: $(SRCDIR2)/ExFatLib/%.cpp 
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ -c

%.o: $(SRCDIR2)/FatLib/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ -c

%.o: $(SRCDIR2)/FsLib/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ -c

%.o: $(SRCDIR2)/iostream/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ -c

%.o: $(SRCDIR2)/SdCard/%.cpp 
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ -c

%.o: $(SRCDIR2)/SpiDriver/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ -c

%.o: $(SRCDIR3)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ -c
	
	
%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ -c

%.o: $(SRCDIR2)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ -c


all: $(LIBNAME)

$(LIBNAME): $(OBJS)
	$(AR) crs$(AROPTS) $(LIBNAME) $(OBJS)


# compiler generated dependency info
-include $(OBJS:.o=.d)

clean:
	rm -f *.o *.d *.a
