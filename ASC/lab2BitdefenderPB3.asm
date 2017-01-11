%include "msdn_defs.inc"
[bits 32]

section .text 

extern  _printf
extern _exit

extern FindFirstFile,FindNextFile,FindClose

global  _main 

_main: 
		push ffd
		push path
		call FindFirstFile
		
		cmp eax,INVALID_HANDLE_VALUE
		je .error
		
		mov [hFind],eax
		
		.findFiles:
			test dword [ffd + WIN32_FIND_DATA.dwFileAttributes],FILE_ATTRIBUTE_DIRECTORY
			jnz .showDirectory
			jmp .printFile
			
			.showDirectory:
				mov al,byte [comma]
				cmp byte [ffd + WIN32_FIND_DATA.cFileName],al
				je .continueFinding
				
				mov eax,ffd
				add eax,WIN32_FIND_DATA.cFileName
				push eax
				push directoryFormat
				call _printf
				add esp,8
				jmp .continueFinding
				
			.printFile:
				push ffd+ WIN32_FIND_DATA.cFileName
				push fileFormat
				call _printf
				add esp,8
			
			.continueFinding:
				push ffd
				push dword [hFind]
				call FindNextFile
				cmp eax,0 ;FindNextFile returns 0 in case of an error
						  ; or if there are no files left to read
				je .finish
				jmp .findFiles
		
	jmp .finish
		
	.error:
		push errorMessage
		call _printf
		add esp,4
		
	.finish:
		push dword [hFind]
		call FindClose
		
		push    0
		call    _exit
		ret 

section .data

ffd: 
istruc  WIN32_FIND_DATA 
at WIN32_FIND_DATA.dwFileAttributes,dd 0
at WIN32_FIND_DATA.ftCreationTime,db 0
at WIN32_FIND_DATA.ftLastAccessTime, db 0
at WIN32_FIND_DATA.ftLastWriteTime, db 0
at WIN32_FIND_DATA.nFileSizeHigh, dd 0
at WIN32_FIND_DATA.nFileSizeLow, dd 0
at WIN32_FIND_DATA.dwReserved0, dd 0
at WIN32_FIND_DATA.dwReserved1, dd 0
at WIN32_FIND_DATA.cFileName, db 0
at WIN32_FIND_DATA.cAlternateFileName,db 0
iend

struct_size: dd $ - ffd
hFind: dd 0
path: db "C:\\Windows\\System32\\*",0
errorMessage: db "No file in the folder",0
directoryFormat: db "D %s",0Ah,0
fileFormat: db "- %s",0Ah,0
comma: db ".",0