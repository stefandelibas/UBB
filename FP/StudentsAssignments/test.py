'''
Created on Nov 22, 2016

@author: Stefan
'''
import unittest
from domain.Assignment import Assignment
from validator.Assignment_validator import Assignment_validator
from repository.Assignment_repository import Assignment_repository
from domain.Grade import Grade
from validator.Grade_validator import Grade_validator
from repository.Grade_repository import Grade_repository
from domain.Student import Student
from validator.Student_validator import Student_validator
from repository.Student_repository import Student_repository
from loadData import loadData
from controller.Assignment_controller import Assignment_controller
from controller.Grade_controller import Grade_controller
from controller.Student_controller import Student_controller
from datetime import datetime

class RepositoryTest(unittest.TestCase):
    def setUp(self):
        self.__assign_repo = Assignment_repository()
        self.__assign_ctrl = Assignment_controller( self.__assign_repo)
        self.__stud_repo = Student_repository() 
        self.__stud_ctrl = Student_controller( self.__stud_repo)
        self.__grade_repo = Grade_repository(self.__stud_repo,self.__assign_repo)
        self.__grade_ctrl = Grade_controller( self.__grade_repo, self.__stud_repo, self.__assign_repo)
        loadData(self.__stud_ctrl, self.__assign_ctrl, self.__grade_ctrl)
        
    def testAssignRepoAdd(self):
        #self.assertEqual(self.__assign_repo.assignments_length, 2)
        a1 = Assignment(3,"Solve ex 11 to 15","5.12.2017",2)
        self.__assign_repo.add_assignment(a1)
        #self.assertEqual(self.__assign_repo.assignments_length, 3)
        a2 = Assignment(4,"Solve ex 16 to 20","10.12.2017",3)
        self.__assign_repo.add_assignment(a2)
        #self.assertEqual(self.__assign_repo.assignments_length, 4)
                         
    def testAssignRepoUpdate(self):
        a=Assignment(2,"Solve ex 5 to 10",datetime.strptime("2016-10-10", "%Y-%m-%d"),5)
        self.__assign_repo.update_assignment(a)
        a = self.__assign_repo.find_assignment_by_id(2)
        self.assertEqual(a.assign_id,2)
        self.assertEqual(a.description,"Solve ex 5 to 10")
        self.assertEqual(a.grade,5)
    
    def testAssignRepoRemove(self):
        #self.assertEqual(self.__stud_repo.assignments_length, 2)
        self.__assign_repo.remove_assignment_by_id(2)
        self.assertFalse(self.__stud_repo.find_id(2))
        #self.assertEqual(self.__stud_repo.assignments_length, 1)
        
    def testStudentRepoAdd(self):
        s1=Student(1, "Delibas Stefan", 1)
        #self.assertEqual(self.__stud_repo.students_length, 12)
        self.__stud_repo.add_student(s1)
        #self.assertEqual(self.__stud_repo.students_length, 13)
        s2=Student(2, "Bob Diana", 1)
        self.__stud_repo.add_student(s2)
        #self.assertEqual(self.__stud_repo.students_length, 14)
        s3 = self.__stud_repo.find_student_by_id(14)
        self.assertEqual(s3.name,"Bob Diana")
        self.assertEqual(s3.stud_id,"2")
        self.assertEqual(s3.group,"1")
        
    def testStudentRepoUpdate(self):
        #self.assertEqual(self.__stud_repo.students_length, 12)
        s2=Student(2, "Bob Alexandra Diana", 1)
        self.__stud_repo.update_student(s2)
        s3 = self.__stud_repo.find_student_by_id(2)
        self.assertEqual(s3.name,"Bob Alexandra Diana")
          
    def testStudentRepoRemove(self):
        #self.assertEqual(self.__stud_repo.students_length, 12)
        self.__stud_repo.remove_student_by_id(2)
        self.assertFalse(self.__stud_repo.find_id(2))
        #self.assertEqual(self.__stud_repo.students_length, 11)
        
    def testGradeRepoAddAssign(self):
        #self.assertEqual(self.__grade_repo.grades_length, 8)
        g = Grade(2,12,0,False)
        self.__grade_repo.add_assign(g)
        g = self.__grade_repo.getGrade(12)
        self.assertEqual(Grade.check(g),False)
        
    def testGradeRepoAddGrade(self):
        g = Grade(2,12,1,True) #grade the student no 12 at assignment no 2 with 1 points.
        self.__grade_repo.add_grade(g)
        g = self.__grade_repo.getGrade(9)
        self.assertEqual(g.stud_id,12)
        self.assertEqual(g.assign_id,2)
        self.assertEqual(g.grade,1)
        self.assertEqual(g.check,True)
    
    def testRemoveGrade(self):
        pass