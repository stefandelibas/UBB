'''
Created on 2 Jun 2018

@author: stefan
'''
from Fuzzy import *

class Temperature(Fuzzy):
    def __init__(self, value):
        self.value = value
        self.labels = {
            'very_cold': [(-np.inf, 1), (-20,0), (5,0), (np.inf, 0)],
            'cold': [(-np.inf, 0), (-5, 0), (0, 1), (10, 0), (np.inf, 0)],
            'normal': [(-np.inf, 0), (5, 0), (10, 1), (15,1),(20, 0), (np.inf, 0)],
            'warm': [(-np.inf, 0), (15, 0), (20, 1), (25,0),(np.inf, 1)],
            'hot':[(-np.inf, 0),(25,0),(30,1),(35,1),(np.inf, 1)]
        }