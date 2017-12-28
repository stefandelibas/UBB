%Write a predicate to remove all occurrences of a certain atom from a list.
%remove(L - list, A - atom, R - result)
%remove(i,i,o)

remove([],_,[]).

remove([H|T],A,[H|R]):-
    H=\=A,
    remove(T,A,R).

remove([H|T],A,R):-
    H=:=A,
    remove(T,A,R).
