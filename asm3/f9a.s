	.file	"f9a.cc"
	.text
	.globl	_Z2g1i
	.type	_Z2g1i, @function
_Z2g1i:
	endbr64
	movl	%edi, %eax
	shrl	$31, %eax
	ret
	.size	_Z2g1i, .-_Z2g1i
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
