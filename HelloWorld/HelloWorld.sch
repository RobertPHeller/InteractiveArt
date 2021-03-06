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
LIBS:HelloWorld-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "24 oct 2018"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L FEATHER_M0_EXPRESS U1
U 1 1 5BCDD2C0
P 3100 2650
F 0 "U1" H 3100 2650 60  0000 C CNN
F 1 "FEATHER_M0_EXPRESS" H 3150 2250 50  0000 C CNN
F 2 "~" H 3100 2650 60  0000 C CNN
F 3 "~" H 3100 2650 60  0000 C CNN
	1    3100 2650
	1    0    0    -1  
$EndComp
$Comp
L MPR121_BREAKOUT U2
U 1 1 5BCDD354
P 6150 2650
F 0 "U2" H 6150 2400 60  0000 C CNN
F 1 "MPR121_BREAKOUT" H 6150 3050 60  0000 C CNN
F 2 "~" H 6150 2650 60  0000 C CNN
F 3 "~" H 6150 2650 60  0000 C CNN
	1    6150 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3000 5500 3000
Wire Wire Line
	5500 3000 5500 2850
Wire Wire Line
	5500 2850 5800 2850
Wire Wire Line
	3800 3100 4600 3100
Wire Wire Line
	4600 3100 4600 2750
Wire Wire Line
	4600 2750 5800 2750
$Comp
L GND #PWR01
U 1 1 5BCDD3EF
P 4000 3350
F 0 "#PWR01" H 4000 3350 30  0001 C CNN
F 1 "GND" H 4000 3280 30  0001 C CNN
F 2 "" H 4000 3350 60  0000 C CNN
F 3 "" H 4000 3350 60  0000 C CNN
	1    4000 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5BCDD3FE
P 5400 2650
F 0 "#PWR02" H 5400 2650 30  0001 C CNN
F 1 "GND" H 5400 2580 30  0001 C CNN
F 2 "" H 5400 2650 60  0000 C CNN
F 3 "" H 5400 2650 60  0000 C CNN
	1    5400 2650
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR03
U 1 1 5BCDD415
P 2150 1850
F 0 "#PWR03" H 2150 1810 30  0001 C CNN
F 1 "+3.3V" H 2150 1960 30  0000 C CNN
F 2 "" H 2150 1850 60  0000 C CNN
F 3 "" H 2150 1850 60  0000 C CNN
	1    2150 1850
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR04
U 1 1 5BCDD424
P 5500 2200
F 0 "#PWR04" H 5500 2160 30  0001 C CNN
F 1 "+3.3V" H 5500 2310 30  0000 C CNN
F 2 "" H 5500 2200 60  0000 C CNN
F 3 "" H 5500 2200 60  0000 C CNN
	1    5500 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2200 5500 2350
Wire Wire Line
	5500 2350 5800 2350
Wire Wire Line
	5400 2650 5400 2550
Wire Wire Line
	5400 2550 5800 2550
Wire Wire Line
	5800 2550 5800 2650
Wire Wire Line
	2400 2100 2150 2100
Wire Wire Line
	2150 2100 2150 1850
Wire Wire Line
	3800 3200 4000 3200
Wire Wire Line
	4000 3200 4000 3350
$Comp
L GND #PWR05
U 1 1 5BCDD47B
P 2100 2350
F 0 "#PWR05" H 2100 2350 30  0001 C CNN
F 1 "GND" H 2100 2280 30  0001 C CNN
F 2 "" H 2100 2350 60  0000 C CNN
F 3 "" H 2100 2350 60  0000 C CNN
	1    2100 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 2300 2100 2300
Wire Wire Line
	2100 2300 2100 2350
Wire Wire Line
	5650 2550 5650 3150
Wire Wire Line
	5650 3150 6500 3150
Wire Wire Line
	6500 3150 6500 2950
Connection ~ 5650 2550
$Comp
L CONN_12 T1
U 1 1 5BCDD4B2
P 7450 2650
F 0 "T1" V 7400 2650 60  0000 C CNN
F 1 "us mx br it de ru na ir cn fr jp in" V 7500 2650 60  0000 C CNN
F 2 "~" H 7450 2650 60  0000 C CNN
F 3 "~" H 7450 2650 60  0000 C CNN
	1    7450 2650
	1    0    0    1   
$EndComp
Wire Wire Line
	6500 2350 6600 2350
Wire Wire Line
	6600 2350 6600 2100
Wire Wire Line
	6600 2100 7100 2100
Wire Wire Line
	6500 2400 6650 2400
Wire Wire Line
	6650 2400 6650 2200
Wire Wire Line
	6650 2200 7100 2200
Wire Wire Line
	6500 2450 6700 2450
Wire Wire Line
	6700 2450 6700 2300
Wire Wire Line
	6700 2300 7100 2300
Wire Wire Line
	6500 2500 6800 2500
Wire Wire Line
	6800 2500 6800 2400
Wire Wire Line
	6800 2400 7100 2400
Wire Wire Line
	7100 2500 6850 2500
Wire Wire Line
	6850 2500 6850 2550
Wire Wire Line
	6850 2550 6500 2550
Wire Wire Line
	6500 2600 7100 2600
Wire Wire Line
	6500 2650 7000 2650
Wire Wire Line
	7000 2650 7000 2700
Wire Wire Line
	7000 2700 7100 2700
Wire Wire Line
	6500 2700 6900 2700
