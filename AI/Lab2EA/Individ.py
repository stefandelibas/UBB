'''
Created on Mar 27, 2018

@author: Stefan
'''
from random import randint,random
import numpy as np

class Individ:
    def __init__(self, xmin=0, xmax=0, ymin=0, ymax=0):
        self.values = self.individual(xmin, xmax, ymin, ymax)
        
    def individual(self, xmin, xmax,ymin,ymax):
        '''
        Create a member of the population
        xmin: the minimum possible value for x
        xmax: the maximum possible value for x
        ymin: the minimum possible value for y
        ymax: the maximum possible value for y
        '''
        return [random()*(xmax-xmin)+xmin,random()*(ymax-ymin)+ymin]
    
    def getX(self):
        return self.values[0]
    
    def getY(self):
        return self.values[1]
        
    def fitness(self):
        """
        Determine the fitness of an individual. Lower is better.(min problem)
        For this problem we have the Cross-in-tray function
        
        individual: the individual to evaluate
        """
        x = self.getX()
        y = self.getY()
        f = -0.0001 * (np.abs(np.sin(x) * np.sin(y) * np.exp(100 - np.sqrt(x*x+y*y)/np.pi)) + 1)**0.1
        return f
        
    def mutate(self, pM, xmin, xmax, ymin, ymax): 
        '''
        Performs a mutation on an individual with the probability of pM.
        If the event will take place, at a random position a new value will be
        generated in the interval [vmin, vmax]
    
        individual:the individual to be mutated
        pM: the probability the mutation to occure
        vmin: the minimum possible value 
        vmax: the maximum possible value
        '''
        if pM > random():
            p = randint(0, 1)
            if p == 1:
                self.values[1] = random()*(ymax-ymin)+ymin
            else:
                self.values[0] = random()*(xmax-xmin)+xmin
    
    def crossover(self,p2):
        '''
        crossover between 2 parents
        Complete arithmetic crossover
        p1[i] = a * p1[i] + (1-a) * p2[i]
        p2[i] = (1-a) * p1[i] + a * p2[i] 
        '''
        a = random()
        self.values[0] = a * self.values[0] + (1-a) * p2[0]
        p2[0] = (1-a) * self.values[0] + a * p2[0] 
        
        self.values[1] = a * self.values[1] + (1-a) * p2[1]
        p2[1] = (1-a) * self.values[1] + a * p2[1] 
 
        return self,p2
    
    def blendcorssover(self,p2):
        child = [0,0]        
        a = random()
        m = min(self.values[0],p2[0])
        M = max(self.values[0],p2[0])
        i = M - m 
        down = m - i * a
        up = M - i * a
        child[0] = random()*(up - down) + down
        
        a = random()
        m = min(self.values[1],p2[1])
        M = max(self.values[1],p2[1])
        i = M - m 
        down = m - i * a
        up = M - i * a
        child[1] = random()*(up - down) + down
        newchild = Individ()
        newchild.values = child
        return newchild
    
    def __getitem__(self, key):
        return self.values[key]
    def __setitem__(self,key,c):
        self.values[key] = c
    
    def __str__(self):
        return "("+str(self.values[0])+","+str(self.values[1])+")"
