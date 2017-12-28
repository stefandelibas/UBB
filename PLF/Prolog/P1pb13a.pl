noOcc([],_,C,C).
noOcc([H|T],E,C,R):-
    H=:=E,
    C2 is C+1,
    noOcc(T,E,C2,R).
noOcc([H|T],E,C,R):-
    H=\=E,
    noOcc(T,E,C,R).

toSet([],[]).
toSet([H|T],[H|R]):-
    noOcc(T,H,0,ROcc),
    ROcc=:=0,
    toSet(T,R).
toSet([H|T],R):-
    noOcc(T,H,0,ROcc),
    ROcc > 0,
    toSet(T,R).


