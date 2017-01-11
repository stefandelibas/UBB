
"""

    * Functions *
    
"""
def DaysPerMonth(m1,m2,y):
    #m1 is the starting month and m2-1 the last month. y is the current year.
    s1=0
    for i in range (m1,m2):
        if i<=7:
            if i==2:
                if is_leap(y)==True:
                    s1=s1+29
                else:
                    s1=s1+28
            elif i%2==1:
                s1=s1+31
            else:
                s1=s1+30
        elif i%2==1:
            s1=s1+30
        else:
            s1=s1+31
    return s1

def is_leap(y):
    #this funtion check if the year y is leap or not(returns True or False)
    if y%4!=0:
        return False
    elif y%100!=0:
        return True
    elif y%400!=0:
        return False
    else:
        return True
    
def DaysLived(y,m,d):
    s=0
    if y!=localtime.tm_year:
        for i in range (y+1,localtime.tm_year):
            if is_leap(i)==True:
                s=s+366
            else:
                s=s+365
        s=s+DaysPerMonth(m,13,y)
        #We add the days from all months that followed the birth of the person
        s=s+DaysPerMonth(1,localtime.tm_mon,localtime.tm_year)
        #We add the days from all months that passed this year
    else:
        s=s+DaysPerMonth(m,localtime.tm_mon,y)
        """
        If the person's birth is this year we will add only the months from
        it's birthday to the current month.
        """
    s=s+localtime.tm_mday
    """
    Because we have olny reached the current month we will add the days
    passed this month.  
    """

    s=s-d
    """
    Because we added the whole month when the person was born we will
    subtract the days before it's birth
    """    
    #print("the person has ",s," days")
    return s


def test_function():
    #this test function is valid only for the day when it was made. When you run first time check if it's valid using https://www.timeanddate.com/date/duration.html
    assert DaysLived(1998,7,6)==6672
    assert DaysLived(2016,10,1)==10
    assert DaysLived(2016,10,11)==366
    
"""

    * Program *
    
"""

print("Insert the birth date:")
y=int(input("Year:"))
m=int(input("Month:"))
d=int(input("Day:"))

import time;
localtime = time.localtime(time.time())

#test_function()

if(localtime.tm_year<y):
    print("Error! You must enter a valid value for a year, less or equal to the current one")
elif m>12 or m<1:
    print("Error! YOu must enter valid value for a month, range from 1 to 12")
elif d<1 or d>31:
    print("Error! You must enter a valid value for a day, range from 1 to 31")
else:
    #only valid values, so it can solve the problem
    final=DaysLived(y,m,d)
    print("the person has ",final," days")
    
# Check the result on https://www.timeanddate.com/date/duration.html
