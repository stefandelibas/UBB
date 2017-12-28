sub([],_,_,_,[]).
sub([_|T],M,N,C,R):-
    C<M,
    C2 is C+1,
    sub(T,M,N,C2,R).
sub([H|T],M,N,C,[H|R]):-
    C>=M,
    C=<N,
    C2 is C+1,
    sub(T,M,N,C2,R).

sub([_|_],M,N,C,R):-
    C>N,
    sub([],M,N,C,R).

sublist(L,M,N,R):-
    sub(L,M,N,1,R).
