#ifndef CCPUID_H
#define CCPUID_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#ifndef CCPUID_NO_STDLIB
#include <string.h>
#endif /* CCPUID_NO_STDLIB */

enum ccpuid_fi_edx
{
	/* EDX beginning */
	CCPUID_FI_EDX_FPU = 1 << 0,
	CCPUID_FI_EDX_VME = 1 << 1,
	CCPUID_FI_EDX_DE = 1 << 2,
	CCPUID_FI_EDX_PSE = 1 << 3,
	CCPUID_FI_EDX_TSC = 1 << 4,
	CCPUID_FI_EDX_MSR = 1 << 5,
	CCPUID_FI_EDX_PAE = 1 << 6,
	CCPUID_FI_EDX_MCE = 1 << 7,
	CCPUID_FI_EDX_CX8 = 1 << 8,
	CCPUID_FI_EDX_APIC = 1 << 9,
	CCPUID_FI_EDX_UNK0 = 1 << 10, /* unknown */
	CCPUID_FI_EDX_SEP = 1 << 11,
	CCPUID_FI_EDX_MTRR = 1 << 12,
	CCPUID_FI_EDX_PGE = 1 << 13,
	CCPUID_FI_EDX_MCA = 1 << 14,
	CCPUID_FI_EDX_CMOV = 1 << 15,
	CCPUID_FI_EDX_PAT = 1 << 16,
	CCPUID_FI_EDX_PSE_36 = 1 << 17,
	CCPUID_FI_EDX_PSN = 1 << 18,
	CCPUID_FI_EDX_CLFSH = 1 << 19,
	CCPUID_FI_EDX_UNK1 = 1 << 20, /* unknown */
	CCPUID_FI_EDX_DS = 1 << 21,
	CCPUID_FI_EDX_ACPI = 1 << 22,
	CCPUID_FI_EDX_MMX = 1 << 23,
	CCPUID_FI_EDX_FXSR = 1 << 24,
	CCPUID_FI_EDX_SSE = 1 << 25,
	CCPUID_FI_EDX_SSE2 = 1 << 26,
	CCPUID_FI_EDX_SS = 1 << 27,
	CCPUID_FI_EDX_HTT = 1 << 28,
	CCPUID_FI_EDX_TM = 1 << 29,
	CCPUID_FI_EDX_IA64 = 1 << 30,
	CCPUID_FI_EDX_PBE = 1 << 31,
	/* EDX end */
};

enum ccpuid_fi_ecx
{
	/* ECX beginning */
	CCPUID_FI_ECX_SSE3 = 1 << 0,
	CCPUID_FI_ECX_PCLMULQDQ = 1 << 1,
	CCPUID_FI_ECX_DTES64 = 1 << 2,
	CCPUID_FI_ECX_MONITOR = 1 << 3,
	CCPUID_FI_ECX_DSCPL = 1 << 4,
	CCPUID_FI_ECX_VMX = 1 << 5,
	CCPUID_FI_ECX_SMX = 1 << 6,
	CCPUID_FI_ECX_EST = 1 << 7,
	CCPUID_FI_ECX_TM2 = 1 << 8,
	CCPUID_FI_ECX_SSSE3 = 1 << 9,
	CCPUID_FI_ECX_CNXT_ID = 1 << 10,
	CCPUID_FI_ECX_SDBG = 1 << 11,
	CCPUID_FI_ECX_FMA = 1 << 12,
	CCPUID_FI_ECX_CX16 = 1 << 13,
	CCPUID_FI_ECX_XTPR = 1 << 14,
	CCPUID_FI_ECX_PDCM = 1 << 15,
	CCPUID_FI_ECX_UNK0 = 1 << 16, /* unknown */
	CCPUID_FI_ECX_PCID = 1 << 17,
	CCPUID_FI_ECX_DCA = 1 << 18,
	CCPUID_FI_ECX_SSE41 = 1 << 19,
	CCPUID_FI_ECX_SSE42 = 1 << 20,
	CCPUID_FI_ECX_X2APIC = 1 << 21,
	CCPUID_FI_ECX_MOVBE = 1 << 22,
	CCPUID_FI_ECX_POPCNT = 1 << 23,
	CCPUID_FI_ECX_TSCDEADLINE = 1 << 24,
	CCPUID_FI_ECX_AES = 1 << 25,
	CCPUID_FI_ECX_XSAVE = 1 << 26,
	CCPUID_FI_ECX_OSXSAVE = 1 << 27,
	CCPUID_FI_ECX_AVX = 1 << 28,
	CCPUID_FI_ECX_F16C = 1 << 29,
	CCPUID_FI_ECX_RDMD = 1 << 30,
	CCPUID_FI_ECX_HYPERVISOR = 1 << 31,
	/* ECX end */
};

