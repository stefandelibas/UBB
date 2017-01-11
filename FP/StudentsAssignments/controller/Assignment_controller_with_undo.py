'''
Created on Dec 11, 2016

@author: Stefan
'''
from controller.UndoController import FunctionCall, Operation
from controller.Assignment_controller import Assignment_controller

class AssignmentControllerWithUndo(Assignment_controller):
    def __init__(self, undoController,grades_ctrl,Assignment_repository):
        Assignment_controller.__init__(self,Assignment_repository)
        self._grades_ctrl = grades_ctrl
        self._undoController = undoController
        
    def add_assignment(self,assign_id,description,deadline,grade):
        assign = Assignment_controller.add_assignment(self,assign_id,description,deadline,grade)
        redo = FunctionCall(self.add_assignment,assign.assign_id,assign.description,assign.deadline,assign.grade)
        undo = FunctionCall(self.remove_assignment_by_id, assign_id)
        operation = Operation(redo, undo)
        self._undoController.recordOperation(operation)   
        return assign
    
    def remove_assignment_by_id(self,assign_id):
        assign = Assignment_controller.remove_assignment_by_id(self,assign_id)
        redo = FunctionCall(self.remove_assignment_by_id,assign_id)
        undo = FunctionCall(self.add_assignment,assign_id,assign.description,assign.deadline,assign.grade)
        operation = Operation(redo, undo)
        self._undoController.recordOperation(operation)   
        return assign
    
    def update_assignment(self,assign_id,description,deadline,grade):
        old_assign,new_assign = Assignment_controller.update_assignment(assign_id,description,deadline,grade)

        redo = FunctionCall(self.update,new_assign.assign_id,new_assign.description,new_assign.deadline,new_assign.grade)
        undo = FunctionCall(self.update,old_assign.assign_id,old_assign.description,old_assign.deadline,old_assign.grade)
        operation = Operation(redo, undo)
        self._undoController.recordOperation(operation)   
        return old_assign,new_assign
    
