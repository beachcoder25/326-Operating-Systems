;
; constants
section	.data
msg	db	'Please enter a digit: ',0xa
len	equ	$ - msg
var1: db 0xff
var2: db 0xee
n1: db 0x0a, 0x0d
msg_notEQ: db 'The byte values are NOT equal', 0x00
msg_EQ: db 'The byte values ARE equal', 0x00
msg_prompt1: db 'Please enter the first digit: ', 0x00
msg_promp2: db 'Please enter the second digit: ', 0x00


section	.text
	global _start		;must be declared for using gcc
_start:					;tell linker entry point
	mov edi, msg_prompt1 ;had as msg prompt1 on doc, incorrect?	






	mov	edx, len		;message length
	mov	ecx, msg		;message to write
	mov	ebx, 1		;file descriptor (stdout)
	mov	eax, 4		;system call number (sys_write)
	int	0x80			;call kernel
	mov	eax, 1		;system call number (sys_exit)
	int	0x80			;call kernel


