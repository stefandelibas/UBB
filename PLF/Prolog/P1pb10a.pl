%decreasing(L:-list)
%decreasing(i)

decreasing([_]).
decreasing([H1, H2 | T]) :-
    H1>H2, decreasing([H2 | T]).

%isMountain(L:-list)
%isMountain(i)

isMountain([H1, H2, H3 | T]) :-
    H1<H2, H2>H3,
    decreasing([H2, H3 | T]).
isMountain([H1, H2 | T]) :-
    H1<H2,
    isMountain([H2 | T]).

%isValley(L:-list)
%isValley(i)

isValley([H1, H2, H3 | T]) :-
    H1>H2, H2<H3,
    increasing([H2, H3 | T]).
isValley([H1, H2 | T]) :-
    H1>H2,
    isValley([H2 | T]).

%increasing(L:-list)
%increasing(i)

increasing([_]).
increasing([H1, H2 | T]) :-
    H1<H2,
    increasing([H2 | T]).

