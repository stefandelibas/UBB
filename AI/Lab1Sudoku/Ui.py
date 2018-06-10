'''
Created on Mar 17, 2018

@author: Stefan-PC
'''

from time import time

import Controller 

class UI:
    def __init__(self,ctrl):
        self.ctrl = ctrl
        self.words = []
    
    def __ui_read_command(self,request):
        print(request)
        return input()
       
        
    def findPathBFS(self):
        startClock = time()
        matr = self.ctrl.BFS()
        for row in matr:
            print(str(row))    
        print('execution time = ',time()-startClock, " seconds" )
        
    def findPathBestFS(self):
        startClock = time()
        matr = self.ctrl.BestFS()
        for row in matr:
            print(str(row))    
        print('execution time = ',time()-startClock, " seconds" )
   
    def ui_run(self):
        print("Wellcome!")
        while True:
            cmds_list = {"1":self.findPathBFS, "2":self.findPathBestFS }
            com_list = ["1","2"]
            cmd = self.__ui_read_command("Type"+"\n"+"1 - find a path with BFS "+"\n"+"2 - find a path with BestFS")
            if cmd in com_list:
                if cmd == "0":
                    print("Thanks for using my app! :)\n")
                    return
                else:
                    cmds_list[cmd]()
            else:
                print("Invalid command!\n")
                
    
   