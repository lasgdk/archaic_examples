;Hello world in asm
;Lars Sommer, spam@lasg.dk, 2005-03-29
;Compile and link with:
;nasm -f elf hello.asm
;ld -s -o hello hello.o

section .data
msg db "Hello world!",0xa ;Our message string, followed by a return
len equ $ - msg ;Length of the string. A directly length could be written as "len equ 13"

section .text
global _start
_start:
mov	edx,len ;Note that we move data in, in "reverse order", the last argument first.
mov	ecx,msg ;The message in before en len.
mov	ebx,1	;To stdout
mov	eax,4	;Do write
int	0x80	;Kernel int and exit
mov	ebx,0	;Load syscall arg.
mov	eax,1	;syscall exit
int	0x80	;Kernel int and exit

