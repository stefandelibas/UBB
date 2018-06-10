'''
Created on 7 May 2018

@author: User
'''


from random import randint
from KNeighboursClassifier import KNeighboursClassifier

def read_data(file_path):
    inData = []
    outData = []

    with open(file_path) as f:
        lines = f.readlines()
        for line in lines:
            elems = line.split(" ")
            newLine=[]
            for i in range(len(elems)-1):
                newLine.append(float(elems[i]))
                
            inData.append(newLine)
            outData.append(elems[6])

    return inData,outData


def main():
    inTrain, outTrain = read_data("column_3C.dat")

    inTest = []
    outTest = []
    
    for i in range(10):
        index = randint(0, len(inTrain))
    
        inTest.append(inTrain[index])
        outTest.append(outTrain[index])
    
        inTrain.remove(inTrain[index])
        outTrain.remove(outTrain[index])
    
    classifier = KNeighboursClassifier()
    
    classifier.fit(inTrain, outTrain)
    
    accuracy = 0
    
    for i in range(len(inTest)):
        if classifier.predict(inTest[i]) == outTest[i]:
            accuracy += 1
    print('accuracy=%.2f' % ( float(accuracy) / len(inTest)))




if __name__ == '__main__':
    main()