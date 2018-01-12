
(defun depth(lst crt)
	(cond 
		(
			(null (cdr lst))
			crt
		)
		(
			t
			(max (depth (cadr lst) (+ 1 crt)) (depth (caddr lst) (+ 1 crt)))
		)
	)
)

(defun isBalanced(lst)
	(cond
		(
			(null lst)
			t 
		) 
		(
			(> (abs(- (depth (caddr lst) 0) (depth (cadr lst) 0))) 1)
			nil
		)
		(
			t
			(and (isBalanced (cadr lst)) (isBalanced (caddr lst)))
		)
	)
)
(print (isBalanced '(A(B)(C)) ))
(print (isBalanced '(A(B(D)(E (Q)   ))(C(F) (R) )) ))
(print (isBalanced '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) ))