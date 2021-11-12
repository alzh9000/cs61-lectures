	.file	"f33.cc"
	.text
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
<<<<<<< HEAD
	addl	$1, %edi
	jmp	_Z1gi@PLT
	.size	_Z1fi, .-_Z1fi
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
=======
	endbr64
	addl	$1, %edi
	jmp	_Z1gi@PLT
	.size	_Z1fi, .-_Z1fi
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
	.section	.note.GNU-stack,"",@progbits
