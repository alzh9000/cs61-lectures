	.file	"f31.cc"
	.text
	.globl	_Z5mod16j
	.type	_Z5mod16j, @function
_Z5mod16j:
	movl	%edi, %eax
	andl	$15, %eax
	ret
	.size	_Z5mod16j, .-_Z5mod16j
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
