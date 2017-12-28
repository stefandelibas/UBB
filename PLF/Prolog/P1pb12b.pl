remove([_|T],1,T).
remove([H|T],C,[H|R]):-
    C2 is C-1,
    remove(T,C2,R).
