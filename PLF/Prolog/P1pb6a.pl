isInList([E|_],E):-!.
isInList([_|T],E):-
    isInList(T,E).


isSet([]).
isSet([H|T]):-
    not(isInList(T,H)),
    isSet(T).

