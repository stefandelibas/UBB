insert([],E,[E]).
insert([H|T],E,[H|T]):-
    E=:=H,!.
insert([H|T],E,[H|R]):-
    E>H,
    insert(T,E,R).
insert([H|T],E,[E,H|T]):-
    E<H.

sortRD([],[]).
sortRD([H|T],R):-
    sortRD(T,Res),
    insert(Res,H,R).
