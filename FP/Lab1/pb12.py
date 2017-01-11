
"""
    * Functions *
"""

def check_digits(n,d):
    #this function checks in the d array (by putting an 1 on that position) each digit that exits in the number n 
    while True:
        d[n%10]=1
        n=int(n/10)
        if n==0:
            break

"""
    * Program *
"""

n1=int(input("n1="))
c1=[0,0,0,0,0,0,0,0,0,0]
n2=int(input("n2="))
c2=[0,0,0,0,0,0,0,0,0,0]

if n1<0:
    n1=n1*(-1)
if n2<0:
    n2=n2*(-1)
    
check_digits(n1,c1)
check_digits(n2,c2)

ok=1
for i in range (0,10):
    if c1[i]!=c2[i]:
        print("Those two numbers do not have the property P.")
        ok=0
        break
if ok==1:
    print("The numbers n1 and n2 have the property P")



