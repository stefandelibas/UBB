'''
Created on Mar 22, 2017

@author: Stefan
'''
from Graph.UI import *
from Graph.Domain import DoubleDictGraph

def main():
    g = DoubleDictGraph("C:\\Users\\Stefan\\workspace2\\Graph\\Graph\\graph.txt")
    print("Welcome")
    ui=uiclass(g)
    while True:
        print("Available commands:")
        meniu()
        n=readCommand()
        if n==-1:
            print("Invalid input!")
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
        elif n==8:
            ui.showAllVUI()
        elif n==9:
            ui.removeAnEdgeUI()
        elif n==10:
            ui.removeAVertexUI()
        elif n==11:
            ui.addAnEdgeUI()
        elif n==12:
            ui.addAVertexUI()
        elif n==13:
            ui.costOfEdgeUI()
        elif n==14:
            ui.connectedComponentsUI()
        elif n==15:
            ui.minCostPathUI()
        elif n==16:
            ui.spanningTreeUI()
        elif n==17:
            ui.hamilton()
        elif n == 0:
            g.storeToFile()
            print("Goodbye")
            break
    
main()
