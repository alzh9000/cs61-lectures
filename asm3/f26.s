	.file	"f26.cc"
	.text
	.globl	_Z1fiii
	.type	_Z1fiii, @function
_Z1fiii:
<<<<<<< HEAD
=======
	endbr64
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	cmpl	%edx, %esi
	cmovl	%edx, %esi
	cmpl	%edi, %esi
	movl	%edi, %eax
	cmovge	%esi, %eax
	ret
	.size	_Z1fiii, .-_Z1fiii
<<<<<<< HEAD
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
=======
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	.section	.note.GNU-stack,"",@progbits
