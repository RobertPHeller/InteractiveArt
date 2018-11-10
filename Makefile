##-*- makefile -*-############################################################
#
#  System        : 
#  Module        : 
#  Object Name   : $RCSfile$
#  Revision      : $Revision$
#  Date          : $Date$
#  Author        : $Author$
#  Created By    : Robert Heller
#  Created       : Thu Nov 8 19:44:29 2018
#  Last Modified : <181110.1645>
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
#    Copyright (C) 2018  Robert Heller D/B/A Deepwoods Software
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


PDFLATEX = /usr/bin/pdflatex
WRITEUPSTEX = InteractiveArtWriteups.tex AndroidsDream/AndroidsDream.tex \
		HelloWorld/HelloWorld.tex \
		OnlyHerHairdresser/OnlyHerHairdresser.tex \
		PagingDrHowardEtAl/PagingDrHowardEtAl.tex \
		SprocketFactory/SprocketFactory.tex \
		SteelWheels/SteelWheels.tex \
		WelcomeToGothemCity/WelcomeToGothemCity.tex \
		WhyDidTheChicken/WhyDidTheChicken.tex

WRITEUPQCODES = InteractiveArtonGitHub.png \
	AndroidsDream/AndroidsDreamonGitHub.png \
	HelloWorld/HelloWorldonGitHub.png \
	OnlyHerHairdresser/OnlyHerHairdresseronGitHub.png \
	PagingDrHowardEtAl/PagingDrHowardEtAlonGitHub.png \
	SprocketFactory/SprocketFactoryonGitHub.png \
	SteelWheels/SteelWheelsonGitHub.png \
	WelcomeToGothemCity/WelcomeToGothemCityonGitHub.png \
	WhyDidTheChicken/WhyDidTheChickenonGitHub.png adafruitQR.png \
	HelloWorld/mpr121-12-key-capacitive-touch-sensorQR.png \
	HelloWorld/nokia-5110-3310-monochrome-lcdQR.png \
	WelcomeToGothemCity/distance-measurement-ultrasound-hcsr04QR.png \
	OnlyHerHairdresser/fiber-optic-pixie-princess-skirtQR.png \
	OnlyHerHairdresser/adafruit-color-sensorsQR.png \
	WhyDidTheChicken/bi-color-8x8-matrixQR.png \
	AndroidsDream/trinket-modded-stuffed-animalQR.png \
	PagingDrHowardEtAl/super-awesome-sylvia-builds-a-pulse-sensor-pendantQR.png \
	PagingDrHowardEtAl/adafruit-led-backpackQR.png \
	SprocketFactory/pwm-or-servo-featherwingQR.png \
	SteelWheels/adafruit-neopixel-uberguideQR.png
	

all: InteractiveArtWriteups.pdf

InteractiveArtWriteups.pdf: $(WRITEUPSTEX) $(WRITEUPQCODES)
	-rm -f *.aux */*.aux
	$(PDFLATEX) InteractiveArtWriteups.tex
	$(PDFLATEX) InteractiveArtWriteups.tex
	$(PDFLATEX) InteractiveArtWriteups.tex

clean:
	-rm -f InteractiveArtWriteups.pdf *.aux */*.aux
