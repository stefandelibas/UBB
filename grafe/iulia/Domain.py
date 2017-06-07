import queue
'''
Created on 21 Mar 2017

@author: User
'''
from math import inf
class DoubleDictGraph():
    """A directed graph, represented as two maps,
    one from each vertex to the set of outbound neighbours,
    the other from each vertex to the set of inbound neighbours"""

    def __init__(self,filename,n):
        """
        Creates a graph with n vertices (numbered from 0 to n-1)
        and no edges
        """
        self._n=n
        self._dictOut={}
        self._dictIn = {}
        self._cost = {}
        for i in range(n):
            self._dictOut[i]=[]
            self._dictIn[i]=[]
        self._filename=filename
        self._loadFromFile()
    
        
    def parseX(self):
        """
        Returns an iterable containing all the vertices(noduri)
        """
        return self._dictOut.keys()

    def parseNout(self,x):
        """
        Returns an iterable containing the outbound neighbours of x
        """
        if self._isInKey(x):
            return self._dictOut[x]

    def parseNin(self,x):
        """
        Returns an iterable containing the inbound neighbours of x
        """
        if self._isOutKey(x):
            return self._dictIn[x]    
    
    def parseVertices(self):
        vList = [] 
        for v in self._dictIn.keys():
            vList.append(v)
        for v in self._dictOut.keys():
            vList.append(v)
            
        return vList
    def _isOutKey(self,x):
        return x in self._dictOut.keys()
    
    def _isInKey(self,x):
        return x in self._dictIn.keys()
    
    def isEdge(self,x,y):
        """
        Returns True if there is an edge from x to y, False otherwise
        """
        if y in self.parseNout(x):
            return True
        else:
            return False
        
    def parseEdges(self, v):   
        vList = [] 
        for vertex in self.parseNin(v):
            vList.append(vertex)
        for vertex in self.parseNout(v):
            vList.append(vertex)
        return vList   

    def addEdge(self,x,y,cost):
        """
        Adds an edge from x to y.
        """
        if not self._isOutKey(x):
            self._dictOut[x] = []
            self._dictIn[x] = []
           
        if not self._isOutKey(y):
            self._dictOut[y] = []
            self._dictIn[y] = []
            
        if self.isEdge(x, y) == False:
            self._dictOut[x].append(y)
            self._dictIn[y].append(x)
            self._dictOut[y].append(x)
            self._dictIn[x].append(y)
            self._cost[(x,y)] = cost
            self._cost[(y,x)] = cost
            return True
        else:
            return False
                
    def removeEdge(self,x,y):
        """
        removes the edge from x to y
        """
        if self.isEdge(x, y):
            self._dictOut[x].remove(y)
            self._dictIn[y].remove(x)
            del self._cost[(x,y)]
            return True
        else:
            return False
    
    def removeVertex(self,x):
        """
        removes the vertex x
        """
        if self._isOutKey(x):
            for v in self._dictIn[x]:
                del self._cost[(v,x)]
                self._dictOut[v].remove(x)
            for v in self._dictOut[x]:
                del self._cost[(x,v)]
                self._dictIn[v].remove(x)
            del self._dictIn[x]
            del self._dictOut[x]
            return True
        else:
            return False
            
    def addVertex(self,x):
        if self._isOutKey(x):
            return False
        else:
            self._dictOut[x] = []
            self._dictIn[x] = []
            self.addEdge(x, -1, -1)
            return True
        
    def chageCost(self,x,y,newcost):
        if self.isEdge(x, y)==True:
            
            self._cost[(x,y)] = newcost
            return True
        else:
            return False
    
    def MatrixMade(self):
        v=len(self.parseX())
        '''print(v)'''
        k=0
        matr=[[0]*v for i in range(0,v)]
        for i in range(0,v):
            for j in range(0,v):
                if i==j:
                    matr[i][j]=0
                elif self.isEdge(i, j)==True:
                    matr[i][j]=self._cost[(i,j)]
                else:
                    matr[i][j]=inf
                
        '''for i in range (0,v):
            print(matr[i])'''
        return matr 
    
    def Structure(self):
        v=len(self.parseX())
        matr=[]
        for i in range(0,v):
            for j in range (0,v):
                if self.isEdge(i, j)==True and self.isEdge(j, i)==True:
                    matr.append((i,j,self._cost[(i,j)]))
        return matr;
      
    def MatrixMultiplication(self,matr):
        v=len(self.parseX())
        m=[[0]*v for i in range(0,v)]  
        for i in range(0,v):
            for j in range(0,v):
                m[i][j] =0
        
        for i in range (0,v):
            for j in range(0,v):
                m[i][j]=inf
                for k in range(0,v):
                    m[i][j] =min(m[i][j],matr[i][k]+matr[k][j])
        return m
                    
             
    def find(self,i,parent):
        while parent[i]:
            i=parent[i]
        return i;
    
    def uni(self,i,j,parent):
        if i!=j:
            parent[j]=i
            return 1
        return 0   
       
                
            
    def _loadFromFile(self): 
        """
        load from a file the data.
        """
        try:
            f = open(self._filename, "r")
        except IOError:
            # file not exist
            return
        line = f.readline().strip()
        while line != "":
            attrs = line.split(" ")
            if attrs[1] == -1:
                self.addVertex(attrs[0])
            else:
                self.addEdge(int(attrs[0]), int(attrs[1]), int(attrs[2]))
            line = f.readline().strip()
        f.close()  
     
        
    def _getCost(self,x,y):
        return self._cost[(x,y)]
    

    
    def storeToFile(self):
        """
         Store all the edges and vertices in to the file
        """
        # open file (rewrite file)
        f = open(self._filename, "w")
        vertices = self.parseX();
        #print(vertices)
        for v1 in vertices:
            succesors = self.parseNout(v1) 
            #print(succesors);
            for v2 in succesors:
                strf=str(v1)+" "
                strf = strf + str(v2) + " " + str(self._getCost(v1, v2))
                strf = strf + "\n"
                f.write(strf)
        f.close()        
    
    def accesible(self, s,end):
        """Returns the set of vertices of the graph g that are accessible
        from the vertex s"""
        acc = set()
        nex={}
        print(nex)
        acc.add(end)
        print(acc)
        list = [end]
        print(list)
        print("--------")
        while len(list) > 0:
            x = list[0]
            list = list[1 : ]
            print(list)
            for y in self.parseNin(x):
                if y ==s:
                    nex[y]=x
                    print("nex:",nex)
                    return nex
                if y not in acc:
                    acc.add(y)
                    print("acc",acc)
                    list.append(y)
                    print(list)
                    nex[y]=x
                    print("nex:",nex)
                    print("---------")
        return nex
    cycle = []
    
    def dfs(self,graph,node):
        if node not in self.cycle:
            self.cycle.append(node)
            for n in graph._dictOut[node]:
                self.dfs(graph,n)
        
    
    def Hamilton(self,mst,start):
        self.cycle.clear()
        g = self._dictOut
        vertices = list(mst.parseX())
        i=0   
        
        self.dfs(mst, start) 
        self.cycle.append(start)
        
        return self.cycle
        
        
        
        
        
           
    
