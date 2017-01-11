ASSUME cs: code, ds:data
data SEGMENT
	s1 db 'acgy'
	l1 equ $-s1
	s2 db 'abdehz'
	l2 equ $-s2
	len equ l1+l2 
	s db len dup(?)
	e dw ?
	f dw ?
data ENDS

code SEGMENT
	start:
		mov AX,data
		mov DS,AX
		mov ES,AX

		lea si,s1									;we will set the source string as the first string (s1)
		lea di,s									;we will set the destiantion string offset with the offset of s
		mov bx, offset s2							;bx register will be the conter through the 2nd string

		cld											;the DF register is set to 0,so the direction of the parsing the strings is from left to right
		mov dx,0									;dx register will be used as a counter through s1 string
		mov cx,0									;cx register will be used as a counter through destination string s

		repeta:
			mov AL,[bx]								;we will store the value of the current value in s2 in AL
			cmp AL, byte ptr DS:[si]				;and we will compare it with the value from ds:[si] where it's the current value in s1
			jb inserts2								;if current chr from s2 < current chr from s1 we will insert in the destination string from s2
			jae inserts1								;if current chr from s1 < current chr from s1 we will insert in the destination string from s1
			
			inserts2:
				stosb								;store the current chr from s2 in the destination string
				add CX,1							;increase the counter for the 2nd string (s2)
				add BX,1							;increase the conter for the 2nd string (s2)
				cmp CX,l2							;compare cx with l2
				jbe nimic							;if the cx < l2 than it means the s2 has been completly used
			inserts1:								
				movsb								;we load the current chr from s1 in AL and then we store it in the destination string
				add dx,1							;we increase the counter for the 1st string (s1)

			nimic:
			mov e,CX								;we save the counter of destination string in a variable
			mov f,DX								;we save the counter of s1 in a variable
			mov CL,s2[l2-1]							;we store the last chr of s2 in CL
			mov DL,s1[l1-1]							;we store the last chr of s1 in DL 
			cmp CL,DL								;we compare the last chrs from each strings 
			jb go2									
			jae go1									

			go2:
				mov CX,e 							;recover the conter
				mov DX,f 							;recover the conter
				cmp CX,l2 							;compare the counter with the len of 2nd string
				jae nimic3							;if the the 2nd string is completely used we jump and fill the destination string with the
													;remaning characters left in 1st string
				jb repeta 							;otherwise the process starts from the beginning
				
			go1:
				mov CX,e 							;recover the counter
				mov DX,f 							;recover the counter
				cmp DX,l1 							;compare the counter with the len of 1st string
				jae nimic2							;if the the 1st string is completely used we jump and fill the destination string with the
													;remaning characters left in 2nd string
				jb repeta							;otherwise the process starts from the beginning
		nimic2:	
			mov AL,[bx]								;we will store the value of the current value in s2 in AL
			stosb									;store the current chr from s2 in the destination string
			add CX,1								;increase the counter for the 2nd string (s2)
			add BX,1								;increase the conter for the 2nd string (s2)
			cmp CX,l2 								;we compare the counter in s2 with the len of 2nd string
			jb nimic2								;if cx < l2 then it means the s2 is not fully complete
			jbe sfarsit								;otherwise the problem is solved
		nimic3:
			movsb									;we move from ds:si to es:di
			add DX,1								;increase the counter of s1
			cmp DX,l1 								;we compare the counter in s2 with the len of 2nd string
			jb nimic3								;if dx < l1 then it means s1 is not fully complete
	sfarsit:
	mov AX,4C00h
	int 21h
	code ends
	end start
		mov ax,4C00h
	int 21h
code ENDS
END start