/* Extra features */
enum ccpuid_ef0_ebx
{
	CCPUID_EF0_EBX_FSGSBASE = 1 << 0,
	CCPUID_EF0_EBX_TSC_ADJUST_MSR = 1 << 1,
	CCPUID_EF0_EBX_SGX = 1 << 2,
	CCPUID_EF0_EBX_BMI1 = 1 << 3,
	CCPUID_EF0_EBX_HLE = 1 << 4,
	CCPUID_EF0_EBX_AVX2 = 1 << 5,
	CCPUID_EF0_EBX_FDP_EXCPTN_ONLY = 1 << 6,
	CCPUID_EF0_EBX_SMEP = 1 << 7,
	CCPUID_EF0_EBX_BMI2 = 1 << 8,
	CCPUID_EF0_EBX_ERMS = 1 << 9,
	CCPUID_EF0_EBX_INVPCID = 1 << 10,
	CCPUID_EF0_EBX_RTM = 1 << 11,
	CCPUID_EF0_EBX_RDTM_PQM = 1 << 12,
	CCPUID_EF0_EBX_FPUCS_FPUDS_DEPRECATED = 1 << 13,
	CCPUID_EF0_EBX_MPX = 1 << 14,
	CCPUID_EF0_EBX_RDT_A_PQE = 1 << 15,
	CCPUID_EF0_EBX_AVX512_F = 1 << 16,
	CCPUID_EF0_EBX_AVX512_DQ = 1 << 17,
	CCPUID_EF0_EBX_RDSEED = 1 << 18,
	CCPUID_EF0_EBX_ADX = 1 << 19,
	CCPUID_EF0_EBX_SMAP = 1 << 20,
	CCPUID_EF0_EBX_AVX512_IFMA = 1 << 21,
	CCPUID_EF0_EBX_UNK0 = 1 << 22, /* unknown */
	CCPUID_EF0_EBX_CLFPUSHOPT = 1 << 23,
	CCPUID_EF0_EBX_CLWB = 1 << 24,
	CCPUID_EF0_EBX_PT = 1 << 25,
	CCPUID_EF0_EBX_AVX512_PF = 1 << 26,
	CCPUID_EF0_EBX_AVX512_ER = 1 << 27,
	CCPUID_EF0_EBX_AVX512_CD = 1 << 28,
	CCPUID_EF0_EBX_SHA = 1 << 29,
	CCPUID_EF0_EBX_AVX512_BW = 1 << 30,
	CCPUID_EF0_EBX_AVX512_VL = 1 << 31,
};

