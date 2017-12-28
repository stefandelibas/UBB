evenList([],0).
evenList([_|T],0):-
    evenList(T,1).

evenList([_|T],1):-
    evenList(T,0).

even(L):-
    evenList(L,0).

