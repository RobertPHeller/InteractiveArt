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
LIBS:mpq3904
LIBS:OnlyHerHairdresser-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "3 nov 2018"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L FEATHER_M0_EXPRESS U1
U 1 1 5BDCB892
P 3150 2600
F 0 "U1" H 3150 2600 60  0000 C CNN
F 1 "FEATHER_M0_EXPRESS" H 3200 2200 50  0000 C CNN
F 2 "~" H 3150 2600 60  0000 C CNN
F 3 "~" H 3150 2600 60  0000 C CNN
	1    3150 2600
	1    0    0    -1  
$EndComp
$Comp
L CONN_7 P1
U 1 1 5BDCB8B2
P 6200 2650
F 0 "P1" V 6170 2650 60  0000 C CNN
F 1 "TCS34725  Breakout" V 6270 2650 60  0000 C CNN
F 2 "~" H 6200 2650 60  0000 C CNN
F 3 "~" H 6200 2650 60  0000 C CNN
	1    6200 2650
	1    0    0    -1  
$EndComp
Text Label 5850 2350 2    60   ~ 0
LED
Text Label 5850 2450 2    60   ~ 0
INT
Text Label 5850 2550 2    60   ~ 0
SDA
Text Label 5850 2650 2    60   ~ 0
SCL
Text Label 5850 2750 2    60   ~ 0
3V3
Text Label 5850 2850 2    60   ~ 0
GND
Text Label 5850 2950 2    60   ~ 0
VIN
Wire Wire Line
	5850 2350 5600 2350
Wire Wire Line
	5600 2350 5600 2450
Wire Wire Line
	5600 2450 5850 2450
Wire Wire Line
	5850 2550 4800 2550
Wire Wire Line
	4800 2550 4800 3050
Wire Wire Line
	4800 3050 3850 3050
Wire Wire Line
	5850 2650 5400 2650
Wire Wire Line
	5400 2650 5400 2950
Wire Wire Line
	5400 2950 3850 2950
Wire Wire Line
	5850 2850 5450 2850
Wire Wire Line
	5450 2850 5450 3250
Wire Wire Line
	5450 3150 3850 3150
Wire Wire Line
	2450 2050 2150 2050
Wire Wire Line
	2150 2050 2150 3550
Wire Wire Line
	2150 3550 5850 3550
Wire Wire Line
	5850 3550 5850 2950
$Comp
L MPQ3904 Q1
U 1 1 5BDCBDEA
P 4350 1400
F 0 "Q1" H 4350 1250 50  0000 R CNN
F 1 "MPQ3904" H 4350 1550 50  0000 R CNN
F 2 "~" H 4350 1400 60  0000 C CNN
F 3 "~" H 4350 1400 60  0000 C CNN
	1    4350 1400
	1    0    0    -1  
$EndComp
$Comp
L MPQ3904 Q1
U 2 1 5BDCBDF9
P 5650 1400
F 0 "Q1" H 5650 1250 50  0000 R CNN
F 1 "MPQ3904" H 5650 1550 50  0000 R CNN
F 2 "~" H 5650 1400 60  0000 C CNN
F 3 "~" H 5650 1400 60  0000 C CNN
	2    5650 1400
	1    0    0    -1  
$EndComp
$Comp
L MPQ3904 Q1
U 3 1 5BDCBE08
P 7050 1400
F 0 "Q1" H 7050 1250 50  0000 R CNN
F 1 "MPQ3904" H 7050 1550 50  0000 R CNN
F 2 "~" H 7050 1400 60  0000 C CNN
F 3 "~" H 7050 1400 60  0000 C CNN
	3    7050 1400
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5BDCBE28
P 6550 1400
F 0 "R5" V 6630 1400 40  0000 C CNN
F 1 "1K Ohms" V 6557 1401 40  0000 C CNN
F 2 "~" V 6480 1400 30  0000 C CNN
F 3 "~" H 6550 1400 30  0000 C CNN
	1    6550 1400
	0    -1   -1   0   
$EndComp
$Comp
L R R3
U 1 1 5BDCBE37
P 5100 1400
F 0 "R3" V 5180 1400 40  0000 C CNN
F 1 "1K Ohms" V 5107 1401 40  0000 C CNN
F 2 "~" V 5030 1400 30  0000 C CNN
F 3 "~" H 5100 1400 30  0000 C CNN
	1    5100 1400
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 5BDCBE8C
P 3800 1400
F 0 "R1" V 3880 1400 40  0000 C CNN
F 1 "1K Ohms" V 3807 1401 40  0000 C CNN
F 2 "~" V 3730 1400 30  0000 C CNN
F 3 "~" H 3800 1400 30  0000 C CNN
	1    3800 1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6850 1400 6800 1400
Wire Wire Line
	6300 1400 6300 1900
Wire Wire Line
	6300 1900 4650 1900
Wire Wire Line
	4650 1900 4650 2850
Wire Wire Line
	4650 2850 3850 2850
Wire Wire Line
	5450 1400 5350 1400
Wire Wire Line
	4850 1400 4550 1400
Wire Wire Line
	4550 1400 4550 2750
Wire Wire Line
	4550 2750 3850 2750
Wire Wire Line
	4150 1400 4050 1400
