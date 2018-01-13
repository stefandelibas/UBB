inv(0,C,C):-!.
inv(N,C,R):-
    N1 is div(N,10),
    C2 is C*10+mod(N,10),
    inv(N1,C2,R).

