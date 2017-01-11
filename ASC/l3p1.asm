ASSUME cs: code, ds:data
data SEGMENT

a db 5
b db 3
c db 2
d dw 2
x dw ?
data ENDS

code SEGMENT
start:
mov ax,data
mov ds,ax

mov al,a
add al,b
sub al,c
mov bl,2
mul bl
add ax,d
mov bx,5
sub ax,bx

mov x,ax

mov ax,4C00h
int 21h
code ENDS
END start