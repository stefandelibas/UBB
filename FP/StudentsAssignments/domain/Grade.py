'''
Created on Nov 4, 2016

@author: Stefan
'''
class Grade:
    def __init__(self, assign_id, stud_id, grade, check):
        '''
        Constructor
        '''
        self.__assign_id = assign_id
        self.__stud_id = stud_id
        self.__grade = grade
        self.__check = check
    @property  
    def assign_id(self):
        return self.__assign_id
        
    @assign_id.setter
    def assign_id(self, assign_id):
        self.__assign_id = assign_id
        
    @assign_id.deleter   
    def assign_id(self):
        del self.__assign_id
     
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
    def grade(self):
        return self.__grade
    
    @grade.setter
    def grade(self, grade):
        self.__grade = grade
   
    @grade.deleter
    def grade(self):
        del self.__grade
        
    @property
    def check(self):
        return self.__check  
      
    @check.setter
    def check(self, check):
        self.__check = check
        
    @check.deleter
    def check(self):
        del slef.__check
        
    def __lt__(self,grade):
        return self.grade < grade.grade
    def __str__(self):
        if self.__check == True:
            return "assign no "+str(self.__assign_id)+" belonging to student no "+str(self.__stud_id)+" evaluated at "+str(self.__grade)
        elif self.__check == False:
            return "assign no "+str(self.__assign_id)+" belonging to student no "+str(self.__stud_id)+" not evaluated yet."