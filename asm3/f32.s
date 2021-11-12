	.file	"f32.cc"
	.text
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
<<<<<<< HEAD
=======
	endbr64
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	subq	$8, %rsp
	addl	$1, %edi
	call	_Z1gi@PLT
	addq	$8, %rsp
	subl	$1, %eax
	ret
	.size	_Z1fi, .-_Z1fi
<<<<<<< HEAD
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
=======
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	.section	.note.GNU-stack,"",@progbits
