'''
Created on 20 May 2018

@author: User
'''
from Layer import *
from Neuron import *
from blaze.compute.core import compute
import math

class Network:
    
    def __init__(self, noInputs,noOutputs,noHidden):
        self.net=[]
        hiddenLayer=Layer(noInputs,noHidden)
        self.net.append(hiddenLayer)
        outputLayer=Layer(noHidden,noOutputs)
        self.net.append(outputLayer)
    
    def forwardPropagate(self,inputs):
        for layer in self.net:
            newInputs=[]
            for neuron in layer:
                activation=neuron.activate(inputs)
                newInputs.append(neuron.output)
            inputs=newInputs
        return inputs
    
    def backwardPropagation(self,expected):
        for i in range(len(self.net)-1,0,-1):
            crtLayer=self.net[i]
            errors=[]
            if (i == len(self.net)-1):
                for j in range(0,len(crtLayer)):
                    crtNeuron=crtLayer[j]
                    errors.append(expected[j]-crtNeuron.output)
            else:
                for j in range(0,len(crtLayer)):
                    crtError=0.0
                    nextLayer=self.net[i+1]
                    for neuron in nextLayer:
                        crtError+=neuron.weights[j]*neuron.err
                    errors.append(crtError)
            for j in range(0,len(crtLayer)):
                crtLayer[j].err=errors[j]*crtLayer[j].transferInverse()
                
    def updateWeights(self,example,learningRate):
        for i in range(0,len(self.net)):
            inputs=example[:-1]
            if (i>0):
                layer=self.net[i-1]
                inputs=[neuron.output for neuron in layer]
            for neuron in self.net[i]:
                for j in range(len(inputs)):
                    neuron.weights[j]+=learningRate*neuron.err*inputs[j]
                neuron.weights[-1]+=learningRate*neuron.err
    
    def learning(self,data,learningRate,noEpochs):
        for epoch in range(0,noEpochs):
            sumErr=0.0
            print(epoch)
            for example in data:
                inputs=example[:-1]
                computedOutputs=self.forwardPropagate(inputs)
                expected=[self.sig(example[-1])]
                crtErr=sum([(expected[i]-computedOutputs[i]) **2 for i in range(0,len(expected))])
                sumErr+=crtErr
                self.backwardPropagation(expected)
                self.updateWeights(example, learningRate)
 
    
    def evaluate(self,data):
        computedOutputs=[]
        for inputs in data:
            computedOutput=self.forwardPropagate(inputs[:-1])
            computedOutputs.append(computedOutput[0])
        return computedOutputs
    

    def evaluatePreformanceRegression(self,computedOutputs,realOutputs):   
        error=sum([abs(computedOutputs[i]-self.sig(realOutputs[i])) for i in range(0,len(computedOutputs))])
        return error/len(computedOutputs)
    
           
    @staticmethod
    def sig(x):
        return 1 / (1 + math.exp(-x))     
        
            
    
    
            