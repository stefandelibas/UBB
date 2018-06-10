'''
Created on Mar 27, 2018

@author: Stefan
'''
from random import randint,random
import matplotlib.pyplot as plt
import numpy as np

from Problem import Problem
from Population import Population
from Individ import Individ

class Algorithm():
    def __init__(self):
        self.problem = Problem()
        self.readProblem()
        self.pop = Population(self.problem.getDimPop(),self.problem.getXMin(), self.problem.getXMax(), self.problem.getYMin(), self.problem.getYMax())
        
            
        
    def readProblem(self):
        self.problem.loadData("C:\\Users\\Stefan-PC\\eclipse-workspace\\Lab2EA\\input.txt")
    
    def run(self,noIteratii):  
        
        results = []
        for i in range(noIteratii):
            self.iteration(self.pop, self.problem.getPM(), self.problem.getXMin(), self.problem.getXMax(), self.problem.getYMin(), self.problem.getYMax())
            
            fitnessValues = []
            for x in self.pop.individs:
                fitnessValues.append(x.fitness())
            fitnessValues = sorted(fitnessValues)
                  
            results.append(fitnessValues[0])
    
        """ arr = np.array(results)
        m = np.mean(arr,axis=0)
        means=[]
        for i in range(noIteratii):
            means.append(m)
        plt.plot(range(0,noIteratii),means)
        plt.plot( range(0,noIteratii),results)
        plt.show()
        """
        return fitnessValues[0]
            

    
    def iteration(self,pop, pM, xmin, xmax, ymin, ymax):
        '''
        an iteration
    
        pop: the current population
        pM: the probability the mutation to occur
        xmin, xmax, ymin, ymax: bounds for x and y
        '''
        newGen = []
        
        recompPop = self.pop.selectForRecombination(self.problem.getDimPop() // 2)
        for i in range(self.problem.getDimPop() // 2):
            i1=randint(0,recompPop.getLen()-1)
            i2=randint(0,recompPop.getLen()-1)
            if (i1!=i2):
                c=recompPop[i1].blendcorssover(recompPop[i2])
                c.mutate(pM, xmin, xmax, ymin, ymax)
                #c2.mutate(pM,xmin,xmax,ymin,ymax)
                newGen.append(c)
            else:
                i-=1
        self.pop.selectForSurvival(newGen)

            