enum ccpuid_ef0_ecx
{
	CCPUID_EF0_ECX_PREFETCHWT1 = 1 << 0,
	CCPUID_EF0_ECX_AVX512_VBMI = 1 << 1,
	CCPUID_EF0_ECX_UMIP = 1 << 2,
	CCPUID_EF0_ECX_PKU = 1 << 3,
	CCPUID_EF0_ECX_OSPKE = 1 << 4,
	CCPUID_EF0_ECX_WAITPKG = 1 << 5,
	CCPUID_EF0_ECX_AVX512_VBMI2 = 1 << 6,
	CCPUID_EF0_ECX_CET_SS = 1 << 7,
	CCPUID_EF0_ECX_GFNI = 1 << 8,
	CCPUID_EF0_ECX_VAES = 1 << 9,
	CCPUID_EF0_ECX_VPCLMULQDQ = 1 << 10,
	CCPUID_EF0_ECX_AVX512_VNNI = 1 << 11,
	CCPUID_EF0_ECX_AVX512_BITALG = 1 << 12,
	CCPUID_EF0_ECX_TME = 1 << 13,
	CCPUID_EF0_ECX_AVX512_VPOPCNTDQ = 1 << 14,
	CCPUID_EF0_ECX_UNK0 = 1 << 15, /* unknown */
	CCPUID_EF0_ECX_LA54 = 1 << 16,
	CCPUID_EF0_ECX_MAWAU_BEGIN = 1 << 17,
	CCPUID_EF0_ECX_MAWAU_END = 1 << 21,
	CCPUID_EF0_ECX_RDPID = 1 << 22,
	CCPUID_EF0_ECX_KI = 1 << 23,
	CCPUID_EF0_ECX_BUS_LOCK_DETECT = 1 << 24,
	CCPUID_EF0_ECX_CLDEMOTE = 1 << 25,
	CCPUID_EF0_ECX_UNK1 = 1 << 26,
	CCPUID_EF0_ECX_MOVDIRI = 1 << 27,
	CCPUID_EF0_ECX_MOVDIR64B = 1 << 28,
	CCPUID_EF0_ECX_ENQCMD = 1 << 29,
	CCPUID_EF0_ECX_SGX_LC = 1 << 30,
	CCPUID_EF0_ECX_PKS = 1 << 31,
};

enum ccpuid_ef0_edx
{
	CCPUID_EF0_EDX_SGX_KEYS = 1 << 0,
	CCPUID_EF0_EDX_UNK0 = 1 << 1, /* unknown */
	CCPUID_EF0_EDX_AVX512_4VNNIW = 1 << 2,
	CCPUID_EF0_EDX_AVX512_4FMAPS = 1 << 3,
	CCPUID_EF0_EDX_FSRM = 1 << 4,
	CCPUID_EF0_EDX_UINTR = 1 << 5,
	CCPUID_EF0_EDX_UNK1 = 1 << 6, /* unknown */
	CCPUID_EF0_EDX_UNK2 = 1 << 7, /* unknown */
	CCPUID_EF0_EDX_AVX512_VP2INTERSECT = 1 << 8,
	CCPUID_EF0_EDX_SRDBS_CTRL = 1 << 9,
	CCPUID_EF0_EDX_MC_CLEAR = 1 << 10,
	CCPUID_EF0_EDX_RTM_ALWAYS_ABORT = 1 << 11,
	CCPUID_EF0_EDX_UNK3 = 1 << 12, /* unknown */
	CCPUID_EF0_EDX_TSX_FORCE_ABORT_MSR = 1 << 13,
	CCPUID_EF0_EDX_SERIALIZE = 1 << 14,
	CCPUID_EF0_EDX_HYBRID = 1 << 15,
	CCPUID_EF0_EDX_TSXLDRTK = 1 << 16,
	CCPUID_EF0_EDX_UNK4 = 1 << 17, /* unknown */
	CCPUID_EF0_EDX_PCONFIG = 1 << 18,
	CCPUID_EF0_EDX_LBR = 1 << 19,
	CCPUID_EF0_EDX_CET_IBT = 1 << 20,
	CCPUID_EF0_EDX_UNK5 = 1 << 21, /* unknown */
	CCPUID_EF0_EDX_AMX_BF16 = 1 << 22,
	CCPUID_EF0_EDX_AVX512_FP16 = 1 << 23,
	CCPUID_EF0_EDX_AMX_TILE = 1 << 24,
	CCPUID_EF0_EDX_AMX_INT8 = 1 << 25,
	CCPUID_EF0_EDX_IBRS_IBPB_SPEC_CTRL = 1 << 26,
	CCPUID_EF0_EDX_STIBP = 1 << 27,
	CCPUID_EF0_EDX_L1D_FLUSH = 1 << 28,
	CCPUID_EF0_EDX_IA32_ARCH_CAPABILITIES = 1 << 29,
	CCPUID_EF0_EDX_IA32_CORE_CAPABILITIES = 1 << 30,
	CCPUID_EF0_EDX_SSBD = 1 << 31,
};

