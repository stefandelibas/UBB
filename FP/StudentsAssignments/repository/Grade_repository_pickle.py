'''
Created on Jan 3, 2017

@author: Stefan
'''
import pickle
from repository.Grade_repository import Grade_repository

class GradePickleFileRepository(Grade_repository):
    def __init__(self,stud_repo,assign_repo,fileName="C:\\Users\\Stefan\\workspace2\\StudentsAssignments\\grades.pickle"):
        Grade_repository.__init__(self,stud_repo,assign_repo)
        self.__fName = fileName
        self.__loadFromFile()
        
    def __loadFromFile(self):
        
        """
        You cannot unpickle an empty file
            - EOFError means the file is empty
            - Exception means no file, not accessible and so on...
            - finally makes sure we close the input file, regardless of error
        """
        
        """
        f = open(self.__fName, "rb")
        try:
            self._data = pickle.load(f)
        except EOFError:
            self._data = []
        except Exception as e:
            raise e
        finally:
            f.close()
        """
        result = []
        try:
            f = open(self.__fName, "rb")
            entities = pickle.load(f)
        except EOFError:
            """
                This is raised if input file is empty
            """
            return []
        except IOError as e:
            """
                Here we 'log' the error, and throw it to the outer layers 
            """
            print("An error occured - " + str(e))
            raise e
        finally:
            for line in entities:
                Grade_repository.add_assign(self, line)
            f.close()
        
        return result

    def __storeToFile(self):
        f = open(self.__fName, "wb")
        pickle.dump(Grade_repository.list_all_grades(self), f)
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
    