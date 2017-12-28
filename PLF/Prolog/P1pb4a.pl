isNotInSet([],_).
isNotInSet([H|T],E):-
    H=\=E,
    isNotInSet(T,E).

diffSets([],_,R,R).
diffSets([H|T],L,R,Res):-
    isNotInSet(L,H),!,
    diffSets(T,L,[H|R],Res).

diffSets([_|T],L,R,Res):-
    diffSets(T,L,R,Res).


