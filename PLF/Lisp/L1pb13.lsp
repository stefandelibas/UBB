
;a
(defun removeNToN(lst n c)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(equal c 1)
			(removeNToN (cdr lst) n n)
		)
		(
			(not(equal c 1))
			(cons (car lst) (removeNToN (cdr lst) n (- c 1)))
		)
	)
)

(defun remNtoN (lst n)
	(removeNToN lst n n)
)

;(print (remNtoN '(1 2 3 4 5 6 7 8 9 10) 3))

;b
(defun valley(lst ck)
	(cond 
		(
			(and (equal (length lst) 2) (equal ck 1))
			t
		)
		(
			(and (equal (length lst) 2) (not(equal ck 1))) 
			nil
		)
		(
			(and(< (car lst) (cadr lst)) (> (cadr lst) (caddr lst)))
		 	nil
		)
		(
			(and(> (car lst) (cadr lst)) (< (cadr lst) (caddr lst)))
			(valley (cdr lst) (+ ck 1))
		)
		
		(
			t 
			(valley (cdr lst) ck)
		)
	)
)
(defun isValley(lst)
	(valley lst 0)
)


;(print (isValley '(5 4 3 2 1 2 3 4 5 6)))
;(print (isValley '(5 4 5)))
;(print (isValley '(5 4 3 2 1 2 3 4 5 6 5)))
;(print (isValley '(5 4 3 2 1 2 3 2 1)))

;c
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
			(listp (car lst))
			(minElem (cdr lst) (minElem (car lst) m))
		)
		(
			t
			(minElem (cdr lst) m)
		)
	)
)
(defun getMin(lst)
	(minElem lst 99999999999999999999)
)
;(print (getMin '(1 2 ( 5 3) 4 (2 (1 0 2) 6))))

;d
(defun maxim(lst m)
	(cond 
		(
			(null lst)
			m
		)
		(
			(listp (car lst))
			(maxim (cdr lst) (maxim (car lst) m))
		)
		(
			(and (numberp (car lst)) (> (car lst) m)) 
			(maxim (cdr lst) (car lst))
		)
		(
			t
			(maxim (cdr lst) m)
		)
	)
)

(defun getMaxNr(lst)
	(maxim lst -999999999999999)
)

(defun remMax(lst m)
	(cond
		(
			(null lst)
			nil
		)
		(
			(listp (car lst))
			(cons (remMax (car lst) m) (remMax (cdr lst) m))
		)
		(
			(and (atom (car lst)) (not (equal (car lst) m)))
			(cons (car lst) (remMax (cdr lst) m))
		)
		(
			(and (atom (car lst)) (equal (car lst) m))
			(remMax (cdr lst) m)
		)	
	)
)
(defun removeMax(lst)
	
	(if(listp lst)(remMax lst (maxim lst 0)))	
)
;(print (removeMax '(1 2 3( 4 (3 2) 4 1 2) 4 2 )))