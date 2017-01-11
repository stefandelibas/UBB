'''
Created on Nov 5, 2016

@author: Stefan
'''
from domain.Student import Student

class Student_repository:
    def __init__(self):
        '''
        Constructor
        '''
        self.__students = {}
    
    def getStudent(self,index):
        return self.__students[index]
    
    def find_id(self,stud_id):
        """
        finds a student by id 
        input: an student id
        output: True if it exists
                False otherwise
        """
        found = False
        for stud in self.__students.values():
            if int(stud.stud_id)  == int(stud_id):
                found = True
        return found
    """
    def give_group(self,group):
        gr=[]
        for stud in self.__students:
            if self.__students[stud.stud_id].group == group:
                gr.append(stud)
        return gr
    """
    def add_student(self,stud):
        """
        adds a student to the list of students if the id is unique
        input: an student with all its attributes(id,name,group,name)
        output: the list of students with the new student added        
        """
        if stud.stud_id in self.__students:
            print("Student ID is already taken!")
        else:
            self.__students[stud.stud_id] = stud
              
    def update_student(self,stud):
        """"
        updates a student from the list of students if there exists the assignment in the list
        input: an assignment with all its attributes(id,description,deadline,grade)
        output: the list of students with the updated assignment       
        """
        if stud.stud_id not in self.__students:
            print("This student ID does not belong to a student!")
        else:
            self.__students[stud.stud_id] = stud
     
    def remove_student(self,stud):
        """
        removes a student 
        """
        if stud.stud_id not in self.__students:
            print("This student ID does not belong to a student!")
        elif stud.name not in self.__students:
            print("This student name does not belong to a student!\n")
        elif stud.group not in self.__students:
            print("This group does not exist/contain any students!\n")
        else:
            del self.__students[stud.stud_id]
  
    def remove_student_by_id(self,stud_id):
        if stud_id not in self.__students:
            print("This student ID does not belong to a student!")
        else:
            del self.__students[stud_id]   
     
    def find_student_by_id(self,stud_id):
        ok = False
        for stud in self.__students.values():
            if stud.stud_id == stud_id:
                ok = True
        if ok == False:
            print("Invalid Id!")
        else:
            return self.__students[stud_id]  
    
    def list_all_students(self):
        stud_list=[]
        for stud in self.__students.values():
            stud_list.append(stud)
        return stud_list
    
    
    def students_length(self):
        return len(self.__students)
    
    def __add_student__(self,stud):
        self.add_student(stud)
        
    def __update_student__(self,stud):
        self.update_student(stud)
        
    def __remove_student__(self,param):
        if type(param) is int:
            self.remove_student_by_id(param)    
        if type(param) is Student:
            self.remove_student(param)
                         
    def __find_student__(self,stud_id):
        return self.find_student_by_id(stud_id)          
    
    def __list_all_students__(self):
        return self.list_all_students() 