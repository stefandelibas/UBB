
;a
(defun insert2th (lst e crt)
	(cond
		(
			(and(null lst) (not(equal crt 2)))
			nil
		)
		(
			(and(null lst) (equal crt 2))
			(list e)
		)
		(
			(equal crt 2)
			(append (list e (car lst)) (insert2th (cdr lst) e 1))
		)
		(
			(not(equal crt 2))
			(cons (car lst) (insert2th (cdr lst) e (+ crt 1)))
		)
	)
)

;(print (insert2th '(1 2 3 4 5 6 7 8 9 10) 100 0))

;b
(defun linRev(lst)
	(cond
		(
			(null lst)
			nil
		)
		(
			(atom (car lst))
			(append (linRev (cdr lst)) (list (car lst)))
		)
		(
			(listp (car lst))
			(append (linRev (cdr lst)) (linRev (car lst)))
		)
	)
)
;(print (linRev '(((A B) C) (D E))))

;c
(defun cmmdc(a b)
	(cond
		(
			(equal a 0) :positive-infinity
		)
		(
			(equal b 0) :positive-infinity
		)
		(
			(equal a b)
			a
		)
		(
			(> a b)
			(cmmdc (- a b) b)
		)
		(
			(< a b)
			(cmmdc a (- b a))
		)
	)
)

(defun cmmdcList(lst)
	(cond
		(
			(null lst)
			0
		)
		( 	
			(and (null (cdr lst)) (numberp (car lst)))
			(car lst)
		)
		(
			(listp (car lst))
			(cmmdc (cmmdcList (car lst)) (cmmdcList (cdr lst)))
		)
		(
			(numberp (car lst))
			(cmmdc (car lst) (cmmdcList (cdr lst)))
		)
		(
			t
			(cmmdcList (cdr lst))
		)
	)
)
;(print (cmmdcList '(3 9 24 54 A 45)))

;d

(defun noOcc(lst e)
	(cond
		(
			(null lst)
			0
		)
		(
			(and(atom (car lst)) (equal (car lst) e))
			(+ 1 (noOcc (cdr lst) e))
		)
		(
			(atom (car lst))
			(noOcc (cdr lst) e)
		)
		(
			(listp (car lst))
			(+ (noOcc (car lst) e) (noOcc (cdr lst) e))
		)
	)
)

(print (noOcc '(1 2 1 (2 2 4) (5 (2))) 2))