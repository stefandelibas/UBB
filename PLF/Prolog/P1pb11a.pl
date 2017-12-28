swap([],_,_,[]).
swap([H|T],O,N,[H|R]):-
    H=\=O,
    swap(T,O,N,R).
swap([H|T],O,N,[N|R]):-
    H=:=O,
    swap(T,O,N,R).

