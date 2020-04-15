global _start
_start:
	jmp lnk
	back:
	pop ebx
	push ebx
	jmp orig
	back2:
	pop ebx
	push ebx
	mov eax,57
	push eax
	int 0x80

	push 0
	mov eax,1
	push eax
	int 0x80

	lnk:
	call back
	db	'testlink',0

	orig:
	call back2
	db	'linkself',0
