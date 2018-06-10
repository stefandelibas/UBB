'''
Created on Mar 27, 2018

@author: Stefan
'''
from random import randint,random
from Individ import Individ
from mpmath.functions.rszeta import aux_J_needed

class Population:
    def __init__(self,n,xmin,xmax,ymin,ymax):
        self.n = n
        self.xmin = xmin
        self.xmax = xmax
        self.ymin = ymin
        self.ymax = ymax
        self.individs = self.population(self.n, xmin, xmax, ymin, ymax)
    
    def setFirst(self):
        self.individs = self.individs[:100]
        
    def getLen(self):
        return len(self.individs)
    
    def put(self,c):
        self.individs.append(c)
        
    def population(self,count,xmin, xmax, ymin, ymax):
        """
        Create a number of individuals (i.e. a population).
    
        count: the number of individuals in the population
        xmin: the minimum possible value for x
        xmax: the maximum possible value for x
        ymin: the minimum possible value for y
        ymax: the maximum possible value for y
        """
        l = []
        for x in range(count):
            individ = Individ(xmin, xmax, ymin, ymax)
            l.append(individ)
        return l
                    
    def selectForRecombination(self,dimension):
        recombPop = Population(0,0,0,0,0)
        strongParents = []
        
        for i in range(dimension):
            participants = []
            for j in range(3):
                p = self.individs[randint(0,len(self.individs) - 1 )]
                participants.append((p,p.fitness()))
                
            participants = sorted(participants,key=lambda p: p[1])
            strongParents.append(participants[0][0])
            
        recombPop.individs = strongParents
        return recombPop
        
    def selectForSurvival(self,newGen):
        for c in newGen:
            self.individs.append(c)
           
        strongIndivids = [] 
        for i in range(self.n):
            participants = []
            for j in range(3):
                p = self.individs[randint(0,len(self.individs) - 1 )]
                participants.append((p,p.fitness()))
                
            participants = sorted(participants,key=lambda p: p[1])
            strongIndivids.append(participants[0][0])
            
        self.individs = strongIndivids

    
    def __getitem__(self, key):
        return self.individs[key]
    def __setitem__(self,key,c):
        self.individs[key] = c
    def __str__(self):
        s = ""
        for i in range(self.getLen()-97):
            s += " "+str(self.individs[i])+" ->"+str(self.individs[i].fitness())+" " 
        return s
    