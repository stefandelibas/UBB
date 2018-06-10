'''
Created on Apr 18, 2018

@author: Stefan-PC
'''
from random import random
import numpy as np
from sympy.physics.units.dimensions import velocity

class Particle:
    def __init__(self, n, vmin, vmax):
        """ constructor

        input--
          n: the number of components
          vmin: the minimum possible value 
          vmax: the maximum possible value
        """
        self._pozition = [ (random()*(vmax-vmin)+vmin) for x in range(n) ]
        self.evaluate()
        self.velocity = [ 0 for i in range(n)]
        
        self._bestPozition=self._pozition.copy()
        self._bestFitness=self._fitness
        
    def fit(self):
        """
        Determine the fitness of an individual. Lower is better.(min problem)
        For this problem we have the Cross-in-tray function
        """
        x = self.pozition[0]
        y = self.pozition[1]
        f = -0.0001 * (np.abs(np.sin(x) * np.sin(y) * np.exp(100 - np.sqrt(x*x+y*y)/np.pi)) + 1)**0.1
        return f
    
    def evaluate(self):
        self._fitness = self.fit()

    @property
    def pozition(self):
        return self._pozition

    @property
    def fitness(self):
        return self._fitness

    @property
    def bestPozition(self):
        return self._bestPozition

    @property
    def bestFitness(self):
        return self._bestFitness
    
    @pozition.setter
    def pozition(self, newPozition):
        self._pozition=newPozition.copy()
        # automatic evaluation of particle's fitness
        self.evaluate()
        # automatic update of particle's memory
        if (self._fitness < self._bestFitness):
            self._bestPozition = self._pozition
            self._bestFitness  = self._fitness
    
    def __str__(self):
        return str(self.pozition[0])+" "+str(self.pozition[1])
    