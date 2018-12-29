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
LIBS:feather_m0_express
LIBS:StrayCats-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "27 dec 2018"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L FEATHER_M0_EXPRESS U1
U 1 1 5C254051
P 2900 2950
F 0 "U1" H 2900 2950 60  0000 C CNN
F 1 "FEATHER_M0_EXPRESS" H 2950 2550 50  0000 C CNN
F 2 "~" H 2900 2950 60  0000 C CNN
F 3 "~" H 2900 2950 60  0000 C CNN
	1    2900 2950
	1    0    0    -1  
$EndComp
$Comp
L CONN_10 P1
U 1 1 5C25411C
P 5300 2800
F 0 "P1" V 5250 2800 60  0000 C CNN
F 1 "1.8 Inch TFT w/card" V 5350 2800 60  0000 C CNN
F 2 "~" H 5300 2800 60  0000 C CNN
F 3 "~" H 5300 2800 60  0000 C CNN
	1    5300 2800
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 P2
U 1 1 5C254310
P 5300 3900
F 0 "P2" V 5250 3900 50  0000 C CNN
F 1 "IR Sensor" V 5350 3900 40  0000 C CNN
F 2 "~" H 5300 3900 60  0000 C CNN
F 3 "~" H 5300 3900 60  0000 C CNN
	1    5300 3900
	1    0    0    -1  
$EndComp
Text Label 4950 2350 2    60   ~ 0
Lite
Text Label 4950 2450 2    60   ~ 0
MISO
Text Label 4950 2550 2    60   ~ 0
SCK
Text Label 4950 2650 2    60   ~ 0
MOSI
Text Label 4950 2750 2    60   ~ 0
TFT_CS
Text Label 4950 2850 2    60   ~ 0
CARD_CS
Text Label 4950 2950 2    60   ~ 0
TFT_DC
Text Label 4950 3050 2    60   ~ 0
TFT_RST
Text Label 4950 3150 2    60   ~ 0
VCC
Text Label 4950 3250 2    60   ~ 0
GND
Text Label 4950 3800 2    60   ~ 0
OUT
Text Label 4950 3900 2    60   ~ 0
GND
Text Label 4950 4000 2    60   ~ 0
VCC
Text Label 2200 3300 2    30   ~ 0
SCK
Text Label 2200 3400 2    30   ~ 0
MOSI
Text Label 2200 3500 2    30   ~ 0
MISO
Text Label 3600 2900 0    30   ~ 0
TFT_CS
Text Label 3600 3000 0    30   ~ 0
TFT_RST
Text Label 3600 3100 0    30   ~ 0
TFT_DC
Text Label 3600 3200 0    30   ~ 0
Lite
Text Label 2200 2400 2    30   ~ 0
VCC
Text Label 2200 2600 2    30   ~ 0
GND
Text Label 3600 2800 0    30   ~ 0
CARD_CS
Text Label 3600 2700 0    30   ~ 0
OUT
$Comp
L CONN_1 P3
U 1 1 5C2560B8
P 2050 2400
F 0 "P3" H 2130 2400 40  0000 L CNN
F 1 "CONN_1" H 2050 2455 30  0001 C CNN
F 2 "~" H 2050 2400 60  0000 C CNN
F 3 "~" H 2050 2400 60  0000 C CNN
	1    2050 2400
	-1   0    0    1   
$EndComp
$Comp
L CONN_1 P4
U 1 1 5C2560C7
P 2050 2600
F 0 "P4" H 2130 2600 40  0000 L CNN
F 1 "CONN_1" H 2050 2655 30  0001 C CNN
F 2 "~" H 2050 2600 60  0000 C CNN
F 3 "~" H 2050 2600 60  0000 C CNN
	1    2050 2600
	-1   0    0    1   
$EndComp
$EndSCHEMATC