enum ccpuid_ef1_eax
{
	CCPUID_EF1_EAX_UNK0 = 1 << 0, /* unknown */
	CCPUID_EF1_EAX_UNK1 = 1 << 1, /* unknown */
	CCPUID_EF1_EAX_UNK2 = 1 << 2, /* unknown */
	CCPUID_EF1_EAX_RAO_INT = 1 << 3,
	CCPUID_EF1_EAX_AVX_VNNI = 1 << 4,
	CCPUID_EF1_EAX_AVX512_BF16 = 1 << 5,
	CCPUID_EF1_EAX_LASS = 1 << 6,
	CCPUID_EF1_EAX_CMPCCXADD = 1 << 7,
	CCPUID_EF1_EAX_ARCHPERFMONEXT = 1 << 8,
	CCPUID_EF1_EAX_UNK3 = 1 << 9, /* unknown */
	CCPUID_EF1_EAX_FAST_ZERO_REP_MOVSB = 1 << 10,
	CCPUID_EF1_EAX_FAST_SHORT_REP_STOSB = 1 << 11,
	CCPUID_EF1_EAX_FAST_SHORT_REP_CMPSB_SCASB = 1 << 12,
	CCPUID_EF1_EAX_UNK4 = 1 << 13, /* unknown */
	CCPUID_EF1_EAX_UNK5 = 1 << 14, /* unknown */
	CCPUID_EF1_EAX_UNK6 = 1 << 15, /* unknown */
	CCPUID_EF1_EAX_UNK7 = 1 << 16, /* unknown */
	CCPUID_EF1_EAX_FRED = 1 << 17,
	CCPUID_EF1_EAX_LKGS = 1 << 18,
	CCPUID_EF1_EAX_WRMSRNS = 1 << 19,
	CCPUID_EF1_EAX_UNK8 = 1 << 20,
	CCPUID_EF1_EAX_AMX_FP16 = 1 << 21,
	CCPUID_EF1_EAX_HRESET = 1 << 22,
	CCPUID_EF1_EAX_AVX_IFMA = 1 << 23,
	CCPUID_EF1_EAX_UNK9 = 1 << 24,
	CCPUID_EF1_EAX_UNK10 = 1 << 25,
	CCPUID_EF1_EAX_LAM = 1 << 26,
	CCPUID_EF1_EAX_MSRLIST = 1 << 27,
	CCPUID_EF1_EAX_UNK11 = 1 << 28,
	CCPUID_EF1_EAX_UNK12 = 1 << 29,
	CCPUID_EF1_EAX_UNK13 = 1 << 30,
	CCPUID_EF1_EAX_UNK14 = 1 << 31,
};

enum ccpuid_ef1_ebx
{
	EF1_EBX_IA32_PPIN_MSR = 1 << 0,
};

