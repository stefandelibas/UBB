'''
Created on 19 May 2018

@author: User
'''
from math import *
from random import *
class Neuron:
    def __init__(self,noInputs):
        self.noInputs=noInputs
        self.weights=[ random() for i in range(noInputs)]
        self.output=None
        self.err=0.0
        
    def __str__(self):
        return"weights"+str(self.weights)+"\n"+"output"+str(self.output)+"\n"
    
    def activate(self,info):
        '''activation of a neuron'''
        s=self.weights[-1]
        for i in range(self.noInputs):
            s=s+info[i]*self.weights[i]
        '''to get the output of a neuron, we compute the sigmoid function'''
        self.output = 1 / (1.0 + exp(-s)); 
        return self.output
    
    def transferInverse(self):
        return self.output*(1-self.output)
    
