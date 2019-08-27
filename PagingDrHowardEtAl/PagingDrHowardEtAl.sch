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
LIBS:metromini
LIBS:itsybitsy
LIBS:PagingDrHowardEtAl-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "27 aug 2019"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_3 P1
U 1 1 5BE04B98
P 2050 3100
F 0 "P1" V 2000 3100 50  0000 C CNN
F 1 "Pulse Playground" V 2100 3100 40  0000 C CNN
F 2 "~" H 2050 3100 60  0000 C CNN
F 3 "~" H 2050 3100 60  0000 C CNN
	1    2050 3100
	-1   0    0    -1  
$EndComp
$Comp
L CONN_4 P3
U 1 1 5BE04C5D
P 5300 3700
F 0 "P3" V 5250 3700 50  0000 C CNN
F 1 "Bargraph Backpack" V 5350 3700 50  0000 C CNN
F 2 "~" H 5300 3700 60  0000 C CNN
F 3 "~" H 5300 3700 60  0000 C CNN
	1    5300 3700
	1    0    0    -1  
$EndComp
$Comp
L CONN_5 P2
U 1 1 5BE05043
P 5300 2450
F 0 "P2" V 5250 2450 50  0000 C CNN
F 1 "7 segment backpack" V 5350 2450 50  0000 C CNN
F 2 "~" H 5300 2450 60  0000 C CNN
F 3 "~" H 5300 2450 60  0000 C CNN
	1    5300 2450
	1    0    0    -1  
$EndComp
Text Label 4900 2250 2    60   ~ 0
D
Text Label 4900 2350 2    60   ~ 0
C
Text Label 4900 2450 2    60   ~ 0
+
Text Label 4900 2550 2    60   ~ 0
-
Text Label 4900 2650 2    60   ~ 0
IO
Text Label 4950 3550 2    60   ~ 0
SCL
Text Label 4950 3650 2    60   ~ 0
SDA
Text Label 4950 3750 2    60   ~ 0
G
Text Label 4950 3850 2    60   ~ 0
Vcc
Text Label 2400 3000 0    60   ~ 0
Vdd
Text Label 2400 3100 0    60   ~ 0
Pulse
Text Label 2400 3200 0    60   ~ 0
GND
$Comp
L ITSYBITSY U1
U 1 1 5BE053A3
P 3700 2600
F 0 "U1" H 3700 2900 60  0000 C CNN
F 1 "ITSYBITSY" H 3650 2200 60  0000 C CNN
F 2 "~" H 3700 2600 60  0000 C CNN
F 3 "~" H 3700 2600 60  0000 C CNN
	1    3700 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 3000 2600 3000
Wire Wire Line
	2600 1400 2600 4500
Wire Wire Line
	2400 3200 2500 3200
Wire Wire Line
	2500 3200 2500 650 
Wire Wire Line
	2500 650  4650 650 
Wire Wire Line
	4650 650  4650 1200
Wire Wire Line
	4650 1200 4400 1200
Wire Wire Line
	2400 3100 2700 3100
Wire Wire Line
	2700 3100 2700 1850
Wire Wire Line
	2700 1850 2950 1850
Wire Wire Line
	4900 2250 4650 2250
Wire Wire Line
	4650 2250 4650 3650
Wire Wire Line
	4650 2700 4400 2700
Wire Wire Line
	4650 3650 4950 3650
Connection ~ 4650 2700
Wire Wire Line
	4900 2350 4750 2350
Wire Wire Line
	4750 2350 4750 3550
Wire Wire Line
	4750 2550 4400 2550
Wire Wire Line
	4750 3550 4950 3550
Connection ~ 4750 2550
Wire Wire Line
	4950 3750 4550 3750
Wire Wire Line
	4550 3750 4550 1200
Connection ~ 4550 1200
Wire Wire Line
	4900 2550 4800 2550
Wire Wire Line
	4800 2550 4800 2850
Wire Wire Line
	4800 2850 4550 2850
Connection ~ 4550 2850
Wire Wire Line
	4900 2650 4900 3500
Wire Wire Line
	4900 3500 4350 3500
Wire Wire Line
	4350 3500 4350 4500
Wire Wire Line
	4350 4500 2600 4500
Connection ~ 2600 3000
Wire Wire Line
	4950 3850 4350 3850
Connection ~ 4350 3850
Wire Wire Line
	4900 2450 4700 2450
Wire Wire Line
	4700 2450 4700 750 
Wire Wire Line
	4700 750  2800 750 
Wire Wire Line
	2800 750  2800 1700
Text Notes 1600 3050 0    60   ~ 0
Pulse\nSensor
Text Notes 5450 2400 0    60   ~ 0
Beats per Minute\nDisplay
Text Notes 5450 3700 0    60   ~ 0
Graphical Pulse\nDisplay
Wire Wire Line
	2800 1700 2950 1700
Wire Wire Line
	2600 1400 2950 1400
$EndSCHEMATC
