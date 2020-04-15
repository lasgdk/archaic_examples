;Lars Sommer, lasg@lasg.dk, 2006-06-01
;Creates an empty file, with the given permissions.

global _start
_start:
	push 0x81c0	;File permissions (700)
	jmp filename	;We use the jmp-trick, instead of a .data-section
	back:		; to make shellcoding easier.
	pop ebx
	push ebx
	mov al,8	;creat is syscall 8
	push eax
	int 0x80	;y0 kernel!

	push 0		;And a normal exit call now..
	mov al,1
	push eax
	int 0x80

	filename:
	call back
	db	'test',0	;Filename and null char


