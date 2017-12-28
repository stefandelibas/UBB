;--find all the nodes at a given level
;--in this solution of the problem edges represents the number of edges
;--and nodes represents the number of nodes
;-- lst is the list we are working on

(defun getLeft(lst nodes edges)

	(cond
		(
			(or(null lst) (> nodes edges))
			nil
		)	
		(
			(<= nodes edges)
			(append (list (car lst) (cadr lst)) (getLeft (cddr lst) (+ nodes 1) (+ edges (cadr lst))))
		)
	)
)
(defun getRight(lst nodes edges)
	
	(cond
		(
			(null lst)
			nil
		)
		(
			(<= nodes edges)
			(getRight (cddr lst) (+ nodes 1) (+ edges (cadr lst)))
		)
		(
			(> nodes edges)
			lst
		)
	)
)

(defun LeftTree(lst)
	(getLeft (cddr lst) 0 0)
)

(defun RightTree(lst)
	(getRight (cddr lst) 0 0)
)

;-- desired is the desired level 
;-- level is the current level we are on
(defun findNodesOnLevel(lst desired level)
	(cond
		(
			(null lst)
			nil
		)
		(
			(equal level desired)
			(list (car lst))
		)
		(
			(and (not (null (findNodesOnLevel (LeftTree lst) desired (+ level 1)))) (null (findNodesOnLevel (RightTree lst) desired (+ level 1))))
		 	(findNodesOnLevel (LeftTree lst) desired (+ level 1))
		) 
		(
			(and (null (findNodesOnLevel (LeftTree lst) desired (+ level 1))) (not(null (findNodesOnLevel (RightTree lst) desired (+ level 1)))))
			(findNodesOnLevel (RightTree lst) desired (+ level 1))
		) 
		(
			(and (not (null (findNodesOnLevel (LeftTree lst) desired (+ level 1)))) (not(null (findNodesOnLevel (RightTree lst) desired (+ level 1))))) 
			(append (findNodesOnLevel (LeftTree lst) desired (+ level 1)) (findNodesOnLevel (RightTree lst) desired (+ level 1)))
		) 
	)
)
;-- here level represents the desired level
(defun findLevel(lst level)
	(findNodesOnLevel lst level 0)
)

;--tests:
(print (findLevel '(A 2 B 2 D 0 E 1 F 2 G 0 H 0 C 2 I 1 K 0 J 0) -1))
(print (findLevel '(A 2 B 2 D 0 E 1 F 2 G 0 H 0 C 2 I 1 K 0 J 0) 0))
(print (findLevel '(A 2 B 2 D 0 E 1 F 2 G 0 H 0 C 2 I 1 K 0 J 0) 1))
(print (findLevel '(A 2 B 2 D 0 E 1 F 2 G 0 H 0 C 2 I 1 K 0 J 0) 2))
(print (findLevel '(A 2 B 2 D 0 E 1 F 2 G 0 H 0 C 2 I 1 K 0 J 0) 3))
(print (findLevel '(A 2 B 2 D 0 E 1 F 2 G 0 H 0 C 2 I 1 K 0 J 0) 4))
(print (findLevel '(A 2 B 2 D 0 E 1 F 2 G 0 H 0 C 2 I 1 K 0 J 0) 5))
