'''
Created on Mar 17, 2018

@author: Stefan-PC
'''

class Controller:
    
    def __init__(self, problem):
        self.problem = problem
       
    def BFS(self):
        q = [self.problem.getRoot()]
        while len(q) > 0 :
            currentState = q.pop(0)
            if self.problem.checkBoard(currentState) == True:
                self.problem.fillConfig(self.problem.getInitialState(),currentState)
                return self.problem.getInitialState()
            q = q + self.problem.expand(currentState)

    def BestFS(self):
        q = [self.problem.getRoot()]
        while len(q) > 0 :
            currentState = q.pop(0)
            if self.problem.checkBoard(currentState) == True:
                self.problem.fillConfig(self.problem.getInitialState(),currentState)
                return self.problem.getInitialState()
            newConfigs = sorted( self.problem.expand(currentState), key=self.problem.cmp_to_key(self.problem.heuristics))
            q = q + newConfigs
    