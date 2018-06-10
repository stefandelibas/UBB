'''
Created on Mar 27, 2018

@author: Stefan
'''
class Problem:
    def __init__(self):
        self.xmin = 0
        self.xmax = 0
        self.ymin = 0
        self.ymax = 0
        self.dimPopulation = 100
        self.pM=0.01
        
    def getXMin(self):
        return self.xmin
    def getXMax(self):
        return self.xmax
    def getYMin(self):
        return self.ymin
    def getYMax(self):
        return self.ymax
    def getDimPop(self):
        return self.dimPopulation
    def getPM(self):
        return self.pM   
    
    def loadData(self,fileName):
        attrs = []
        f = open(fileName, "r")
        line = f.readline().strip()
        while line != "":
            elem = line.split("=")
            attrs.append(elem[1])     
            line = f.readline().strip()       
        f.close()
        
        self.xmin = int(attrs[0])
        self.xmax = int(attrs[1])
        self.ymin = int(attrs[2])
        self.ymax = int(attrs[3])
        self.dimPopulation = int(attrs[4])
        self.pM = float(attrs[5])
            