add1([],[]).
add1([H|T],[H|R]):-
    C is mod(H,2),
    C=:=1,
    add1(T,R).

add1([H|T],[H,1|R]):-
    C is mod(H,2),
    C=:=0,
    add1(T,R).
