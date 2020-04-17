	.file	"check.c"
	.text
	.p2align 2,,3
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	subl	%eax, %esp
	movl	$0, -12(%ebp)
	movl	12(%ebp), %eax
	addl	$4, %eax
	cmpl	$0, (%eax)
	je	.L2
	subl	$12, %esp
	movl	12(%ebp), %eax
	addl	$4, %eax
	pushl	(%eax)
	call	atoi
	addl	$16, %esp
	movl	%eax, -12(%ebp)
.L2:
	cmpl	$0, -12(%ebp)
	je	.L3
	subl	$12, %esp
	pushl	-12(%ebp)
	call	controlcode
	addl	$16, %esp
	movl	%eax, -8(%ebp)
.L3:
	cmpl	$1, -8(%ebp)
	jne	.L4
	call	ok
	movl	%eax, -4(%ebp)
	jmp	.L5
.L4:
	call	notok
	movl	%eax, -4(%ebp)
.L5:
	movl	-4(%ebp), %eax
	leave
	ret
	.size	main, .-main
	.p2align 2,,3
.globl ok
	.type	ok, @function
ok:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$42, %eax
	leave
	ret
	.size	ok, .-ok
	.p2align 2,,3
.globl notok
	.type	notok, @function
notok:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$13, %eax
	leave
	ret
	.size	notok, .-notok
	.p2align 2,,3
.globl controlcode
	.type	controlcode, @function
controlcode:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp
	movl	8(%ebp), %ecx
	movl	$1717986919, %eax
	imull	%ecx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %ecx
	movl	$1717986919, %eax
	imull	%ecx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	%eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	addl	-4(%ebp), %eax
	cmpl	$10, %eax
	jne	.L9
	movl	$1, -12(%ebp)
	jmp	.L8
.L9:
	movl	$0, -12(%ebp)
.L8:
	movl	-12(%ebp), %eax
	leave
	ret
	.size	controlcode, .-controlcode
	.ident	"GCC: (GNU) 3.4.6 [FreeBSD] 20060305"
