;pb 2 L1

;a
(defun dotProduct(a b)
	(cond
		(
			(null a)
			0
		)
		(
			t
			(+ (* (car a)(car b)) (dotProduct (cdr a)(cdr b)))
		)
	)
)
;(print (dotProduct '(1 -3 5 7) '(4 5 1 2)))

;b
(defun maxim(a b)
	(cond
		(
			(>= a b)
			a
		)
		(
			t
			b
		)
	)
)

(defun depth(lst crt)
	(cond
		(
			(null lst)
			crt
		)
		(
			(atom (car lst))
			(depth (cdr lst) crt)
		)
		(
			(listp(car lst))
			(maxim (depth (car lst) (+ 1 crt)) (depth (cdr lst) 1))
		)
	)
)
;(print (depth '(1 (2 3) (4 5) (6 7)) 1))

;c
(defun insertSorted(lst e)
	(cond
		(
			(null lst)
			(list e)
		)
		(
			(> (car lst) e)
			(cons e lst)
		)
		(
			(< (car lst) e)
			(cons (car lst) (insertSorted (cdr lst) e))
		)
		(
			(equal (car lst) e)
			lst
		)
	)
)

(defun sortList(lst)
	(cond
		(
			(null lst)
			nil
		)
		(
			t
			(insertSorted (sortList (cdr lst)) (car lst))
		)
	)
)
;(print (sortList '(5 4 2 3 1 6 3)))

;d
(defun isInList(lst e)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(and (atom (car lst)) (equal e (car lst)))	
			t
		)
		(
			(and (atom (car lst)) (not(equal e (car lst))))		
			(isInList (cdr lst) e)
		)
		(
			(listp (car lst))
			(or (isInList (car lst) e) (isInList (cdr lst) e))
		)
	)
)

(defun intersectionSets (a b)
	(cond
		(
			(null a)
			nil
		)
		(
			(isInList b (car a))
			(cons (car a) (intersectionSets (cdr a) b))
		)
		(
			t
			(intersectionSets (cdr a) b)
		)

	)
)
(print (intersectionSets '(1 2 3 4 5) '(2 5 6 7 4)))