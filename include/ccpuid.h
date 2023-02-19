#ifndef CCPUID_H
#define CCPUID_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>

enum ccpuid_fi_edx
{
	/* EDX beginning */
	FI_EDX_FPU = 1 << 0,
	FI_EDX_VME = 1 << 1,
	FI_EDX_DE = 1 << 2,
	FI_EDX_PSE = 1 << 3,
	FI_EDX_TSC = 1 << 4,
	FI_EDX_MSR = 1 << 5,
	FI_EDX_PAE = 1 << 6,
	FI_EDX_MCE = 1 << 7,
	FI_EDX_CX8 = 1 << 8,
	FI_EDX_APIC = 1 << 9,
	FI_EDX_UNK0 = 1 << 10, /* unknown */
	FI_EDX_SEP = 1 << 11,
	FI_EDX_MTRR = 1 << 12,
	FI_EDX_PGE = 1 << 13,
	FI_EDX_MCA = 1 << 14,
	FI_EDX_CMOV = 1 << 15,
	FI_EDX_PAT = 1 << 16,
	FI_EDX_PSE_36 = 1 << 17,
	FI_EDX_PSN = 1 << 18,
	FI_EDX_CLFSH = 1 << 19,
	FI_EDX_UNK1 = 1 << 20, /* unknown */
	FI_EDX_DS = 1 << 21,
	FI_EDX_ACPI = 1 << 22,
	FI_EDX_MMX = 1 << 23,
	FI_EDX_FXSR = 1 << 24,
	FI_EDX_SSE = 1 << 25,
	FI_EDX_SSE2 = 1 << 26,
	FI_EDX_SS = 1 << 27,
	FI_EDX_HTT = 1 << 28,
	FI_EDX_TM = 1 << 29,
	FI_EDX_IA64 = 1 << 30,
	FI_EDX_PBE = 1 << 31,
	/* EDX end */
};

enum ccpuid_fi_ecx
{
	/* ECX beginning */
	FI_ECX_SSE3 = 1 << 0,
	FI_ECX_PCLMULQDQ = 1 << 1,
	FI_ECX_DTES64 = 1 << 2,
	FI_ECX_MONITOR = 1 << 3,
	FI_ECX_DSCPL = 1 << 4,
	FI_ECX_VMX = 1 << 5,
	FI_ECX_SMX = 1 << 6,
	FI_ECX_EST = 1 << 7,
	FI_ECX_TM2 = 1 << 8,
	FI_ECX_SSSE3 = 1 << 9,
	FI_ECX_CNXT_ID = 1 << 10,
	FI_ECX_SDBG = 1 << 11,
	FI_ECX_FMA = 1 << 12,
	FI_ECX_CX16 = 1 << 13,
	FI_ECX_XTPR = 1 << 14,
	FI_ECX_PDCM = 1 << 15,
	FI_ECX_UNK0 = 1 << 16, /* unknown */
	FI_ECX_PCID = 1 << 17,
	FI_ECX_DCA = 1 << 18,
	FI_ECX_SSE41 = 1 << 19,
	FI_ECX_SSE42 = 1 << 20,
	FI_ECX_X2APIC = 1 << 21,
	FI_ECX_MOVBE = 1 << 22,
	FI_ECX_POPCNT = 1 << 23,
	FI_ECX_TSCDEADLINE = 1 << 24,
	FI_ECX_AES = 1 << 25,
	FI_ECX_XSAVE = 1 << 26,
	FI_ECX_OSXSAVE = 1 << 27,
	FI_ECX_AVX = 1 << 28,
	FI_ECX_F16C = 1 << 29,
	FI_ECX_RDMD = 1 << 30,
	FI_ECX_HYPERVISOR = 1 << 31,
	/* ECX end */
};

