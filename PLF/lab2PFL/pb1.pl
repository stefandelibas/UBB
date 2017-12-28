%Add an element E on a position p in a list
%add(L - list,E - element, P - position, R - result List)
%add(i,i,i,o)
add([],E,_,[E]).
add(L,E,1,[E|L]).
add([H|T],E,P,[H|TR]):-P=\=1,
    P2 is P-1,
    add(T,E,P2,TR).


