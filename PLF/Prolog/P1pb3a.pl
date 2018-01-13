isInList([E|_],E):-!.
isInList([_|T],E):-
    isInList(T,E).

removeElem([],_,[]).
removeElem([H|T],E,[H|R]):-
    H=\=E,
    removeElem(T,E,R).
removeElem([H|T],E,R):-
    H=:=E,
    removeElem(T,E,R).

remove([],[]).
remove([H|T],R):-
    isInList(T,H),!,
    removeElem(T,H,Rez),
    remove(Rez,R).
remove([H|T],[H|R]):-
    remove(T,R).
