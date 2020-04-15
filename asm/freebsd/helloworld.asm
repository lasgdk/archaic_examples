	%include	'system.inc'	;We have to include our system.inc-file with nice stuff in.

section .data	;starting with data-section to declare labels
hello	db	'Hello world!',0Ah	;our message string, ended with a LF in hex.

;A wrecked way the message could also be written is:
;48h,65h,6Ch,6Ch,6Fh,20h,77h,6Fh,72h,6Ch,64h,21h,0Ah


hellolen	equ $-hello	;lenght of the string, which we need to write it.

section .text	;starting the text-section. here all the program code goes
global	_start	;the linker ld expects a global called _start
_start:	;and here we start _start.
push	dword	hellolen	;pushing the lenght to the stack.
push	dword	hello	;pushing the message to the stack
push	dword	stdout	;pushing the device we want to write to. stdout is defined in system.inc
sys.write	;sys.write is defined in system.inc, and does a write system call.

push	dword	0	;pushes 0 to the stack. 
sys.exit	;makes an exit system call , with the parameter 0, from the stack.

