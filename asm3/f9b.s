	.file	"f9b.cc"
	.text
	.globl	_Z2g2Pmm
	.type	_Z2g2Pmm, @function
_Z2g2Pmm:
	endbr64
	movq	%rsi, %rax
	salq	$4, %rax
	movsbq	(%rdi,%rax), %rax
	subq	(%rdi,%rsi,8), %rax
	ret
	.size	_Z2g2Pmm, .-_Z2g2Pmm
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
