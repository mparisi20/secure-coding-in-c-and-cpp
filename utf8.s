	.file	"utf8.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$1819043176, 18(%esp)
	movw	$111, 22(%esp)
	leal	18(%esp), %eax
	movl	%eax, (%esp)
	call	_puts
	movl	$1, 28(%esp)
	jmp	L2
L3:
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
L2:
	movl	28(%esp), %eax
	leal	-1(%eax), %edx
	movl	%edx, 28(%esp)
	testl	%eax, %eax
	jg	L3
	movl	$100, 24(%esp)
	leal	18(%esp), %eax
	movl	%eax, (%esp)
	call	_spc_utf8_isvalid
	movl	%eax, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.globl	_spc_utf8_isvalid
	.def	_spc_utf8_isvalid;	.scl	2;	.type	32;	.endef
_spc_utf8_isvalid:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	jmp	L6
L17:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	js	L7
	movl	$0, -4(%ebp)
	jmp	L15
L7:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	andl	$192, %eax
	cmpl	$128, %eax
	jne	L9
	movl	$0, %eax
	jmp	L10
L9:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	andl	$224, %eax
	cmpl	$192, %eax
	jne	L11
	movl	$1, -4(%ebp)
	jmp	L15
L11:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	andl	$240, %eax
	cmpl	$224, %eax
	jne	L12
	movl	$2, -4(%ebp)
	jmp	L15
L12:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	andl	$248, %eax
	cmpl	$240, %eax
	jne	L13
	movl	$3, -4(%ebp)
	jmp	L15
L13:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	andl	$252, %eax
	cmpl	$248, %eax
	jne	L14
	movl	$4, -4(%ebp)
	jmp	L15
L14:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	andl	$254, %eax
	cmpl	$252, %eax
	jne	L15
	movl	$5, -4(%ebp)
	jmp	L15
L16:
	movl	-4(%ebp), %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	andl	$192, %eax
	cmpl	$128, %eax
	je	L15
	movl	$0, %eax
	jmp	L10
L15:
	movl	-4(%ebp), %eax
	leal	-1(%eax), %edx
	movl	%edx, -4(%ebp)
	testl	%eax, %eax
	jg	L16
	movl	-4(%ebp), %eax
	addl	$1, %eax
	addl	%eax, -8(%ebp)
L6:
	movl	-8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L17
	movl	$1, %eax
L10:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
