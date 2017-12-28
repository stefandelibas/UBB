%divizori(N,2,[],R).

reverse([],R,R).
reverse([H|T],R,Res):-
    reverse(T,[H|R],Res).

divizori(N,M,R,R):-
    M>N,!.
divizori(N,C,R,Res):-
    M is mod(N,C),
    M=:=0,
    C2 is C+1,
    divizori(N,C2,[C|R],Res).
divizori(N,C,R,Res):-
    M is mod(N,C),
    M=\=0,
    C2 is C+1,
    divizori(N,C2,R,Res).

insert([],R,R).
insert([H|T],R,Res):-
    insert(T,[H|R],Res).

insertDivizori([],R,R).
insertDivizori([H|T],R,Res):-
    divizori(H,2,[],Divs),
    insert(Divs,R,RT),
    insertDivizori(T,RT,Res).

insertDivs(L,R):-
    insertDivizori(L,[],RT),
    reverse(RT,[],R).






