min([],R,R).
min([H|T],C,R):-
    H<C,
    min(T,H,R).
min([H|T],C,R):-
    H>=C,
    min(T,C,R).

minimum(L,R):-
    min(L,999999999999,R).

deleteFirstMin(L,R):-
    minimum(L,MIN),
    deleteMin(L,MIN,0,R).

deleteMin([],_,_,[]).
deleteMin([H|T],MIN,0,[H|R]):-
    MIN=\=H,
    deleteMin(T,MIN,0,R).
deleteMin([H|T],MIN,0,R):-
    MIN=:=H,
    deleteMin(T,MIN,1,R).
deleteMin(L,_,1,L).



