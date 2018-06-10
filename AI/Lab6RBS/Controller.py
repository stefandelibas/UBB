'''
Created on 2 Jun 2018

@author: stefan
'''
from Ruler import *
from Humidity import *
from Temperature import *
class Controller:
    def __init__(self, temperature, humidity):
        self.rules = Ruler()
        self.t = Temperature(temperature)
        self.h = Humidity(humidity)

    def solve(self):
        agg = self.rules.evaluate(self.t, self.h)
        print(sorted(list(agg.items()), key = lambda x: x[1])[-1][0])