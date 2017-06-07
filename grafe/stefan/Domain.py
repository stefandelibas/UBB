'''
Created on 21 Mar 2017

@author: Stefan
'''
import collections
from json.encoder import INFINITY
from math import inf

class DoubleDictGraph():
    """A directed graph, represented as two maps,
    one from each vertex to the set of outbound neighbours,
    the other from each vertex to the set of inbound neighbors"""

    def __init__(self,filename):
        """
        Creates a graph 
        """
        #self._dictOut = {0: [1, 2], 1: [0,2,10], 2: [0,1],3:[4],4:[3],5:[6],6:[5,7,8],7:[6,8],8:[6,7],9:[],10:[1],11:[]}
        self._dictOut = {}
        self._dictIn = {}
        self._cost = {}
        
        
        for i in range(5):
            self._dictOut[i] = []
            self._dictIn[i] = []
        
        self._filename=filename
        self._loadFromFile()
        
    def parseX(self):
        """
        Returns an iterable containing all the vertices
        """
        return self._dictOut.keys()

    def parseNout(self,x):
        """
        Returns an iterable containing the outbound neighbors of x
        """
        return self._dictOut[x]

    def parseNin(self,x):
        """
        Returns an iterable containing the inbound neighbors of x
        """
        if self._isOutKey(x):
            return self._dictIn[x]    
    
    def _isOutKey(self,x):
        return x in self._dictOut.keys()
    
    def _isInKey(self,x):
        return x in self._dictIn.keys()
    
    def isEdge(self,x,y):
        """
        Returns True if there is an edge from x to y, False otherwise
        """
        if self._isOutKey(x):
            return y in self._dictOut[x]
        else:
            return 0 #0 is the code of an error. x is not a key
    def addEdge(self,x,y,cost):
        """
        Adds an edge from x to y.
        Precondition: there is no edge from x to y
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
            self._cost[(x,y)] = cost
            return True
        else:
            return False
        
    def addEdgeUndirectedGraph(self,x,y,cost):
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
        Precondition: there is an edge from x to y
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
        Precondition: x is a key in the dict
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
            return True
        
    def changeCost(self,x,y,newcost):
        if self.isEdge(x, y):
            self._cost[(x,y)] = newcost
            
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
                #self.addEdge(int(attrs[0]), int(attrs[1]), int(attrs[2]))
                self.addEdgeUndirectedGraph(int(attrs[0]), int(attrs[1]),int(attrs[2]))
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
            if len(succesors)==0:
                if(v1!=-1):
                    strf = str(v1) + " "
                    strf = strf + "-1" + " " + "-1"
                    strf=strf+"\n"
                    f.write(strf)
            else:
                for v2 in succesors:
                    strf=str(v1)+" "
                    strf = strf + str(v2) + " " + str(self._getCost(v1, v2))
                    strf = strf + "\n"
                    f.write(strf)
        f.close()
        
    def isolated(self):
        for i in range(0,10000):
            if not self._isInKey(i):
                self.addVertex(i) 
                
    def bfs(self,graph, root): 
        visited = set()
        queue = collections.deque([root])
        while queue: 
            vertex = queue.popleft()
            for neighbour in graph[vertex]: 
                if neighbour not in visited: 
                    visited.add(neighbour) 
                    queue.append(neighbour) 
        return visited
    
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
        
    def connectedComponents(self):
        g = self._dictOut
        vertices = list(self.parseX())
        i=0
        
        for v in vertices:
            if self._dictOut[v] == []:
                i+=1
                print("the component number",i,"is:\n",v," as an isolated vertex")
                vertices.remove(v)
                
        while len(vertices)!=0:
            i+=1
            component = self.bfs(self._dictOut, vertices[0])
            visited = []
            print("the component",i,"is:")
            for x in g:
                if x in component:
                    print(x)
                    if x not in visited:
                        visited.append(x)
                        if(len(g[x])):
                            for y in g[x]:
                                print("    ",y)
                                if y not in visited:
                                    visited.append(y)
            
            for c in visited:
                for x in g[c]:
                    print(c,' ',x)
            
            for c in component:
                vertices.remove(c)
           
    def minCostPath(self, start,end):
        dist = {}
        prev = {start:None}
        
        for x in self.parseX():
            dist[x] = INFINITY
        dist[start] = 0
        changed = True
        while changed:
            changed = False
            i=0
            for (x,y) in self._cost:
                if dist[y] > dist[x] + self._getCost(x, y):
                    dist[y] = dist[x] + self._getCost(x, y)
                    prev[y] = x
                    changed = True 
                    i=i+1    
            if i==len(self.parseX()):
                raise "Negative cycle"  
        if dist[end] == INFINITY:
            return (-1,[])
        else:
            sol = self._constructPath(start,end,prev)
            return (dist[end],sol)
        
    def _constructPath(self,start,end,prev):
        x = end
        sol = []
        while x != None:
            sol.append(x)
            x = prev[x]
        sol.reverse()
        return sol
            
    def Structure(self):
        v=len(self.parseX())
        matr=[]
        for i in range(0,v):
            for j in range (0,v):
                if self.isEdge(i, j)==True and self.isEdge(j, i)==True:
                    matr.append((i,j,self._cost[(i,j)]))
        return matr;
    
        
def accessible(g, s):
    """Returns the set of vertices of the graph g that are accessible
    from the vertex s"""
    acc = set()
    acc.add(s)
    list = [s]
    while len(list) > 0:
        x = list[0]
        list = list[1 : ]
        for y in g.parseNout(x):
            if y not in acc:
                acc.add(y)
                list.append(y)
    return acc



    
