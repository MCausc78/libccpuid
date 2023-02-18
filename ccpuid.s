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
	retq

.globl ccpuid_rdrand_32
ccpuid_rdrand_32:
	rdrand %eax
	movl %eax, (%rdi)
	retq

.globl ccpuid_rdrand_64
ccpuid_rdrand_64:
	rdrand %rax
	movq %rax, (%rdi)
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


/* remove ld warning */
.section .note.GNU-stack
