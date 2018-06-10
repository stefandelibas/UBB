'''
Created on 20 May 2018

@author: User
'''
from Network import *

def run(trainData,testData,learningRate,noEpochs):
        noInputs=len(trainData[0])-1
        noOutputs=1
        net=Network(noInputs,noOutputs,10)
        print("learning")
        net.learning(trainData, learningRate, noEpochs)
        print("realOutputs")
        realOutputs=[trainData[i][j] for j in range (len(trainData[0])-1,len(trainData[0])) for i in range(0,len(trainData))]
        print("evaluate")
        computedOutputs=net.evaluate(trainData)
        print("train: ",net.evaluatePreformanceRegression(computedOutputs, realOutputs))
        realOutputs=[testData[i][j] for j in range (len(testData[0])-1,len(testData[0])) for i in range(0,len(testData))]
        computedOutputs=net.evaluate(testData)
        print("test:",net.evaluatePreformanceRegression(computedOutputs, realOutputs))


def readFromFile(filename):
    print("training data is loading...")
    attrs = []
    f = open(filename, "r")
    line1 = f.readline().strip()
    line = f.readline().strip()
    elems = line.split(",")
    i = 0 
    inData = [] 
    testData = []
    while i < 40000:
        elems = line.split(",")
        attrs = [ float(elems[i]) for i in range(len(elems)) ]
        inData.append(attrs[1:])
        line = f.readline().strip()  
        i+=1     
    
    print("load test data...")
    
    while line != "":
        elems = line.split(",")
        attrs = [ float(elems[i]) for i in range(len(elems)) ]
        testData.append(attrs[1:])
        line = f.readline().strip()       
    f.close()
   
    return  inData,testData
    
    
            
def main():
    dataTrain,dataTest=readFromFile("slice_localization_data.csv")
    learningRate=0.001
    noEpochs=10
    run(dataTrain,dataTest,learningRate,noEpochs)

        
if __name__ == '__main__':
    main()