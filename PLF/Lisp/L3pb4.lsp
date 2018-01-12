(defun prodAtoms(lst)
	(cond 
		(
			(numberp lst)
			lst
		)
		(
			(atom lst)
			1
		)
		(
			t
			(apply '* (mapcar 'prodAtoms lst))
		)
	)
)

(print (prodAtoms '(1 2 a 3( 1 b 10))))