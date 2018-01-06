
;a
(defun twiceNth(lst n)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(equal n 1)
			(append (list (car lst) (car lst)) (cdr lst))
		)
		(
			t
			(cons (car lst) (twiceNth (cdr lst) (- n 1)))
		)
	)
)

;(print (twiceNth '(1 2 3 4 5) 3))

;b
(defun assocation(a b)
	(cond 
		(
			(null a)
			nil
		)
		(
			t
			(cons (cons (car a)(car b)) (assocation (cdr a)(cdr b)))
		)
	)
)
;(print (assocation '(a b c) '(x y z)))

;c
(defun nrsublists(lst)
	(cond
		(
			(null lst)
			1
		)
		(
			(atom (car lst))
			(nrsublists (cdr lst))
		)
		(
			(listp (car lst))
			(+ (nrsublists (car lst)) (nrsublists (cdr lst)))
		)
	)
)

;(print (nrsublists '(1 2 (3 (4 5) (6 7)) 8 (9 10))))

;d
(defun numbersSuperficial(lst)
	(cond
		(
			(null lst)
			0
		)
		(
			(numberp (car lst))
			(+ 1 (numbersSuperficial (cdr lst)))
		)
		(
			t
			(numbersSuperficial (cdr lst))
		)
	)
)
(print (numbersSuperficial '(1 2 a b( 1 2 a (5 1 b) 3) c w 3)))









