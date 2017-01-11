'''
Created on Nov 5, 2016

@author: Stefan
'''

class Menu:
    def __init__(self, stud_ctrl, assign_ctrl, grade_ctrl, undo_ctrl):
        '''
        Constructor
        '''
        self.__stud_ctrl = stud_ctrl
        self.__assign_ctrl = assign_ctrl
        self.__grade_ctrl = grade_ctrl
        self.__undoController = undo_ctrl
    
    def __ui_read_command(self,request):
        print(request)
        return input()
    
    def __ui_add(self):
        while True:
            cmds_list = {"1":self.__ui_add_student, "2":self.__ui_add_assignment, "3":self.__ui_add_grade}
            com_list = ["1","2","3","4"]
            cmd = self.__ui_read_command("Type"+"\n"+"1 - to add student"+"\n"+"2 - to add assignment"+"\n"+"3 - to add grade"+"\n"+"4 - to go back")
            if cmd in com_list:
                if cmd == "4":
                    return
                else:
                    cmds_list[cmd]()
                    return
            else:
                print("Invalid input!\n")
                return
            
    def __ui_add_student(self):
        stud_id = self.__ui_read_command("Insert student ID: ")
        try:
            stud_id = int(stud_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        name = self.__ui_read_command("Insert student name: ")
        group = self.__ui_read_command("Insert student group: ")
        try:
            group = int(group)
        except ValueError as ve:
            ve="The group must be a positive integer!\n"
            print(ve)
            return 0
        self.__undoController.newOperation()
        self.__stud_ctrl.add_student(stud_id, name, group)
        print("We added ",name," successfully.")
            
    def __ui_add_assignment(self):
        assign_id = self.__ui_read_command("Insert assignment ID: ")
        try:
            assign_id = int(assign_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        description = self.__ui_read_command("Insert assignment description: ")
        deadline = self.__ui_read_command("Insert assignment deadline: ")
        grade = self.__ui_read_command("Insert assignment grade: ")
        try:
            grade = int(grade)
        except ValueError as ve:
            ve="The grade must be a positive integer!\n"
            print(ve)
            return 0
        if int(grade) < 1 or int(grade) > 10:
            print("The grade must be between 1 and 10!\n")
            return 0
        self.__undoController.newOperation()
        self.__assign_ctrl.add_assignment(assign_id, description, deadline, grade)
        print("We added a new assignment successfully.")
        
    def __ui_add_grade(self):
        stud_id = self.__ui_read_command("Insert student ID: ")
        try:
            stud_id = int(stud_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        assign_id = self.__ui_read_command("Insert assignment ID: ")
        try:
            assign_id = int(assign_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        grade = self.__ui_read_command("Insert assignment grade: ")
        try:
            grade = int(grade)
        except ValueError as ve:
            ve="The grade must be a positive integer!\n"
            print(ve)
            return 0
        if int(grade) < 1 or int(grade) > 10:
            print("The grade must be between 1 and 10!\n")
            return 0
        self.__undoController.newOperation()
        self.__grade_ctrl.add_grade(assign_id, stud_id, grade)
        print("We added associated a new grade to the student no "+str(stud_id)+" successfully.")
    
    def __ui_remove(self):
        while True:
            cmds_list = {"1":self.__ui_remove_student_by_id, "2":self.__ui_remove_assign_by_id}
            com_list = ["1","2","3"]
            cmd = self.__ui_read_command("Type 1 - to remove student"+"\n"+"2 - to remove assignment"+"\n"+"3 - to go back")
            if cmd in com_list:
                if cmd == "3":
                    return
                else:
                    cmds_list[cmd]()
                    return
            else:
                print("Invalid input!\n")
                return
        
    def __ui_remove_student_by_id(self):
        stud_id = self.__ui_read_command("Insert student ID..")   
        try:
            stud_id = int(stud_id)
        except ValueError as ve:
            ve = "ID must be a positive integer!\n"
            print(ve)
            return 0
        
        save_list = self.__grade_ctrl.remove_grade_by_id_s(stud_id)
        self.__undoController.newOperation()
        self.__stud_ctrl.remove_student_by_id(stud_id)
        self.__grade_ctrl.recordOperationsForAssign(save_list)
        
    def __ui_remove_assign_by_id(self):
        assign_id = self.__ui_read_command("Insert assign ID..")   
        try:
            assign_id = int(assign_id)
        except ValueError as ve:
            ve = "ID must be a positive integer!\n"
            print(ve)
            return 0
        save_list = self.__grade_ctrl.remove_grade_by_id_a(assign_id)
        self.__undoController.newOperation()
        self.__assign_ctrl.remove_assignment_by_id(assign_id)
        self.__grade_ctrl.recordOperationsForAssign(save_list)
    def __ui_update(self):
        while True:
            cmds_list = {"1":self.__ui_update_student, "2":self.__ui_update_assignment}
            com_list = ["1","2","3"]
            cmd = self.__ui_read_command("Type"+"\n"+"1 - to update student"+"\n"+"2 - to update assignment"+"\n"+"3 - to go back")
            if cmd in com_list:
                if cmd == "3":
                    return
                else:
                    cmds_list[cmd]()
                    return
            else:
                print("Invalid input!\n")
                return
            
    def __ui_update_student(self):
        stud_id = self.__ui_read_command("Insert student ID: ")
        try:
            stud_id = int(stud_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        name = self.__ui_read_command("Insert student name: ")
        group = self.__ui_read_command("Insert student group: ")
        try:
            group = int(group)
        except ValueError as ve:
            ve="The group must be a positive integer!\n"
            print(ve)
            return 0
        self.__undoController.newOperation()
        self.__stud_ctrl.update_student(stud_id, name, group)

    def __ui_update_assignment(self):
        assign_id = self.__ui_read_command("Insert assignment ID: ")
        try:
            assign_id = int(assign_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        description = self.__ui_read_command("Insert assignment description: ")
        deadline = self.__ui_read_command("Insert assignment deadline: ")
        grade = self.__ui_read_command("Insert assignment grade: ")
        try:
            grade = int(grade)
        except ValueError as ve:
            ve="The grade must be a positive integer!\n"
            print(ve)
            return 0
        self.__undoController.newOperation()
        self.__assign_ctrl.update_assignment(assign_id, description, deadline)
        
    def __print_list(self,l):
        for element in l:
            print(element)                  
                                                        
    def __ui_list(self):
        while True:
            cmds_list = {"1":self.__ui_list_students, "2":self.__ui_list_assignments,"3":self.__ui_list_grades}
            com_list = ["1","2","3","4"]
            cmd = self.__ui_read_command("Type"+"\n"+"1 -  to list students"+"\n"+"2 - to list assignment"+"\n"+"3 - to list grades"+"\n"+"4 - to go back")
            if cmd in com_list:
                if cmd == "4":
                    return
                else:
                    cmds_list[cmd]()
            else:
                print("Invalid input!\n")
                return
            
    def __ui_list_students(self):
        self.__print_list(self.__stud_ctrl.list_all_students())
        
    def __ui_list_assignments(self):
        self.__print_list(self.__assign_ctrl.list_all_assignments())
        
    def __ui_list_grades(self):
        self.__print_list(self.__grade_ctrl.list_all_grades())
        
         
    def __ui_give_assign(self):
        cmds_list = {"1":self.__ui_assign_group, "2":self.__ui_assign_stud}
        com_list = ["1","2","3"]
        cmd = self.__ui_read_command("Type"+"\n"+"1 -  to give an assignment to a group of students"+"\n"+"2 - to give an assignment to a students"+"\n"+"3 - to go back")
        if cmd in com_list:
                if cmd == "3":
                    return
                else:
                    cmds_list[cmd]()
        else:
            print("Invalid input!\n")
            return
    def __ui_assign_group(self):
        group = self.__ui_read_command("Insert group number : ")
        try:
            group = int(group)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        assign_id = self.__ui_read_command("Insert assignment ID: ")
        try:
            assign_id = int(assign_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        self.__undoController.newOperation()
        self.__grade_ctrl.give_assign_group(assign_id, group)
        print("We assigned to the students from group no "+str(group)+" the assignment no "+str(assign_id)+" successfully.")
    def __ui_assign_stud(self):
        stud_id = self.__ui_read_command("Insert student ID: ")
        try:
            stud_id = int(stud_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        assign_id = self.__ui_read_command("Insert assignment ID: ")
        try:
            assign_id = int(assign_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        self.__undoController.newOperation()
        self.__grade_ctrl.give_assign(assign_id, stud_id,0,False)
        print("We assigned to the student no "+str(stud_id)+" the assignment no "+str(assign_id)+" successfully.")
    def __ui_stats(self): 
        cmds_list = {"1":self.__ui_stud_per_assign, "2":self.__ui_late_stud,"3":self.__ui_best_students,"4":self.__ui_best_assign}
        com_list = ["1","2","3","4","5"]
        cmd = self.__ui_read_command("Type"+"\n"+"1 -  provide all students on an assignment"+"\n"+"2 -  provide all students who are late"+"\n"+"3 - best students"+"\n"+"4 - provide stats on assignments"+"\n"+"5 - to go back")
        if cmd in com_list:
                if cmd == "5":
                    return
                else:
                    cmds_list[cmd]()
        else:
            print("Invalid input!\n")
            return
    def __ui_stud_per_assign(self):
        assign_id = self.__ui_read_command("Insert assign number : ")
        sort_method =self.__ui_read_command("Insert the method:1 - alphabetically 2 - by the average")
        try:
            assign_id = int(assign_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        try:
            sort_method = int(sort_method)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        stud_list = self.__grade_ctrl.stud_per_assign(assign_id, sort_method)
        for stud in stud_list:
            print(str(stud.stud_id)+" "+stud.name+" from group "+str(stud.group))
        #self.__print_list(stud_list)
    def __ui_late_stud(self):
        stud_list = self.__grade_ctrl.late_stud()
        self.__print_list(stud_list)  
    def __ui_best_students(self):
        stud_list = self.__grade_ctrl.best_students()
        for stud in stud_list:
            print(stud[0]+" with average "+str(stud[1]))
    def __ui_best_assign(self):
        assign_list = self.__grade_ctrl.best_assign()
        for assign in assign_list:
            print("Assignment no "+str(assign[0])+" with average "+str(assign[1]))
    def __ui_undo(self):
        self.__undoController.undo()
    def __ui_redo(self):
        self.__undoController.redo()
        
    def __ui_showGivenID(self):
        stud_id = self.__ui_read_command("Insert student ID: ")
        try:
            stud_id = int(stud_id)
        except ValueError as ve:
            ve="The ID must be a positive integer!\n"
            print(ve)
            return 0
        res = self.__grade_ctrl.showGivenID(stud_id)
        for e in res:
            print(e)
    def ui_run(self):
        print("Wellcome!")
        while True:
            cmds_list = {"1":self.__ui_add, "2":self.__ui_remove, "3":self.__ui_update, "4":self.__ui_list, "5":self.__ui_give_assign,"6":self.__ui_stats,"7":self.__undoController.undo,"8":self.__ui_redo,"9":self.__ui_showGivenID}
            com_list = ["1","2","3","4","5","6","7","8","9"]
            cmd = self.__ui_read_command("Type"+"\n"+"1 - to add"+"\n"+"2 - to remove"+"\n"+"3 - to update"+"\n"+"4 - to list"+"\n"+"5 - give assignments"+"\n"+"6 - give stats"+"\n"+"7 - undo"+"\n"+"8 - redo"+"\n"+"9 -s show all grades by a given ID"+"\n"+"100 -to exit")
            if cmd in com_list:
                if cmd == "100":
                    print("Thanks for using my app! :)\n")
                    return
                else:
                    cmds_list[cmd]()
            else:
                print("Invalid command!\n")
                
                
                