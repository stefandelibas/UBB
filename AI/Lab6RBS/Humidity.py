'''
Created on 2 Jun 2018

@author: stefan
'''
from Fuzzy import *
class Humidity(Fuzzy):
    def __init__(self, value):
        self.value = value
        self.labels = {
            'dry': [(-np.inf, 1), (0, 1), (50, 0), (np.inf, 0)],
            'normal': [(-np.inf, 0), (0, 0), (50, 1), (100, 0), (np.inf, 0)],
            'wet': [(-np.inf, 0), (50, 0), (100, 1),  (np.inf, 1)]
        }