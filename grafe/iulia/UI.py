'''
Created on 21 Mar 2017

@author: User
'''
from Graph.Domain import *
from asyncio.queues import PriorityQueue
def meniu():
    print("Hello!\n")
    print("1. Get the number of vertices")
    print("2. Find out if there is an edge between two vertices")
    print("3. Get the in degree of a vertex")
    print("4. Get the out degree of a vertex")
    print("5. Show the outbound edges of a vertex")
    print("6. Show the inbound edges of a vertex")
    print("7. Modify the cost of an edge")
    print("8. List all the edges")
    print("9. Remove an edge")
    print("10. Remove a vertex")
    print("11. Add an edge")
    print("12. Add a vertex")
    print("13. Show the cost of the edge (x,y)")
    print("14- Lowest length path")
    print("15-Minimum cost path")
    print("16-Kruskal")
    print("17-Hamiltoniam cycle")
    print("0. Exit")

def readCommand():
    n=int(input("Enter your command:"))
    #print(n)
    
    if int(n)>-1 and int(n)<18:
        
        return n
    else:
        return -1

class uiclass:
    def __init__(self,g):
        self._graph = g;
        
    def numberOfVerticesUI(self):
        l=self._graph.parseX()
        print("Here are the number of the vertices: ")
        print(len(l))
        
    def isEdgeUI(self):
        x=int(input("x:"))
        y=int(input("y:"))
        if self._graph._isOutKey(y) and self._graph._isInKey(x):
            t=self._graph.isEdge(x,y)
            if t == True:
                print("Yes, there is an edge")
            elif t == False:
                print("No, there is not an edge")
        else:
            print("Invalid x and y.")
            
    def removeAnEdgeUI(self):
        x=int(input("x:"))
        y=int(input("y:"))
        i = self._graph.removeEdge(x,y)
        if i:
            print("The edge was successfully removed.")
        else:
            print("The egde could not be removed.")
            
    def path(self):
        print("Input start vertice: ")
        start=int(input())
        print("Input ending vertice: ")
        end=int(input())
        next=self._graph.accesible(start,end)
        if next=={}:
            print("there is no path between ",start," and ",end)
        else:
            print(next)
            i=start
            while i!= end:
                print(i,"-",next[i])
                i=next[i]
             
    def minCostPath(self):
        print("Input start vertice: ")
        start=int(input())
        print("Input ending vertice: ")
        end=int(input())
        di=self._graph.MatrixMultiplication(start,end)
        print("the minimum cost path: ")
        print(di[end]);
                       
    def FolydWarshall(self):
        matr=self._graph.MatrixMade()
        l=self._graph.MatrixMultiplication(matr)
        m=1
        n=len(self._graph.parseX())
        while m<n-1:
            l=self._graph.MatrixMultiplication(l)
            m=m+1
        for i in range (0,n):
            print(l[i])
        print("Input start vertice: ")
        start=int(input())
        print("Input ending vertice: ")
        end=int(input())  
        print (l[start][end]) 
        
        
    def kruskal(self):
        #n- nr de vertexuri
        #m-nr de edgeuri
        matr=self._graph.Structure()
        print(matr)
        f=()
     
        n=len(self._graph.parseX())
        print(n)
        ceva=len(matr)
        l=[0]*(n+1)
        for i in range (1,n+1):
            l[i]=i
        print(matr)
        for i in range(0,ceva):
            for j in range(i+1,ceva):
                if matr[i][2]>matr[j][2]:
                    f=matr[i]
                    matr[i]=matr[j]
                    matr[j]=f
        k=0
        ct=0
        i=1
        aux = DoubleDictGraph("new.txt",10)
        while k<n-2:
    
            if l[matr[i][0]]!=l[matr[i][1]]:
                k=k+1
                ct=ct+matr[i][2]
                for j in range (1,n):
                    if l[j]==l[matr[i][0]]:
                        l[j]=l[matr[i][1]]
                print(matr[i])
                aux.addVertex(matr[i][0])
                aux.addVertex(matr[i][1])
                aux.addEdge(matr[i][0], matr[i][1], matr[i][2])
            i=i+1
        print("Total cost: ",ct)
        return aux
        
    def hamilton(self):
        start=int(input("Input starting vertex:"))
        cycle = []
        mst = self.kruskal()
        cycle = self._graph.Hamilton(mst,start)
        print("The cycle is: ",end='')
        totalCost = 0
        for i in range(len(cycle)):
            print(cycle[i]," ",end='')
        for i in range(len(cycle)-1):
            totalCost += self._graph._getCost(cycle[i],cycle[i+1])   
        print("Total cost",totalCost)     
    
    
    def removeAVertexUI(self):
        x=int(input("x:"))
        i = self._graph.removeVertex(x)
        if i:
            print("The vertex was successfully removed.")
        else:
            print("The vertex could not be removed.x is not a vertex.")
    
    def addAVertexUI(self): 
        x=int(input("x:"))
        i = self._graph.addVertex(x)
        if i:
            print("The vertex was added successfully.")
            
        else:
            print("The vertex could not be added. Error! x is already a vertex")
    def addAnEdgeUI(self):
        x=int(input("x:"))
        y=int(input("y:"))
        cost=int(input("cost:"))
        i = self._graph.addEdge(x,y,cost)
        if i:
            print("The edge was added successfully.")
        else:
            print("The edge could not be added. Error! the vertices are not valid.")
            
    def parseInDegreeUI(self):
        x=int(input("x:"))
        if self._graph._isInKey(x):
            l=self._graph.parseNin(x)
            if(len(l)==0):
                print("The vertex ",x,"is isolated.")
            else:
                print("The IN degree of ",x," is: ",len(l))
        else:
            print("Invalid x.")
        
    def parseOutDegreeUI(self):
        x=int(input("x:"))
        if self._graph._isInKey(x):
            l=self._graph.parseNout(x)
            if(len(l)==0):
                print("The vertex ",x,"is isolated.")
            else:
                print("The OUT degree of ",x," is: ",len(l))
        else:
            print("Invalid x")
        
    def parseNinUI(self):
        x=int(input("x:"))
        if not self._graph._isOutKey(x):
            print("The vertex does not exist")
        else:
            l=self._graph.parseNin(x)
            print("Here are the inbound edges of ",x,": ")
            for i in l:
                print (x," ",i)
                
    def parseNoutUI(self):
        x=int(input("x:"))
        if not self._graph._isInKey(x):
            print("The vertex does not exist")
        else:
            l=self._graph.parseNout(x)
            print("Here are the outbound edges of ",x,": ")
            for i in l:
                print (x," ",i)
            
    def changeCostUI(self):
        x=int(input("x:"))
        y=int(input("y:"))
        newcost=int(input("new cost:"))
        if self._graph._isOutKey(y) and self._graph._isInKey(x):
            f=self._graph.chageCost(x,y,newcost)
            if f == False:
                print("The cost hasn't been changed! The edge is not existent")
            else:
                print("The cost has been successfully modified")
        else:
            print("Invalid x and y.")
            
    def getCostOfEdge(self):
        x=int(input("x:"))
        y=int(input("y:"))
        if self._graph._isOutKey(y) and self._graph._isInKey(x):
            if self._graph.isEdge(x,y):
                cost=self._graph._getCost(x,y)
                print("The cost of the edge (",x ,",",y,") is :",cost)
            else:
                print("There is no edge between x and y.")
        else:
            print("Invalid x and y.")
            
                
            
    def showAllUI(self):
        for x in self._graph.parseX():
            print ("for ",x)
            for y in self._graph.parseNout(x):
                print (x," ",y)