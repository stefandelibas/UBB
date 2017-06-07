'''
Created on Mar 22, 2017

@author: User
'''
from Graph.UI import *
from Graph.Domain import DoubleDictGraph

def main():
    d = DoubleDictGraph("graph.txt",5)
    
    ui=uiclass(d)
    while True:
        #g.test()
        meniu()
        n=readCommand()
        if n==-1:
            print("Invalit input!")
        elif n==1:
            ui.numberOfVerticesUI()
        elif n==2:
            ui.isEdgeUI()
        elif n==3:
            ui.parseInDegreeUI()
        elif n==4:
            ui.parseOutDegreeUI()
        elif n==5:
            ui.parseNoutUI()
        elif n==6:
            ui.parseNinUI()
        elif n==7:
            ui.changeCostUI()
            d.storeToFile()
        elif n==8:
            ui.showAllUI()
        elif n==9:
            ui.removeAnEdgeUI()
            d.storeToFile()
        elif n==10:
            ui.removeAVertexUI()
            d.storeToFile()
        elif n==11:
            ui.addAnEdgeUI()
            d.storeToFile()
        elif n==12:
            ui.addAVertexUI()
            d.storeToFile()
        elif n==13:
            ui.getCostOfEdge()
            d.storeToFile()
        elif n == 0:
            d.storeToFile()
            break
        elif n==14:
            ui.path()
        elif n==15:
            ui.FolydWarshall()
        elif n==16:
            ui.kruskal()
        elif n==17:
            ui.hamilton()
            
    
main()
