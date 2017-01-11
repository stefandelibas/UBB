%include "msdn_defs.inc"

[bits 32]

struc Student
.lastName resb 20
.firstName resb 20
.age resd 1
.height resd 1
.eyeColor resb 15
.size
endstruc

%define MAX_STUDENTS 100
%define NULL 0

section .text 

extern  _printf
extern _exit

extern _fopen
extern _fscanf
extern _strtok
extern _strcpy
extern _scanf
extern _atoi
extern _fclose
extern __open_osfhandle
extern __fdopen
extern CreateFileA

global  _main 

_main: 
		push NULL
		push FILE_ATTRIBUTE_NORMAL
		push OPEN_EXISTING
		push NULL
		push 0
		push GENERIC_READ 
		push fileName
		call CreateFileA
		cmp eax,INVALID_HANDLE_VALUE
		je .error
	
		mov [hFile],eax ; 
		
		
		push 0 
		push dword [hFile]
		call __open_osfhandle
		add esp,4*2
		
		cmp eax,-1
		je .error
		mov [cHandle],eax
		
		
		push readMode
		push dword [cHandle]
		call __fdopen
		add esp,4*2
		

		mov [filePointer],eax
				
		push n_students
		push intType
		push dword [filePointer]
		call _fscanf
		
		mov ecx,[n_students]
		mov edi,0 
		
		.read_data:
			push ecx
			
			push buffer
			push strType
			push dword [filePointer]
			call _fscanf
			add esp,12

			push d
			push buffer
			call _strtok
			add esp,8

			mov ebx,0
			
			.tokenize:

				mov [token],eax
				inc ebx
				cmp byte [token],NULL
				je .continue_reading
				cmp ebx,1
				je .AddlastName
				cmp ebx,2
				je .AddfirstName
				cmp ebx,3
				je .AddAge
				cmp ebx,4
				je .AddHeight
				cmp ebx,5
				je .AddEyeColor
			
				.AddlastName:
					push edi
					mov eax,token
					lea edi,students[edi + Student.lastName]
					mov esi,[token]
					cld
					.copy:
						lodsb
						stosb
						test al,al
						jnz .copy
					
					pop edi
					jmp .continue_token
				.AddfirstName:
					push edi
					mov eax,token
					lea edi,students[edi + Student.firstName]
					mov esi,[token]
					cld
					.copy_name:
						lodsb
						stosb
						test al,al
						jnz .copy_name
					pop edi
					jmp .continue_token
				.AddAge:
					push dword [token]
					call _atoi
					mov students[edi + Student.age],eax
					add esp,4
					jmp .continue_token
				.AddHeight:
					push dword [token]
					call _atoi
					mov students[edi + Student.height],eax
					add esp,4
					jmp .continue_token
				.AddEyeColor:
					push edi
					mov eax,token
					lea edi,students[edi + Student.eyeColor]
					mov esi,[token]
					
					.copy_color:
						lodsb
						stosb
						test al,al
						jnz .copy_color
					pop edi
					jmp .continue_token
				
				.continue_token:
					push d
					push NULL
					call _strtok 
					add esp,8
					jmp .tokenize
			.continue_reading:
				pop ecx 
				add edi,Student.size 
				dec ecx
				cmp ecx,0 
				jne .read_data

		.read_command:
			
			push command
			push intType
			call _scanf
			add esp,4*2
			
			
			cmp dword [command],0
			je .finish
			
			
			mov eax,[n_students]
			cmp dword [command],eax
			jg .no_id
			
			
			mov bx,Student.size
			mov ax,[command]
			dec ax
			mul bx 
			
			push dx
			push ax
			pop eax
			
			add eax,students 
			

			add eax,Student.eyeColor
			push eax

			sub eax,Student.eyeColor
			add eax,Student.height
			push dword [eax]
			
			sub eax,Student.height
			add eax,Student.age
			push dword [eax]

			sub eax,Student.age
			add eax,Student.firstName
			push eax

			sub eax,Student.firstName
			add eax,Student.lastName
			push eax
			
			push studentFormat
			call _printf
			add esp,4

			jmp .read_command
			
			.no_id:
				push dword [command]
				push invalidIndexError
				call _printf
				add esp,8
				jmp .read_command
		
		jmp .finish

		.error:
			push errorMessage
			call _printf
			add esp,4
		
		.finish:
		push filePointer
		call _fclose
		add esp,4
		
        push    0
        call    _exit
        ret 

section .data
	students: times MAX_STUDENTS * Student.size db 0
	buffer: times 100 db 0
	token: times 25 db 0
	fileName: db "students.txt",0
	readMode: db "r",0
	intType: db "%d",0
	strType: db "%s",0
	studentFormat: db "%s %s %d %d %s",0Ah,0 
	command : dd 0
	n_students: dd 0
	cHandle: dd 0
	hFile: dd 0
	filePointer: dd 0
	errorMessage: db "An error has occurred while opening the file.",0
	invalidIndexError: db "Invalid index: max index value is %d.",0Ah,0
	d: db ",",0