enum ccpuid_ef1_edx
{
	CCPUID_EF1_EDX_UNK0 = 1 << 0, /* unknown */
	CCPUID_EF1_EDX_UNK1 = 1 << 1, /* unknown */
	CCPUID_EF1_EDX_UNK2 = 1 << 2, /* unknown */
	CCPUID_EF1_EDX_UNK3 = 1 << 3, /* unknown */
	CCPUID_EF1_EDX_AVX_VNN_INT8 = 1 << 4, /* unknown */
	CCPUID_EF1_EDX_AVX_NE_CONVERT = 1 << 5, /* unknown */
	CCPUID_EF1_EDX_UNK4 = 1 << 6, /* unknown */
	CCPUID_EF1_EDX_UNK5 = 1 << 7, /* unknown */
	CCPUID_EF1_EDX_UNK6 = 1 << 8, /* unknown */
	CCPUID_EF1_EDX_UNK7 = 1 << 9, /* unknown */
	CCPUID_EF1_EDX_UNK8 = 1 << 10, /* unknown */
	CCPUID_EF1_EDX_UNK9 = 1 << 11, /* unknown */
	CCPUID_EF1_EDX_UNK10 = 1 << 12, /* unknown */
	CCPUID_EF1_EDX_UNK11 = 1 << 13, /* unknown */
	CCPUID_EF1_EDX_PREFETCHITI = 1 << 14,
	CCPUID_EF1_EDX_UNK13 = 1 << 15, /* unknown */
	CCPUID_EF1_EDX_UNK14 = 1 << 16, /* unknown */
	CCPUID_EF1_EDX_UNK15 = 1 << 17, /* unknown */
	CCPUID_EF1_EDX_CET_SSS = 1 << 18,
};

enum ccpuid_fi_eax_d1
{
	CCPUID_FI_EAX_D1_XSAVEOPT = 1 << 0,
	CCPUID_FI_EAX_D1_XSAVEC = 1 << 1,
	CCPUID_FI_EAX_D1_XGETBV_ECX1 = 1 << 2,
	CCPUID_FI_EAX_D1_XSS = 1 << 3,
};

enum ccpuid_epi_edx
{
	CCPUID_EPI_EDX_FPU = 1 << 0,
	CCPUID_EPI_EDX_VME = 1 << 1,
	CCPUID_EPI_EDX_DE = 1 << 2,
	CCPUID_EPI_EDX_PSE = 1 << 3,
	CCPUID_EPI_EDX_TSC = 1 << 4,
	CCPUID_EPI_EDX_MSR = 1 << 5,
	CCPUID_EPI_EDX_PAE = 1 << 6,
	CCPUID_EPI_EDX_MCE = 1 << 7,
	CCPUID_EPI_EDX_CX8 = 1 << 8,
	CCPUID_EPI_EDX_APIC = 1 << 9,
	CCPUID_EPI_EDX_UNK0 = 1 << 10, /* unknown */
	CCPUID_EPI_EDX_SYSCALL = 1 << 11,
	CCPUID_EPI_EDX_MTRR = 1 << 12,
	CCPUID_EPI_EDX_PGE = 1 << 13,
	CCPUID_EPI_EDX_MCA = 1 << 14,
	CCPUID_EPI_EDX_CMOV = 1 << 15,
	CCPUID_EPI_EDX_PAT = 1 << 16,
	CCPUID_EPI_EDX_PSE36 = 1 << 17,
	CCPUID_EPI_EDX_UNK1 = 1 << 18, /* unknown */
	CCPUID_EPI_EDX_MP = 1 << 19,
	CCPUID_EPI_EDX_NX = 1 << 20,
	CCPUID_EPI_EDX_UNK2 = 1 << 21, /* unknown */
	CCPUID_EPI_EDX_MMXEXT = 1 << 22,
	CCPUID_EPI_EDX_MMX = 1 << 23,
	CCPUID_EPI_EDX_FXSR = 1 << 24,
	CCPUID_EPI_EDX_FXSR_OPT = 1 << 25,
	CCPUID_EPI_EDX_PDPE1GB = 1 << 26,
	CCPUID_EPI_EDX_RDTSCP = 1 << 27,
	CCPUID_EPI_EDX_UNK3 = 1 << 28, /* unknown */
	CCPUID_EPI_EDX_LONG_MODE = 1 << 29,
	CCPUID_EPI_EDX_3DNOW_EXT = 1 << 30,
	CCPUID_EPI_EDX_3DNOW = 1 << 31,
};

