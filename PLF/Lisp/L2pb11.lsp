
(defun getNodesOnLevel(lst lvl crt)
	(cond 
		(
			(null lst)
			nil
		)
		(
			(equal lvl crt)
			(list (car lst))
		)
		(
			(> lvl crt)
			(append (getNodesOnLevel (cadr lst) lvl (+ 1 crt)) (getNodesOnLevel (caddr lst) lvl (+ 1 crt)))
		)
	)
)

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

(defun getMaxNodesOnALevel(lst de crt)
	(cond
		(
			(> crt de)
			0
		)
		(
			t
			(max (length (getNodesOnLevel lst crt 0)) (getMaxNodesOnALevel lst de (+ crt 1)))	
		)
		
	)
)
(defun LevelWithMax(lst de crt m)
	(cond
		(
			(equal (length (getNodesOnLevel lst crt 0)) m)
			(cons crt (getNodesOnLevel lst crt 0))
		)
		(
			t
			(LevelWithMax lst de (+ 1 crt) m)	
		)
		
	)
)

(defun getLevelWithMax(lst)
	(LevelWithMax lst (depth lst 0) 0 (getMaxNodesOnALevel lst (depth lst 0) 0))
)

(print (getLevelWithMax '(A(B (D) (E (F(G)(H))))(C (I(K))(J)))))
