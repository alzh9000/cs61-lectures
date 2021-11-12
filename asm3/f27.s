	.file	"f27.cc"
	.text
	.globl	_Z1fjjj
	.type	_Z1fjjj, @function
_Z1fjjj:
<<<<<<< HEAD
=======
	endbr64
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	cmpl	%edx, %esi
	cmovb	%edx, %esi
	cmpl	%edi, %esi
	movl	%edi, %eax
	cmovnb	%esi, %eax
	ret
	.size	_Z1fjjj, .-_Z1fjjj
<<<<<<< HEAD
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
=======
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	.section	.note.GNU-stack,"",@progbits
