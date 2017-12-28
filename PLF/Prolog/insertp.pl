%insert(L - list,E - element C - contor, P - position, R - result)

insertp([],_,_,_,[]).
insertp([H|T],E,C,P,[H,E|R]):-
    C=:=1,
    insertp(T,E,P,P,R).
insertp([H|T],E,C,P,[H|R]):-
    C=\=1,
    C2 is C-1,
    insertp(T,E,C2,P,R).

insertpth(L,E,P,R):-
    insertp(L,E,P,P,R).