enum ccpuid_epi_ecx
{
	CCPUID_EPI_ECX_LAHF_LM = 1 << 0,
	CCPUID_EPI_ECX_CMP_LEGACY = 1 << 1,
	CCPUID_EPI_ECX_SVM = 1 << 2,
	CCPUID_EPI_ECX_EXTAPIC = 1 << 3,
	CCPUID_EPI_ECX_CR8_LEGACY = 1 << 4,
	CCPUID_EPI_ECX_ABM = 1 << 5,
	CCPUID_EPI_ECX_SSE4A = 1 << 6,
	CCPUID_EPI_ECX_MISALIGNSSE = 1 << 7,
	CCPUID_EPI_ECX_3DNOWPREFETCH = 1 << 8,
	CCPUID_EPI_ECX_OSVW = 1 << 9,
	CCPUID_EPI_ECX_IBS = 1 << 10,
	CCPUID_EPI_ECX_XOP = 1 << 11,
	CCPUID_EPI_ECX_SKINIT = 1 << 12,
	CCPUID_EPI_ECX_WDT = 1 << 13,
	CCPUID_EPI_ECX_UNK0 = 1 << 14, /* unknown */
	CCPUID_EPI_ECX_WLP = 1 << 15,
	CCPUID_EPI_ECX_FMA4 = 1 << 16,
	CCPUID_EPI_ECX_TCE = 1 << 17,
	CCPUID_EPI_ECX_UNK1 = 1 << 18, /* unknown */
	CCPUID_EPI_ECX_NODEID_MSR = 1 << 19,
	CCPUID_EPI_ECX_UNK2 = 1 << 20, /* unknown */
	CCPUID_EPI_ECX_TBM = 1 << 21,
	CCPUID_EPI_ECX_TOPOEXT = 1 << 22,
	CCPUID_EPI_ECX_PERFCTR_CORE = 1 << 23,
	CCPUID_EPI_ECX_PERFCTR_NB = 1 << 24,
	CCPUID_EPI_ECX_UNK3 = 1 << 25, /* unknown */
	CCPUID_EPI_ECX_DBX = 1 << 26,
	CCPUID_EPI_ECX_PERFTSC = 1 << 27,
	CCPUID_EPI_ECX_PCX_L2I = 1 << 28,
	CCPUID_EPI_ECX_MONITORX = 1 << 29,
	CCPUID_EPI_ECX_ADDR_MASK_EXT = 1 << 30,
	CCPUID_EPI_ECX_UNK4 = 1 << 31, /* unknown */
};

enum ccpuid_hfp
{
	CCPUID_HFP_EAX_I486_PENTIUM = 0x01,
	CCPUID_HFP_EAX_PENTIUM_PRO = 0x02,
	CCPUID_HFP_EAX_PENTIUM_II = 0x02,
	CCPUID_HFP_EAX_CELERON = 0x02,
	CCPUID_HFP_EAX_PENTIUM_III = 0x03,
	CCPUID_HFP_EAX_PENTIUM_4 = 0x02,
	CCPUID_HFP_EAX_XEON = 0x02,
	CCPUID_HFP_EAX_PENTIUM_M = 0x02,
	CCPUID_HFP_EAX_PENTIUM_4_HT = 0x05,
	CCPUID_HFP_EAX_PENTIUM_D8XX = 0x05,
	CCPUID_HFP_EAX_PENTIUM_D9XX = 0x06,
	CCPUID_HFP_EAX_CORE_DUO = 0x0A,
	CCPUID_HFP_EAX_CORE_2_DUO = 0x0A,
	CCPUID_HFP_EAX_XEON_3000_5000 = 0x0A,
	CCPUID_HFP_EAX_CORE_2_DUO_8000 = 0x0D,
	CCPUID_HFP_EAX_XEON_5200_5400 = 0x0A,
	CCPUID_HFP_EAX_ATOM = 0x0A,
	CCPUID_HFP_EAX_NEHALEM = 0x0B,
	CCPUID_HFP_EAX_IVY_BRIDGE = 0x0D,
	CCPUID_HFP_EAX_SKYLAKE = 0x16,
	CCPUID_HFP_EAX_SOC = 0x17,
};

