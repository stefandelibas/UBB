'''
Created on Mar 17, 2018

@author: Stefan-PC
'''
class State:
    def __init__(self):
        """
        n2= [[3,0,0,2],
             [0,1,4,0],
             [1,2,0,4],
             [0,3,2,1]]
        n3 = [[0,7,5,0,9,0,0,0,6],
              [0,2,3,0,8,0,0,4,0],
              [8,0,0,0,0,3,0,0,1],
              [5,0,0,7,0,2,0,0,0],
              [0,4,0,8,0,6,0,2,0],
              [0,0,0,9,0,1,0,0,3],
              [9,0,0,4,0,0,0,0,7],
              [0,6,0,0,7,0,5,8,0],
              [7,0,0,0,1,0,3,9,0]]
              """
        self.initialState = self.loadFromFile()
        
    def getInitalState(self):   
        return self.initialState
    
    def getSize(self):
        return len(self.initialState)
    
    def loadFromFile(self):
        f = open("in.txt","r")
        line = f.readline().strip()
        matr = []
        while line != "":
            attrs = line.split(" ")
            l = []
            for x in attrs:
                l.append(int(x))
            matr.append(l)
            line = f.readline().strip()
        f.close()
        return matr
        