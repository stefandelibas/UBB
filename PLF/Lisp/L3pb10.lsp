(defun replaceAtom(lst torepl replwith)
	(cond
		(
			(and(equal lst torepl)(atom lst))
			replwith
		)
		(
			(and(not(equal lst torepl))(atom lst))
			lst
		)
		(
			T 
			(mapcar #'(lambda(x)(replaceAtom x torepl replwith)) lst) 
		)
	)
)

(print (replaceAtom '(a (b (c)) (d) (e (b))) 'b 'Q))