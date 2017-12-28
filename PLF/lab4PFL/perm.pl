%return the permutations with the property that for any j, n>j>i>0 it
% exists i such that |j-1|=1
insert(E,L,[E|L]).
insert(E,[H|T],[H|Res]):-
     insert(E,T,Res).

perm([],[]).
perm([H|T],R):-
    perm(T,Res),
    insert(H,Res,R).

permfin(X,R):-
     findall(P,perm(X,P),R).

hasAfter([],_,1).
hasAfter([H|_],E,0):-
     A is abs(H-E),
     A=:=1,
     hasAfter([],E,1).
hasAfter([H|T],E,0):-
     A is abs(H-E),
     A=\=1,
     hasAfter(T,E,0).

good([_]).
good([H|T]):-
     hasAfter(T,H,0),
     good(T).

reverse([],R,R).
reverse([H|T],R,Res):-
    reverse(T,[H|R],Res).

solve([],[]).
solve([H|T],[H|R]):-
     reverse(H,[],INV),
     good(INV),
     solve(T,R).
solve([H|T],R):-
     reverse(H,[],INV),
     not(good(INV)),
     solve(T,R).

listN(1,[1]).
listN(N,[N|R]):-
     M is N-1,
     listN(M,R).

permPb9(N,R):-
     listN(N,L),
     permfin(L,Perms),
     solve(Perms,R).


