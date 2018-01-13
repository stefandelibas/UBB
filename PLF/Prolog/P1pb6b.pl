remove3([],_,_,[]).
remove3(T,_,0,T).
remove3([H|T],E,C,[H|R]):-
    H=\=E,
    C=\=0,
    remove3(T,E,C,R).
remove3([H|T],E,C,R):-
    H=:=E,
    C=\=0,
    C2 is C-1,
    remove3(T,E,C2,R).




