;a
(defun isLinear(lst)
	(cond 
		(
			(null lst)
			T
		)
		(
			(listp (car lst))
			nil
		)
		(
			T
			(isLinear (cdr lst))
		)
	)
)

;(print (isLinear '(1 2 3 4)))
;(print (isLinear '(1 2 (3) 4)))

;c
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
(defun getLastElem(lst)
	(cond
		(
			(null (cdr lst))
			(car lst)
		)
		(
			(listp (car lst))
			(getLastElem )
		)
		(
			T
			(getLastElem (cdr lst))
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
			(atom (Car lst))
			(cons (car lst) (repl (cdr lst)))
		)
		(
			(listp (car lst))
			(cons (getLastElem (lin(car lst))) (repl (cdr lst)))
		)
	)
)
;(print (repl '(a (b c) (d(e(f))))))


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


;d
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

(defun remDoubles(lst)
	(cond
		(
			(null lst)
			nil	
		)
		(
			(isInList (cdr lst) (car lst))
			(remDoubles (cdr lst))
		)
		(
			t
			(cons (car lst) (remDoubles (cdr lst)))
		)
	)
)
(defun mergeSets(a b)
	(sortList (remDoubles (append a b)))
)
(print (mergeSets '(1 2 3 5 6) '(2 4 5 7)))


