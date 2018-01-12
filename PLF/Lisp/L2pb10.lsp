(defun getLevel(lst e crt)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(equal (car lst) e)
			crt
		)
		(
			(not(equal (getLevel (cadr lst) e (+ crt 1)) nil))
			(getLevel (cadr lst) e (+ crt 1))
		)
		(
			t
			(getLevel (caddr lst) e (+ crt 1))
		)
	)
)
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'A 0))
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'B 0))
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'C 0))
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'D 0))
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'E 0))
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'I 0))
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'J 0))
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'F 0))
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'K 0))
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'G 0))
(print (getLevel '(A(B (D) (E (F(G)(H))))(C (I(K))(J))) 'H 0))

