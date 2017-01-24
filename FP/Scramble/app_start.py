'''
Created on Jan 23, 2017

@author: Stefan
'''
from repository.repository import SentencesRepository
from controller.controller import Controller
from ui.ui import UI
from domain.domain import Game,Sentance

import random
from copy import deepcopy



sentance_list = []
sentance = Sentance("")



game = Game(sentance)
repo = SentencesRepository(game)
i = random.randint(0,len(repo.list_all())-1)
sentance_list = repo.list_all()
sentance = sentance_list[i]
save = deepcopy(sentance)

def shuffle(sentance):

    i = random.randint(10,25)
    while i!=0:
        c1 = random.randint(0,len(sentance)-1)
        c2 = random.randint(0,len(sentance)-1)
        word1 = sentance.getWord(c1)
        word2 = sentance.getWord(c2)
        if len(word1)<=2 or len(word2)<=2:
            continue
        l1 = random.randint(1,len(word1)-2)
        l2 = random.randint(1,len(word2)-2)
        if c1 == c2:
            if l1 == l2:
                continue
            else:
                w = list(word1)
                w[int(l1)],w[int(l2)] = w[int(l2)],w[int(l1)]
                word1 = ''.join(w)
                i = i - 1
                sentance.setWord(word1,c1) 
        else:
            
            w1 = list(word1)
            w2 = list(word2)
            w1[int(l1)],w2[int(l2)] = w2[int(l2)],w1[int(l1)]
            
            #print(w1[int(l1)]+"-"+w2[int(l2)])
            #print(str(c1)+str(l1)+ " "+str(c2)+str(l2))
            
            word1 = ''.join(w1)
            word2 = ''.join(w2)  
            i = i - 1
            sentance.setWord(word1,c1)
            sentance.setWord(word2,c2)
            
        final_sentance = ''
        for e in sentance.list_words():
            final_sentance = final_sentance + str(e) + " "
        
    return final_sentance[:len(final_sentance)]
    

sentance = shuffle(sentance)
formedSentance = Sentance(sentance)

game = Game(formedSentance)
repo = SentencesRepository(game)

ctrl = Controller(repo,game)
Menu = UI(ctrl,game,save)

Menu.run_ui()
