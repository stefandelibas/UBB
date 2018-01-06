;L1pb1

;a
(defun nthElement(lst n crt)
	(cond
		(
			(equal crt n)
			(car lst)
		)
		(
			t
			(nthElement (cdr lst) n (+ crt 1))
		)	
	)
)
(defun len (lst)
	(cond
		(
			(null lst)
			0
		)
		(
			(atom (car lst))
			(+ 1 (len (cdr lst)))
		)
		(
			(listp (car lst))
			(+ (len (car lst)) (len (cdr lst)))
		)
	)
)
(defun nthAtom(lst n crt)
	(cond
		(
			(null lst)
			nil
		)
		(
			(and (atom (car lst)) (equal crt n))
			(car lst)
		)
		(
			(and (listp (car lst)) (<= (+ crt (len (car lst))) n))
			(nthAtom (cdr lst) n (+ crt (len (car lst))))
		)
		(
			(and (listp (car lst)) (> (+ crt (len (car lst))) n))
			(nthAtom (car lst) n crt)
		)
		(
			t
			(nthAtom (cdr lst) n (+ crt 1))
		)	
	)
)
(defun getNthAtom (lst n)
	(nthAtom lst n 1)
)
(defun getNthElement (lst n)
	(nthElement lst n 1)
)
;(print "a:")
;(print (getNthElement '(1 2 (3 4) 5 6) 3)) 	;should return (3 4)
;(print (getNthAtom '(1 2 (3 4) 5 6) 4))		;should return 4
;(print (getNthElement '(1 2 3 4 5 6) 6))	;should return 6
;(print (getNthElement '(1 2 3 4 5 6) 7))	;should return nil
;(print (getNthAtom '(1 2 (3(4(5)6)) 3) 7))	;should return 3  

(defun isInList(lst e)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(and (atom (car lst)) (equal e (car lst)))	
			t
		)
		(
			(and (atom (car lst)) (not(equal e (car lst))))		
			(isInList (cdr lst) e)
		)
		(
			(listp (car lst))
			(or (isInList (car lst) e) (isInList (cdr lst) e))
		)
	)
)
;(print "b:")
;(print (isInList '(1 2 3) 2))			;t
;(print (isInList '(1 2 3) 3))			;t		
;(print (isInList '(1 2 3) 1))			;t
;(print (isInList '(1 2 3) 4))			;nil
;(print (isInList '(1 (2 3)) 2))			;t
;(print (isInList '(1 (4 (3 5)) 2) 2))	;t
;(print (isInList '(1 (4 (3 5) 2)) 2))	;t
;(print (isInList '(1 (4 (3 5) 2)) 100))	;nil


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


(defun getSub(lst)
	(cond
		(
			(atom lst)
			nil
		)
		(
			(listp lst)
			(cons lst (getSub lst))
		)
		(
			t
			(mapcar (getSub lst))
		)
	)
)
;(trace getSub)
;(print (getSub  '(1 2 (3 (4 5) (6 7)) 8 (9 10)) ) )

(defun makeSet(lst)
	(cond
		(
			(null lst)
			nil
		)
		(
			(isInList (cdr lst) (car lst))
			(makeSet (cdr lst))
		)
		(
			(not(isInList (cdr lst) (car lst)))
			(cons (car lst) (makeSet (cdr lst)))
		)
	)
)
(print (makeSet  '(1 2 3 4 5 2 3 4 ) ) )