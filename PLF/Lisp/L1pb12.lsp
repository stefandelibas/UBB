

;b
(defun maxNr(lst m)
	(cond
		(
			(null lst)
			m
		)
		(
			(and(numberp (car lst)) (> (car lst) m))
			(maxNr (cdr lst) (car lst))
		)
		(
			(and (listp (car lst)) (>= (maxNr (car lst) m) (maxNr (cdr lst) m)))
			(maxNr (car lst) m)
		)
		(
			t
			(maxNr (cdr lst) m)
		)
	)
)
(defun getMaxNr(lst)
	(maxNr lst -999999999999999)
)
;(print (getMaxNr '(1 2( 3 4 (2  3) 5) 6)))

;d
(defun isOdd(lst c)
	(cond
		(
			(and (null lst)(equal c 0))
			t
		)
		(
			(and (null lst)(equal c 1))
			nil	
		)
		(
			(equal c 0)
			(isOdd (cdr lst) 1)
		)
		(
			(equal c 1)
			(isOdd (cdr lst) 0)
		)
	)
)

(defun hasOddNumberOfElementsOn1stLever(lst)
	(isOdd lst 1)
)
(print (hasOddNumberOfElementsOn1stLever '(1 2 3)))