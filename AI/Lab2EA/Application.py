'''
Created on Mar 27, 2018

@author: Stefan
'''
from Algorithm import Algorithm
import matplotlib.pyplot as plt
import numpy as np


def main():
    a = Algorithm()
    return a.run(100)

if __name__ == '__main__':
    results = []
    for i in range(30):
        results.append(main())
    
    print(results)
    arr = np.array(results)
    m = np.mean(arr,axis=0)
    means=[]
    for i in range(30):
        means.append(m)
    plt.plot(range(0,30),means)
    plt.plot( range(0,30),results,"ro")
    plt.show()
