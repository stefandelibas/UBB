(defun mtn(lst ck)
	(cond 
		((and (equal (length lst) 2) (equal ck 1)) 1)
		((and (equal (length lst) 2) (not(equal ck 1))) 0)
		((and(< (car lst) (cadr lst)) (> (cadr lst) (caddr lst))) (mtn (cdr lst) (+ ck 1)))
		((and(> (car lst) (cadr lst)) (< (cadr lst) (caddr lst))) 0)
		(t  (mtn (cdr lst) ck))
	)
)
(defun mountain(lst)
	(mtn lst 0)
)