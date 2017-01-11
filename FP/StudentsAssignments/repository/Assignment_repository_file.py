'''
Created on Dec 18, 2016

@author: Stefan
'''

from domain.Assignment import Assignment
from repository.Assignment_repository import Assignment_repository

class AssignemntFileRepository(Assignment_repository):
    def __init__(self, fileName="C:\\Users\\Stefan\\workspace2\\StudentsAssignments\\assignments.txt"):
            Assignment_repository.__init__(self)
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
            assign = Assignment(attrs[0], attrs[1],attrs[2],attrs[3])
            Assignment_repository.add_assignment(self, assign)
            line = f.readline().strip()
        f.close()
    def __storeToFile(self):
        """
         Store all the students  in to the file
         raise CorruptedFileException if we can not store to the file
        """
        # open file (rewrite file)
        f = open(self.__fName, "w")
        assignments = Assignment_repository.list_all_assignments(self)
        for assign in assignments:
            strf = str(assign.assign_id) + ";" + assign.description + ";" + assign.deadline + ";" +  str(assign.grade) + ";"
            strf = strf + "\n"
            f.write(strf)
        f.close()
    def add_assignment(self,assign):
        Assignment_repository.add_assignment(self,assign)
        self.__storeToFile()
        
    def remove_assignment_by_id(self,assign_id):
        Assignment_repository.remove_assignment_by_id(self,assign_id)
        self.__storeToFile()
        
    def update_assignment(self,assign):
        Assignment_repository.update_assignment(assign)
        self.__storeToFile()
        
    