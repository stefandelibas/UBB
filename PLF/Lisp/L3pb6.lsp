(defun getMax(lst m)
	(cond
		(
			(null lst)
			nil
		)
		(
			(numberp lst)
			lst
		)
		(
			(atom lst)
			-9999999
		)
		(
			t
			(apply 'max  (mapcar #'(lambda(x)(getMax x m)) lst))
		)
	)
)


(print (getMax '(1 (3 6 2 4) 5) 0))