typedef struct ccpuid_result
{
	uint32_t eax;
	uint32_t ebx;
	uint32_t ecx;
	uint32_t edx;
} ccpuid_result_t;

extern const char * CCPUID_VENDORS_AMD_K5;
extern const char * CCPUID_VENDORS_AMD;
extern const char * CCPUID_VENDORS_WINCHIP;
extern const char * CCPUID_VENDORS_CYRIX;
extern const char * CCPUID_VENDORS_INTEL;
extern const char * CCPUID_VENDORS_TRANSMETA;
extern const char * CCPUID_VENDORS_TRANSMETA_ALT;
extern const char * CCPUID_VENDORS_NSC;
extern const char * CCPUID_VENDORS_NEXGEN;
extern const char * CCPUID_VENDORS_RISE;
extern const char * CCPUID_VENDORS_SIS;
extern const char * CCPUID_VENDORS_UMC;
extern const char * CCPUID_VENDORS_VIA;
extern const char * CCPUID_VENDORS_VORTEX86;
extern const char * CCPUID_VENDORS_ZHAOXIN;
extern const char * CCPUID_VENDORS_HYGON;
extern const char * CCPUID_VENDORS_RDC;
extern const char * CCPUID_VENDORS_ELBRUS;
extern const char * CCPUID_VENDORS_AO486;
extern const char * CCPUID_VENDORS_BHYVE;
extern const char * CCPUID_VENDORS_KVM;
extern const char * CCPUID_VENDORS_QEMU;
extern const char * CCPUID_VENDORS_HYPER_V;
extern const char * CCPUID_VENDORS_X86_TO_ARM;
extern const char * CCPUID_VENDORS_PARALLELS;
extern const char * CCPUID_VENDORS_PARALLELS_ALT;
extern const char * CCPUID_VENDORS_VMWARE;
extern const char * CCPUID_VENDORS_XEN_HVM;
extern const char * CCPUID_VENDORS_ACRN;
extern const char * CCPUID_VENDORS_QNX;
extern const char * CCPUID_VENDORS_ROSETTA_2;

enum ccpuid_vendor
{
	CCPUID_VENDOR_UNKNOWN,
	CCPUID_VENDOR_AMD_K5,
	CCPUID_VENDOR_AMD,
	CCPUID_VENDOR_WINCHIP,
	CCPUID_VENDOR_CYRIX,
	CCPUID_VENDOR_INTEL,
	CCPUID_VENDOR_TRANSMETA,
	CCPUID_VENDOR_NSC,
	CCPUID_VENDOR_NEXGEN,
	CCPUID_VENDOR_RISE,
	CCPUID_VENDOR_SIS,
	CCPUID_VENDOR_UMC,
	CCPUID_VENDOR_VIA,
	CCPUID_VENDOR_VORTEX86,
	CCPUID_VENDOR_ZHAOXIN,
	CCPUID_VENDOR_HYGON,
	CCPUID_VENDOR_RDC,
	CCPUID_VENDOR_ELBRUS,
	CCPUID_VENDOR_AO486,
	CCPUID_VENDOR_BHYVE,
	CCPUID_VENDOR_KVM,
	CCPUID_VENDOR_QEMU,
	CCPUID_VENDOR_HYPER_V,
	CCPUID_VENDOR_X86_TO_ARM,
	CCPUID_VENDOR_PARALLELS,
	CCPUID_VENDOR_VMWARE,
	CCPUID_VENDOR_XEN_HVM,
	CCPUID_VENDOR_ACRN,
	CCPUID_VENDOR_QNX,
	CCPUID_VENDOR_ROSETTA_2,
};

