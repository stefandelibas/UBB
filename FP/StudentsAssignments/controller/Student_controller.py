'''
Created on Nov 5, 2016

@author: Stefan
'''
from domain.Student import Student
from validator.Student_validator import Student_validator
from lab9.sort import *
from lab9 import sort

class Student_controller:
    def __init__(self, repository):
        '''
        Constructor
        '''
        self.__stud_repository = repository
        self.__stud_validator = Student_validator()
        
    def add_student(self,stud_id,name,group):
        stud = Student(stud_id,name,group)
        self.__stud_validator.validate_student(stud)
        self.__stud_repository.add_student(stud)
        return stud
        
    def update_student(self,stud_id,name,group):
        stud = Student(stud_id,name,group)
        old_stud = self.__stud_repository.find_student_by_id(stud_id)
        self.__stud_validator.validate_student(stud)
        self.__stud_repository.update_student(stud)
        return old_stud,stud
        
    def remove_student(self,stud_id,name,group):
        stud = Student(stud_id,name,group)
        self.__stud_validator.validate_student(stud)
        self.__stud_repository.remove_student(stud)
        return stud
    
    def remove_student_by_id(self,stud_id):
        stud = self.__stud_repository.find_student_by_id(stud_id)
        self.__stud_repository.remove_student_by_id(stud_id)
        return stud
    
    def find_student_by_id(self,stud_id):
        return self.__stud_repository.find_student(stud_id)
    
    def students_length(self):
        return self.__stud_repository.student_length()
        
    def list_all_students(self):
        x = self.__stud_repository.list_all_students()
        GnomeSort(x)
        return x
    
    