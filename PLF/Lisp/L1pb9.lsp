


;b
(defun repl(lst e L1)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(and(atom (car lst)) (equal (Car lst) e))
			(append L1 (repl (cdr lst) e L1))								
		)
		(
			(and(atom (car lst)) (not(equal (Car lst) e)))
			(cons (car lst)(repl (cdr lst) e L1))								
		)
		(
			(listp (car lst))
			(cons (repl (car lst) e L1) (repl (cdr lst) e L1))
		)
	)
)
;(print (repl '(1 ( 2 ( 3 ) 3 ) 2 5 3 4) 3 '(100 200 300)))


;c

(defun mysum(a b c)
	(cond
		(
			(and (null a) (null b) (equal c 0))
			nil
		)
		(
			(and (null a) (null b) (equal c 1))
			(list 1)
		) 
		(
			(null a)
			(mysum b (list c) 0)
		)
		(
			(null b)
			(mysum a (list c) 0)
		)
		(
			(< (+ (car a) (car b) c) 10)
			(cons (+ (car a) (car b) c) (mysum (cdr a) (cdr b) 0))
		)
		(
			(>= (+ (car a) (car b) c) 10)
			(cons (mod (+ (car a) (car b) c) 10) (mysum (cdr a) (cdr b) 1))
		)
	)
)

(defun mysumOfList(a b)
	(reverse (mysum (reverse a) (reverse b) 0))
)

;(print (mysumOfList '(1 2 3) '(1 2 3))) 	;2 4 6
;(print (mysumOfList '(1 2 3) '(2)))		;1 2 5
;(print (mysumOfList '(1 2 3) '(1 2 9)))	;2 5 2
;(print (mysumOfList '( 9 9) '(1 1 1)))	;2 1 0

(print (mysumOfList '(9) '(1)))				;1 0
(print (mysumOfList '(9 9 9 9) '(1)))		;1 0 0 0 0 





