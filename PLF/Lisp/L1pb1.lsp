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
(defun getNthElement (lst n)
	(nthElement lst n 1)
)
(print "a:")
(print (getNthElement '(1 2 3 4 5 6) 5))
(print (getNthElement '(1 2 3 4 5 6) 6))
(print (getNthElement '(1 2 3 4 5 6) 7))

