(defun sEvenDOdd(lst)
	(cond 
		(
			(and (numberp lst) (equal (mod lst 2) 0))
			lst
		)
		(
			(and (numberp lst) (equal (mod lst 2) 1))
			(- 0 lst)
		)
		(
			(atom lst)
			0
		)
		(
			t
			(apply '+ (mapcar 'sEvenDOdd lst))
		)
	)
)

(print (sEvenDOdd '(1 2 a 3( 4 b 5) 6)))