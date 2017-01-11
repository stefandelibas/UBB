'''
Created on Nov 5, 2016

@author: Stefan
'''
from domain.Assignment import Assignment

class Assignment_repository:
    def __init__(self):
        '''
        Constructor
        '''
        self.__assignments={}
        
    def find_id(self,assign_id):
        """
        verify if an assignment is in the list of assignments by comparing their unique key
        input: and assignment id
        output: true - if it is in the list
                false - if it is not
        """
        found = False
        for assign in self.__assignments.values():
            if int(assign.assign_id) == int(assign_id):
                found = True
        return found
        
    def add_assignment(self,assign):
        """
        adds an assignment to the list of assignments if the id is unique
        input: an assignment with all its attributes(id,description,deadline,grade)
        output: the list of assignments with the new assignment added        
        """
        if assign.assign_id in self.__assignments:
            print("Assignment ID is already taken!")
        else:
            self.__assignments[assign.assign_id] = assign
              
    def update_assignment(self,assign):
        """
        updates an assignment to the list of assignments if there exists the assignment in the list
        input: an assignment with all its attributes(id,description,deadline,grade)
        output: the list of assignments with the updated assignment       
        """
        if assign.assign_id not in self.__assignments:
            print("This assignment ID does not belong to a assignment!")
        else:
            self.__assignments[assign.assign_id] = assign
     
    def remove_assignment(self,assign):
        if assign.assign_id not in self.__assignments:
            print("This assignment ID does not belong to a assignment!")
        elif assign.description not in self.__assignments:
            print("This assignment description does not belong to a assignment!\n")
        elif assign.group not in self.__assignments:
            print("This group does not exist/contain any assignments!\n")
        else:
            del self.__assignments[assign.assign_id]
  
    def remove_assignment_by_id(self,assign_id):
        """
        removes an assignment to the list of assignments if the id is unique
        input: an assignment id
        output: the list of assignments without the removed assignment       
        """
        if assign_id not in self.__assignments:
            print("This assignment ID does not belong to a assignment!")
        else:
            del self.__assignments[assign_id]   
     
    def find_assignment_by_id(self,assign_id):
        """
        finds an assignment by id
        input: an assignment id
        output: the searched element    
        """
        ok = False
        for assign in self.__assignments.values():
            if assign.assign_id == assign_id:
                ok = True
        if ok == False:
            print("Invalid Id!")
        else:
            return self.__assignments[assign_id]  

    def assignments_length(self):
        """
        provides the len of the assignments.
        """
        return len(self.__assignments)
    
    def list_all_assignments(self):
        """
        creates a list of all assignments and returns it
        """
        assign_list=[]
        for assign in self.__assignments.values():
            assign_list.append(assign)
        return assign_list
    
    def __add_assignment__(self,assign):
        self.add_assignment(assign)
        
    def __update_assignment__(self,assign):
        self.update_assignment(assign)
        
    def __remove_assignment__(self,param):
        if type(param) is int:
            self.remove_assignment_by_id(param)    
        if type(param) is Assignment:
            self.remove_assignment(param)
                         
    def __find_assignment__(self,assign_id):
        return self.find_assignment_by_id(assign_id)          
    
    def __list_all_assignments__(self):
        assign_list = ""
        for assign in self.__assignments.values():
            assign_list += str(assign)+"\n"
            return assign_list