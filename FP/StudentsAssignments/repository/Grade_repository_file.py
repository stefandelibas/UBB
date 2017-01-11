'''
Created on Dec 18, 2016

@author: Stefan
'''

from repository.Grade_repository import Grade_repository
from domain.Grade import Grade

class GradeFileRepository(Grade_repository):
    def __init__(self,stud_repo,assign_repo,fileName="C:\\Users\\Stefan\\workspace2\\StudentsAssignments\\grades.txt"):
            Grade_repository.__init__(self,stud_repo,assign_repo)
            self.__fName = fileName
            self.__loadFromFile()
            
            
    def __loadFromFile(self):
        """
          Load students from file
          raise CorruptedFileException if there is an error when reading from the file
        """
        try:
            f = open(self.__fName, "r")
        except IOError:
            # file not exist
            return
        line = f.readline().strip()
        while line != "":
            attrs = line.split(";")
            print(attrs[0],attrs[1],attrs[2],attrs[3])
            assign = Grade(attrs[0],attrs[1],attrs[2],bool(attrs[3]))
            Grade_repository.add_assign(self, assign)
            line = f.readline().strip()
        f.close()
        
    def __storeToFile(self):
        """
         Store all the students  in to the file
         raise CorruptedFileException if we can not store to the file
        """
        # open file (rewrite file)
        f = open(self.__fName, "w")
        grades = Grade_repository.list_all_grades(self)
        for grade in grades:
            strf = str(grade.assign_id) + ";" + str(grade.stud_id) + ";" + str(grade.grade) + ";" +  str(grade.check) + ";"
            strf = strf + "\n"
            f.write(strf)
        f.close()
        
    def give_assign(self, assign):
        Grade_repository.give_assign(self, assign)
        self.__storeToFile()
        
    def add_assign(self, grade):
        Grade_repository.add_assign(self, grade)
        self.__storeToFile()
    
    def add_grade(self, grade):
        Grade_repository.add_grade(self, grade)
        self.__storeToFile()
        
    def remove_assign_a(self, assign_id):
        Grade_repository.remove_assign_a(self, assign_id)
        self.__storeToFile()
        
    def remove_assign_s(self, stud_id):
        return Grade_repository.remove_assign_s(self, stud_id)
        self.__storeToFile()
        
    def give_assign_group(self, assign_id, group, grade):
        Grade_repository.give_assign_group(self, assign_id, group, grade)
        self.__storeToFile()
    
