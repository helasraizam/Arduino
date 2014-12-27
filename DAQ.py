#!/usr/bin/python2

import matplotlib.pyplot as plt
import pylab,serial,csv
from math import *
import numpy as np

data=[]

def readSerial():
    ser=serial.Serial('/dev/ttyACM0',9600,timeout=1)
    txt=ser.readline()
    print 'Ignoring data to start at beginning.'
    while txt!='':
        txt=ser.readline()
        pass
    print 'Paused data.'
    while txt=='':
        txt=ser.readline()
        pass
    print 'Gathering data.'
    while txt!='':
        txt=ser.readline()
        data.append([float(s) for s in txt.replace('\r\n','').split('\t')])
        #print 'Nothing.' if txt=='' else txt
    print 'Done, closing port.'
    ser.close()

readSerial()
csv.writer(open('data.csv','wb'))
