
%include "msdn_defs.inc"

[bits 32]

section .text 

%define BYTES_TO_READ						4096

extern  _printf
extern _exit

extern CreateFileA, ReadFile, WriteFile, SetFilePointer, CloseHandle
extern GetLastError

global  _main 

_main: 
		; HANDLE WINAPI CreateFile(
		; 	_In_     LPCTSTR               lpFileName,
		; 	_In_     DWORD                 dwDesiredAccess,
		; 	_In_     DWORD                 dwShareMode,
		; 	_In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		; 	_In_     DWORD                 dwCreationDisposition,
		; 	_In_     DWORD                 dwFlagsAndAttributes,
		; 	_In_opt_ HANDLE                hTemplateFile
		; 	);
		
		push	NULL
		push	FILE_ATTRIBUTE_NORMAL
		push	OPEN_EXISTING
		push	NULL
		push	0
		push	(GENERIC_READ | GENERIC_WRITE)
		push	FileName
		call  	CreateFileA
		cmp		eax, INVALID_HANDLE_VALUE
		je		.error
		
		mov		[hFile], eax
		
	.convert_file:
		;BOOL WINAPI ReadFile(
		;	_In_        HANDLE       hFile,
		;	_Out_       LPVOID       lpBuffer,
		;	_In_        DWORD        nNumberOfBytesToRead,
		;	_Out_opt_   LPDWORD      lpNumberOfBytesRead,
		;	_Inout_opt_ LPOVERLAPPED lpOverlapped
		;	);
		
		push	NULL
		push	bytesRead
		push	BYTES_TO_READ
		push	buf
		push	DWORD [hFile]
		call	ReadFile
		test	eax, eax
		jz		.error
		
		cmp		DWORD [bytesRead], 0
		je		.finish
		
		
		; actually convert to lowercase everything which is ascii
		mov		ecx, [bytesRead]
	.convert_buffer:
		mov		al, [buf+ecx-1]
		cmp		al, 'A'
		jb		.next_iter
		cmp		al, 'Z'
		ja		.next_iter
		add		[buf+ecx-1], BYTE 0x20
		
	.next_iter:
		loop	.convert_buffer
		
		; move back to write the changes to the file
		;DWORD WINAPI SetFilePointer(
		;	_In_        HANDLE hFile,
		;	_In_        LONG   lDistanceToMove,
		;	_Inout_opt_ PLONG  lpDistanceToMoveHigh,
		;	_In_        DWORD  dwMoveMethod
		;	);

		push	FILE_CURRENT
		push	NULL
		
		mov		eax, [bytesRead]
		neg		eax
		
		push	eax
		push	DWORD [hFile]
		call 	SetFilePointer
		cmp		eax, INVALID_SET_FILE_POINTER
		je		.error
		
		
		; actually write the changes
		
		;BOOL WINAPI WriteFile(
		;	_In_        HANDLE       hFile,
		;	_In_        LPCVOID      lpBuffer,
		;	_In_        DWORD        nNumberOfBytesToWrite,
		;	_Out_opt_   LPDWORD      lpNumberOfBytesWritten,
		;	_Inout_opt_ LPOVERLAPPED lpOverlapped
		;	);

		push	NULL
		push	bytesWritten
		push	DWORD [bytesRead]
		push	buf
		push	DWORD [hFile]
		call	WriteFile
		test	eax, eax
		jz		.error
		
		jmp 	.convert_file
		
	.error:
		call	GetLastError
		
		push	eax
		push	fail_str
		call	_printf
	
		
	.finish:

        push    0
        call    _exit
        ret 

section .data

hFile:			dd		0
buf:			resb	BYTES_TO_READ
bytesRead:		dd		0
bytesWritten:	dd		0
FileName:		db		'exemplu_lung.txt', 0
fail_str:		db		'Failed with error code %d', 0xA, 0
