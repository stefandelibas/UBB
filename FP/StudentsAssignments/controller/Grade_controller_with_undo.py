'''
Created on Dec 13, 2016

@author: Stefan
'''
from controller.UndoController import FunctionCall, Operation
from controller.Grade_controller import Grade_controller

class GradeControllerWithUndo(Grade_controller):
    def __init__(self, undoController,Grade_repository,Student_repository,Assignmet_repository):
        Grade_controller.__init__(self,Grade_repository,Student_repository,Assignmet_repository)
        self._undoController = undoController
    def give_assign(self,assign_id,stud_id,grade,check):
        assign = Grade_controller.give_assign(self,assign_id,stud_id,0,False)
        redo = FunctionCall(self.give_assign,assign.assign_id,assign.stud_id)
        undo = FunctionCall(self.remove_grade,assign.assign_id,assign.stud_id)
        operation = Operation(redo,undo)
        self._undoController.recordOperation(operation)
        return assign
    def add_grade(self,assign_id,stud_id,grade):
        grade = Grade_controller.add_grade(self,assign_id,stud_id,grade)
        redo = FunctionCall(self.give_assign,grade.assign_id,grade.stud_id,grade.grade,True)
        undo = FunctionCall(self.remove_grade,grade.assign_id,grade.stud_id)
        operation = Operation(redo,undo)
        self._undoController.recordOperation(operation)
        return grade
    """
    def remove_grade_by_id_s(self,stud_id):
        save_list = Grade_controller.remove_grade_by_id_s(self,stud_id)
        for e in save_list:
            redo = FunctionCall(self.remove_grade,e.assign_id,e.stud_id)
            undo = FunctionCall(self.add_grade,e.assign_id,e.stud_id,e.grade)
            operation = Operation(redo,undo)
            self._undoController.recordOperation(operation)
    """
    """
    def remove_grade_by_id_a(self,assign_id):
        save_list = Grade_controller.remove_grade_by_id_a(self,assign_id)
        for e in save_list:
            redo = FunctionCall(self.remove_grade,e.assign_id,e.stud_id)
            undo = FunctionCall(self.add_grade,e.assign_id,e.stud_id,e.grade)
            operation = Operation(redo,undo)
            self._undoController.recordOperation(operation)
    """       
    def recordOperationsForAssign(self,save_list):
        for e in save_list:
            redo = FunctionCall(Grade_controller.remove_grade,self,e.assign_id,e.stud_id)
            undo = FunctionCall(Grade_controller.give_assign,self,e.assign_id,e.stud_id,e.grade,True)
            operation = Operation(redo,undo)
            self._undoController.recordOperation(operation)
        return save_list

        """
        assign =
        redo = FunctionCall(self.)
        undo = FunctionCall(self.)
        operation = Operation(redo,undo)
        self._undoController.recordOperation(operation)
        return assign
        """