Wire Wire Line
	3550 1400 3550 1800
Wire Wire Line
	3550 1800 4300 1800
Wire Wire Line
	4300 1800 4300 2550
Wire Wire Line
	4300 2550 3850 2550
Wire Wire Line
	2450 2250 2250 2250
Wire Wire Line
	2250 2250 2250 3500
Wire Wire Line
	2250 3500 4100 3500
Wire Wire Line
	4100 3500 4100 3150
Connection ~ 4100 3150
Wire Wire Line
	4450 1600 7150 1600
Connection ~ 5750 1600
Wire Wire Line
	4450 1600 4450 3150
Connection ~ 4450 3150
$Comp
L R R2
U 1 1 5BDCBFCC
P 4450 900
F 0 "R2" V 4530 900 40  0000 C CNN
F 1 "45 Ohms" V 4457 901 40  0000 C CNN
F 2 "~" V 4380 900 30  0000 C CNN
F 3 "~" H 4450 900 30  0000 C CNN
	1    4450 900 
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5BDCBFDB
P 5750 900
F 0 "R4" V 5830 900 40  0000 C CNN
F 1 "45 Ohms" V 5757 901 40  0000 C CNN
F 2 "~" V 5680 900 30  0000 C CNN
F 3 "~" H 5750 900 30  0000 C CNN
	1    5750 900 
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5BDCBFEA
P 7150 900
F 0 "R6" V 7230 900 40  0000 C CNN
F 1 "45 Ohms" V 7157 901 40  0000 C CNN
F 2 "~" V 7080 900 30  0000 C CNN
F 3 "~" H 7150 900 30  0000 C CNN
	1    7150 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 1150 7150 1200
Wire Wire Line
	5750 1150 5750 1200
Wire Wire Line
	4450 1150 4450 1200
$Comp
L SW_PUSH SW1
U 1 1 5BDCC074
P 4000 1650
F 0 "SW1" H 4150 1760 50  0000 C CNN
F 1 "SW_PUSH" H 4000 1570 50  0000 C CNN
F 2 "~" H 4000 1650 60  0000 C CNN
F 3 "~" H 4000 1650 60  0000 C CNN
	1    4000 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 1650 4450 1650
Connection ~ 4450 1650
Wire Wire Line
	3700 1650 3700 1850
Wire Wire Line
	3700 1850 4200 1850
Wire Wire Line
	4200 1850 4200 2450
Wire Wire Line
	4200 2450 3850 2450
$Comp
L CONN_4 P2
U 1 1 5BDCEE1A
P 6350 600
F 0 "P2" V 6300 600 50  0000 C CNN
F 1 "RGB LEDS" V 6400 600 50  0000 C CNN
F 2 "~" H 6350 600 60  0000 C CNN
F 3 "~" H 6350 600 60  0000 C CNN
	1    6350 600 
	0    -1   -1   0   
$EndComp
Text Label 6200 950  2    60   ~ 0
R
Text Label 6300 950  2    60   ~ 0
G
Text Label 6400 950  2    60   ~ 0
B
Text Label 6500 950  0    60   ~ 0
Comm
Wire Wire Line
	5750 650  6050 650 
Wire Wire Line
	6050 650  6050 1150
Wire Wire Line
	6050 1150 6300 1150
Wire Wire Line
	7150 650  6900 650 
Wire Wire Line
	6900 650  6900 1150
Wire Wire Line
	6900 1150 6400 1150
Wire Wire Line
	6400 1150 6400 950 
Wire Wire Line
	6300 1150 6300 950 
Wire Wire Line
	4450 650  4450 550 
Wire Wire Line
	4450 550  6100 550 
Wire Wire Line
	6100 550  6100 1100
Wire Wire Line
	6100 1100 6200 1100
Wire Wire Line
	6200 1100 6200 950 
Text Label 3850 1950 0    60   ~ 0
Comm
$Comp
L CONN_1 P4
U 1 1 5BDCF445
P 6100 3350
F 0 "P4" H 6180 3350 40  0000 L CNN
F 1 "CONN_1" H 6100 3405 30  0001 C CNN
F 2 "~" H 6100 3350 60  0000 C CNN
F 3 "~" H 6100 3350 60  0000 C CNN
	1    6100 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3350 5850 3350
Connection ~ 5850 3350
$Comp
L CONN_1 P3
U 1 1 5BDCF493
P 5600 3250
F 0 "P3" H 5680 3250 40  0000 L CNN
F 1 "CONN_1" H 5600 3305 30  0001 C CNN
F 2 "~" H 5600 3250 60  0000 C CNN
F 3 "~" H 5600 3250 60  0000 C CNN
	1    5600 3250
	1    0    0    -1  
$EndComp
Connection ~ 5450 3150
$Comp
L CONN_1 P5
U 1 1 5BDCF4E2
P 6750 650
F 0 "P5" H 6830 650 40  0000 L CNN
F 1 "CONN_1" H 6750 705 30  0001 C CNN
F 2 "~" H 6750 650 60  0000 C CNN
F 3 "~" H 6750 650 60  0000 C CNN
	1    6750 650 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6750 800  6750 1050
Wire Wire Line
	6750 1050 6500 1050
Wire Wire Line
	6500 1050 6500 950 
$EndSCHEMATC
