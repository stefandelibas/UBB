%addpow2(L - list,V - value to be added C - contor, K - pow2 contor, R - result)
%addpow2(i,i,i,i,o)
% Write a predicate to add a value v after 1-st,2-nd,4-th,8-thelement in a list

addpow2([],_,_,_,[]).
addpow2([H|T],V,C,K,[H|R]):-
    C=\=K,
    C2 is C+1,
    addpow2(T,V,C2,K,R).
addpow2([H|T],V,C,K,[V,H|R]):-
    C=:=K,
    C2 is C+1,
    K2 is K*2,
    addpow2(T,V,C2,K2,R).

addp2th(L,E,R):-
    addpow2(L,E,1,1,R).

