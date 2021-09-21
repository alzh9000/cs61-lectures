	.file	"f14.cc"
	.text
	.globl	_Z12array_accessPil
	.type	_Z12array_accessPil, @function
_Z12array_accessPil:
	endbr64
	movl	(%rdi,%rsi,4), %eax
	ret
	.size	_Z12array_accessPil, .-_Z12array_accessPil
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
