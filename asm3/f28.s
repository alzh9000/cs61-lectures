	.file	"f28.cc"
	.text
	.globl	_Z7times13j
	.type	_Z7times13j, @function
_Z7times13j:
	leal	(%rdi,%rdi,2), %eax
	leal	(%rdi,%rax,4), %eax
	ret
	.size	_Z7times13j, .-_Z7times13j
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
