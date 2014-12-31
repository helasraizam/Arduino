#!/usr/bin/python2

import matplotlib.pyplot as plt
import pylab,serial,csv
from math import *
import numpy as np

data=[]

with open('time_resolved.csv','wb') as f:
    c=csv.writer(f)
    ser=serial.Serial('/dev/ttyACM0',9600,timeout=1)
    txt=ser.readline()

    print 'Sending start code.'
    serial.write('start.')

    while ser.readline()!='done.':
        c.writerow([float(s) for s in txt.replace('\r\n','').split('\t')])
        txt=ser.readline()

    print 'Got end code.  Data output to time_resolved.csv.'
    

with open('data.csv','wb') as f:
    c=csv.writer(f)
    ser=serial.Serial('/dev/ttyACM0',9600,timeout=1)
    txt=ser.readline()
    
    print 'Ignoring data to start at beginning.'
    while txt!='':
        txt=ser.readline()

    print 'Paused data.'
    while txt=='':
        txt=ser.readline()

    print 'Gathering data.'
    while txt!='':
        c.writerow([float(s) for s in txt.replace('\r\n','').split('\t')])
        txt=ser.readline()
        
    print 'Done, closing port.'
    ser.close()
