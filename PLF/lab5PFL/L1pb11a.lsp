(defun cmmdc(a b)
	(cond
		((equal a 0) :positive-infinity)
		((equal b 0) :positive-infinity)
		((equal a b) a)
		((> a b) (cmmdc (- a b) b))
		((< a b) (cmmdc a (- b a)))
	)
)

(defun cmmmc(a b)
	(/ (* a b) (cmmdc a b))
)

	  
(defun LCMList(x)
  (cond
  	((NULL x) 1)
  	((and (null (cdr x)) (numberp(car x))) (car x))
  	((listp (car x)) (cmmmc (LCMList (car x)) (LCMList(cdr x))))
  	((numberp (car x)) (cmmmc (car x) (LCMList(cdr x))))
  	(t  (LCMList(cdr x)))
  )
)