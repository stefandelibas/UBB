
;a

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

(defun diffSets(a b)
	(cond 
		(
			(null a)
			nil
		)
		(
			(not(isInList b (car a)))
			(cons (car a) (diffSets (cdr a) b))
		)
		(
			t
			(diffSets (cdr a) b)
		)
	)
)
(defun unionSets(a b) 
	(append a (diffSets b a))
)

;(print (unionSets '(1 2 3 4) '(1 3 4 5 6)))

;b
(defun prod(lst)
	(cond
		(
			(null lst)
			1
		)
		(
			(numberp (car lst))
			(* (car lst) (prod (cdr lst)))
		)
		(
			(listp (car lst))
			(* (prod (car lst)) (prod (cdr lst)))
		)
	)
)

;(print (prod '(1 2( 3 (4) 2 ))))

;c
(defun insertSorted(lst e)
	(cond
		(
			(null lst)
			(list e)
		)
		(
			(> (car lst) e)
			(cons e lst)
		)
		(
			(<= (car lst) e)
			(cons (car lst) (insertSorted (cdr lst) e))
		)
	)
)

(defun sortList(lst)
	(cond
		(
			(null lst)
			nil
		)
		(
			t
			(insertSorted (sortList (cdr lst)) (car lst))
		)
	)
)
;(print (sortList '(5 4 2 3 1 6 3)))

;d
(defun minElem(lst m)
	(cond 
		(
			(null lst)
			m
		)
		(
			(and(numberp (car lst)) (< (car lst) m))
			(minElem (cdr lst) (car lst))	
		)
		(
			t
			(minElem (cdr lst) m)
		)
	)
)
(defun indexOfN(lst n crt)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(equal (car lst) n)
			(cons crt (indexOfN (cdr lst) n (+ crt 1)))
		)
		(
			t
			(indexOfN (cdr lst) n (+ crt 1))
		)
	)
)
(defun getMin(lst)
	(minElem lst 99999999999999999999)
)
(defun indexOfMin(lst)
	(indexOfN lst (getMin lst) 1)
)

(print (indexOfMin '(5 6 1 2 3 4 1 2 3 1)))