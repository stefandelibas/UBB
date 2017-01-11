'''
Created on Jan 11, 2017

@author: Stefan
'''
from copy import deepcopy
class Stack:
    def __init__(self):
        self.__arr=[]
 
    def push(self,val):
        self.__arr.append(val)
 
    def empty(self): 
        return (len(self.__arr)==0)
 
    def top(self): 
        return self.__arr[ len(self.__arr) -1 ]
 
    def __len__(self):
        return len(self.__arr)
 
    def pop(self): 
        return self.__arr.pop()
 
def backtracking_it(arr):
    sgn=[0]*(len(arr)+1)
    st=Stack()
    st.push( [1,deepcopy(sgn)] )
    cnt=0
    while(st.empty()==False):
        x=st.top()
        st.pop()
        step=x[0]
        sgn=x[1]
        if( step==len(arr) ):
            if(computeSum(arr,sgn) > 0):
                for i in range(0,len(arr)):
                    if(i!=0):
                        print(sgn[i],end="")
                    print(arr[i],end="")
                cnt+=1
                print()
            continue
        sgn[step]='+'
        st.push( [step+1, deepcopy(sgn)] )
        sgn[step]='-'
        st.push( [step+1, deepcopy(sgn)] )
    #print("Number of solutions is:"+str(cnt))
 
 
 
def computeSum(arr,sgn):
    sum=arr[0]
    for i in range(1,len(arr)):
        if(sgn[i]=='+'):
            sum+=arr[i]
        else:
            sum-=arr[i]
    return sum

def backtracking(step,arr,sgn):
    if( step==len(arr) ):
        if(computeSum(arr,sgn) > 0):
            for i in range(0,len(arr)):
                if(i!=0):
                    print(sgn[i],end="")
                print(arr[i],end="")
            i+=1
            print()
        return
    sgn[step]='-'
    backtracking(step+1,arr,sgn)
    sgn[step]='+'
    backtracking(step+1,arr,sgn)
arr=[1,2,3,4,5]
sgn=[0]*6

print("Iterativ:")
backtracking_it(arr)

print("Recursiv:")
backtracking(1,arr,sgn)