/* Extra features */
enum ccpuid_ef0_ebx
{
	EF0_EBX_FSGSBASE = 1 << 0,
	EF0_EBX_TSC_ADJUST_MSR = 1 << 1,
	EF0_EBX_SGX = 1 << 2,
	EF0_EBX_BMI1 = 1 << 3,
	EF0_EBX_HLE = 1 << 4,
	EF0_EBX_AVX2 = 1 << 5,
	EF0_EBX_FDP_EXCPTN_ONLY = 1 << 6,
	EF0_EBX_SMEP = 1 << 7,
	EF0_EBX_BMI2 = 1 << 8,
	EF0_EBX_ERMS = 1 << 9,
	EF0_EBX_INVPCID = 1 << 10,
	EF0_EBX_RTM = 1 << 11,
	EF0_EBX_RDTM_PQM = 1 << 12,
	EF0_EBX_FPUCS_FPUDS_DEPRECATED = 1 << 13,
	EF0_EBX_MPX = 1 << 14,
	EF0_EBX_RDT_A_PQE = 1 << 15,
	EF0_EBX_AVX512_F = 1 << 16,
	EF0_EBX_AVX512_DQ = 1 << 17,
	EF0_EBX_RDSEED = 1 << 18,
	EF0_EBX_ADX = 1 << 19,
	EF0_EBX_SMAP = 1 << 20,
	EF0_EBX_AVX512_IFMA = 1 << 21,
	EF0_EBX_UNK0 = 1 << 22, /* unknown */
	EF0_EBX_CLFPUSHOPT = 1 << 23,
	EF0_EBX_CLWB = 1 << 24,
	EF0_EBX_PT = 1 << 25,
	EF0_EBX_AVX512_PF = 1 << 26,
	EF0_EBX_AVX512_ER = 1 << 27,
	EF0_EBX_AVX512_CD = 1 << 28,
	EF0_EBX_SHA = 1 << 29,
	EF0_EBX_AVX512_BW = 1 << 30,
	EF0_EBX_AVX512_VL = 1 << 31,
};

enum ccpuid_ef0_ecx
{
	EF0_ECX_PREFETCHWT1 = 1 << 0,
	EF0_ECX_AVX512_VBMI = 1 << 1,
	EF0_ECX_UMIP = 1 << 2,
	EF0_ECX_PKU = 1 << 3,
	EF0_ECX_OSPKE = 1 << 4,
	EF0_ECX_WAITPKG = 1 << 5,
	EF0_ECX_AVX512_VBMI2 = 1 << 6,
	EF0_ECX_CET_SS = 1 << 7,
	EF0_ECX_GFNI = 1 << 8,
	EF0_ECX_VAES = 1 << 9,
	EF0_ECX_VPCLMULQDQ = 1 << 10,
	EF0_ECX_AVX512_VNNI = 1 << 11,
	EF0_ECX_AVX512_BITALG = 1 << 12,
	EF0_ECX_TME = 1 << 13,
	EF0_ECX_AVX512_VPOPCNTDQ = 1 << 14,
	EF0_ECX_UNK0 = 1 << 15, /* unknown */
	EF0_ECX_LA54 = 1 << 16,
	EF0_ECX_MAWAU_BEGIN = 1 << 17,
	EF0_ECX_MAWAU_END = 1 << 21,
	EF0_ECX_RDPID = 1 << 22,
	EF0_ECX_KI = 1 << 23,
	EF0_ECX_BUS_LOCK_DETECT = 1 << 24,
	EF0_ECX_CLDEMOTE = 1 << 25,
	EF0_ECX_UNK1 = 1 << 26,
	EF0_ECX_MOVDIRI = 1 << 27,
	EF0_ECX_MOVDIR64B = 1 << 28,
	EF0_ECX_ENQCMD = 1 << 29,
	EF0_ECX_SGX_LC = 1 << 30,
	EF0_ECX_PKS = 1 << 31,
};

