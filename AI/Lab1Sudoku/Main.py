'''
Created on Mar 17, 2018

@author: Stefan-PC
'''

from Problem import Problem
from Controller import Controller
from Ui import UI

def main():
    prbl = Problem()
    ctrl = Controller(prbl)
    ui = UI(ctrl)
    ui.ui_run()
    
if __name__ == '__main__':
    main()