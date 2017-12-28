nrOcc([], _, 0).
nrOcc([H|T], H, R):-
    nrOcc([H|T], H, R1),
    R is R1+1.
nrOcc([H|T], E, R):-
    H\=E,
    nrOcc([H|T], E, R).

nrOcc1([],_ , V,V).
nrOcc1([H|T], H,V, R):-
    V1 is V + 1,
    nrOcc1([H|T], H, V1,R).

nrOcc1([H|T], E, V, R):-
    H\=E,
    nrOcc1([H|T], E, V, R).

