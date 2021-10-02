	.file	"f28.cc"
	.text
	.globl	_Z1f5small
	.type	_Z1f5small, @function
_Z1f5small:
	endbr64
	movl	%edi, %eax
	movsbl	%ah, %edx
	movsbl	%dl, %edx
	movsbl	%dil, %eax
	leal	(%rax,%rdx,2), %eax
	ret
	.size	_Z1f5small, .-_Z1f5small
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
