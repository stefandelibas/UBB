'''
Created on Jan 3, 2017

@author: Stefan
'''
import pickle
from repository.Assignment_repository import Assignment_repository

class AssignmentPickleFileRepository(Assignment_repository):
    def __init__(self,fileName="C:\\Users\\Stefan\\workspace2\\StudentsAssignments\\assignments.pickle"):
        Assignment_repository.__init__(self)
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
                Assignment_repository.add_assignment(self, line)
            f.close()
        
        
        return result
        
    def __storeToFile(self):
        f = open(self.__fName, "wb")
        pickle.dump(Assignment_repository.list_all_assignments(self), f)
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
        