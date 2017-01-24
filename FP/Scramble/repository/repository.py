'''
Created on Jan 23, 2017

@author: Stefan
'''
from domain.domain import Sentance
import random

class SentencesRepository():
    def __init__(self,game,fileName = "C:\\Users\\Stefan\\workspace2\\Scramble\\sentences.txt"):
        self.__fName =fileName
        self.__sentences = []
        self.__loadFromFile()
        self.__game = game
        
    def __loadFromFile(self):
        """"
        reads and loads the sentences from the file to the local memory
        """
        try:
            f = open(self.__fName, "r")
        except IOError:
            # file not exist
            return IOError("file error")
        line = f.readline()
        while line != "":
            attrs = line.split("\n")
            sentence = Sentance(attrs[0])
            self.__sentences.append(sentence)
            line = f.readline()
        f.close()
        return self.__sentences
    def __storeToFile(self):
        """
         Store all the sentences in to the file
        """
        f = open(self.__fName, "w")
        for sentence in self.__sentences:
            strf = str(sentence) + "\n"
            f.write(strf)
        f.close()
      
    def swap_index(self,c1,l1,c2,l2):
        """
        swaps the letters l1 with l2 from the words c1 and c2
        """
        s = self.__game.sentance
        word1 = s.getWord(c1)
        word2 = s.getWord(c2)
        if c1 == c2:
            if l1 == l2:
                return
            else:
                w = list(word1)
                w[int(l1)],w[int(l2)] = w[int(l2)],w[int(l1)]
                word1 = ''.join(w)
                s.setWord(word1,c1)
        else: 
            for i in range(0,len(word1)):
                if str(i) == str(l1):
                    for j in range(0,len(word2)):
                        if str(j) == str(l2):
                            w1 = list(word1)
                            w2 = list(word2)
                            w1[int(i)],w2[int(j)] = w2[int(j)],w1[int(i)]
                            word1 = ''.join(w1)
                            word2 = ''.join(w2)
                            
            s.setWord(word1,c1)
            s.setWord(word2,c2)
        final_sentance = ''
        
        for e in s.list_words():
            final_sentance = final_sentance + str(e) + " "
        
        #print(final_sentance)
        self.__game.__sentance = final_sentance[:len(final_sentance)-1]
        return self.__game.__sentance
    
        #self.__storeToFile()
        
    def getSentencesLen(self):
        return len(self.__sentences)
    
    def list_all(self):
        #this function is only helping me to see if the repository is okay
        sentences_list = []
        for s in self.__sentences:
            sentences_list.append(s)
        return sentences_list
    
            