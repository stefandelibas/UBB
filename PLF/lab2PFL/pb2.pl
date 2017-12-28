%compute the great common divisor of two numbers A and B
%gcd(A - number,B - number,R - result=gcd(A and B))
%gcd(i,i,o)
gcd1(A,A,A).
gcd1(A,B,R):-
    B<A,
    C is A-B,
    gcd1(C,A,R).
gcd1(A,B,R):-
    A<B,
    C is B-A,
    gcd1(A,C,R).

%compute the great common divisor of the elements of a list
%gcdList(L - list,R - result)
%gcdList(i,o)
gcdList([H],H).
gcdList([H1,H2|L],R):-gcd1(H1,H2,Res),
    gcdList([Res|L],R).
