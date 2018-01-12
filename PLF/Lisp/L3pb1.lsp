(defun isMember(lst e)
	(cond 
		(
			(and (atom lst) (equal lst e))
			2
		)
		(
			(and (atom lst) (not(equal lst e)))
			1
		)
		
		(
			t
			(apply '* (mapcar #'(lambda(x)(isMember x e)) lst))
		)
	)
)
(defun isMemberOf(lst e)
	(cond
		(
			(equal (isMember lst e) 1)
			nil
		)
		(
			t
			t

		)
	)
)
(print (isMemberOf '(1  (3 2 4) 5) '2))