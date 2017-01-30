ASSUME CS:code

public _printLongestArr,_printNumberBase10
	
code segment
	
	_printLongestArr proc
		
		;input: bx register loaded with the offset of a string of bytes
		;			containing many subarrays 0-terminated 
		;		cx register loaded with the len of the string of bytes
		;output: prints on the screen the longest subarray in the string of bytes
		IRP reg,<a,c,d>	;we save the registers on the stack
			push &reg&x		;not to destroy their values in the main program
		endm
			
		push bx				;initially the starting point of the longest subarray is the offset of the
							;entire string of bytes
		push 0 				;and the longest subarray has the len 0
		
		repeta:
			mov dx,0 		;we will use dx to count the numbers of bytes in a subarry
							;for each array we reset the counter to 0
			mov si,bx		;the starting point of an subarray is the current counter(bx)
			still_in_arr:
				mov al,byte ptr [bx]	;we load into ax register the content of the current byte in the sting
				inc dx		;we increment the counter dx to conterize the current element
				inc bx		;we move the the next element
				cmp al,0	;we compare the current element with 0
			jne still_in_arr;if it is not equal to 0 then we are still in the subarray
			
			sub cx,dx		;not sure tho :)) ig there are too many decrementation
			inc cx			;because we parse the string of bytes with a outer loop based on cx
							;but we parse subarrays in a inner loop we have to decrement the cx
			pop ax			;we pop the max len of an subarray until now into ax register
			cmp dx,ax		;we compare the len of the last subarray with the maximum len
			jl not_max		;if it is less than the maximum len we jump over the reinitialization of the maximum
							;reach here if it is greater or equal
			pop ax			;we extract the beginning of the old longest subarray
			push si			;we load the new start point of the longest subarray
			push dx			;we reinitialize the maximum
			jmp new_max		;if it was a new maximum and we skip the not_max part
			
			not_max:
				push ax		;we load the max back into the stack
			new_max:
				
		loop repeta			; the outer loop counting with cx in the sting of bytes
		
		;now we will print the longest subarray using the values stored on the top of the stack
		pop bx				;the len is the last-in the stack
		pop si				;the starting point of the the longest subarray is the 2nd one in the stack
		
	
		IRP reg,<d,c,a>	;we put the values of the registers back
			pop &reg&x		;so that they are kept unchanged after calling the procedure
		endm
	
	ret
	_printLongestArr endp

	_printNumberBase10 proc
		;prints the number from al register in base 10 
		mov di,10				;constant 10 used for division
		mov ah,0				;we extend to word
			mov cx,0			;the counter of digits
				repeta10:
					mov dx,0	;we extend to doubleword
					div di		;divide dx:ax to 10(word)
					push dx		;push on the stack the reminder
					inc cx		;increment the counter of digits
					cmp ax,0	;compare the result of the division (in ax) with 0
				jne repeta10	;if it is not zero we continue to divide by 10
				
				repetaListDigits:
					pop dx		;pop from the stack the last digit
					add dl,'0'	;transform it to ASCII code
					mov ah,02h	;prepare to print
					int 21h
				loop repetaListDigits
	ret
	_printNumberBase10 endp
code ends
end
