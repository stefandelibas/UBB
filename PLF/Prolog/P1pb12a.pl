
putList([],R,R).
putList([H|T],R,Res):-
    putList(T,[H|R],Res).

replace([],_,_,R,R).
replace([H|T],E,L,R,Res):-
    H=:=E,
    putList(L,R,Rez),
    replace(T,E,L,Rez,Res).
replace([H|T],E,L,R,Res):-
    H=\=E,
    putList([H],R,Rez),
    replace(T,E,L,Rez,Res).


