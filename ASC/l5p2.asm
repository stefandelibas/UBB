ASSUME cs:code, ds:data
data SEGMENT
	a dw 1001111011011010b
	b dw 1010001110000111b
	c dw ?
data ENDS

code SEGMENT
	start:
		mov ax,data
		mov ds,ax
	mov CX,0
	mov AX,b
	shr AX,5
	and AX,0000000000001111b
	or CX,AX
	mov AX,a
	shl AX,4
	and AX,0000000111110000b
	or CX,AX
	mov AX,a
	shl AX,3
	and AX,1111111000000000b
	or CX,AX+
	mov c,CX

	mov ax,4C00h
	int 21h
code ENDS
END start