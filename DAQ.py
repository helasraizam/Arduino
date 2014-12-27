#!/usr/bin/python2

import matplotlib.pyplot as plt
import pylab
from math import *
import numpy as np
import serial

data=[]

def readSerial():
    ser=serial.Serial('/dev/ttyACM0',9600,timeout=1)
    txt=ser.readline()
    print 'Ignoring data to start at beginning.'
    while txt!='':
        pass
    print 'Paused data.'
    while txt=='':
        pass
    print 'Gathering data.'
    while txt!='':
        data.append(ser.readline().split('\t'))
        print 'Nothing.' if txt=='' else txt
    print 'Done, closing port.'
    ser.close()

readSerial()
print data
