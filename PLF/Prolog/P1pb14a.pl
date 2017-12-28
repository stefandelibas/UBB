
notInSet([],_).
notInSet([H|T],E):-
    H=\=E,
    notInSet(T,E).

es([],_).
es([H|T],L):-
    not(notInSet(L,H)),
    es(T,L).


