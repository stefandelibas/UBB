'''
Created on Jan 23, 2017

@author: Stefan
'''
class Game():
    def __init__(self,sentance):
        self.__score = self.__getSentanceLen(sentance)
        self.__state = True
        self.__sentance = sentance
        
    
    def __getSentanceLen(self,sentance):
        n = 0
        for word in sentance.list_words():
            n = n + len(word)
        n = n - 2
        return n
    
    @property
    def sentance(self):
        return self.__sentance
    
    @sentance.setter
    def sentance(self,sentance):
        self.__sentance = sentance
        
    @property
    def state(self):
        return self.__state
    @property
    def score(self):
        return self.__score
    
    @score.setter
    def score(self,score):
        self.__score = score
       
    @state.setter
    def state(self,state):
        self.__state = bool(state)
        
        
class Word():
    def __init__(self,word,word_id):
        self.__word = word
        self.__word_id = word_id
        
    @property
    def word(self):
        return self.__word
    
    @word.setter
    def word(self,w):
        self.__word = w
        
    @property
    def word_id(self):
        return self.__word_id
    
    @word_id.setter
    def word_id(self,w_id):
        self.__word_id = w_id
        
    
    def __len__(self):
        return len(self.__word)
    
    def __setitem__(self,letter,item):
        self.__word[int(letter)] = item
     
    def __getitem__(self,letter):
        return self.__word[int(letter)]
    
    def __str__(self):
        return str(self.__word)
    
class Sentance():
    def __init__(self,sentence):
        self.__sentence = sentence
        self.__words = []
        self.__loadWords()
        
    def __loadWords(self):
        s = self.__sentence.split(" ")
        for i in range(0,len(s)):
            word = Word(s[i],i)
            self.__words.append(word)
    
    def list_words(self):
        words_list = []
        for w in self.__words:
            words_list.append(w)
        return words_list
       
    def getWord(self,index):
        return self.__words[int(index)]
    
    def setWord(self,word,index):
        w = list(word)
        self.__words[int(index)] = ''.join(w)
        
    def __setitem__(self, key, item):
        self.__words[key].__word = item.__word
        
    def __getitem__(self, key):
        return self.__words[key]
    
    def __len__(self):
        return len(self.__words)
    def __str__(self):
        return str(self.__sentence)