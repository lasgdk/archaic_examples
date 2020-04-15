global _start
_start:
;section .text
	jmp two
	one:
	pop ebx
	push 21
	push ebx
	push 1
	mov al,4
	push eax
	int 0x80

	push 0
	mov al,1
	push eax
	int 0x80

	two:
	call one
	db	'Greetings to Mondus!',0x0a,0
