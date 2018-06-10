'''
Created on 2 Jun 2018

@author: stefan
'''
import numpy as np

class Fuzzy:
    def __init__(self):
        self.labels = {}
        self.value = 0

    def toDiscrete(self):
        ret = {}
        graph = self.labels
        value = self.value
        
        for key in graph.keys():
            #check where it is:
            for i in range(len(graph[key]) - 1):
                if graph[key][i][0] <= value and value <= graph[key][i + 1][0]:
                    if graph[key][i][0] == -np.inf:
                        ret[key] = graph[key][i][1]
                        continue
                    if graph[key][i + 1][0] == np.inf:
                        ret[key] = graph[key][i + 1][1]
                        continue
                    deltaY = graph[key][i + 1][1] - graph[key][i][1]
                    deltaX = graph[key][i + 1][0] - graph[key][i][0]
                    ret[key] = graph[key][i][1] + ((value - graph[key][i][0]) / deltaX) * deltaY
        
        return ret


