	.file	"offbyone.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "dest = %s\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$96, %esp
	call	___main
	movl	$858927408, 78(%esp)
	movl	$926299444, 82(%esp)
	movw	$56, 86(%esp)
	movl	$858927408, 67(%esp)
	movl	$926299444, 71(%esp)
	movw	$14648, 75(%esp)
	movb	$0, 77(%esp)
	leal	78(%esp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, 88(%esp)
	movl	$1, 92(%esp)
	jmp	L2
L3:
	movl	92(%esp), %edx
	movl	88(%esp), %eax
	addl	%eax, %edx
	leal	78(%esp), %ecx
	movl	92(%esp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	addl	$1, 92(%esp)
L2:
	cmpl	$11, 92(%esp)
	jle	L3
	movl	92(%esp), %edx
	movl	88(%esp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	movl	88(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$858927408, 51(%esp)
	movl	$926299444, 55(%esp)
	movl	$1650538808, 59(%esp)
	movl	$1717920867, 63(%esp)
	movl	$858927473, 35(%esp)
	movl	$926299444, 39(%esp)
	movl	$1751595320, 43(%esp)
	movl	$1818978921, 47(%esp)
	leal	51(%esp), %eax
	movl	%eax, 4(%esp)
	leal	19(%esp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	leal	19(%esp), %eax
	movl	%eax, (%esp)
	call	_puts
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_strcpy;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
