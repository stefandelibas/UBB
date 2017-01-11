ASSUME cs: code, ds:data
data SEGMENT
	s1 DB '1','2','3','4'
	len1 equ $-s1
	s2 DB '5','6','7'
	len2 equ $-s2
	len equ len1+len2
	d DB len dup(?)
data ENDS

code SEGMENT
	start:
	mov ax,data
	mov ds,ax
	mov ES,AX

	;mov BX,0
	;repeat1:
		;mov AL,s1[BX]
		;mov d[BX],AL
		;add BX,1
		;cmp BX,len1
	;jb repeat1


	mov CX,len1
	lea SI,s1
	lea DI,d
	repeat1:
		movsb
	loop repeat1



	mov CX,len1
	lea SI,d-1			;similar to mov SI, offset d-1
	lea DI,d+len1 		;similar to mov DI,d+len1
	
	repeat2:
		std
		lodsb
		cld
		stosb
	loop repeat2

	mov ax,4C00h
	int 21h
code ENDS
END start