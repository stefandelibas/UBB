ASSUME cs: code, ds:data
data SEGMENT
	msg db 'insert a character: $'
	msg_letter db "you inserted a non-number character, we'll show all letters at the end of the programm",0dh,0ah,'$'
	msg_no_letter db "no letter was inserted during the run time of this programm, so we have nothing to display",'$'
	msg_showing_letters db "the letters you've inserted so far are:",'$'
	msg_terminate db "programm terminated!",0dh,0ah,'$'
	buffer db 100 dup (?), '$'
data ENDS

code SEGMENT
	start:
		mov ax,data
		mov ds,ax
		mov bx,0
		new:
		;show a message
			mov ah, 09h
			mov dx, offset msg
			int 21h
		
		;reads a character
			mov ah,07h
			int 21h
		
		;if the character is $ the programm is done
		cmp al,'$'
		je finish
		
		;checks if it the ascii code is above 47, that means it could be a number
			cmp al,2fh
			ja check_number
		
		jmp notnumber
		
		check_number:
			;checks if it the ascii code is less than 58. if yes that means it's a number. otherwise it's not a number
			cmp al,3ah
			jl isnumber
		
		jmp notnumber
		
		isnumber:
			mov ah, 02h
			mov dl,al
			int 21h 
			
		notnumber:
		
		
		;if it's not a number or the character $ then it's another character
		
			;checks if it the ascii code is above 96, that means it could be a letter a lower case letter
				cmp al,60h
				ja check_lower
				
			jmp notletter
			
			check_lower:
				;checks if it the ascii code is less than 123. if yes that means it's a lower case letter
				cmp al,7bh
				jl isletter
			
			
			;checks if it the ascii code is above 64, that means it could be a upper case letter letter
				cmp al,40h
				ja check_upper
				
			jmp notletter
			
			check_upper:
				;checks if it the ascii code is less than 91. if yes that means it's a upper case letter
				cmp al,5bh
				jl isletter
				
			jmp notletter
		
		isletter:
			;if it is a letter, lower or upper case, it will be stored in a buffer and printed at the end of the programm
			add bx,1
			mov buffer[bx],al
			mov ah,09h
			mov dx, offset msg_letter
			int 21h
			
		notletter:
		;if the programm is not finished the process runs again.
		;print a new line
			mov ah, 02h
			mov dl,0dh
			int 21h
			mov dl,0ah
			int 21h
		jmp new
		
		
	finish:
		mov ah,09h
		lea dx,msg_terminate
		int 21h
		next:
			;put a $ at the end of the buffer
			mov buffer[bx+1],'$'
			
			;we check if the buffer is not empty, so there is something to display. if not, we show a message
			cmp bx,0
			je noletterinserted
			
			;print the buffer where we saved all the letters 
			mov ah,09h
			mov dx,offset msg_showing_letters
			int 21h
			mov dx, offset buffer 
			int 21h
			
			jmp there_was_smth
			
			noletterinserted:
				;if no letter was inserted we should print out a message
				mov ah,09h
				mov dx,offset msg_no_letter
				int 21h
				
			there_was_smth:
	mov ax,4C00h
	int 21h
code ENDS
END start