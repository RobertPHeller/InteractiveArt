EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:adafruit_breakouts
LIBS:feather_m0_express
LIBS:adafruit_powerboost_500
LIBS:SprocketFactory-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "29 oct 2018"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L FEATHER_M0_EXPRESS U1
U 1 1 5BD71463
P 2800 2450
F 0 "U1" H 2800 2450 60  0000 C CNN
F 1 "FEATHER_M0_EXPRESS" H 2850 2050 50  0000 C CNN
F 2 "~" H 2800 2450 60  0000 C CNN
F 3 "~" H 2800 2450 60  0000 C CNN
	1    2800 2450
	1    0    0    -1  
$EndComp
$Comp
L 8-CHANNELSERVO​FEATHERWING U2
U 1 1 5BD74B3A
P 5250 2400
F 0 "U2" H 5250 2400 60  0000 C CNN
F 1 "8-CHANNELSERVO​FEATHERWING" V 5550 2600 50  0000 C CNN
F 2 "~" H 5250 2400 60  0000 C CNN
F 3 "~" H 5250 2400 60  0000 C CNN
	1    5250 2400
	1    0    0    -1  
$EndComp
Text Label 2100 1800 2    60   ~ 0
Rst
Text Label 2100 1900 2    60   ~ 0
3V
Text Label 2100 2000 2    60   ~ 0
ARef
Text Label 2100 2100 2    60   ~ 0
GND
Text Label 2100 2200 2    60   ~ 0
A0
Text Label 2100 2300 2    60   ~ 0
A1
Text Label 2100 2400 2    60   ~ 0
A2
Text Label 2100 2500 2    60   ~ 0
A3
Text Label 2100 2600 2    60   ~ 0
A4
Text Label 2100 2700 2    60   ~ 0
A5
Text Label 2100 2800 2    60   ~ 0
SCK
Text Label 2100 2900 2    60   ~ 0
MOSI
Text Label 2100 3000 2    60   ~ 0
MISO
Text Label 2100 3100 2    60   ~ 0
RX
Text Label 4550 1750 2    60   ~ 0
Rst
Text Label 4550 1850 2    60   ~ 0
3V
Text Label 4550 1950 2    60   ~ 0
ARef
Text Label 4550 2050 2    60   ~ 0
GND
Text Label 4550 2150 2    60   ~ 0
A0
Text Label 4550 2250 2    60   ~ 0
A1
Text Label 4550 2350 2    60   ~ 0
A2
Text Label 4550 2450 2    60   ~ 0
A3
Text Label 4550 2550 2    60   ~ 0
A4
Text Label 4550 2650 2    60   ~ 0
A5
Text Label 4550 2750 2    60   ~ 0
SCK
Text Label 4550 2850 2    60   ~ 0
MOSI
Text Label 4550 2950 2    60   ~ 0
MISO
Text Label 4550 3050 2    60   ~ 0
RX
Text Label 3500 1800 0    60   ~ 0
BAT
Text Label 3500 1900 0    60   ~ 0
Enable
Text Label 3500 2000 0    60   ~ 0
USB
Text Label 3500 2100 0    60   ~ 0
13
Text Label 3500 2200 0    60   ~ 0
12
Text Label 3500 2300 0    60   ~ 0
11
Text Label 3500 2400 0    60   ~ 0
10
Text Label 3500 2500 0    60   ~ 0
9
Text Label 3500 2600 0    60   ~ 0
6
Text Label 3500 2700 0    60   ~ 0
5
Text Label 3500 2800 0    60   ~ 0
SCL
Text Label 3500 2900 0    60   ~ 0
SDA
Text Label 3500 3000 0    60   ~ 0
GND
Text Label 3500 3100 0    60   ~ 0
TX
Text Label 5950 1850 0    60   ~ 0
Enable
Text Label 5950 1950 0    60   ~ 0
USB
Text Label 5950 2050 0    60   ~ 0
13
Text Label 5950 2150 0    60   ~ 0
12
Text Label 5950 2250 0    60   ~ 0
11
Text Label 5950 2350 0    60   ~ 0
10
Text Label 5950 2450 0    60   ~ 0
9
Text Label 5950 2550 0    60   ~ 0
6
Text Label 5950 2650 0    60   ~ 0
5
Text Label 5950 2750 0    60   ~ 0
SCL
Text Label 5950 2850 0    60   ~ 0
SDA
Text Label 5950 2950 0    60   ~ 0
GND
Text Label 5950 3050 0    60   ~ 0
TX
Wire Wire Line
	6150 1550 6350 1550
Wire Wire Line
	6350 1550 6350 3100
Wire Wire Line
	6350 2950 5950 2950
$Comp
L SW_PUSH SW1
U 1 1 5BD75742
P 7050 2550
F 0 "SW1" H 7200 2660 50  0000 C CNN
F 1 "Start" H 7050 2470 50  0000 C CNN
F 2 "~" H 7050 2550 60  0000 C CNN
F 3 "~" H 7050 2550 60  0000 C CNN
	1    7050 2550
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 5BD75751
P 7050 2850
F 0 "SW2" H 7200 2960 50  0000 C CNN
F 1 "Stop" H 7050 2770 50  0000 C CNN
F 2 "~" H 7050 2850 60  0000 C CNN
F 3 "~" H 7050 2850 60  0000 C CNN
	1    7050 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2550 5950 2550
Wire Wire Line
	5950 2650 6500 2650
Wire Wire Line
	6500 2650 6500 2850
Wire Wire Line
	6500 2850 6750 2850
Wire Wire Line
	7350 2350 7350 3100
Wire Wire Line
	7350 3100 6350 3100
Connection ~ 6350 2950
Connection ~ 7350 2850
Text Label 5950 1750 0    60   ~ 0
BAT
$Comp
L ADAFRUIT_POWERBOOST_500 U3
U 1 1 5BD761A4
P 8100 1650
F 0 "U3" H 8100 1500 60  0000 C CNN
F 1 "ADAFRUIT_POWERBOOST_500" H 8150 1800 60  0000 C CNN
F 2 "~" H 8100 1650 60  0000 C CNN
F 3 "~" H 8100 1650 60  0000 C CNN
	1    8100 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 900  8100 700 
Wire Wire Line
	8100 700  6150 700 
Wire Wire Line
	6150 700  6150 1400
Wire Wire Line
	8000 750  8000 900 
Wire Wire Line
	7200 750  8000 750 
Wire Wire Line
	7800 750  7800 900 
Wire Wire Line
	7500 750  7500 900 
Connection ~ 7800 750 
Wire Wire Line
	7600 900  7600 850 
Wire Wire Line
	7600 850  6500 850 
Wire Wire Line
	6500 850  6500 1750
Wire Wire Line
	6500 1750 5950 1750
Wire Wire Line
	7200 750  7200 2350
Wire Wire Line
	7200 2350 7350 2350
Connection ~ 7350 2550
Connection ~ 7500 750 
$EndSCHEMATC
