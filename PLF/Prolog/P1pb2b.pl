%Define a predicate to produce a list of pairs (atom n) from an initial list of atoms
%noOcc(L - list, E - element,C - colector, R - result)
%noOcc(i,i,i,o).

noOcc([],_,C,C).
noOcc([H|T],E,C,R):-
    H=:=E,
    C2 is C+1,
    noOcc(T,E,C2,R).
noOcc([H|T],E,C,R):-
    H=\=E,
    noOcc(T,E,C,R).

%return true if H is not the head of the list, false otherwise
notTheHead([H|_],E):-
    H=\=E.

%return true if H is not a head of one of the pairs,false otherwise
notInList([],_).

notInList([H|T],E):-
    notTheHead(H,E),
    notInList(T,E).


%parseList( L-list, R - result acumulator, Res - the result list)
%parseList(i,i,o)
parseList([],R,R):-!.

parseList([H|T],R,Res):-
    noOcc(T,H,1,NOcc),
    notInList(R,H),
    HR = [H,NOcc],
    parseList(T,[HR|R],Res).

parseList([H|T],R,Res):-
    not(notInList(R,H)),
    parseList(T,R,Res).

% makes a list of pairs representing each element in the list and the
% number of occurances in the initial list list.
makePairs(L,Res):-
    parseList(L,[],Res).





