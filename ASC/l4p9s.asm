ASSUME cs: code, ds:data
data SEGMENT
a db 5
b db 3
c dw 1
e dd 2
f dd ?
g dd ?
h dw ?
x dd ?
data ENDS

code SEGMENT
start:
mov ax,data
mov ds,ax

mov AL,a
sub AL,b
cbw
cwd
mov word PTR f,AX
mov word PTR f+2,DX
mov DX,128
mov AX,c
imul DX
add AX,word PTR f
adc DX,word PTR f+2
mov word PTR g,AX
mov word PTR g+2,DX
mov AL,a
add AL,b
cbw
mov h,AX
mov AX,word PTR g
mov DX,word PTR g+2
idiv h
add AX, word PTR e
adc DX, word PTR e+2
mov word PTR x,AX
mov word PTR x+2,DX

mov ax,4C00h
int 21h
code ENDS
END start