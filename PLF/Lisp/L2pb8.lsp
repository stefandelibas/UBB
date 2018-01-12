(defun inorder(lst)
	(cond 

		(
			(null lst)
			nil
		)
		(
			t
			(append (inorder (cadr lst)) (list (car lst)) (inorder (caddr lst)))
		)
				
	)
)
(print (inorder '(A(B (D) (E (F(G)(H))))(C (I(K))(J)))))