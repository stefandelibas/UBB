[bits 32]

section .text 

extern  _printf
extern _exit

global  _main 

_main: 
		mov ecx,0
		mov ebx,0
		mov edx,len
		repeta:
			mov eax,v[ecx]
			cmp eax,0
			jge continua
			neg eax
			continua:
			add ebx,eax
			inc ecx
		cmp edx,ecx
	    ja repeta
		
		push dword ebx
        push    DWORD format
        call    _printf
        add     esp, 8
        push    0
        call    _exit
        ret 

section .data

v: dd 1,-10,5,2,5,0,-9,17
len: equ ($-v)/4
format: dd "%d",0