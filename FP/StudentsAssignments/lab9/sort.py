'''
Created on Jan 10, 2017

@author: Stefan
'''

def cmp(a,b):
    return a < b 
       
def GnomeSort(iterObj,cmpFct=cmp):
    i = j = 0
    n = len(iterObj)
    while i < n:
        if i and cmpFct(iterObj[i],iterObj[i-1]):
            iterObj[i], iterObj[i-1] = iterObj[i-1], iterObj[i]
            i -= 1
        else:
            if i < j:
                i = j
            j = i = i + 1
    return


def filterBy(arr,test):
    res=[]
    for it in arr:
        if(test(it)):
            res.append(it)
    return res