'''
Created on Nov 4, 2016

@author: Stefan
'''
class Student:
    def __init__(self, stud_id, name, group):
        '''
        Constructor
        '''
        self.__stud_id = stud_id
        self.__name = name
        self.__group = group
    
    @property  
    def stud_id(self):
        return self.__stud_id
        
    @stud_id.setter
    def stud_id(self, stud_id):
        self.__stud_id = stud_id
        
    @stud_id.deleter   
    def stud_id(self):
        del self.__stud_id
     
    @property
    def name(self):
        return self.__name
    
    @name.setter
    def name(self, name):
        self.__name = name
        
    @name.deleter
    def name(self):
        del self.__name
        
    @property
    def group(self):
        return self.__group
    
    @group.setter
    def group(self, group):
        self.__group = group
        
    def graterByID(self,s1,s2):
        return s1.stud_id < s2.__stud_id
    
    @group.deleter
    def group(self):
        del self.__group
        
    def __lt__(self,stud):
        return self.name < stud.name
    
    def __str__(self):
        return str(self.__stud_id)+" "+self.__name+" from "+str(self.__group)