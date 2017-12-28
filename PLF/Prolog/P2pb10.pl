prime(N,N).
prime(N,C):-
    C<N,
    M is mod(N,C),
    M=\=0,
    C2 is C+1,
    prime(N,C2).

isPrime(N):-
    prime(N,2).

doublePrimes([],[]).
doublePrimes([H|T],[H,H|R]):-
    isPrime(H),
    doublePrimes(T,R).
doublePrimes([H|T],[H|R]):-
    not(isPrime(H)),
    doublePrimes(T,R).


