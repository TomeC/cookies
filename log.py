#!/usr/bin/py
import fcntl, datetime

class logging(object):
    def __init__(self, path, pre):
        self.path = path
        self.pre = pre
        self.date = datetime.datetime.now().strftime('%Y%m%d')
        self.hand = open(path+"/"+pre+"-"+self.date+".log", 'a+')

    def write(self, level, msg):
        now = datetime.datetime.now().strftime('%Y%m%d')
        if now != self.date:
            self.hand.close()
            self.date = datetime.datetime.now().strftime('%Y%m%d')
            self.hand = open(self.path+"/"+self.pre+"-"+self.date+".log", 'a+')
        fcntl.flock(self.hand, fcntl.LOCK_EX)
        self.hand.write(str(datetime.datetime.now())+"["+level+"]:"+msg+'\n')
        self.hand.flush()
        fcntl.flock(self.hand, fcntl.LOCK_UN)
    
    def DEBUG(self, msg):
        self.write("DEBUG", msg)
    def INFO(self, msg):
        self.write("INFO", msg)
    def ERROR(self, msg):
        self.write("ERROR", msg)
    def FATAL(self, msg):
        self.write("FATAL", msg)

    def __del__(self):
        self.hand.close()
