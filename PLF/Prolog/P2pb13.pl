remove([_],1,[]).
remove([E],0,[E]).

remove([A,B|T],1,R):-
    C is A+1,
    C=\=B,
    remove([B|T],0,R).

remove([A,B|T],1,R):-
    C is A+1,
    C=:=B,
    remove([B|T],1,R).

remove([A,B|T],0,[A|R]):-
    C is A+1,
    C=\=B,
    remove([B|T],0,R).

remove([A,B|T],0,R):-
    C is A+1,
    C=:=B,
    remove([B|T],1,R).


