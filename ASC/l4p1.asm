ASSUME cs: code, ds:data
data SEGMENT
	a db 3
	b dd 2
	c dd ?
	d dw ?
	x dw ?
data ENDS

code SEGMENT
	start:
		mov ax,data
		mov ds,ax
	mov AL,a
	mul a
	mov DX,0
	;mov CX,word PTR b
	;mov BX,word PTR b+2
	sub AX,word PTR b
	sbb DX,word PTR b+2
	mov word PTR c,AX
	mov word Ptr c+2,DX
	mov AL,7
	mov AH,0
	mov DX,0
	add word PTR c,AX
	adc word PTR c+2,DX
	mov AL,2
	add AL,a
	mov AH,0
	adc AH,0
	mov d,AX
	mov AX,word PTR c
	mov DX,word PTR c+2
	div d
	mov x,AX

	mov ax,4C00h
	int 21h
code ENDS
END start