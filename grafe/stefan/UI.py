'''
Created on 21 Mar 2017

@author: Stefan
'''

from Graph.Domain import *
from cgi import valid_boundary
def meniu():
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
    print("13. Show the cost of an edge")
    print("14.Show the connected components of the undirected graph stored in dictOut")
    print("15.Min cost path")
    print("16.Spanning tree.")
    print("17.hamilton")
    print("0. Exit")

def readCommand():
    n=input("Enter your command:")
    n = int(n)
    if n<0 or n > 17:
        return -1
    else:
        return n

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
        if self._graph._isInKey(x) and self._graph._isInKey(y):
            torf=self._graph.isEdge(x,y)
            if torf == True:
                print("There is an edge between the vertex ",x," and the vertex ",y)
            elif torf == False:
                print("There is NO edge between the vertex ",x," and the vertex ",y)
        else:
            print("invalid keys")
            
    def removeAnEdgeUI(self):
        x=int(input("x:"))
        y=int(input("y:"))
        i = self._graph.removeEdge(x,y)
        if i:
            print("The edge was successfully removed.")
        else:
            print("The egde could not be removed. Error! The vertices are not valid.")
    
    def removeAVertexUI(self):
        x=int(input("x:"))
        i = self._graph.removeVertex(x)
        if i:
            print("The vertex was successfully removed.")
        else:
            print("The vertex could not be removed. Error! x is not a vertex.")
    
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
            print("The IN degree of ",x," is: ",len(l))
        else:
            print("not a valid key.")
    def parseOutDegreeUI(self):
        x=int(input("x:"))
        if self._graph._isInKey(x):
            l=self._graph.parseNout(x)
            print("The OUT degree of ",x," is: ",len(l))
        else:
            print("not a valid key.")
    def parseNinUI(self):
        x=int(input("x:"))
        if self._graph._isInKey(x):
            l=self._graph.parseNin(x)
            print("Here are the inbound edges of ",x,": ")
            for i in l:
                print (i)
        else:
            print("not a valid key.")
            
    def parseNoutUI(self):
        x=int(input("x:"))
        if self._graph._isOutKey(x):
            l=self._graph.parseNout(x)
            print("Here are the outbound edges of ",x,": ")
            for i in l:
                print (i)
        else:
            print("not a valid key.")
    
    def costOfEdgeUI(self):
        x=int(input("x:"))
        y=int(input("y:"))
        if self._graph._isInKey(x) and self._graph._isInKey(y):
            if self._graph.isEdge(x,y):
                c=self._graph._getCost(x,y)
                print("The cost is ",c)
            else:
                print("There is no edge between ",x," and ", y)
        else:
            print("Invalid keys") 
    def changeCostUI(self):
        x=int(input("x:"))
        y=int(input("y:"))
        newcost=int(input("new cost:"))
        if self._graph._isInKey(x) and self._graph._isInKey(y):
            f=self._graph.changeCost(x,y,newcost)
            if f == False:
                print("The cost hasn't been changed! The edge is not existent")
            else:
                print("The cost has been successfully modified")
        else:
            print("not valid keys")
    def connectedComponentsUI(self):
        self._graph.connectedComponents()
        
    def minCostPathUI(self):
        x=int(input("x:"))
        y=int(input("y:"))
        if self._graph._isInKey(x) and self._graph._isInKey(y):   
            try:
                sol = []
                cost=0
                (cost,sol)=self._graph.minCostPath(x,y)
            except:
                print("There is a negative cycle detected!")
                return
            if cost == -1:
                print("there is no path from x to y")
            else:
                print("The cost of the path from x to y is:",cost)
                print("The path is:",sol)
        else:
            print("Invalid keys") 
    
    def spanningTreeUI(self):
        #n- nr de vertexuri
        #m-nr de edgeuri
        matr=self._graph.Structure()
        f=()
        n=len(self._graph.parseX())
        l=[0]*(n+1)
        for i in range (1,n+1):
            l[i]=i
        for i in range(0,len(matr)):
            for j in range(i+1,len(matr)):
                if matr[i][2]>matr[j][2]:
                    f=matr[i]
                    matr[i]=matr[j]
                    matr[j]=f
        k=0
        ct=0
        i=1
        aux = DoubleDictGraph("C:\\Users\\Stefan\\workspace2\\Graph\\Graph\\blank.txt")
        
        while k<n-2:
            if l[matr[i][0]]!=l[matr[i][1]]:
                k=k+1
                ct=ct+matr[i][2]
                for j in range (1,n):
                    if l[j]==l[matr[i][0]]:
                        l[j]=l[matr[i][1]]
                aux.addVertex(matr[i][0])
                aux.addVertex(matr[i][1])
                aux.addEdgeUndirectedGraph(matr[i][0], matr[i][1], matr[i][2])
            i=i+1
        """for x in aux.parseX():
                print ("for ",x)
                for y in aux.parseNout(x):
                    print ("        ",x," ",y)
        print("Total cost: ",ct)"""
        return aux
    
    def hamilton(self):
        start=int(input("starting vertex:"))
        cycle = []
        mst = self.spanningTreeUI()
        cycle = self._graph.Hamilton(mst,start)
        print("The cycle is: ",end='')
        totalCost = 0
        for i in range(len(cycle)):
            print(cycle[i]," ",end='')
            #totalCost += self._graph._getCost(cycle[i],cycle[i+1])
       
    
    def showAllVUI(self):
        for x in self._graph.parseX():
            print ("for ",x)
            for y in self._graph.parseNout(x):
                print ("        ",x," ",y)
                