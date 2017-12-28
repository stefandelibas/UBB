oddandeven([],R1,R1,R2,R2,L1,L1,L2,L2).
oddandeven([H|T],R1,RF1,[H|R2],RF2,L1,RL1,L2,RL2):-
    P is mod(H,2),
    P=:=0,
    NL is L2+1,
    oddandeven(T,R1,RF1,R2,RF2,L1,RL1,NL,RL2).
oddandeven([H|T],[H|R1],RF1,R2,RF2,L1,RL1,L2,RL2):-
    P is mod(H,2),
    P=:=1,
    NL is L1+1,
    oddandeven(T,R1,RF1,R2,RF2,NL,RL1,L2,RL2).



