;Lars Sommer, lasg@lasg.dk, 2006-06-01
; Simple sync syscall

global _start
_start:
	mov eax,36
	push eax
	int 0x80

	push 0
	mov eax,1
	push eax
	int 0x80
