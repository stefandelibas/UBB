'''
Created on Nov 5, 2016

@author: Stefan
'''
from domain.Assignment import Assignment
from validator.Assignment_validator import Assignment_validator

class Assignment_controller:
    def __init__(self, repository):
        '''
        Constructor
        '''
        self.__assign_repository = repository
        self.__assign_validator = Assignment_validator()
        
    def add_assignment(self,assign_id,description,deadline,grade):
        """
        takes the data from the UI, validates it and passes data to the repository
        input: all data for an assignment:id,description,deadline,grade
        output: the call of the adding function from the repository
        """
        assign = Assignment(assign_id,description,deadline,grade)
        self.__assign_validator.validate_assignment(assign)
        self.__assign_repository.add_assignment(assign)
        return assign
        
    def update_assignment(self,assign_id,description,deadline,grade):
        """
        takes the data from the UI, validates it and passes data to the repository
        input: all data for an assignment:id,description,deadline,grade
        output: the call of the update function from the repository
        """
        assign = Assignment(assign_id,description,deadline,grade)
        old_assign = self.__assign_repository.find_assignment_by_id(assign_id)
        self.__assign_validator.validate_assignment(assign)
        self.__assign_repository.update_assignment(assign)
        return old_assign,assign
        
    def remove_assignment(self,assign_id,description,deadline,grade):
        """
        takes the data from the UI, validates it and passes data to the repository
        input: all data for an assignment:id,description,deadline,grade
        output: the call of the removing function from the repository
        """
        assign = Assignment(assign_id,description,deadline,grade)
        self.__assign_validator.validate_assignment(assign)
        self.__assign_repo.remove_assignment(assign)
        return assign
         
    def remove_assignment_by_id(self,assign_id):
        """
        takes the data from the UI, validates it and passes data to the repository
        input: all data for an assignment:id,description,deadline,grade
        output: the call of the removing function of a assignment by its id from the repository
        """
        assign = self.__assign_repository.find_assignment_by_id(assign_id)
        self.__assign_repository.remove_assignment_by_id(assign_id)
        return assign
        
    def find_assignment_by_id(self,assign_id):
        return self.__assign_repository.find_assignment_by_id(assign_id)         
    
    def assignments_length(self):
        return self.__assign_repository.assignments_length()
        
    def list_all_assignments(self):
        return self.__assign_repository.list_all_assignments()