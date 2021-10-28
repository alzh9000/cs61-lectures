	.file	"f9d.cc"
	.text
	.globl	_Z2g4P4statj
	.type	_Z2g4P4statj, @function
_Z2g4P4statj:
	endbr64
	movl	%esi, %edx
	addq	$1, (%rdi)
	addq	%rdx, 8(%rdi)
	movq	%rdx, %rax
	imull	%edx, %edx
	addq	%rdx, 16(%rdi)
	ret
	.size	_Z2g4P4statj, .-_Z2g4P4statj
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
