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
LIBS:AndroidsDream-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "11 nov 2018"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ITSYBITSY U1
U 1 1 5BDF3C2F
P 3550 3350
F 0 "U1" H 3550 3650 60  0000 C CNN
F 1 "ITSYBITSY" H 3500 2950 60  0000 C CNN
F 2 "" H 3550 3350 60  0000 C CNN
F 3 "" H 3550 3350 60  0000 C CNN
	1    3550 3350
	0    1    1    0   
$EndComp
Text Label 2800 2450 2    60   ~ 0
Servo+
$Comp
L GND #PWR01
U 1 1 5BDF3C40
P 3400 5350
F 0 "#PWR01" H 3400 5350 30  0001 C CNN
F 1 "GND" H 3400 5280 30  0001 C CNN
F 2 "" H 3400 5350 60  0000 C CNN
F 3 "" H 3400 5350 60  0000 C CNN
	1    3400 5350
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 P4
U 1 1 5BDF3C68
P 6050 2450
F 0 "P4" V 6000 2450 50  0000 C CNN
F 1 "Servo 1" V 6100 2450 40  0000 C CNN
F 2 "~" H 6050 2450 60  0000 C CNN
F 3 "~" H 6050 2450 60  0000 C CNN
	1    6050 2450
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 P5
U 1 1 5BDF3C77
P 6050 3000
F 0 "P5" V 6000 3000 50  0000 C CNN
F 1 "Servo 2" V 6100 3000 40  0000 C CNN
F 2 "~" H 6050 3000 60  0000 C CNN
F 3 "~" H 6050 3000 60  0000 C CNN
	1    6050 3000
	1    0    0    -1  
$EndComp
Text Label 5550 2150 0    60   ~ 0
Servo+
$Comp
L GND #PWR02
U 1 1 5BDF3D1D
P 5500 3250
F 0 "#PWR02" H 5500 3250 30  0001 C CNN
F 1 "GND" H 5500 3180 30  0001 C CNN
F 2 "" H 5500 3250 60  0000 C CNN
F 3 "" H 5500 3250 60  0000 C CNN
	1    5500 3250
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P2
U 1 1 5BDF3D5C
P 1300 2700
F 0 "P2" V 1250 2700 40  0000 C CNN
F 1 "LDR2" V 1350 2700 40  0000 C CNN
F 2 "~" H 1300 2700 60  0000 C CNN
F 3 "~" H 1300 2700 60  0000 C CNN
	1    1300 2700
	-1   0    0    -1  
$EndComp
$Comp
L CONN_2 P3
U 1 1 5BDF3D6B
P 1300 3200
F 0 "P3" V 1250 3200 40  0000 C CNN
F 1 "LDR3" V 1350 3200 40  0000 C CNN
F 2 "~" H 1300 3200 60  0000 C CNN
F 3 "~" H 1300 3200 60  0000 C CNN
	1    1300 3200
	-1   0    0    -1  
$EndComp
$Comp
L CONN_2 P1
U 1 1 5BDF3D7A
P 1300 2150
F 0 "P1" V 1250 2150 40  0000 C CNN
F 1 "LDR1" V 1350 2150 40  0000 C CNN
F 2 "~" H 1300 2150 60  0000 C CNN
F 3 "~" H 1300 2150 60  0000 C CNN
	1    1300 2150
	-1   0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5BDF3DE5
P 1800 3550
F 0 "R1" V 1880 3550 40  0000 C CNN
F 1 "1K Ohms" V 1807 3551 40  0000 C CNN
F 2 "~" V 1730 3550 30  0000 C CNN
F 3 "~" H 1800 3550 30  0000 C CNN
	1    1800 3550
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5BDF3DF4
P 2400 3250
F 0 "R3" V 2480 3250 40  0000 C CNN
F 1 "1K Ohms" V 2407 3251 40  0000 C CNN
F 2 "~" V 2330 3250 30  0000 C CNN
F 3 "~" H 2400 3250 30  0000 C CNN
	1    2400 3250
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 5BDF3E03
P 2000 2500
F 0 "R2" V 2080 2500 40  0000 C CNN
F 1 "1K Ohms" V 2007 2501 40  0000 C CNN
F 2 "~" V 1930 2500 30  0000 C CNN
F 3 "~" H 2000 2500 30  0000 C CNN
	1    2000 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 2150 2300 2150
Wire Wire Line
	2300 2050 2300 2300
Wire Wire Line
	2300 2300 2800 2300
Wire Wire Line
	2800 3950 2300 3950
Wire Wire Line
	2300 3950 2300 5250
Wire Wire Line
	2300 4150 2800 4150
Wire Wire Line
	2300 5250 5000 5250
Wire Wire Line
	3400 5250 3400 5350
Connection ~ 2300 4150
Wire Wire Line
	4250 1950 5000 1950
Wire Wire Line
	5000 1950 5000 5250
Connection ~ 3400 5250
Wire Wire Line
	4250 2850 5250 2850
Wire Wire Line
	5250 2850 5250 3000
Wire Wire Line
	5250 3000 5700 3000
Wire Wire Line
	4250 2700 5350 2700
Wire Wire Line
	5350 2700 5350 2450
Wire Wire Line
	5350 2450 5700 2450
Wire Wire Line
	5550 2150 5550 2900
Wire Wire Line
	5550 2350 5700 2350
Wire Wire Line
	5550 2900 5700 2900
Connection ~ 5550 2350
Wire Wire Line
	5700 2550 5500 2550
Wire Wire Line
	5500 2550 5500 3250
Wire Wire Line
	5700 3100 5500 3100
Connection ~ 5500 3100
Wire Wire Line
	1800 3800 1800 4300
Wire Wire Line
	1800 4300 2300 4300
Connection ~ 2300 4300
Wire Wire Line
	2000 2750 2000 4300
Connection ~ 2000 4300
Wire Wire Line
	1650 3300 1850 3300
Wire Wire Line
	2650 3250 2650 3950
Connection ~ 2650 3950
Wire Wire Line
	1650 2800 2500 2800
Connection ~ 2150 3250
Wire Wire Line
	2150 2800 2150 3250
Wire Wire Line
	1650 2250 2350 2250
Wire Wire Line
	2300 2050 1650 2050
Connection ~ 2300 2150
Wire Wire Line
	1650 2600 1800 2600
Wire Wire Line
	1800 2050 1800 3100
Connection ~ 1800 2050
Wire Wire Line
	1800 3100 1650 3100
Connection ~ 1800 2600
Wire Wire Line
	2350 2250 2350 2600
Wire Wire Line
	2350 2600 2800 2600
Connection ~ 2000 2250
Wire Wire Line
	2500 2800 2500 2750
Wire Wire Line
	2500 2750 2800 2750
Connection ~ 2150 2800
Wire Wire Line
	2800 2900 2450 2900
Wire Wire Line
	2450 2900 2450 3100
Wire Wire Line
	2450 3100 1850 3100
Wire Wire Line
	1850 3100 1850 3300
Connection ~ 1800 3300
Text Notes 6200 2350 0    60   ~ 0
Head Servo\ncontrols head movement
Text Notes 6200 2950 0    60   ~ 0
Tail Servo\ncontrols tail movement
Text Notes 550  2100 0    60   ~ 0
Head LDR\nSenses Head \nPetting
Text Notes 550  2600 0    60   ~ 0
Back LDR\nHelps to \ndetect \nnighttime
Text Notes 550  3150 0    60   ~ 0
Tail LDR\nSenses Tail\nPetting
$EndSCHEMATC
