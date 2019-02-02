; this source was taken from https://www.tutorialspoint.com/compile_assembly_online.php

section	.text
	global _start		;must be declared for using gcc
_start:					;tell linker entry point
	mov	edx, len		;message length
	mov	ecx, msg		;message to write
	mov	ebx, 1		;file descriptor (stdout)
	mov	eax, 4		;system call number (sys_write)
	int	0x80			;call kernel
	mov	eax, 1		;system call number (sys_exit)
	int	0x80			;call kernel

section	.data

msg	db	'First: Jonah',0xa, 'Last: Cornish',0xa,'ID: 016597813',0xa
len	equ	$ - msg
