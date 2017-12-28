member1([H | _], H).
member1([H | T], E) :-
    H =\= E,
    member1(T, E).

append1([], E, [E]).
append1([H | T], E, R) :-
    R = [H | Cum],
    append1(T, E, Cum).

%R result, C1 cumulator1, C2 cumulator 2
uniq([], R,R).

uniq([H | T], C1, R) :-
    member1(C1, H),
    uniq(T, C1, R).

uniq([H | T], C1, Y) :-
    not(member1(C1, H)),
    append1(C1, H, C2),
    uniq(T, C2, Y).

unique(X, Y) :-
    uniq(X, [], Y).
