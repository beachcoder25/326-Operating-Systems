

;;;; SYMBOLIC CONSTANT DEFINITIONS

null 	equ	0x00
MAXARGS	equ	2 ; 1 = program path 2 = 1st arg 3 = 2md arg etc...
sys_exit	equ	1 ; goes into eax register, eax is where OS looks for syscall code
sys_read	equ	3
sys_write	equ 	4
stdin		equ 	0
stdout		equ	1 ; passed ebx register, used as file descriptor, stdout is the name of the file, stdout will ALWAYS eq 1 
stderr		equ	3


;;;; MACRO DEFINITIONS
	; print_char macro
	; PRINTS ONE ASCII CHARACTER TO THE CONSOLE
	
	
	
	;;;;; QUESTIONS
	; Difference between a macro and a function?
		; Macro, creates different text/symbol to reporesent text; Replacing one symbol with another, symbol being replaced can be anything
	; Is there a reason we didn't use print-char to print the digit input by the user instead of print_string?
		; We could have used print_char, would have been optimal
	; Walk through sys calls and mov instructions for print_char... Hoe can sys_exit equ 1 AND stdout also equ 1

	; Reference is the actual address of a variable
	; Pointer 
	; Focus on OS related information, C++ was just a supplement, nbthing C++ related
	%macro print_char 1 ; 1 is like a paramtert
		mov eax, 4 ; An address in an interupt table, asks where do I write? Ebx has answer
		mov ebx, stdout ; Prints out to screen
		mov ecx, %1 ;Thi is the 1 from the parameter
					; What do I write? The ecx register will tell 
		mov edx, 1 ; Tells how many bytes to output
		int 0x80
		
		; A register is the MAIN one for sys calls
		
		; He mentioned stack frames
		
	%endmacro

	%macro pushRegisters 0
		push eax 
		push ebx
		push ecx
		push edx
	%endmacro

	%macro popRegisters 0
		pop eax 
		pop ebx
		pop ecx
		pop edx
	%endmacro

	;exit0 macro
	; exits program with return code 0
	%macro exit0 0
		mov ebx, 0
		mov eax, sys_exit
		int 0x80
	%endmacro



;;;; DATA SEGMENT

section	.data

var1: db 0xff, 0	;UNSURE of why we start at 0xff
var2: db 0xee, 0 ; single ASCII can call printstream pass address of var1 into edi
n1: db 0x0a, 0x0d
msg_notEQ: db 'The byte values are NOT equal', 0x00
msg_greaterThan: db ' is greater than ', 0x00
msg_lessThan: db ' is less than ', 0x00
msg_EQ: db ' is equal to ', 0x00
msg_prompt1: db 'Please enter a digit: ', 0x00
msg_prompt2: db 'Please enter a second digit: ', 0x00





section	.text
	GLOBAL _start		;must be declared for using gcc
	_start:

	;;; Ask for input
	mov edi, msg_prompt1
	call  print_string

		;; Getting first digit from user 
	mov eax, 3 ; UNSURE of significance of number 3?
	mov ebx, 2
	mov ecx, var1
	mov edx, 1
	int 0x80
	call print_nl	
	


	mov edi, msg_prompt2
	call  print_string

		;; Getting second digit from user 
	mov eax, 3 ; UNSURE of significance of number 3
	mov ebx, 2
	mov ecx, var2
	mov edx, 1
	int 0x80
	call print_nl	
	
	; assuming var1 and var2 exist and havesome values
	mov al, [var1] 		; al = var1 value
	cmp al, byte [var2] 	; the variables couldn't be compared directly so al was used
			  	; the values held in 2 memory locatiuons cant be compared by a ;single instruction
	
	
	je var1_eq_var2 	; put sum of variable values into the "sum" variable
				; if we are here, var1 != var2
	jg var1_gt_var2
	
	; This should code will be for LESS THAN due to previous jumps
	  
	  mov edi, var1
	  call print_string
	  mov edi, msg_lessThan ; put EQUAL message into edi register
							; edi used as destination index for string operations
							; esi source index for sring operations, can you give an example using esi?
							; Your basic explanation of flags?
							
							; End of chapter six, walk through code
							
	  call print_string
	  mov edi, var2
	  call print_string
	  
	  ; I should use the print_char here to print the variables?
	  ; How do I know which register it is in?
	  ;   print_char ecx

	  call print_nl 	; print new line	
	  jmp end_main 		; go to end of main program section
	
	; can use print string for printing variable alter data.segment
	
	var1_eq_var2:
				; if we are here, var1 == var2
	  mov edi, var1
	  call print_string
  	  mov edi, msg_EQ	; put EQUAL meddage into edi register
	  call print_string	; print EQUAL message
	  mov edi, var2
	  call print_string
	  call print_nl 	; print nl
	  jmp end_main		; go to end of main program section
	 
	 var1_gt_var2:
	 
	   mov edi, var1
	  call print_string
  	  mov edi, msg_greaterThan	; put EQUAL meddage into edi register
	  call print_string	; print EQUAL message
	  mov edi, var2
	  call print_string
	  call print_nl 	; print nl
	 jmp end_main	
	
	end_main:
	exit0	



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
