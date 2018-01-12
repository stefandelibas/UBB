
(defun isInTree(lst e)
	(cond
		(
			(null lst)
			nil
		)
		(
			(equal (car lst) e)
			t
		)
		(
			t
			(or (isInTree (cadr lst) e) (isInTree (caddr lst) e))
		)
	)
)

(defun pathToANode(lst n path)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(equal (car lst) n)
			(append path (list (car lst)))
		)
		(
			(isInTree (cadr lst) n)
			(pathToANode (cadr lst) n (append path (list (car lst))))
		)
		(
			(isInTree (caddr lst) n)
			(pathToANode (caddr lst) n (append path (list (car lst))))
		)
	)
)

(print (pathToANode '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'K nil))

(print (pathToANode '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'D nil))