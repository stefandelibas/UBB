max([],R,R).
max([H|T],C,R):-
    H > C,!,
    C2 is H,
    max(T,C2,R).
max([_|T],C,R):-
    max(T,C,R).

removeElement([],_,[]).
removeElement([H|T],E,[H|R]):-
    H=\=E,
    removeElement(T,E,R).

removeElement([H|T],E,R):-
    H=:=E,
    removeElement(T,E,R).

removeMax(L,R):-
    max(L,0,MAX),
    removeElement(L,MAX,R).



