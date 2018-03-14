#!/usr/bin/python
import log

Log = log.logging('/home/user_00/test/', 'ha')
index = 1
while True:
    Log.DEBUG(str(index)+':This is a debug message')
    Log.INFO(str(index)+':This is a info message')
    Log.ERROR(str(index)+':This is a error message')
    Log.FATAL(str(index)+':This is a fatal message')
    index = index +1
