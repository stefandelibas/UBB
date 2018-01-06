(defun removeNth(lst n)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(equal n 1)
			(cdr lst)
		)
		(
			t
			(cons (car lst) (removeNth (cdr lst) (- n 1)))
		)
	)
)
;(print (removeNth '(1 2 3 4 5 6) 3))
;(print (removeNth '(1 2 3 4 5 6) 8))

;b
(defun rev(lst)
	(cond 
		(
			(null lst)
			nil
		)
		(
			t
			(append (rev (cdr lst)) (list (car lst)))
		)
	)
)
(defun increment(lst c)
	(cond 
		(
			(and (null lst)(equal c 1))
			(list 1)
		)
		(
			(null lst)
			nil
		)
		(
			(and (equal c 1) (= (+ (car lst) 1) 10))
			(cons 0 (increment (cdr lst) 1))
		)
		(
			(and (equal c 1) (< (+ (car lst) 1) 10))
			(cons (+ (car lst) 1) (increment (cdr lst) 0))
		)
		(
			(not (equal c 1)) 
			(cons (car lst) (increment (cdr lst) 0))
		)
	)
)

(defun inc(lst)
	(rev (increment (rev lst) 1))
)

;(print (inc '(9 9 9)))

;c
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
(defun allAtoms(lst rez)
	(cond 
		(
			(null lst)
			rez
		)
		(
			(and (atom (car lst)) (not(isInList rez (car lst))))
			(allAtoms (cdr lst) (cons (car lst) rez))
		)
		(
			(and (atom (car lst)) (isInList rez (car lst)))
			(allAtoms (cdr lst) rez)
		)
		(
			(listp (car lst))
			(allAtoms (cdr lst) (allAtoms (car lst) rez))
		)
	)
)
;(print (allAtoms '(1 (2 (1 3 (2 4) 3) 1)5 (1 4)) nil))

;d
(defun isSet(lst)
	(cond 
		(
			(null lst)
			t
		)
		(
			(isInList (cdr lst) (Car lst))
			nil
		)
		(
			t
			(isSet (cdr lst))
		)
	)
)
(print (isSet '(1 2 3 4 5)))
(print (isSet '(1 2 3 2 5)))
(print (isSet '(1 2 3 4 5 5)))
