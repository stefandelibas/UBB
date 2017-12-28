isNotInSet([],_).
isNotInSet([H|T],E):-
    H=\=E,
    isNotInSet(T,E).

addRestOf2([],R,R).
addRestOf2([H|T],R,Res):-
    isNotInSet(R,H),!,
    addRestOf2(T,[H|R],Res).
addRestOf2([_|T],R,Res):-
    addRestOf2(T,R,Res).


unionSets(L1,L2,Res):-
    F = L1,
    addRestOf2(L2,F,Res).
