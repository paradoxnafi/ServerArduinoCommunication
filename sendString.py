#!/usr/bin/env python3
import serial

usbCon = serial.Serial('/dev/ttyACM0', 9600)

while True:

#	x = input()
#	x = x.encode()
#	usbCon.write(x)

	string = input() + '\n'

	usbCon.write(string.encode("utf-8"))