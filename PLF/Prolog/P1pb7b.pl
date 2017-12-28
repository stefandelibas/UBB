interval(N,N,[N]):-!.
interval(M,N,[M|R]):-
    M2 is M+1,
    interval(M2,N,R).

