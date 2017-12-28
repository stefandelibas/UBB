isNotInSet([],_).
isNotInSet([H|T],E):-
    H=\=E,
    isNotInSet(T,E).

intersection([],_,R,R).

intersection([H|T],L,R,Res):-
    isNotInSet(L,H),!,
    intersection(T,L,R,Res).

intersection([H|T],L,R,Res):-
    intersection(T,L,[H|R],Res).

intersectionSets(L1,L2,R):-
    intersection(L1,L2,[],R).

