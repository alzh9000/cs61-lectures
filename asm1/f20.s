	.file	"f20.cc"
	.text
	.globl	_Z1fii
	.type	_Z1fii, @function
_Z1fii:
	endbr64
	movl	%edi, %eax
	imull	%esi, %eax
	ret
	.size	_Z1fii, .-_Z1fii
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
