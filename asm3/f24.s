	.file	"f24.cc"
	.text
	.globl	_Z1fPmm
	.type	_Z1fPmm, @function
_Z1fPmm:
	testq	%rsi, %rsi
	je	.L4
	leaq	(%rdi,%rsi,8), %rdx
	xorl	%eax, %eax
.L3:
	addq	(%rdi), %rax
	addq	$8, %rdi
	cmpq	%rdx, %rdi
	jne	.L3
	rep ret
.L4:
	xorl	%eax, %eax
	ret
	.size	_Z1fPmm, .-_Z1fPmm
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
