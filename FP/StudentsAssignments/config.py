'''
Created on Dec 18, 2016

@author: Stefan
'''

class Configurator():
    def __init__(self,fileName):
        self.__fName = fileName  
        self.__mode =  self.__loadFromFile()  
    
    def __loadFromFile(self):
        """
        try:
            
        except IOError:
            # file does not exist
            return
        """
        f = open(self.__fName, "r")
        line = f.readline().strip()
        attrs = line.split("=")
        return attrs[1]
        f.close()
        

    def getMode(self):
        return self.__mode
