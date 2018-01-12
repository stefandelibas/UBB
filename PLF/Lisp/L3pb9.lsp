(defun removeElem(lst e)
	(cond
		(
			(and (atom lst)(equal lst e))
			nil
		)
		(
			(and (atom lst)(not(equal lst e)))
			(list lst)
		)
		(
			t
			(list (mapcan #'(lambda(x)(removeElem x e)) lst))
		)
	)
)

(defun removeFinal(lst e)
	(car (removeElem lst e))
)

(print (removeFinal '(1 2 (3 (2 ( 77 2) 9)6 2 4) 2 5) '2))