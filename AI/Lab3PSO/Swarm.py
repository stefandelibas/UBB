'''
Created on Apr 18, 2018

@author: Stefan-PC
'''
from random import randint
from Particle import Particle

class Swarm:
    def __init__(self, count, n, vmin, vmax):
        self.noOfParticles = count
        self.v = self.population(count, n, vmin, vmax)
        
    def __len__(self):
        return len(self.v)
    
    def population(self, count, n, vmin, vmax):
        return [ Particle(n, vmin, vmax) for x in range(count) ]

    def getBestNeighbour(self,particle,neighbours):

        bestNeighbor = neighbours[particle][0]
        for j in range(1,len(neighbours[particle])):
            if (neighbours[particle][j].fitness < bestNeighbor.fitness):
                bestNeighbor = neighbours[particle][j]                   
        return bestNeighbor
    
    def getBestParticle(self):
        #print the best individual
        best = 0
        for i in range(1, len(self.v)):
            if (self.v[i].fitness < self.v[best].fitness):
                best = i
        
        return self.v[best]
    
    def __getitem__(self, key):
        return self.v[key]
    def __setitem__(self,key,c):
        self.v[key] = c
    
    def __str__(self):
        s = ""
        for i in range(len(self.v)):
            s += " "+str(self.v[i].pozition)+" ->"+str(self.v[i].bestFitness)+" " 
        return s