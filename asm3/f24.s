	.file	"f24.cc"
	.text
	.globl	_Z1fPmm
	.type	_Z1fPmm, @function
_Z1fPmm:
<<<<<<< HEAD
=======
	endbr64
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	testq	%rsi, %rsi
	je	.L4
	leaq	(%rdi,%rsi,8), %rdx
	xorl	%eax, %eax
.L3:
	addq	(%rdi), %rax
	addq	$8, %rdi
	cmpq	%rdx, %rdi
	jne	.L3
<<<<<<< HEAD
	rep ret
=======
	ret
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
.L4:
	xorl	%eax, %eax
	ret
	.size	_Z1fPmm, .-_Z1fPmm
<<<<<<< HEAD
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
=======
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	.section	.note.GNU-stack,"",@progbits
