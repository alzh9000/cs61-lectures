	.file	"f23.cc"
	.text
	.globl	_Z1fPmm
	.type	_Z1fPmm, @function
_Z1fPmm:
	endbr64
	testq	%rsi, %rsi
	je	.L4
	leaq	(%rdi,%rsi,8), %rdx
	xorl	%eax, %eax
.L3:
	addq	(%rdi), %rax
	addq	$8, %rdi
	cmpq	%rdx, %rdi
	jne	.L3
	ret
.L4:
	xorl	%eax, %eax
	ret
	.size	_Z1fPmm, .-_Z1fPmm
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
