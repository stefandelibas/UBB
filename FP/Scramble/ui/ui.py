'''
Created on Jan 23, 2017

@author: Stefan
'''
class UI():
    def __init__(self,ctrl,game,save):
        self.__controller = ctrl
        self.__game = game
        self.__initial_sentance = save
    
    def __ui_read_command(self,request):
        print(request)
        return input()
    
    def __ui_list_all(self):
        list = self.__controller.list_all()
        for e in list:
            print(e)
    
    def __ui_valid(self,attrs):
        if len(attrs) != 5:
            print("the number of attributes is not valid.")
            return False
        return self.__valid_integer(attrs[0]) and self.__valid_integer(attrs[1]) and self.__valid_integer(attrs[3]) and self.__valid_integer(attrs[4])
    def run_ui(self):
        undo = []
        print("the sentance is:"+str(self.__initial_sentance))
        print("your score(available moves):"+str(self.__game.score))
        print("the sentance you have to order is:"+str(self.__game.sentance))
        while True:
            if self.__controller.valid_form(self.__initial_sentance,self.__game.sentance) == True:
                self.__game.state = False
            if self.__game.state == False:
                if self.__game.score == 0:
                    print("You lost!")
                    break
                print("You won!Your score is :"+ str(self.__game.score))
                break
            command,attrs = self.__read_command()
            if(command == "swap"):
                if self.__ui_valid(attrs) == False:
                    continue
                currentSentance = self.__controller.swap_index(attrs[0],attrs[1],attrs[3],attrs[4])
                undo.append([attrs[0],attrs[1],attrs[3],attrs[4]])
                print(currentSentance)

                self.__controller.decrementScore()
                if self.__game.score == 0:
                    self.__controller.endGame()
                print("your current score is:"+str(self.__game.score))
                
            elif(command == "exit"):
                break
            
            elif(command == "list"):
                self.__ui_list_all()
            elif(command == "undo"):
                if len(undo) == 0:
                    print("no available undos")
                    continue
                attrs = undo[-1]
                currentSentance = self.__controller.swap_index(attrs[0],attrs[1],attrs[2],attrs[3])
                undo.pop()
                print(currentSentance)
                print("your current score is:"+str(self.__game.score))
            
            
        
    def __valid_integer(self,index):
        """
        checks if an index is integer or not. if not it raise a ValueError.
        """
        try:
            index = int(index)
        except ValueError as ve:
            ve="The indexes must be a positive integer!\n"
            print(ve)
            return False
        return True
            

    def __read_command(self):
        """
        reads a command
        """
        com=input("Please state your command: ")
        poz=com.find(" ")
        if poz==-1:
            if com=="exit" or com=="list" or com=="undo":
                command=com
                attrs=""
        else:
            command=com[:poz]
            attrs=com[poz+1:]
            attrs=attrs.split(" ")
            
        return (command,attrs)