Wire Wire Line
	6900 2700 6900 2800
Wire Wire Line
	6900 2800 7100 2800
Wire Wire Line
	6500 2750 6850 2750
Wire Wire Line
	6850 2750 6850 2900
Wire Wire Line
	6850 2900 7100 2900
Wire Wire Line
	6500 2800 6800 2800
Wire Wire Line
	6800 2800 6800 3000
Wire Wire Line
	6800 3000 7100 3000
Wire Wire Line
	6500 2850 6750 2850
Wire Wire Line
	6750 2850 6750 3100
Wire Wire Line
	6750 3100 7100 3100
Wire Wire Line
	6500 2900 6700 2900
Wire Wire Line
	6700 2900 6700 3200
Wire Wire Line
	6700 3200 7100 3200
$Comp
L CONN_8 P1
U 1 1 5BCDD718
P 1200 2900
F 0 "P1" V 1150 2900 60  0000 C CNN
F 1 "Nokia 5110/3310 Monochrome LCD" V 1250 2900 60  0000 C CNN
F 2 "~" H 1200 2900 60  0000 C CNN
F 3 "~" H 1200 2900 60  0000 C CNN
	1    1200 2900
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 5BCDD73A
P 1650 2550
F 0 "#PWR06" H 1650 2550 30  0001 C CNN
F 1 "GND" H 1650 2480 30  0001 C CNN
F 2 "" H 1650 2550 60  0000 C CNN
F 3 "" H 1650 2550 60  0000 C CNN
	1    1650 2550
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR07
U 1 1 5BCDD749
P 2000 2600
F 0 "#PWR07" H 2000 2560 30  0001 C CNN
F 1 "+3.3V" H 2000 2710 30  0000 C CNN
F 2 "" H 2000 2600 60  0000 C CNN
F 3 "" H 2000 2600 60  0000 C CNN
	1    2000 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 2550 1650 2550
Wire Wire Line
	1550 2750 1900 2750
Wire Wire Line
	1900 2750 1900 3000
Wire Wire Line
	1900 3000 2400 3000
Wire Wire Line
	1550 2850 1850 2850
Wire Wire Line
	1850 2850 1850 3100
Wire Wire Line
	1850 3100 2400 3100
Wire Wire Line
	1550 3250 1550 3900
Wire Wire Line
	1550 3900 4250 3900
Wire Wire Line
	4250 3900 4250 2900
Wire Wire Line
	4250 2900 3800 2900
Wire Wire Line
	1550 3150 1650 3150
Wire Wire Line
	1650 3150 1650 3800
Wire Wire Line
	1650 3800 4200 3800
Wire Wire Line
	4200 3800 4200 2800
Wire Wire Line
	4200 2800 3800 2800
Wire Wire Line
	1550 3050 1700 3050
Wire Wire Line
	1700 3050 1700 3700
Wire Wire Line
	1700 3700 4150 3700
Wire Wire Line
	4150 3700 4150 2600
Wire Wire Line
	1550 2950 1750 2950
Wire Wire Line
	1750 2950 1750 3600
Wire Wire Line
	1750 3600 4100 3600
Wire Wire Line
	4100 3600 4100 2500
Wire Wire Line
	4100 2500 3800 2500
Wire Wire Line
	4150 2600 3800 2600
Text Label 1550 3750 2    60   ~ 0
LED
Text Label 2200 3800 0    60   ~ 0
RST
Text Label 1850 3700 0    60   ~ 0
CS
Text Label 1750 3300 0    60   ~ 0
D_C
Text Label 2000 3100 0    60   ~ 0
DIN
Text Label 2000 3000 0    60   ~ 0
CLK
Text Label 2000 2650 0    60   ~ 0
VCC
Text Label 1600 2550 0    60   ~ 0
GND
$Comp
L CONN_1 P2
U 1 1 5BCDE79F
P 6500 1750
F 0 "P2" H 6580 1750 40  0000 L CNN
F 1 "CONN_1" H 6500 1805 10  0001 C CNN
F 2 "~" H 6500 1750 60  0000 C CNN
F 3 "~" H 6500 1750 60  0000 C CNN
	1    6500 1750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5BCDE7D2
P 6250 1750
F 0 "#PWR08" H 6250 1750 30  0001 C CNN
F 1 "GND" H 6250 1680 30  0001 C CNN
F 2 "" H 6250 1750 60  0000 C CNN
F 3 "" H 6250 1750 60  0000 C CNN
	1    6250 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	6350 1750 6250 1750
$Comp
L CONN_1 P3
U 1 1 5BCDE843
P 7500 1600
F 0 "P3" H 7580 1600 40  0000 L CNN
F 1 "CONN_1" H 7500 1655 30  0001 C CNN
F 2 "~" H 7500 1600 60  0000 C CNN
F 3 "~" H 7500 1600 60  0000 C CNN
	1    7500 1600
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR09
U 1 1 5BCDE852
P 7200 1600
F 0 "#PWR09" H 7200 1560 30  0001 C CNN
F 1 "+3.3V" H 7200 1710 30  0000 C CNN
F 2 "" H 7200 1600 60  0000 C CNN
F 3 "" H 7200 1600 60  0000 C CNN
	1    7200 1600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7350 1600 7200 1600
Wire Wire Line
	1550 2650 2000 2650
Wire Wire Line
	2000 2650 2000 2600
$EndSCHEMATC
