
makePairs(_,[],R,R).
makePairs(E,[H|T],R,Res):-
    P=[E,H],
    makePairs(E,T,[P|R],Res).

pairs([_],R,R).
pairs([H|T],C,R):-
    makePairs(H,T,C,Res),
    pairs(T,Res,R).
