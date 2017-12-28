%mygcd(A - number,B - number, R -result the gcd of A and B)
%mygcd(i,i,o)
%Write a predicate to determine the lowest common multiple of a list formed from integer numbers

mygcd(_,0,inf):-!.
mygcd(0,_,inf):-!.
mygcd(A,A,A).
mygcd(A,B,R):-
    A>B,
    C is A-B,
    mygcd(C,B,R).
mygcd(A,B,R):-
    B>A,
    C is B-A,
    mygcd(A,C,R).

lcm(_,0,inf):-!.
lcm(0,_,inf):-!.
lcm(A,B,R):-
    Prod is A*B,
    mygcd(A,B,GCD),
    R is Prod/GCD.

%lcmList(L - list, R - result).
lcmList([E],E):-!.
lcmList([A,B|T],R):-
    lcm(A,B,C),
    lcmList([C|T],R).


