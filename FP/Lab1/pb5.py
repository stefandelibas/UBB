
"""

    * Functions *
    
"""

def is_prime(a):
    #this function returns False if it's not prime and True if it's prime
    if a<=1 or a%2==0 and a!=2:
        return False
    else:
      for d in range (3,a,2):
        if a%d==0:
            return False
    return True

def lowerPrime(n):
    #this function returns the greatest prime numer smaller than a given value (n)
    for i in range (n-1,1,-1):
        if is_prime(i)==True:
            break;
    return i


def test():
    assert lowerPrime(10)==7
    assert lowerPrime(33)==31
    assert lowerPrime(5)==3
    assert lowerPrime(3)==2
"""

    * Program *
    
"""
n=int(input("Insert a number: "))

test()

if n<2:
    print("Error! Insert a bigger value. There is no prime number smaller then the given value for n.")
elif n==2:
    print("2 is the smallest prime number")
else:
    p=lowerPrime(n)
    print("The greatest prime number samller than ",n," is:",p)

