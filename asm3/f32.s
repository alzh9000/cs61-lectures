	.file	"f32.cc"
	.text
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
	endbr64
	subq	$8, %rsp
	addl	$1, %edi
	call	_Z1gi@PLT
	addq	$8, %rsp
	subl	$1, %eax
	ret
	.size	_Z1fi, .-_Z1fi
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
