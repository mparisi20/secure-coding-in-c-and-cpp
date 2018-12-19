	.file	"pass.c"
	.section .rdata,"dr"
LC0:
	.ascii "goodpass\0"
	.text
	.globl	_isPasswordOK
	.def	_isPasswordOK;	.scl	2;	.type	32;	.endef
_isPasswordOK:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_gets
	movl	$LC0, 4(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L2
	movl	$1, %eax
	jmp	L4
L2:
	movl	$0, %eax
L4:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Enter Password: \0"
LC2:
	.ascii "Access denied\0"
LC3:
	.ascii "Access granted\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$LC1, (%esp)
	call	_puts
	call	_isPasswordOK
	movl	%eax, 28(%esp)
	cmpl	$0, 28(%esp)
	jne	L6
	movl	$LC2, (%esp)
	call	_puts
	movl	$-1, (%esp)
	call	_exit
L6:
	movl	$LC3, (%esp)
	call	_puts
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_gets;	.scl	2;	.type	32;	.endef
	.def	_strcmp;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