enum ccpuid_ef0_edx
{
	EF0_EDX_SGX_KEYS = 1 << 0,
	EF0_EDX_UNK0 = 1 << 1, /* unknown */
	EF0_EDX_AVX512_4VNNIW = 1 << 2,
	EF0_EDX_AVX512_4FMAPS = 1 << 3,
	EF0_EDX_FSRM = 1 << 4,
	EF0_EDX_UINTR = 1 << 5,
	EF0_EDX_UNK1 = 1 << 6, /* unknown */
	EF0_EDX_UNK2 = 1 << 7, /* unknown */
	EF0_EDX_AVX512_VP2INTERSECT = 1 << 8,
	EF0_EDX_SRDBS_CTRL = 1 << 9,
	EF0_EDX_MC_CLEAR = 1 << 10,
	EF0_EDX_RTM_ALWAYS_ABORT = 1 << 11,
	EF0_EDX_UNK3 = 1 << 12, /* unknown */
	EF0_EDX_TSX_FORCE_ABORT_MSR = 1 << 13,
	EF0_EDX_SERIALIZE = 1 << 14,
	EF0_EDX_HYBRID = 1 << 15,
	EF0_EDX_TSXLDRTK = 1 << 16,
	EF0_EDX_UNK4 = 1 << 17, /* unknown */
	EF0_EDX_PCONFIG = 1 << 18,
	EF0_EDX_LBR = 1 << 19,
	EF0_EDX_CET_IBT = 1 << 20,
	EF0_EDX_UNK5 = 1 << 21, /* unknown */
	EF0_EDX_AMX_BF16 = 1 << 22,
	EF0_EDX_AVX512_FP16 = 1 << 23,
	EF0_EDX_AMX_TILE = 1 << 24,
	EF0_EDX_AMX_INT8 = 1 << 25,
	EF0_EDX_IBRS_IBPB_SPEC_CTRL = 1 << 26,
	EF0_EDX_STIBP = 1 << 27,
	EF0_EDX_L1D_FLUSH = 1 << 28,
	EF0_EDX_IA32_ARCH_CAPABILITIES = 1 << 29,
	EF0_EDX_IA32_CORE_CAPABILITIES = 1 << 30,
	EF0_EDX_SSBD = 1 << 31,
};

enum ccpuid_ef1_eax
{
	EF1_EAX_UNK0 = 1 << 0, /* unknown */
	EF1_EAX_UNK1 = 1 << 1, /* unknown */
	EF1_EAX_UNK2 = 1 << 2, /* unknown */
	EF1_EAX_RAO_INT = 1 << 3,
	EF1_EAX_AVX_VNNI = 1 << 4,
	EF1_EAX_AVX512_BF16 = 1 << 5,
	EF1_EAX_LASS = 1 << 6,
	EF1_EAX_CMPCCXADD = 1 << 7,
	EF1_EAX_ARCHPERFMONEXT = 1 << 8,
	EF1_EAX_UNK3 = 1 << 9, /* unknown */
	EF1_EAX_FAST_ZERO_REP_MOVSB = 1 << 10,
	EF1_EAX_FAST_SHORT_REP_STOSB = 1 << 11,
	EF1_EAX_FAST_SHORT_REP_CMPSB_SCASB = 1 << 12,
	EF1_EAX_UNK4 = 1 << 13, /* unknown */
	EF1_EAX_UNK5 = 1 << 14, /* unknown */
	EF1_EAX_UNK6 = 1 << 15, /* unknown */
	EF1_EAX_UNK7 = 1 << 16, /* unknown */
	EF1_EAX_FRED = 1 << 17,
	EF1_EAX_LKGS = 1 << 18,
	EF1_EAX_WRMSRNS = 1 << 19,
	EF1_EAX_UNK8 = 1 << 20,
	EF1_EAX_AMX_FP16 = 1 << 21,
	EF1_EAX_HRESET = 1 << 22,
	EF1_EAX_AVX_IFMA = 1 << 23,
	EF1_EAX_UNK9 = 1 << 24,
	EF1_EAX_UNK10 = 1 << 25,
	EF1_EAX_LAM = 1 << 26,
	EF1_EAX_MSRLIST = 1 << 27,
	EF1_EAX_UNK11 = 1 << 28,
	EF1_EAX_UNK12 = 1 << 29,
	EF1_EAX_UNK13 = 1 << 30,
	EF1_EAX_UNK14 = 1 << 31,
};

enum ccpuid_ef1_ebx
{
	EF1_EBX_IA32_PPIN_MSR = 1 << 0,
};

