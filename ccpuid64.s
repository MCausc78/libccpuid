.text
.globl ccpuid_memchra
ccpuid_memchra:
	movq %rdx, %rcx
	movb %al, %sil
	movq %rdi, %rsi
	cld
	repe scasb
	cmpq %rsi, %rdi
	jne .ccpuid_memchra_found
	xorq %rax, %rax
	jmp .ccpuid_memchra_clean
.ccpuid_memchra_found:
	movq %rdi, %rax
.ccpuid_memchra_clean:
	retq

.globl ccpuid_memcmpa
ccpuid_memcmpa:
	movq %rdx, %rcx
	movb %al, %sil
	cld
	repe cmpsb
	jb .is_less
	ja .is_greater
	xorl %eax, %eax
	jmp .ccpuid_memcmpa_clean
.is_less:
	movl $-1, %eax
	jmp .ccpuid_memcmpa_clean
.is_greater:
	movl $1, %eax
	jmp .ccpuid_memcmpa_clean
.ccpuid_memcmpa_clean:
	retq

.globl ccpuid_memcpya
ccpuid_memcpya:
	movq %rdx, %rax
	movl $8, %ecx
	cqo
	idiv %rcx
	movq %rax, %rcx
	cld
	rep movsq
	movq %rdx, %rcx
	cld
	rep movsb
	movq %rdi, %rax
	retq

.globl ccpuid_cpuid_1
ccpuid_cpuid_1:
	testq %rdi, %rdi
	jz .is_nullptr_1
	movl %esi, %eax
	movl %edx, %ecx
	cpuid
	movl %eax, (%rdi)
	movl %ebx, 4(%rdi)
	movl %ecx, 8(%rdi)
	movl %edx, 12(%rdi)
	movq %rdi, %rax
	jmp .clean_1
.is_nullptr_1:
	xorq %rax, %rax
.clean_1:
	retq

.globl ccpuid_cpuid_2
ccpuid_cpuid_2:
	testq %rdi, %rdi
	jz .is_nullptr_2
	movl %esi, %eax
	cpuid
	movl %eax, (%rdi)
	movl %ebx, 4(%rdi)
	movl %ecx, 8(%rdi)
	movl %edx, 12(%rdi)
	movq %rdi, %rax
	jmp .clean_2
.is_nullptr_2:
	xorq %rax, %rax
.clean_2:
	retq

.globl ccpuid_rdrand_16
ccpuid_rdrand_16:
	rdrand %ax
	movw %ax, (%rdi)
	xorl %eax, %eax
	retq

.globl ccpuid_rdrand_32
ccpuid_rdrand_32:
	rdrand %eax
	movl %eax, (%rdi)
	xorl %eax, %eax
	retq

.globl ccpuid_rdrand_64
ccpuid_rdrand_64:
	rdrand %rax
	movq %rax, (%rdi)
	xorl %eax, %eax
	retq

.globl ccpuid_rdseed_16
ccpuid_rdseed_16:
	rdseed %ax
	movw %ax, (%rdi)
	xorl %eax, %eax
	retq

.globl ccpuid_rdseed_32
ccpuid_rdseed_32:
	rdseed %eax
	movl %eax, (%rdi)
	xorl %eax, %eax
	retq

.globl ccpuid_rdseed_64
ccpuid_rdseed_64:
	rdseed %rax
	movq %rax, (%rdi)
	xorl %eax, %eax
	retq

/* removed: Segmentation fault */
/* .globl ccpuid_fetch_vendor
ccpuid_fetch_vendor:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	
	leaq -16(%rbp), %rdi
	xorl %esi, %esi
	call ccpuid_cpuid_1
	movl %eax, -12(%rbp)
	movl %eax, (%rdi)
	movl %eax, -4(%rbp)
	movl %eax, 4(%rdi)
	movl %eax, -8(%rbp)
	movl %eax, 8(%rdi)
	movq %rdi, %rax
	addq $16, %rsp
	leave
	retq */

.globl ccpuid_is_available
ccpuid_is_available:
	movl $1, %eax
	retq

.globl ccpuid_getflags
ccpuid_getflags:
	pushfq
	popq %rax
	retq

.globl ccpuid_setflags
ccpuid_setflags:
	pushq %rdi
	popfq
	retq

.globl ccpuid_cld
ccpuid_cld:
	cld
	retq

.globl ccpuid_std
ccpuid_std:
	std
	retq

/* remove ld warning */
.section .note.GNU-stack
