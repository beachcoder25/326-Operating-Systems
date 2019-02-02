;
; constants
section	.data
msg	db	'Please enter a digit: ',0xa
len	equ	$ - msg
var1: db 0xff	;UNSURE of why we start at 0xff
var2: db 0xee
n1: db 0x0a, 0x0d
msg_notEQ: db 'The byte values are NOT equal', 0x00
msg_EQ: db 'The byte values ARE equal', 0x00
msg_prompt1: db 'Please enter the first digit: ', 0x00
msg_promp2: db 'Please enter the second digit: ', 0x00


section	.text
	GLOBAL _start		;must be declared for using gcc
	-start:

	mov edi, msg_prompt1
	call  print_string

		;; Getting first digit from user 
	mov eax, 3 ; UNSURE of significance of number 3
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
	cmp al, byt[var2] 	; the variables couldn't be compared directly so al was used
			  	; the values held in 2 memory locatiuons cant be compared by a single instruction
	je var1_eq_var2 	; put sum of variable values into the "sum" variable
				; if we are here, var1 != var2
	  mov edi, mst_notEQ	; put EQUAL message into edi register
	  call print_string 	; print new line	
	  jmp end_main 		; go to end of main program section
	var1_eq_var2:
				; if we are here, var1 == var2
  	  mov edi, msg_EQ	; put EQUAL meddage into edi register
	  call print_string	; print EQUAL message
	  call print_nl 	; print nl
	jmp end_main		; go to end of main program section
	end_main:
	exit0	

	;;;;;;;; FUNCTIONS/SUBROUTINE ;;;;;;;;;;;;;;;;;;;;;;;;;;
	; print_nl
	; prints a newline
	; returns - nothing
	print_nl:
	    pushRegisters
	mov eax , 4 		; system call number (sys_write)
	mov ebx, 1		; file descriptor (stdout)
	mov ecx, n1		; address of data to print
	mov edx, 2		; number of bytes to print
	int 0x80		; do it!
	popRegisters
	ret

	; print_string
	; receives - address of a C-Style String in register edi
	; C-Style means null terminated
	; uses		- eax, ebx, ecx, edx
	; returns - nothing
	print_string:
	pushRegisters
	mov ecx, edi
	checknull;
	cmp byte [ecx], null
	jz endstring
	    print_char ecx
	    inc ecx
	    jmp checknull
	endstring:
	popRegister
	    ret
	    




