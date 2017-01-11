ASSUME cs: code, ds:data
data SEGMENT
	a dw 0111011000111001b
	b dw 1110101000110001b
	c dw ?
data ENDS

code SEGMENT
	start:
		mov ax,data
		mov ds,ax
	mov c,0

	mov AX,a
	shr AX,11
	or AX,0000111111100000b
	mov c,AX
	mov AX,b
	shl AX,4
	and AX,1111000000000000b
	or c,AX

	mov ax,4C00h
	int 21h
code ENDS
END start