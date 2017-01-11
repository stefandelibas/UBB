'''
Created on Dec 6, 2016

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
        loadData( self.__stud_ctrl, self.__assign_ctrl, self.__grade_ctrl)
        
    def testAssignDomain(self):
        a = Assignment(3,"Solve ex 11 to 15","5.12.2017",2)
        assign_id = a.assign_id
        self.assertEqual(assign_id,3)
        description = a.description
        self.assertEqual(description,"Solve ex 11 to 15","5.12.2017")
        grade = a.grade
        self.assertEqual(grade,2)
        a.assign_id = 4
        self.assertEqual(a.assign_id,4)
        a.description = "Solve ex 12 to 15"
        self.assertEqual(a.description,"Solve ex 12 to 15")
        a.grade = 3
        self.assertEqual(a.grade,3)
        
    def testStudDomain(self):
        s = Student(1, "Delibas Stefan", 1)
        name = s.name
        self.assertEqual(name,"Delibas Stefan")
        stud_id = s.stud_id
        self.assertEqual(stud_id,1)
        group = s.group
        self.assertEqual(group,1)
        s.stud_id = 2
        self.assertEqual(s.stud_id,2)
        s.name = "Delibas Stefaaan"
        self.assertEqual(s.name,"Delibas Stefaaan")
        s.group = 2
        self.assertEqual(s.group,2)
        
    def testGradeDomain(self):
        g = Grade(1,1,1,True)
        assign_id = g.assign_id
        self.assertEqual(assign_id,1)
        stud_id = g.stud_id
        self.assertEqual(stud_id,1)
        grade = g.grade
        self.assertEqual(grade,1)
        check = g.check
        self.assertTrue(check)
        g.assign_id = 2
        self.assertEqual(g.assign_id,2)
        g.stud_id = 2
        self.assertEqual(g.stud_id,2)
        g.grade = 2
        self.assertEqual(g.grade,2)