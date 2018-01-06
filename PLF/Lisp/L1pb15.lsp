
;a
(defun insertOnNth(lst e n crt)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(equal n crt)
			(cons e lst)
		)
		(
			t
			(cons (car lst) (insertOnNth (cdr lst) e n (+ crt 1)))
		)
	)
)
;(print (insertOnNth '(1 2 3 4 5 6 7) 100 4 1))

;b
(defun sumAtoms(lst)
	(cond 
		(
			(null lst)
			0
		)
		(
			(numberp (car lst))
			(+ (car lst) (sumAtoms (cdr lst)))
		)
		(
			(listp (car lst))
			(+ (sumAtoms (car lst)) (sumAtoms (cdr lst)))
		)
	)
)

;(print (sumAtoms '(1 2 (2 1) 2 ((1) 1))))


;c
(defun sublists(lst)
	(cond
		(
			(null lst)
			nil
		)
		(
			(atom (car lst))
			(sublists (cdr lst))
		)
		(
			(listp (car lst))
			(cons  (car lst) (append (sublists (car lst)) (sublists (cdr lst)))) 
		)
	)
)

(defun getSublists(lst)
	(cons lst (sublists lst))
)
;(print (getSublists  '(1 2 (3 (4 5) (6 7)) 8 (9 10)) ) )


;d
(defun isInList(lst e)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(equal e (car lst))
			t
		)
		(
			(not(equal e (car lst)))	
			(isInList (cdr lst) e)
		)
	)
)

(defun areSetsEqual(a b n)
	(cond 
		(
			(and (null a) (equal n 0))
			t
		)
		(
			(null a)
			nil
		)
		(
			(equal n 0)
			nil
		)
		(
			(not(isInList b (car a)))
			nil
		)
		(
			t
			(areSetsEqual (cdr a) b (- n 1))
		)
	)
)

(defun areEqual(a b)
	(areSetsEqual a b (length b))
)

;(print (areEqual '(1 2 3 4 5) '(1 4 3 2)))	;nil
;(print (areEqual '(1 2 3 4) '(1 4 3 2 5)))	;nil
;(print (areEqual '(1 2 3 4) '(1 4 3 2)))	;t