enum ccpuid_flags
{
	CCPUID_FLAGS_CF = 1 << 0,
	CCPUID_FLAGS_UNK0 = 1 << 1, /* unknown */
	CCPUID_FLAGS_PF = 1 << 2,
	CCPUID_FLAGS_UNK1 = 1 << 3, /* unknown */
	CCPUID_FLAGS_AF = 1 << 4,
	CCPUID_FLAGS_UNK2 = 1 << 5, /* unknown */
	CCPUID_FLAGS_ZF = 1 << 6,
	CCPUID_FLAGS_SF = 1 << 7,
	CCPUID_FLAGS_TF = 1 << 8,
	CCPUID_FLAGS_IF = 1 << 9,
	CCPUID_FLAGS_DF = 1 << 10,
	CCPUID_FLAGS_OF = 1 << 11,
	CCPUID_FLAGS_NT = 1 << 14,
};

enum ccpuid_eflags
{
	CCPUID_EFLAGS_RF = 1 << 16,
	CCPUID_EFLAGS_VM = 1 << 17,
	CCPUID_EFLAGS_AC = 1 << 18,
	CCPUID_EFLAGS_VIF = 1 << 19,
	CCPUID_EFLAGS_VIP = 1 << 20,
	CCPUID_EFLAGS_ID = 1 << 21,
	CCPUID_EFLAGS_AES_KSLF = 1 << 30,
};

/* broken functions, do not use */
extern void * ccpuid_memchra(const void *, int, size_t);
extern int ccpuid_memcmpa(const void *, const void *,  size_t);
extern void * ccpuid_memcpya(void *, const void *, size_t);

extern void * ccpuid_memchr(const void *, int, size_t);
extern int ccpuid_memcmp(const void *, const void *,  size_t);
extern void * ccpuid_memcpy(void *, const void *, size_t);

extern ccpuid_result_t * ccpuid_cpuid_1(ccpuid_result_t * dest, int leaf);
extern ccpuid_result_t * ccpuid_cpuid_2(ccpuid_result_t * dest, int leaf, int subleaf);

extern int ccpuid_rdrand_16(uint16_t * dest);
extern int ccpuid_rdrand_32(uint32_t * dest);
extern int ccpuid_rdrand_64(uint64_t * dest);

extern int ccpuid_rdseed_16(uint16_t * dest);
extern int ccpuid_rdseed_32(uint32_t * dest);
extern int ccpuid_rdseed_64(uint64_t * dest);

inline
char * ccpuid_fetch_vendor(char * vendor)
{
	ccpuid_result_t info;
	ccpuid_cpuid_1(&info, 0);
	(*(int *) vendor) = info.ebx;
	(*(int *) (vendor + 4)) = info.edx;
	(*(int *) (vendor + 8)) = info.ecx;
	return vendor;
}

inline size_t ccpuid_fetch_brand(char * brand)
{
	size_t len = 48;
	int i;
	char buffer[96] = { 0 };
	for (i = 0; i < 3; ++i)
	{
		ccpuid_cpuid_1((ccpuid_result_t *) (buffer + i * 16), i + 0x80000002);
	}
	char * ptr = buffer;
	for (i = 0; i < 48 && buffer[i] == ' '; ++i, ++ptr);
	char * eos =
#ifndef CCPUID_NO_STDLIB
		memchr
#else
		ccpuid_memchr
#endif /* CCPUID_NO_STDLIB */
		(ptr, '\0', 48);
	
	len = eos - ptr;
#if 1
#ifndef CCPUID_NO_STDLIB
	memcpy
#else
	ccpuid_memcpy
#endif /* CCPUID_NO_STDLIB */
	(brand, ptr, len);
#endif
	/*int j;
	for (j = 0; j < len; ++j)
	{
		brand[j] = ptr[j];
	}*/
	return len;
}

extern enum ccpuid_vendor ccpuid_get_vendor(void);
extern const char * ccpuid_vendor_tostring(enum ccpuid_vendor vendor);
extern int ccpuid_is_available(void);
extern size_t ccpuid_getflags(void);
extern void ccpuid_setflags(size_t);
extern void ccpuid_cld(void);
extern void ccpuid_std(void);

#ifdef __cplusplus
}
#endif

#endif /* CCPUID_H */
