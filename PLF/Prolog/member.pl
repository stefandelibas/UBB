member([H|T],H).

member([H|T],E):-
    member(T,E).

f(L,E):-
    member(L,E1),
    member(L,E2),
    E is E1+E2.
