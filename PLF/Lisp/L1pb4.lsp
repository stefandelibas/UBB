;a
(defun sumVectors(a b)
	(cond
		(
			(null a)
			nil
		)
		(
			t
			(cons (+ (car a) (car b)) (sumVectors (cdr a) (cdr b)))
		)
	)
)
;(print (sumVectors '(1 2) '(3 4)))

;b
(defun lin(lst)
	(cond
		(
			(null lst)
			nil
		)
		(
			(atom (car lst))
			(cons (car lst) (lin (cdr lst)))
		)
		(
			(listp (car lst))
			(append (lin (car lst)) (lin (cdr lst)))
		)
	)
)

;(print (lin '((A)B(C(D(E)))F)))

;c   ----------------------------???????????????????????????????????????????????/
(defun reverseContigous(lst c)
	(cond
		(
			(null lst)
			nil
		)
		(
			(null c)
			(reverseContigous (cdr lst) (list (car lst)))
		)
		(
			(atom (car lst))
			(reverseContigous (cdr lst) (cons c (car lst)))
		)
		(
			(listp (car lst))
			(cons c (reverseContigous (cdr lst) nil))
		)
	)
)

;(print (reverseContigous '(a b c (d (e f) g h i)) nil))

;d
(defun maxSuperficial(lst m)
	(cond
		(
			(null lst)
			m
		)
		(
			(and(numberp (car lst)) (> (car lst) m))
			(maxSuperficial (cdr lst) (car lst))
		)
		(
			t
			(maxSuperficial (cdr lst) m)
		)
	)
)
(defun maxNumberSuperficial (lst)
	(maxSuperficial lst -9999999999999999)
)
(print (maxNumberSuperficial '(1 2 3(4 5) -2 3 A (5 B 8 (9)))))










