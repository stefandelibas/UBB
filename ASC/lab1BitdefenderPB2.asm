[bits 32]

section .text 

extern  _printf
extern _exit

global  _main 

_main: 
	    mov eax,[n1]
		mov ebx,[n2]
	repeta:
        cmp eax,ebx
		jmp sc
	    sub ebx,eax	
		sc:
		sub eax,ebx
	cmp eax,ebx
	jne repeta
		
		mov [rez],eax
		push dword [rez]		
		push format
        call    _printf
        add     esp, 8
        push    0
        call    _exit
        ret 

section .data

n1: dd 40
n2: dd 5
rez: dd 0
format: db '%d',0