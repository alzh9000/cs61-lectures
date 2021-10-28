	.file	"f9c.cc"
	.text
	.globl	_Z2g3P2ll
	.type	_Z2g3P2ll, @function
_Z2g3P2ll:
	endbr64
	xorl	%eax, %eax
	testq	%rdi, %rdi
	je	.L4
.L3:
	movq	(%rdi), %rdi
	addl	$1, %eax
	testq	%rdi, %rdi
	jne	.L3
	ret
.L4:
	ret
	.size	_Z2g3P2ll, .-_Z2g3P2ll
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
