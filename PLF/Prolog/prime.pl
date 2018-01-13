prime(N,N,C,C):-!.
prime(N,I,C,R):-
    M is mod(N,I),
    M=:=0,
    C2 is C+1,
    I2 is I+1,
    prime(N,I2,C2,R).
prime(N,I,C,R):-
    M is mod(N,I),
    M=\=0,
    I2 is I+1,
    prime(N,I2,C,R).

isPrime(N):-
    prime(N,2,0,R),
    R=:=0.
