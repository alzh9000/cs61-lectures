	.file	"f30.cc"
	.text
	.globl	_Z1flll
	.type	_Z1flll, @function
_Z1flll:
	salq	$20, %rdi
	imulq	%rdx, %rsi
	leaq	(%rdi,%rsi), %rax
	ret
	.size	_Z1flll, .-_Z1flll
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
