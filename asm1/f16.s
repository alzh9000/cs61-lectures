	.file	"f16.cc"
	.text
	.globl	_Z12array_accessPll
	.type	_Z12array_accessPll, @function
_Z12array_accessPll:
	endbr64
	movq	(%rdi,%rsi,8), %rax
	ret
	.size	_Z12array_accessPll, .-_Z12array_accessPll
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
