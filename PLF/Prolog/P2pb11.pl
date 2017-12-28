%replace(L - list, N - element to be replaced, M - element to replace
%with, R - result list)
replace([],_,_,[]):-!.
replace([H|T],N,M,[M|R]):-
    N=:=H,!,
    replace(T,N,M,R).
replace([H|T],N,M,[H|R]):-
    replace(T,N,M,R).
