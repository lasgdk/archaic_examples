%include	'system.inc'

section .data
char	db	'./loop',0Ah

section .text
global _start
_start:
push	dword	7
push	dword	char
push	dword	stdout
sys.write
jmp	_start
