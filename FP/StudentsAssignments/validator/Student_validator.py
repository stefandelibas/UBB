'''
Created on Nov 7, 2016

@author: Stefan
'''

class Student_repository_exception(Exception):
    pass

class Student_validation_exception(Exception):
    pass

class Student_validator:
    def validate_student(self,stud):
        errors =""
        if stud.stud_id < 0:
            errors += "Student ID must be a positive integer!\n"
        if stud.name == "":
            errors += "Student name cannot be empty!\n"
        if stud.group < 0:
            errors += "Student group must be a positive integer!\n"
        if len(errors) > 0:
            raise Student_validation_exception(errors)