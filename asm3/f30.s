	.file	"f30.cc"
	.text
	.globl	_Z1flll
	.type	_Z1flll, @function
_Z1flll:
<<<<<<< HEAD
=======
	endbr64
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	salq	$20, %rdi
	imulq	%rdx, %rsi
	leaq	(%rdi,%rsi), %rax
	ret
	.size	_Z1flll, .-_Z1flll
<<<<<<< HEAD
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
=======
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	.section	.note.GNU-stack,"",@progbits
