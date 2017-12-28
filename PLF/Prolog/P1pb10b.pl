altsum([],R,_,R):-!.
altsum([H|T],S,0,R):-
    S2 is S+H,
    altsum(T,S2,1,R).
altsum([H|T],S,1,R):-
    S2 is S-H,
    altsum(T,S2,0,R).
sum(L,R):-
    altsum(L,0,0,R).
