'''
Created on Nov 5, 2016

@author: Stefan
'''
from repository.Student_repository import Student_repository
from controller.Student_controller import Student_controller
from repository.Assignment_repository import Assignment_repository
from controller.Assignment_controller import Assignment_controller
from repository.Grade_repository import Grade_repository
from controller.Grade_controller import Grade_controller
from ui.Menu import Menu
from loadData import *
from controller.UndoController import UndoController
from controller.Assignment_controller_with_undo import AssignmentControllerWithUndo
from controller.Student_controller_with_undo import StudentControllerWithUndo
from controller.Grade_controller_with_undo import GradeControllerWithUndo
from repository.Assignment_repository_file import AssignemntFileRepository
from repository.Student_repository_file import StudentFileRepository
from repository.Grade_repository_file import GradeFileRepository
from repository.Assignment_repository_pickle import AssignmentPickleFileRepository
from repository.Student_repository_pickle import StudentPickleFileRepository
from repository.Grade_repository_pickle import GradePickleFileRepository
from config import Configurator

config = Configurator("c.txt")
mode = config.getMode()

print(mode)
if mode == "InMemory":
    stud_repo = Student_repository()
    assign_repo = Assignment_repository()
    grade_repo = Grade_repository(stud_repo,assign_repo)
elif mode == "TextFile":
    stud_repo = StudentFileRepository()
    assign_repo = AssignemntFileRepository()
    grade_repo = GradeFileRepository(stud_repo,assign_repo)
elif mode == "PickleFile":
    stud_repo = StudentPickleFileRepository()
    assign_repo = AssignmentPickleFileRepository()
    grade_repo = GradePickleFileRepository(stud_repo,assign_repo)
else:
    print("Error! The configuration file is corrupted")
 
grade_ctrl = Grade_controller(grade_repo,stud_repo,assign_repo)
undo_ctrl = UndoController() 
assign_ctrl = AssignmentControllerWithUndo(undo_ctrl,grade_ctrl,assign_repo)
stud_ctrl = StudentControllerWithUndo(undo_ctrl,grade_ctrl,stud_repo)
grade_ctrl = GradeControllerWithUndo(undo_ctrl,grade_repo,stud_repo,assign_repo)

if mode == "InMemory":
    loadData(stud_ctrl,assign_ctrl,grade_ctrl,undo_ctrl)
    
menu = Menu(stud_ctrl,assign_ctrl,grade_ctrl,undo_ctrl)
menu.ui_run()