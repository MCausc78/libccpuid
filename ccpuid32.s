.text
.globl ccpuid_memchra
ccpuid_memchra:
	movl 24(%esp), %edi
	movl 20(%esp), %esi
	movl 16(%esp), %edx
	movl %edx, %ecx
	
	movw %ax, %si
	andb $0xFF, %al
	movl %edi, %esi
	cld
	repe scasb
	cmpl %esi, %edi
	jne .ccpuid_memchra_found
	xorl %eax, %eax
	jmp .ccpuid_memchra_clean
.ccpuid_memchra_found:
	movl %edi, %eax
.ccpuid_memchra_clean:
	retl

.globl ccpuid_memcmpa
ccpuid_memcmpa:
	movl 24(%esp), %edi
	movl 20(%esp), %esi
	movl 16(%esp), %edx
	movl %edx, %ecx
	movw %ax, %si
	andb $0xFF, %al
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
	retl

.globl ccpuid_memcpya
ccpuid_memcpya:
	movl %edx, %eax
	xorl %edx, %edx
	movl $4, %ecx
	idiv %ecx
	movl %eax, %ecx
	cld
	rep movsl
	movl %edx, %ecx
	cld
	rep movsb
	movl %edi, %eax
	retl

.globl ccpuid_cpuid_1
ccpuid_cpuid_1:
	movl 16(%esp), %edi 
	testl %edi, %edi
	jz .is_nullptr_1
	movl 20(%esp), %eax
	cpuid
	movl %eax, (%edi)
	movl %ebx, 4(%edi)
	movl %ecx, 8(%edi)
	movl %edx, 12(%edi)
	movl %edi, %eax
	jmp .clean_1
.is_nullptr_1:
	xorl %eax, %eax
.clean_1:
	retl

.globl ccpuid_cpuid_2
ccpuid_cpuid_2:
	movl 16(%esp), %edi 
	testl %edi, %edi
	jz .is_nullptr_2
	movl 20(%esp), %eax
	movl 24(%esp), %ecx
	cpuid
	movl %eax, (%edi)
	movl %ebx, 4(%edi)
	movl %ecx, 8(%edi)
	movl %edx, 12(%edi)
	movl %edi, %eax
	jmp .clean_2
.is_nullptr_2:
	xorl %eax, %eax
.clean_2:
	retl

.globl ccpuid_rdrand_16
ccpuid_rdrand_16:
	movl $1, %eax
	retl

.globl ccpuid_rdrand_32
ccpuid_rdrand_32:
	movl $1, %eax
	retl

.globl ccpuid_rdrand_64
ccpuid_rdrand_64:
	movl $1, %eax
	retl

.globl ccpuid_rdseed_16
ccpuid_rdseed_16:
	movl $1, %eax
	retl

.globl ccpuid_rdseed_32
ccpuid_rdseed_32:
	movl $1, %eax
	retl

.globl ccpuid_rdseed_64
ccpuid_rdseed_64:
	movl $1, %eax
	retl


.globl ccpuid_is_available
ccpuid_is_available:
	call ccpuid_getflags
	movl %eax, %edx
	xorl %eax, %eax
	testl $0x200000, %edx
	setnz %al
	movzbl %al, %eax
	retl

.globl ccpuid_getflags
ccpuid_getflags:
	pushfl
	popl %eax
	retl

.globl ccpuid_setflags
ccpuid_setflags:
	movl 16(%esp), %eax
	pushl %eax
	popfl
	xorl %eax, %eax
	retl

.globl ccpuid_cld
ccpuid_cld:
	cld
	retl

.globl ccpuid_std
ccpuid_std:
	std
	retl

/* remove ld warning */
.section .note.GNU-stack
