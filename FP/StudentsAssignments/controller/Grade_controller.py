'''
Created on Nov 5, 2016

@author: Stefan
'''
from domain.Grade import Grade
from validator.Grade_validator import Grade_validator
from lab9.sort import *

class Grade_controller:
    def __init__(self,gradeRepo,studRepo,assignRepo):
        '''
        Constructor
        '''
        self.__grade_repository = gradeRepo
        self.__grade_validator = Grade_validator()
        self.__studRepo = studRepo
        self.__assignRepo = assignRepo
        
    def showGivenID(self,stud_id):
        return self.__grade_repository.showGivenID(stud_id)
    
    def add_grade(self,assign_id,stud_id,grade):
        """
        takes the data from the UI, validates it and passes data to the repository
        input: all data for an grade: assignment id,student id,grade
        output: the call of the adding function from the repository
        """
        grade = Grade(assign_id,stud_id,grade,True)
        #self.__grade_validator.validate_grade(grade)
        self.__grade_repository.add_grade(grade)
        return grade
        
    def list_all_grades(self):
        """
        lists all grades from the repository
        """
        x = self.__grade_repository.list_all_grades()
        GnomeSort(x)
        return x 
    
    def give_assign(self,assign_id, stud_id,grade,check):
        """
        takes the data from the UI, validates it and passes data to the repository
        input: all data for an grade: assignment id,student id,grade
        output: the call of a function from the repository which give an assignment to a student
        """
        assign = Grade(assign_id,stud_id,grade,check)
        self.__grade_repository.give_assign(assign)
        return assign
        
    def give_assign_group(self,assign_id,group):
        """
        takes the data from the UI, validates it and passes data to the repository
        input: all data for an grade: assignment id,student id,grade
        output: the call of a function from the repository which give an assignment to a group of students
        """
        stud_id=0
        assign = Grade(assign_id,stud_id,0,False)
        self.__grade_repository.give_assign_group(assign_id,group,assign)
        
    def remove_grade(self,assign_id,stud_id):
        self.__grade_repository.remove_grade_by_both_IDs(assign_id,stud_id)
        return self.__grade_repository.find_grade(assign_id,stud_id)
    
    def remove_grade_by_id_s(self,stud_id):
        """
        takes the data from the UI, validates it and passes data to the repository
        input: the id of the student whose assignments and grades have to be removed
        output: the call of the removing function from the repository 
        """
        save_list = self.__grade_repository.remove_assign_s(stud_id)
        return save_list
    
    def remove_grade_by_id_a(self,assign_id):
        """
        takes the data from the UI, validates it and passes data to the repository
        input: the id of the assignment whose assignments and grades have to be removed
        output: the call of the removing function from the repository 
        """
        save_list = self.__grade_repository.remove_assign_a(assign_id)
        return save_list
    """
    def recordOperationsForAssign(self,save_list):
        return save_list
    """
    def filterGrades(self, stud, assign):
        """
        Return a list of rentals performed by the provided client for the provided car
        client - The client performing the rental. None means all clients
        cars - The rented car. None means all cars 
        """
        result = []
        for grade in self.__grade_repository():
            if stud != None and grade.stud_id() != stud.stud_id:
                continue 
            if  assign != None and grade.assign_id() != assign.assign_id:
                continue
            result.append(grade)
        return result
    
    
    def stud_per_assign(self,assign_id,sort_method):
        """
        if assign_id not in self.__assignRepo.list_all_assignments():
            print("This assignment ID does not belong to a assignment!")
        if sort_method != 1 or sort_method != 2:
            print("invalid command for the sort method")
        """
        return self.__grade_repository.stud_per_assign(assign_id, sort_method)
    
    def late_stud(self):
        return self.__grade_repository.late_stud()
    def best_students(self):
        return self.__grade_repository.best_students()  
    def best_assign(self):
        return self.__grade_repository.best_assign() 
    