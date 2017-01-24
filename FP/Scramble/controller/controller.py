'''
Created on Jan 23, 2017

@author: Stefan
'''

class Controller():
    def __init__(self,repo,game):
        self.__repo = repo
        self.__game = game
        
    def list_all(self):
        """
        passes the list of sentences from the file to the UI
        """
        return self.__repo.list_all()
    
    def __getSentence(self):
        """
        returns the sentence of the game
        """
        return self.__game.__sentance
    
    def swap_index(self,c1,l1,c2,l2):
        """
        takes the indexs from the ui and pas
        """
        return self.__repo.swap_index(c1,l1,c2,l2)
    
    def decrementScore(self):
        """
        Subtracts a point from the current score of the game
        """
        self.__game.score = self.__game.score - 1
        
    def endGame(self):
        """
        initialize the state of the game with False
        """
        self.__game.state = False
        
    def valid_form(self,initial,current):
        """
        checks if the current form of the sentance is the same as the initial one
        """
        for i in range(0,len(initial)):
            for j in range(0,len(initial[i])):
                if initial[i][j] != current[i][j]:
                    return False
        return True