'''
Created on Nov 5, 2016

@author: Stefan
'''
import datetime
from lab9.interableDS import IterableDS
from lab9.sort import filterBy

class Grade_repository:
    def __init__(self,stud_repo,assign_repo):
        '''
        Constructor
        '''
        self.__grades= IterableDS()
        self.__stud_repo = stud_repo
        self.__assign_repo = assign_repo
        
    def getGrade(self,index):
        return self.__grades[index] 
    
    
    def showGivenID(self,stud_id):
        res = filterBy(self.__grades, lambda x:(x.stud_id == stud_id))
        return res
    
    def add_assign(self,grade):
        stud_id = grade.stud_id
        assign_id = grade.assign_id
        if self.__stud_repo.find_id(stud_id) == False:
            print("The ID does not belong to a student!\n")
        elif self.__assign_repo.find_id(assign_id) == False:
            print("The ID does not belong to an assignment!\n")
        else:
            self.__grades.append(grade)
        
    def add_grade(self,grade):
        """
        gives a grade to a given student if it wasn't graded before and it is in the students list.
        """
        ok = 0
        for g in self.__grades:
            if g.stud_id == grade.stud_id and g.assign_id == grade.assign_id and g.check == False:
                g.check = True
                g.grade = grade.grade
                ok = 1 
        if ok == 0:
            print("Cannot grade this student.")   
                     
    def give_assign(self,assign):
        """
        gives assignments to students if they are not given already.
        """
        ok = 1
        for g in self.__grades:
            if assign.stud_id == g.stud_id and assign.assign_id == g.assign_id:
                print("Cannot assign to a student that already have that assignment.")
                ok=0
                return
        if ok == 1:
            self.add_assign(assign)
            
    def find_grade(self,assign_id,stud_id):
        for i in range(0,len(self.__grades)):
            if self.__grades[i].stud_id == stud_id and self.__grades[i].assign_id == assign_id:
                return i
        return False
    
    def remove_grade_by_both_IDs(self,assign_id,stud_id):
        if self.find_grade is not False:
            self.remove_grade(self.first_stud_index(stud_id))  
    
    def give_assign_group(self,assign_id,group,grade):
        """
        gives assignments to a group of students if they are not given already that assignment.
        """
        stud_list=[]
        for stud in self.__stud_repo.list_all_students():
            stud_list.append(stud)
        for stud in stud_list:
            if stud.group == group:
                grade.stud_id = stud.stud_id
                print("we assigned student no "+str(stud.stud_id)+" the assignment no "+str(assign_id))
                self.add_assign(grade) 
            
    
    def remove_assign_s(self,stud_id):
        """
        removes the assignment with the given student (by its ID)
        """
        save_list=[]
        while(self.first_stud_index(stud_id) is not False):
            save_list.append(self.__grades[self.first_stud_index(stud_id)])
            self.remove_grade(self.first_stud_index(stud_id))
        return save_list
    def remove_assign_a(self,assign_id):
        """
        removes the assignment with the given assignment (by its ID)
        """ 
        save_list=[]
        while(self.first_assign_index(assign_id) is not False):
            save_list.append(self.__grades[self.first_assign_index(assign_id)])
            self.remove_grade(self.first_assign_index(assign_id))
        return save_list 
    def first_stud_index(self,stud_id):
        for i in range(0,len(self.__grades)):
            if self.__grades[i].stud_id == stud_id:
                return i
        return False    
    def first_assign_index(self,assign_id):
        for i in range(0,len(self.__grades)):
            if self.__grades[i].assign_id == assign_id:
                return i
        return False
    def remove_grade(self,i):
        del self.__grades[i]

    def list_all_grades(self):
        """
        creates a list of all grades and returns it
        """
        grade_list=[]
        for grade in self.__grades:
            grade_list.append(grade)
        return grade_list
    
    def sortByGrade(self,list,assign_id):
        """
        sorts the list of students by their grade from a given assignment (by ID)
        """
        for i in range(0,len(list)-1):
            for g in self.__grades:
                if g.stud_id == list[i].stud_id and g.assign_id == assign_id:
                    g1=g.grade
            for j in range(i,len(list)):
                for g in self.__grades:
                    if g.stud_id == list[j].stud_id and g.assign_id == assign_id:
                        g2=g.grade
                if g1 <= g2:
                    list[i],list[j] = list[j],list[i]
        return list
    
    def stud_per_assign(self,assign_id,sort_method):
        """
        returns a list of students which has a given assignment
        """
        stud_list=[]
        for stud in self.__stud_repo.list_all_students():
            for g in self.__grades:
                if g.stud_id == stud.stud_id and g.assign_id == assign_id and g.check == True:
                    stud_list.append(stud)
        
        #stud_list = filterBy(self.__stud_repo.list_all_students(),lambda g:( g.stud_id == stud.stud_id and g.assign_id == assign_id and g.check == True))
        if  int(sort_method) == 2:
            #return stud_list.sort(key=self.__grades[2])
            return self.sortByGrade(stud_list,assign_id)
            #return sorted(stud_list,key=lambda g:g.grade)
        elif int(sort_method) == 1:
            return sorted(stud_list,key=lambda stud:stud.name)
            
       
        #return self.sortAlpha(stud_list)
    def late_stud(self):
        """
        returns the list of all students who are late on any assignments
        """
        stud_list=[]
        for stud in self.__stud_repo.list_all_students():
            for g in self.__grades:
                for assign in self.__assign_repo.list_all_assignments():
                    if g.stud_id == stud.stud_id and g.assign_id == assign.assign_id and g.check == False:
                        if assign.deadline < datetime.datetime.now():
                            stud_list.append(stud)
        return stud_list 
    def sortByAvg(self,avg_list):
        """
        sorts a list of average grades where the first element is a random element and the second one is the average
        """
        for i in range(0,len(avg_list)-1):
            for j in range(i,len(avg_list)):
                if avg_list[i][1] < avg_list[j][1]:
                    avg_list[i],avg_list[j] = avg_list[j],avg_list[i]
        return avg_list
    def best_students(self):
        """
        returns a list of students and their average grade on all assignments sorted descending by average
        """
        avg_list=[]
        for stud in self.__stud_repo.list_all_students():
            k=0
            s=0
            for g in self.__grades:
                for assign in self.__assign_repo.list_all_assignments():
                    if g.stud_id == stud.stud_id and g.assign_id == assign.assign_id and g.check == True:
                        s+=g.grade
                        k+=1
            if k!=0:
                avg_list.append([stud.name,s/k])
        avg_list = self.sortByAvg(avg_list)
        return avg_list
    def best_assign(self):
        """
        returns a list with the assignments and their average grade sorted descending by average
        """
        avg_list=[]
        for assign in self.__assign_repo.list_all_assignments():
            k=0
            s=0
            for g in self.__grades:
                if g.assign_id == assign.assign_id and g.check != False:
                    s+=float(g.grade)
                    k+=1
            if k != 0:
                avg_list.append([assign.assign_id,s/k])
        avg_list = self.sortByAvg(avg_list)
        return avg_list
    
    def grades_length(self):
        return len(self.__grades)
    
    def __add_grade__(self,grade):
        self.add_grade(grade)
      
    def __list_all_grades__(self):
        return self.list_all_grades()
