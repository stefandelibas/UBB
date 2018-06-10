'''
Created on Mar 17, 2018

@author: Stefan-PC
'''
from State import State
from copy import deepcopy
import math

class Problem:
    def __init__(self):
        self.state = State()
        self.n = self.state.getSize()
        self.initialState = self.state.getInitalState()
        
    def getInitialState(self):
        return self.initialState
    
    def fillConfig(self,state,config):
        crt = 0
        for i in range(self.n):
            for j in range(self.n):
                if state[i][j] == 0:
                    state[i][j] = config[crt]
                    crt += 1 
         
    def getRoot(self):
        occ = {}
        for i in range(1,self.n + 1):
            occ[i] = self.n
        needed = []
        for i in range(self.n):
            for j in range(self.n):
                if self.initialState[i][j] != 0:
                    occ[self.initialState[i][j]] -= 1
        for x in occ.keys():
            while(occ[x]>0):
                needed.append(x)
                occ[x] -= 1
        return needed  
         
    def expand(self,config):
        config_list = []
        first = config[0]
        for i in range(len(config)):
            newConfig = deepcopy(config[1:])
            newConfig.insert(i,first)
            config_list.append(newConfig)                  
        return config_list    
    
    def checkBoard(self,config):
        required = (self.n * (self.n + 1))/2
        crtState = deepcopy(self.initialState)
        self.fillConfig(crtState,config)

        #check if the sum on each row is correct
        for row in crtState:
            if sum(row) != required:
                return False
        
        #check if the sum on each column is correct
        for i in range(self.n):
            s = 0
            for j in range(self.n):
                s += crtState[j][i]
            if s != required:
                return False
        
        #check if the sum of each sqare is correct
        sq = int(math.sqrt(self.n))
        for i in range(0,self.n,sq):
            for j in range(0,self.n,sq):
                s = 0
                for q in range(i,i+sq):
                    for p in range(j,j+sq):
                        s += crtState[q][p]
                if s != required:
                    return False
             
        return True
                   
    def conflicts(self,state):
        required = (self.n * (self.n + 1))/2
        crtState = deepcopy(self.initialState)
        self.fillConfig(crtState,state)
        conflicts = 0
        
        for row in crtState:
            if sum(row) != required:
                conflicts += 1
        
        for i in range(self.n):
            s = 0
            for j in range(self.n):
                s += crtState[j][i]
            if s != required:
                conflicts += 1

        sq = int(math.sqrt(self.n))
        for i in range(0,self.n,sq):
            for j in range(0,self.n,sq):
                s = 0
                for q in range(i,i+sq):
                    for p in range(j,j+sq):
                        s += crtState[q][p]
                if s != required:
                    conflicts += 1
        return conflicts
    
    def cmp_to_key(self,mycmp):
        'Convert a cmp= function into a key= function'
        class K(object):
            def __init__(self, obj, *args):
                self.obj = obj
            def __lt__(self, other):
                return mycmp(self.obj, other.obj) < 0
            def __gt__(self, other):
                return mycmp(self.obj, other.obj) > 0
            def __eq__(self, other):
                return mycmp(self.obj, other.obj) == 0
            def __le__(self, other):
                return mycmp(self.obj, other.obj) <= 0
            def __ge__(self, other):
                return mycmp(self.obj, other.obj) >= 0
            def __ne__(self, other):
                return mycmp(self.obj, other.obj) != 0
        return K
    def heuristics(self, state1, state2):
        c1 = self.conflicts(state1)
        c2 = self.conflicts(state2)
        return c2-c1