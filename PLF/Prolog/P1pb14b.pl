elem([H|_],1,H):-!.
elem([],_,lengthToShort).
elem([_|T],C,R):-
    C2 is C-1,
    elem(T,C2,R).

