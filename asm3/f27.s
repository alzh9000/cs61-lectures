	.file	"f27.cc"
	.text
	.globl	_Z1fjjj
	.type	_Z1fjjj, @function
_Z1fjjj:
	cmpl	%edx, %esi
	cmovb	%edx, %esi
	cmpl	%edi, %esi
	movl	%edi, %eax
	cmovnb	%esi, %eax
	ret
	.size	_Z1fjjj, .-_Z1fjjj
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
