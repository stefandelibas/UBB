%delete(L - list, C - contor, K - powers of 2, R - the result list).
%delete(i,i,i,o)
% C starts with 1 and K with the first power of 2 meaning 2 to the power
% 1. the counter increses at each step, if C+1 == K then we delete the
% current element and set K tot the next power of 2, multipying by 2
% otherwise we put the current element in the result list and increase C
delete([],_,_,[]).

delete([_|T],C,K,R):-
    C+1=:=K,
    C2 is C+1,
    K2 is K*2,!,
    delete(T,C2,K2,R).

delete([H|T],C,K,[H|R]):-
    C+1=\=K,
    C2 is C+1,
    delete(T,C2,K,R).

%delete137(L - list, R -result list)
%delete137(i,o).
%
delete137(L,R):-
    delete(L,1,2,R).
