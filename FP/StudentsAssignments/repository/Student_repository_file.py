'''
Created on Dec 18, 2016

@author: Stefan
'''
from domain.Student import Student
from repository.Student_repository import Student_repository

class StudentFileRepository(Student_repository):
    def __init__(self, fileName="C:\\Users\\Stefan\\workspace2\\StudentsAssignments\\students.txt"):
            Student_repository.__init__(self)
            self.__fName = fileName
            self.__loadFromFile()
        
    def __loadFromFile(self):
        """
          Load students from file
          raise CorruptedFileException if there is an error when reading from the file
        """
        """
        try:
            f = open(self.__fName, "r")
        except IOError:
            # file not exist
            return
        """
        f = open(self.__fName, "r")
        line = f.readline().strip()
        while line != "":
            attrs = line.split(";")
            stud = Student(attrs[0], attrs[1],attrs[2])
            Student_repository.add_student(self, stud)
            line = f.readline().strip()
        f.close()
    def __storeToFile(self):
        """
         Store all the students  in to the file
         raise CorruptedFileException if we can not store to the file
        """
        # open file (rewrite file)
        f = open(self.__fName, "w")
        students = Student_repository.list_all_students(self)
        for stud in students:
            strf = str(stud.stud_id) + ";" + stud.name + ";" + str(stud.group) + ";"
            strf = strf + "\n"
            f.write(strf)
        f.close()
    def add_student(self,stud):
        Student_repository.add_student(self,stud)
        self.__storeToFile()
        
    def remove_student_by_id(self,stud_id):
        Student_repository.remove_student_by_id(self, stud_id)
        self.__storeToFile()
        
    def update_student(self,stud):
        Student_repository.update_student(self, stud)
        self.__storeToFile()
    