enum ccpuid_ef1_edx
{
	EF1_EDX_UNK0 = 1 << 0, /* unknown */
	EF1_EDX_UNK1 = 1 << 1, /* unknown */
	EF1_EDX_UNK2 = 1 << 2, /* unknown */
	EF1_EDX_UNK3 = 1 << 3, /* unknown */
	EF1_EDX_AVX_VNN_INT8 = 1 << 4, /* unknown */
	EF1_EDX_AVX_NE_CONVERT = 1 << 5, /* unknown */
	EF1_EDX_UNK4 = 1 << 6, /* unknown */
	EF1_EDX_UNK5 = 1 << 7, /* unknown */
	EF1_EDX_UNK6 = 1 << 8, /* unknown */
	EF1_EDX_UNK7 = 1 << 9, /* unknown */
	EF1_EDX_UNK8 = 1 << 10, /* unknown */
	EF1_EDX_UNK9 = 1 << 11, /* unknown */
	EF1_EDX_UNK10 = 1 << 12, /* unknown */
	EF1_EDX_UNK11 = 1 << 13, /* unknown */
	EF1_EDX_PREFETCHITI = 1 << 14,
	EF1_EDX_UNK13 = 1 << 15, /* unknown */
	EF1_EDX_UNK14 = 1 << 16, /* unknown */
	EF1_EDX_UNK15 = 1 << 17, /* unknown */
	EF1_EDX_CET_SSS = 1 << 18,
};

enum ccpuid_fi_eax_d1
{
	FI_EAX_D1_XSAVEOPT = 1 << 0,
	FI_EAX_D1_XSAVEC = 1 << 1,
	FI_EAX_D1_XGETBV_ECX1 = 1 << 2,
	FI_EAX_D1_XSS = 1 << 3,
};

enum ccpuid_epi_edx
{
	EPI_EDX_FPU = 1 << 0,
	EPI_EDX_VME = 1 << 1,
	EPI_EDX_DE = 1 << 2,
	EPI_EDX_PSE = 1 << 3,
	EPI_EDX_TSC = 1 << 4,
	EPI_EDX_MSR = 1 << 5,
	EPI_EDX_PAE = 1 << 6,
	EPI_EDX_MCE = 1 << 7,
	EPI_EDX_CX8 = 1 << 8,
	EPI_EDX_APIC = 1 << 9,
	EPI_EDX_UNK0 = 1 << 10, /* unknown */
	EPI_EDX_SYSCALL = 1 << 11,
	EPI_EDX_MTRR = 1 << 12,
	EPI_EDX_PGE = 1 << 13,
	EPI_EDX_MCA = 1 << 14,
	EPI_EDX_CMOV = 1 << 15,
	EPI_EDX_PAT = 1 << 16,
	EPI_EDX_PSE36 = 1 << 17,
	EPI_EDX_UNK1 = 1 << 18, /* unknown */
	EPI_EDX_MP = 1 << 19,
	EPI_EDX_NX = 1 << 20,
	EPI_EDX_UNK2 = 1 << 21, /* unknown */
	EPI_EDX_MMXEXT = 1 << 22,
	EPI_EDX_MMX = 1 << 23,
	EPI_EDX_FXSR = 1 << 24,
	EPI_EDX_FXSR_OPT = 1 << 25,
	EPI_EDX_PDPE1GB = 1 << 26,
	EPI_EDX_RDTSCP = 1 << 27,
	EPI_EDX_UNK3 = 1 << 28, /* unknown */
	EPI_EDX_LONG_MODE = 1 << 29,
	EPI_EDX_3DNOW_EXT = 1 << 30,
	EPI_EDX_3DNOW = 1 << 31,
};

