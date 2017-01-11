'''
Created on Dec 12, 2016

@author: Stefan
'''
from controller.UndoController import FunctionCall, Operation
from controller.Student_controller import Student_controller

class StudentControllerWithUndo(Student_controller):
    def __init__(self, undoController,grades_ctrl,Student_repository):
        Student_controller.__init__(self,Student_repository)
        self._grades_ctrl = grades_ctrl
        self._undoController = undoController
    def add_student(self,stud_id,name,group):
        stud = Student_controller.add_student(self,stud_id,name,group)
        redo = FunctionCall(self.add_student,stud.stud_id,stud.name,stud.group)
        undo = FunctionCall(self.remove_student_by_id,stud_id)
        operation = Operation(redo,undo)
        self._undoController.recordOperation(operation)
        return stud
    
    def remove_student_by_id(self,stud_id):
        stud = Student_controller.remove_student_by_id(self,stud_id)
        redo = FunctionCall(self.remove_student_by_id,stud_id)
        undo = FunctionCall(self.add_student,stud_id,stud.name,stud.group)
        operation = Operation(redo, undo)
        self._undoController.recordOperation(operation)
        return stud
    
    def update_student(self,stud_id,name,group):
        old_stud,stud = Student_controller.update_student(self,stud_id,name,group)
        redo = FunctionCall(self.update_student,stud.stud_id,stud.name,stud.group)
        undo = FunctionCall(self.update_student,old_stud.stud_id,old_stud.name,old_stud.group)
        operation = Operation(redo, undo)
        self._undoController.recordOperation(operation) 
        return old_stud,stud
     
    