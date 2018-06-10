'''
Created on 20 May 2018

@author: User
'''
from Neuron import *
class Layer:
    
    def __init__(self,inp,n):
        self.noNeurons=n
        self.neurons=[Neuron(inp) for i in range(n)]
        
    def __getitem__(self, key):
        return self.neurons[key]
    def __setitem__(self,key,c):
        self.neurons[key] = c
    def __len__(self):
        return len(self.neurons)
    def __str__(self):
        return "noNeurons:"+str(self.noNeurons)+"neurons:"+str(self.neurons)
        
        