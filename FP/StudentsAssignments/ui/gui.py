'''
Created on Nov 8, 2016

@author: Stefan
'''
from kivy.app import App
from kivy.uix.button import Button

class TestApp(App):
    def build(self):
        return Button(text='Hello World')

TestApp().run()