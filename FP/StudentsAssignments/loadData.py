'''
Created on Nov 20, 2016

@author: Stefan
'''

from controller.Assignment_controller import Assignment_controller
from repository.Grade_repository import Grade_repository
from controller.Grade_controller import Grade_controller
from controller.Grade_controller import Grade_controller
from datetime import datetime

def loadData(stud_ctrl,assign_ctrl,grade_ctrl,undo_ctrl):
    undo_ctrl.newOperation()
    stud_ctrl.add_student(1, "Delibas Stefan", 1)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(2, "Bob Diana", 1)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(3, "Acatrinei Andreea", 1)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(4, "Mircea Sorin", 2)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(5, "Fratila Matei", 2)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(6, "Nechita Sebastian", 2)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(7, "Banciu Raul", 3)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(8, "Nicula Andrei", 3)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(9, "Artene Dragos", 3)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(10, "Rusan Tudor:", 3)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(11, "Marius Imbrisca", 4)
    undo_ctrl.newOperation()
    stud_ctrl.add_student(12, "Bogdan Acsinia", 4)
    
    undo_ctrl.newOperation()
    assign_ctrl.add_assignment(1,"Solve ex 1 to 5",datetime.strptime("2016-12-5", "%Y-%m-%d"),2)
    undo_ctrl.newOperation()
    assign_ctrl.add_assignment(2,"Solve ex 6 to 10",datetime.strptime("2016-10-10", "%Y-%m-%d"),3)
    
    undo_ctrl.newOperation()
    grade_ctrl.give_assign(1,1,0,False)
    undo_ctrl.newOperation()
    grade_ctrl.give_assign(1,2,0,False)
    undo_ctrl.newOperation()
    grade_ctrl.give_assign(2,1,0,False)
    undo_ctrl.newOperation()
    grade_ctrl.give_assign(2,2,0,False)
    undo_ctrl.newOperation()
    grade_ctrl.give_assign(2,3,0,False)
    undo_ctrl.newOperation()
    grade_ctrl.give_assign(2,4,0,False)
    undo_ctrl.newOperation()
    grade_ctrl.give_assign(1,5,0,False)
    undo_ctrl.newOperation()
    grade_ctrl.give_assign(2,5,0,False)
    undo_ctrl.newOperation()
    grade_ctrl.give_assign(2,10,0,False)
    
    undo_ctrl.newOperation()
    grade_ctrl.add_grade(1,1,1)
    undo_ctrl.newOperation()
    grade_ctrl.add_grade(1,2,0)
    undo_ctrl.newOperation()
    grade_ctrl.add_grade(2,1,2)
    undo_ctrl.newOperation()
    grade_ctrl.add_grade(2,2,1.7)
    undo_ctrl.newOperation()
    grade_ctrl.add_grade(2,3,2)
    undo_ctrl.newOperation()
    grade_ctrl.add_grade(2,4,0)
    undo_ctrl.newOperation()
    grade_ctrl.add_grade(1,5,2)
    undo_ctrl.newOperation()
    grade_ctrl.add_grade(2,5,1.5)    
