	.file	"f31.cc"
	.text
	.globl	_Z5mod16j
	.type	_Z5mod16j, @function
_Z5mod16j:
	endbr64
	movl	%edi, %eax
	andl	$15, %eax
	ret
	.size	_Z5mod16j, .-_Z5mod16j
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
