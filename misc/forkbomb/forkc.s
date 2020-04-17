	.file	"forkc.c"
	.text
	.p2align 2,,3
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	subl	%eax, %esp
.L2:
	call	fork
	jmp	.L2
	.size	main, .-main
	.ident	"GCC: (GNU) 3.4.4 [FreeBSD] 20050518"
