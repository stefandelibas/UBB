(defun maxim(lst m)
	(cond 
		((null lst) m)
		((listp (car lst)) (maxim (cdr lst) (maxim (car lst) m)))
		((and (numberp (car lst)) (> (car lst) m)) (maxim (cdr lst) (car lst)))
		(t (maxim (cdr lst) m))

	)
)

(defun remMax(lst m)
	(cond
		((null lst) nil)
		((listp (car lst)) (cons  (remMax (car lst) m) (remMax (cdr lst) m)))
		((and (atom (car lst)) (not (equal (car lst) m))) (cons (car lst) (remMax (cdr lst) m)))
		((and (atom (car lst)) (equal (car lst) m)) (remMax (cdr lst) m))	
	)
)
(defun removeMax(lst)
	
		(if(listp lst)(remMax lst (maxim lst 0)))
	
)