enum ccpuid_epi_ecx
{
	EPI_ECX_LAHF_LM = 1 << 0,
	EPI_ECX_CMP_LEGACY = 1 << 1,
	EPI_ECX_SVM = 1 << 2,
	EPI_ECX_EXTAPIC = 1 << 3,
	EPI_ECX_CR8_LEGACY = 1 << 4,
	EPI_ECX_ABM = 1 << 5,
	EPI_ECX_SSE4A = 1 << 6,
	EPI_ECX_MISALIGNSSE = 1 << 7,
	EPI_ECX_3DNOWPREFETCH = 1 << 8,
	EPI_ECX_OSVW = 1 << 9,
	EPI_ECX_IBS = 1 << 10,
	EPI_ECX_XOP = 1 << 11,
	EPI_ECX_SKINIT = 1 << 12,
	EPI_ECX_WDT = 1 << 13,
	EPI_ECX_UNK0 = 1 << 14, /* unknown */
	EPI_ECX_WLP = 1 << 15,
	EPI_ECX_FMA4 = 1 << 16,
	EPI_ECX_TCE = 1 << 17,
	EPI_ECX_UNK1 = 1 << 18, /* unknown */
	EPI_ECX_NODEID_MSR = 1 << 19,
	EPI_ECX_UNK2 = 1 << 20, /* unknown */
	EPI_ECX_TBM = 1 << 21,
	EPI_ECX_TOPOEXT = 1 << 22,
	EPI_ECX_PERFCTR_CORE = 1 << 23,
	EPI_ECX_PERFCTR_NB = 1 << 24,
	EPI_ECX_UNK3 = 1 << 25, /* unknown */
	EPI_ECX_DBX = 1 << 26,
	EPI_ECX_PERFTSC = 1 << 27,
	EPI_ECX_PCX_L2I = 1 << 28,
	EPI_ECX_MONITORX = 1 << 29,
	EPI_ECX_ADDR_MASK_EXT = 1 << 30,
	EPI_ECX_UNK4 = 1 << 31, /* unknown */
};

enum ccpuid_hfp
{
	HFP_EAX_I486_PENTIUM = 0x01,
	HFP_EAX_PENTIUM_PRO = 0x02,
	HFP_EAX_PENTIUM_II = 0x02,
	HFP_EAX_CELERON = 0x02,
	HFP_EAX_PENTIUM_III = 0x03,
	HFP_EAX_PENTIUM_4 = 0x02,
	HFP_EAX_XEON = 0x02,
	HFP_EAX_PENTIUM_M = 0x02,
	HFP_EAX_PENTIUM_4_HT = 0x05,
	HFP_EAX_PENTIUM_D8XX = 0x05,
	HFP_EAX_PENTIUM_D9XX = 0x06,
	HFP_EAX_CORE_DUO = 0x0A,
	HFP_EAX_CORE_2_DUO = 0x0A,
	HFP_EAX_XEON_3000_5000 = 0x0A,
	HFP_EAX_CORE_2_DUO_8000 = 0x0D,
	HFP_EAX_XEON_5200_5400 = 0x0A,
	HFP_EAX_ATOM = 0x0A,
	HFP_EAX_NEHALEM = 0x0B,
	HFP_EAX_IVY_BRIDGE = 0x0D,
	HFP_EAX_SKYLAKE = 0x16,
	HFP_EAX_SOC = 0x17,
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

extern ccpuid_result_t * ccpuid_cpuid_1(ccpuid_result_t * dest, int leaf);
extern ccpuid_result_t * ccpuid_cpuid_2(ccpuid_result_t * dest, int leaf, int subleaf);

extern void ccpuid_rdrand_16(uint16_t * dest);
extern void ccpuid_rdrand_32(uint32_t * dest);
extern void ccpuid_rdrand_64(uint64_t * dest);

extern void ccpuid_rdseed_16(uint16_t seed);
extern void ccpuid_rdseed_32(uint32_t seed);
extern void ccpuid_rdseed_64(uint64_t seed);

/* extern char * ccpuid_fetch_vendor(char * vendor); */

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

inline
size_t ccpuid_fetch_brand(char * brand)
{
	size_t len = 48;
	int i;
	char buffer[96] = { 0 };
	for (i = 0; i <= 2; ++i)
	{
		ccpuid_cpuid_1((ccpuid_result_t *) (buffer + i * 16), i + 0x80000002);
	}
	char * ptr = buffer;
	for (i = 0; i < 48 && buffer[i] == ' '; ++i, ++ptr);
	char * eos = memchr(ptr, '\0', 48);
	len = eos - ptr;
	memcpy(brand, ptr, len);
	return len;
}

extern enum ccpuid_vendor ccpuid_get_vendor(void);
extern const char * ccpuid_vendor_tostring(enum ccpuid_vendor vendor);

#ifdef __cplusplus
}
#endif

#endif /* CCPUID_H */
