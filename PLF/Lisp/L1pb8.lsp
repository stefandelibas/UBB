
;a

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

(defun diffSets(a b)
	(cond 
		(
			(null a)
			nil
		)
		(
			(not(isInList b (car a)))
			(cons (car a) (diffSets (cdr a) b))
		)
		(
			t
			(diffSets (cdr a) b)
		)
	)
)
;(print (diffSets '(1 2 3 4 5 6) '(1 2 3)))

;b

(defun rev(lst)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(atom (car lst))
			(append (rev (cdr lst)) (list (car lst)))
		)
		(
			(listp (car lst))
			(append (rev (cdr lst)) (list (rev (car lst))))
		)
	)
)

;(print (rev '((1 2)(3 (4 5))(6 (7 8 (9 10))))))

;c

(defun countSuperficial(lst )
	(cond 
		(
			(null lst)
			0
		)
		(
			(atom (car lst))
			(+ 1 (countSuperficial (cdr lst)))
		)
		(
			t
			(countSuperficial (cdr lst))
		)
	)
)
(defun isOddSuperficial(lst)
	(cond 
		(
			(equal(mod (countSuperficial lst) 2) 1)
			t 
		)
		(
			t
			nil
		)
	)
)
(defun getFirst(lst)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(numberp (Car lst))
			(car lst)
		)
		(
			(listp (Car lst))
			(getFirst (car lst))
		)
	)
)
(defun repl(lst)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(and (listp (car lst)) (isOddSuperficial (car lst)))
			(cons (getFirst (Car lst)) (repl (cdr lst)))
		)
		(
			t
			(repl (cdr lst))
		)
	)
)
(defun replOddListsWith1stElement(lst)
	(cond
		(
			(isOddSuperficial lst)
			(cons (getFirst lst) (repl lst))
		)
		(
			t
			(repl lst)
		)
	)
)
;(print (replOddListsWith1stElement '(1 2 (3 (4 5) (6 7)) 8 (9 10 11))))

;d

(defun sumSuperficial(lst)
	(cond 
		(
			(null lst)
			0
		)
		(
			(numberp (car lst))
			(+ (car lst) (sumSuperficial (cdr lst)))
		)
		(
			t
			(sumSuperficial (cdr lst))
		)
	)
)

(print (sumSuperficial '(1 2 (3 4) 5 ((6) 7))))
