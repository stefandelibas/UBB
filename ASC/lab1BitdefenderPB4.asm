
section .text
extern _printf
extern _exit
extern __time32
extern _getchar


global _main
_main:
		push 0
		call __time32 
		mov [s],EAX
		add ESP,4

		random:
		call _getchar 
		cmp EAX,-1
		je finish

		mov EAX,[s]
		shr EAX,8 

		mov [r],AX

		push dword [r]
		push format
		call _printf
		add ESP,8

		mov AX,[r]
		mul AX; 

		mov [s],AX
		mov [s+2],DX 
		mov EAX,[s]
		add EAX,k
		mov [s],EAX

		jmp random

		finish:
		push 0
		call _exit
		ret
		
section .data
	format db '%d',0
	s dd 0
	r dd 0
	k equ 257
