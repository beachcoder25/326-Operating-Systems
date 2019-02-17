;
;   Program to multiply two values
;   COMPILATION OPTION:
;       nasm -f elf *.asm; ld -m elf_i386 -s -o mulB *.o; mulB 0x05 0x03
;   The above compilation option perform 5 * 3
;   WARNING: the program can overflow 8-bits

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;	CONSTANT DEFINITIONS	;;;;;;;;;;;;;;;;;;;;
null				equ		0x00
MAXARGS 	equ		2 ; 1 = program path 2 = 1st arg  3 = 2nd arg etc... 
sys_exit		equ		1
sys_read		equ		3
sys_write		equ		4
stdin				equ		0
stdout			equ		1
stderr			equ		3



;;;;;;;;;;;;;;;;;;;;;;;	MACRO DEFINITIONS	;;;;;;;;;;;;;;;;;;;;;;;;

%macro pushRegisters 0
	push eax
	push ebx
	push ecx
	push edx
%endmacro

%macro popRegisters 0
	pop edx
	pop ecx
	pop ebx
	pop eax
%endmacro


; print_char macro
; prints one ascii character to the console
%macro print_char 1
	mov eax, 4	;system call number (sys_write)
	mov ebx, stdout	;file descriptor (stdout)
	mov ecx, %1		;address of data to print
	mov edx, 1	;number of bytes to print
	int 0x80	;do it!
%endmacro

section .data
	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; WRITINGTOFILE.ASM
	
	file_name	db '016597813.txt', 0
	fn_len		equ $ - file_name
	msg			db 'Welcome to Tutorials Point'
	msg_len	equ $ - msg
	msg_done	db 'Written to file:', 0x9
	len_done	equ $ - msg_done
	cr	db 0x0a
	
	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; cToF.asm
	
	hexprefix	db "0x",null
	debugOK		db	"OK",null
	nl			db	0x0a,0x0d
	msg1		db	"8-bit variable 1 = ",null
	msg2		db	"8-bit variable 2 = ",null
	msg3		db	"8-bit product of variable 1 * variable 2 = ",null
	var1		db	0xff	; default value
	var2		db	0xff	; default value
	product		db	0xff	;0xff is default value

	;;;;; error messages ;;;;;
	szErrMsg    		db      "Too many arguments.  The max number of args is !", null
	szLineFeed  		db      10
	szBErrMsg			db "Invalid number of hex digits entered.",null
	properMsg			db "Proper 2 digit hex value: 0x4F",null
	arg1nullMsg:		db "First argument is null",null
	arg2nullMsg:		db "Second argument is null",null

section .bss
	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; WRITINGTOFILE.ASM
	
	fd_out	resb 1
	fd_in		resb 1
	info		resb 30
	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; cToF.asm
	
	tmpbyte		resb	1	;hold byte temporarily for the hex to ascii conversion
	tmphexchar	resb	2	;holds hex version of ascii char to be printed

	arg1hex		resb	1	;holds the hex value of first argument
	arg2hex		resb	1	;holds the hex value of second argument

	arg1ascii		resb	5	;holds the ascii version of first argument (4 characters and a null)
	arg2ascii		resb	5	;holds the ascii version of second argument (4 characters and a null)




;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



section .text
	global _start	;must be declared for using gcc
	_start:		;tell linker entry point
	
;create the file
	mov eax, 8
	mov ebx, file_name
	mov ecx, 0o666		; read and write by all
	mov edx, fn_len 
	int 0x80				; call kernel
	mov [fd_out], al	; filedescriptor is returned in the A register
	
	
	;;; Ask for input
	mov edi, msg1
	call  print_string

		;; Getting first digit from user 
	mov eax, 3 ; UNSURE of significance of number 3?
	mov ebx, 2
	mov ecx, var1
	mov edx, 1
	int 0x80
	call print_nl	
	
	; write into the file
	mov edx,msg_len			; number of bytes
	mov ecx, msg		; message to write
	mov ebx, [fd_out]	; file descriptor of the created file
	mov eax,4			; system call number (sys_write)
	int 0x80				; call kernel
	


	mov edi, msg_prompt2
	call  print_string

		;; Getting second digit from user 
	mov eax, 3 ; UNSURE of significance of number 3
	mov ebx, 2
	mov ecx, var2
	mov edx, 1
	int 0x80
	call print_nl	
	
	
	; write into the file
	mov edx,msg_len			; number of bytes
	mov ecx, msg		; message to write
	mov ebx, [fd_out]	; file descriptor of the created file
	mov eax,4			; system call number (sys_write)
	int 0x80				; call kernel
	
	
	
	; close the file
	mov eax, 6
	mov ebx, [fd_out]
	int 0x80
	
	; announce that the file has been written to
	mov eax, 4
	mov ebx, 1
	mov ecx, msg_done
	mov edx, len_done
	int 0x80
	
	

	
;open the file for reading
	mov eax, 5
	mov ebx, file_name
	mov ecx, 0			;for read only access
	mov edx, 0o666		;read, write and execute by all
	int 0x80
	mov [fd_in], eax
	
;read from file
	mov eax, 3
	mov ebx, [fd_in]
	mov ecx, info
	mov edx, 26
	int 0x80
	
; close the file
	mov eax, 6
	mov ebx, [fd_in]
	int 0x80
	
; print the info
	mov eax, 4
	mov ebx, 1
	mov ecx, info
	mov edx, 26
	int 0x80
	
; write into the file
	mov edx,1			; number of bytes
	mov ecx, cr		; message to write
	mov ebx, 1	; file descriptor of the created file
	mov eax,4			; system call number (sys_write)
	int 0x80				; call kernel

; terminate program execution	
	mov eax,1			;system call number (sys_exit)
	int 0x80			;call kernel






;;;;;;;; FUNCTIONS/SUBROUTINE ;;;;;;;;;;;;;;;;;;;;;;;;;;
	; print_nl
	; prints a newline
	; returns - nothing
	print_nl:
	    pushRegisters ; Values(registers) are saved on trhe STACK
						; Values are manipulated, this is whyyou need to restore
	mov eax , 4 		; system call number (sys_write)
	mov ebx, 1		; file descriptor (stdout)
	mov ecx, n1		; address of data to print
	mov edx, 2		; number of bytes to print
	int 0x80		; do it!
	popRegisters	; Restores saved values
	ret

	; print_string
	; receives - address of a C-Style String in register edi
	; C-Style means null terminated
	; uses		- eax, ebx, ecx, edx
	; returns - nothing
	print_string: ; Going through an "array of chars" to "print string"
		pushRegisters
		mov ecx, edi
		checknull:
		cmp byte [ecx], null ; whil data pointed to is NOT NULL, then print that byte
		jz endstring
		    print_char ecx
		    inc ecx
		    jmp checknull
		endstring:
		popRegisters
		    ret



	    ; Micro-code interpreter