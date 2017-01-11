[bits 32]

section .text 
extern _printf
extern _exit

global  _main 

_main: 
       mov eax,[n1]
	   mov ecx,[n2]
	   add eax,ecx
	   mov [rez],eax
	   push dword [rez]
	   push dword format
	   call _printf
	   add esp,8
	   push 0
	   call _exit
       ret 

section .data
n1: dd 12
n2: dd 30
rez: dd 0
format: db '%d',0
