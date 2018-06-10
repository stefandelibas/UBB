'''
Created on Apr 18, 2018

@author: Stefan-PC
'''

from random import random,randint
from Swarm import Swarm
import matplotlib.pyplot as plt


class Controller:
    def __init__(self):
        self.loadParameters()
        self.pop =  Swarm(self.noParticles,self.dimParticle,self.vmin,self.vmax)
        self.result = [self.pop.getBestParticle().fitness]
        
    
    def iteration(self,neighbors, c1, c2, w ):
        bestNeighbors=[]
        for i in range(len(self.pop)):
            bestNeighbors.append(self.pop.getBestNeighbour(self.pop[i], neighbors))
                           
        for i in range(len(self.pop)):
            for j in range(len(self.pop[0].velocity)):
                newVelocity = w * self.pop[i].velocity[j]
                newVelocity = newVelocity + c1*random()*(bestNeighbors[i].pozition[j]-self.pop[i].pozition[j])    
                newVelocity = newVelocity + c2*random()*(self.pop[i].bestPozition[j]-self.pop[i].pozition[j])
                self.pop[i].velocity[j]=newVelocity
        
        for i in range(len(self.pop)):
            newPozition=[]
            for j in range(len(self.pop[0].velocity)):
                newPozition.append(self.pop[i].pozition[j]+self.pop[i].velocity[j])
            self.pop[i].pozition=newPozition
        
        self.result.append(self.pop.getBestParticle().fitness)
        
     
    def selectNeighbors(self,nSize):    
        if (nSize>len(self.pop)):
            nSize=len(self.pop)
    
        neighbors={}
        for i in range(len(self.pop)):
            localNeighbor=[]
            for j in range(nSize):
                x=randint(0, len(self.pop)-1)
                while (x in localNeighbor):
                    x=randint(0, len(self.pop)-1)
                localNeighbor.append(self.pop[x])
            neighbors[self.pop[i]] = localNeighbor.copy()
        return neighbors       
            
    def runAlgorithm(self,noIteratii=100): 
        neighborhoods=self.selectNeighbors(self.sizeOfNeighborhood)
                
        for i in range(noIteratii):
            self.iteration(neighborhoods, self.c1,self.c2, self.w/(i+1))
        
        """
        plt.plot( range(0,noIteratii+1),self.result)
        plt.show()
        """

        best = 0
        for i in range(1, len(self.pop)):
            if (self.pop[i].fitness < self.pop[best].fitness):
                best = i
        
        
        fitnessOptim = self.pop[best].fitness
        individualOptim = self.pop[best].pozition
        print('minimum of the function is:',fitnessOptim,' at (',individualOptim[0],',',individualOptim[1]),')'
    
    def loadParameters(self):
        #PARAMETERS:
        #number of particles
        self.noParticles = 100
        #individual size
        self.dimParticle = 2
        #the boundries of the search interval
        self.vmin = -10
        self.vmax = 10
        #specific parameters for PSO
        self.w=1.0
        self.c1=1.0
        self.c2=2.5
        self.sizeOfNeighborhood=20

    
    