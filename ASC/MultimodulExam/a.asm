ASSUME cs: code, ds:data
data SEGMENT
	sir db 1,2,3,4,55,0,1,2,3,4,0,1,0
	len db $-sir
	
data ENDS


code SEGMENT
	extrn _printLongestArr:FAR
	extrn _printNumberBase10:FAR
	
	start:
		push data
		pop ds
		
		mov bx,offset sir
		mov ch,0
		mov cl,len
		call _printLongestArr
			
	
		;after returning from the procedure in module b.asm we will have:
		;	bx - the len of the longest subarray
		;	si - the starting point of the longest subarray
		
		print_number:
			mov al,[si]			;we load in al the current element of the longest subarray
			call _printNumberBase10
			
			inc si				;move to the next element
			dec bx				;and decrement the counter
			
			mov ah,02h			;print a comma
			mov dl,','
			int 21h
			
			cmp bx,2			;print commas only until the last element
		jne print_number
		
		mov al,[si]				;prints the last element without a comma after it :)
		call _printNumberBase10
		
	mov ax,4C00h
	int 21h
code ENDS
END start

