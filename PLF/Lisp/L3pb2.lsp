(defun sumAtoms(lst)
	(cond 
		(
			(numberp lst)
			lst
		)
		(
			(atom lst)
			0
		)
		(
			t
			(apply '+ (mapcar 'sumAtoms lst))
		)
	)
)

(print (sumAtoms '(1 2 a 3( 4 b 5))))