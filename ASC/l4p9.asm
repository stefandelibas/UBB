ASSUME cs: code, ds:data
data SEGMENT
a db 5
b db 3
c dw 1
e dd 2
x dd ?
data ENDS

code SEGMENT
start:
mov ax,data
mov ds,ax

mov BL,a
sub BL,b
mov BH,0
mov CX,0
mov Dx,128
mov AX,c
imul DX
add AX,BX
adc DX,CX
mov BL,a
add BL,b
mov BH,0
idiv BX
mov DX,0
add AX, word PTR e
add DX, word PTR e+2
mov word PTR x,AX
mov word PTR x+2,DX

mov ax,4C00h
int 21h
code ENDS
END start