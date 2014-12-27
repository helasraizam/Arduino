#!/usr/bin/python2

import matplotlib.pyplot as plt
import pylab
from math import *
import numpy as np
import serial

def readSerial():
    ser=serial.Serial('/dev/ttyACM0',9600,timeout=1)
    print ser.name
    txt=ser.readline()
    print txt
    ser.close()

readSerial()
