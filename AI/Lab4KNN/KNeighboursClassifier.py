'''
Created on 7 May 2018

@author: User
'''
from math import sqrt


def euc_dist(a, b):
    return sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2+ (a[2] - b[2]) ** 2+ (a[3] - b[3]) ** 2+ (a[4] - b[4]) ** 2+ (a[5] - b[5]) ** 2)


class KNeighboursClassifier:
    '''for k=1'''
    def __init__(self):
        self.__x = []
        self.__y = []

    def fit(self, x_train, y_train):
        self.__x = x_train
        self.__y = y_train

    def predict(self, data):
        return self.get_closest(data)

    def get_closest(self, data):
        best_dist = euc_dist(data, self.__x[0])
        best_index = 0

        for i in range(1, len(self.__x)):
            dist = euc_dist(data, self.__x[i])
            if dist < best_dist:
                best_dist = dist
                best_index = i

        return self.__y[best_index]
