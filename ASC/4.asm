ASSUME CS:code, DS:data

data SEGMENT
	e dw 01fh
	six dw 16
	tabHexa db "0123456789abcdef"
data ENDS

code SEGMENT
	start:
	push data
	pop ds
	
	mov ax,e
	mov cx,0
	imparte:
		mov dx,0			;extend ax to dx:ax
		div six				;divide dx:ax with constant 16
		push dx				;dx will store the reminder of the previous division, so we save every reminder in the stack
		inc cx				;count how many characters should be displayed (hexadecimal digits)
	cmp ax,0				;if it is not 0 then it can still be divided by 16
	jne imparte
	
	afis16:
		pop ax					;take each reminder in reverse order
		mov bx,offset tabHexa	;load in bx the tabHexa offset
		xlat					;translate the byte from AL using tabHexa
		mov dl,al
		mov ah,02h				;prepare for printing a character
		int 21h
	loop afis16
	
	mov ax,4C00h
	int 21h
code ENDS
END start