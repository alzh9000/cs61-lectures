	.file	"f22.cc"
	.text
	.globl	_Z1fPKc
	.type	_Z1fPKc, @function
_Z1fPKc:
	testq	%rdi, %rdi
	je	.L7
	subq	$8, %rsp
	call	puts@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	ret
.L7:
	xorl	%eax, %eax
	ret
	.size	_Z1fPKc, .-_Z1fPKc
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
