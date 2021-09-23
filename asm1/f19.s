	.file	"f19.cc"
	.text
	.globl	_Z9ptr_arithml
	.type	_Z9ptr_arithml, @function
_Z9ptr_arithml:
	endbr64
	leaq	(%rdi,%rsi,4), %rax
	ret
	.size	_Z9ptr_arithml, .-_Z9ptr_arithml
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
