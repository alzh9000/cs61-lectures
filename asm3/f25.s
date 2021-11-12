	.file	"f25.cc"
	.text
	.globl	_Z1fiii
	.type	_Z1fiii, @function
_Z1fiii:
<<<<<<< HEAD
=======
	endbr64
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L2
	movl	-4(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L2
	movl	-4(%rbp), %eax
	jmp	.L3
.L2:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L4
	movl	-8(%rbp), %eax
	jmp	.L3
.L4:
	movl	-12(%rbp), %eax
.L3:
	popq	%rbp
	ret
	.size	_Z1fiii, .-_Z1fiii
<<<<<<< HEAD
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
=======
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	.section	.note.GNU-stack,"",@progbits
