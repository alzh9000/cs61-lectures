	.file	"f22.cc"
	.text
	.globl	_Z1fPKc
	.type	_Z1fPKc, @function
_Z1fPKc:
<<<<<<< HEAD
=======
	endbr64
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
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
<<<<<<< HEAD
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
=======
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	.section	.note.GNU-stack,"",@progbits
