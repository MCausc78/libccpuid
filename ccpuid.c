#include <ccpuid.h>
#include <string.h>

const char * CCPUID_VENDORS_AMD_K5 = "AMDisbetter!";
const char * CCPUID_VENDORS_AMD = "AuthenticAMD";
const char * CCPUID_VENDORS_WINCHIP = "CentaurHauls";
const char * CCPUID_VENDORS_CYRIX = "CyrixInstead";
const char * CCPUID_VENDORS_INTEL = "GenuineIntel";
const char * CCPUID_VENDORS_TRANSMETA = "TransmetaCPU";
const char * CCPUID_VENDORS_TRANSMETA_ALT = "GenuineTMx86";
const char * CCPUID_VENDORS_NSC = "Geode by NSC";
const char * CCPUID_VENDORS_NEXGEN = "NexGenDriven";
const char * CCPUID_VENDORS_RISE = "RiseRiseRise";
const char * CCPUID_VENDORS_SIS = "SiS SiS SiS ";
const char * CCPUID_VENDORS_UMC = "UMC UMC UMC ";
const char * CCPUID_VENDORS_VIA = "VIA VIA VIA ";
const char * CCPUID_VENDORS_VORTEX86 = "Vortex86 SoC";
const char * CCPUID_VENDORS_ZHAOXIN = "  Shanghai  ";
const char * CCPUID_VENDORS_HYGON = "HygonGenuine";
const char * CCPUID_VENDORS_RDC = "Genuine  RDC";
const char * CCPUID_VENDORS_ELBRUS = "E2K MACHINE";
const char * CCPUID_VENDORS_AO486 = "MiSTer AO486";
const char * CCPUID_VENDORS_BHYVE = "bhyve bhyve ";
const char * CCPUID_VENDORS_KVM = " KVMKVMKVM  ";
const char * CCPUID_VENDORS_QEMU = "TCGTCGTCGTCG";
const char * CCPUID_VENDORS_HYPER_V = "Microsoft Hv";
const char * CCPUID_VENDORS_X86_TO_ARM = "MicrosoftXTA";
const char * CCPUID_VENDORS_PARALLELS = " lrpepyh  vr";
const char * CCPUID_VENDORS_PARALLELS_ALT = "prl hyperv ";
const char * CCPUID_VENDORS_VMWARE = "VMwareVMware";
const char * CCPUID_VENDORS_XEN_HVM = "XenVMMXenVMM";
const char * CCPUID_VENDORS_ACRN = "ACRNACRNACRN";
const char * CCPUID_VENDORS_QNX = " QNXQVMBSQG ";
const char * CCPUID_VENDORS_ROSETTA_2 = "VirtualApple";

enum ccpuid_vendor ccpuid_get_vendor(void)
{
	char vendor[13] = { 0 };
	ccpuid_fetch_vendor(vendor);
	if (memcmp(vendor, CCPUID_VENDORS_AMD_K5, 12) == 0)
	{
		return CCPUID_VENDOR_AMD_K5;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_AMD, 12) == 0)
	{
		return CCPUID_VENDOR_AMD;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_WINCHIP, 12) == 0)
	{
		return CCPUID_VENDOR_WINCHIP;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_CYRIX, 12) == 0)
	{
		return CCPUID_VENDOR_CYRIX;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_INTEL, 12) == 0)
	{
		return CCPUID_VENDOR_INTEL;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_TRANSMETA, 12) == 0 || memcmp(vendor, CCPUID_VENDORS_TRANSMETA_ALT, 12) == 0)
	{
		return CCPUID_VENDOR_TRANSMETA;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_NSC, 12) == 0)
	{
		return CCPUID_VENDOR_NSC;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_NEXGEN, 12) == 0)
	{
		return CCPUID_VENDOR_NEXGEN;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_RISE, 12) == 0)
	{
		return CCPUID_VENDOR_RISE;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_SIS, 12) == 0)
	{
		return CCPUID_VENDOR_SIS;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_UMC, 12) == 0)
	{
		return CCPUID_VENDOR_UMC;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_VIA, 12) == 0)
	{
		return CCPUID_VENDOR_VIA;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_VORTEX86, 12) == 0)
	{
		return CCPUID_VENDOR_VORTEX86;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_ZHAOXIN, 12) == 0)
	{
		return CCPUID_VENDOR_ZHAOXIN;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_HYGON, 12) == 0)
	{
		return CCPUID_VENDOR_HYGON;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_RDC, 12) == 0)
	{
		return CCPUID_VENDOR_RDC;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_ELBRUS, 12) == 0)
	{
		return CCPUID_VENDOR_ELBRUS;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_AO486, 12) == 0)
	{
		return CCPUID_VENDOR_AO486;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_BHYVE, 12) == 0)
	{
		return CCPUID_VENDOR_BHYVE;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_KVM, 12) == 0)
	{
		return CCPUID_VENDOR_KVM;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_QEMU, 12) == 0)
	{
		return CCPUID_VENDOR_QEMU;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_HYPER_V, 12) == 0)
	{
		return CCPUID_VENDOR_HYPER_V;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_X86_TO_ARM, 12) == 0)
	{
		return CCPUID_VENDOR_X86_TO_ARM;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_PARALLELS, 12) == 0 || memcmp(vendor, CCPUID_VENDORS_PARALLELS_ALT, 12) == 0)
	{
		return CCPUID_VENDOR_PARALLELS;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_VMWARE, 12) == 0)
	{
		return CCPUID_VENDOR_VMWARE;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_XEN_HVM, 12) == 0)
	{
		return CCPUID_VENDOR_XEN_HVM;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_ACRN, 12) == 0)
	{
		return CCPUID_VENDOR_ACRN;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_QNX, 12) == 0)
	{
		return CCPUID_VENDOR_QNX;
	}
	else if (memcmp(vendor, CCPUID_VENDORS_ROSETTA_2, 12) == 0)
	{
		return CCPUID_VENDOR_ROSETTA_2;
	}
	return CCPUID_VENDOR_UNKNOWN;
}

const char * ccpuid_vendor_tostring(enum ccpuid_vendor vendor)
{
	switch (vendor)
	{
	case CCPUID_VENDOR_AMD_K5: return "amd-k5";
	case CCPUID_VENDOR_AMD: return "amd";
	case CCPUID_VENDOR_WINCHIP: return "winchip";
	case CCPUID_VENDOR_CYRIX: return "cyrix";
	case CCPUID_VENDOR_INTEL: return "intel";
	case CCPUID_VENDOR_TRANSMETA: return "transmeta";
	case CCPUID_VENDOR_NSC: return "national-semiconductor";
	case CCPUID_VENDOR_NEXGEN: return "nexgen";
	case CCPUID_VENDOR_RISE: return "rise";
	case CCPUID_VENDOR_SIS: return "sis";
	case CCPUID_VENDOR_UMC: return "umc";
	case CCPUID_VENDOR_VIA: return "via";
	case CCPUID_VENDOR_VORTEX86: return "vortex86";
	case CCPUID_VENDOR_ZHAOXIN: return "zhaoxin";
	case CCPUID_VENDOR_HYGON: return "hygon";
	case CCPUID_VENDOR_RDC: return "rdc";
	case CCPUID_VENDOR_ELBRUS: return "elbrus";
	case CCPUID_VENDOR_AO486: return "ao486";
	case CCPUID_VENDOR_BHYVE: return "bhyve";
	case CCPUID_VENDOR_KVM: return "kvm";
	case CCPUID_VENDOR_QEMU: return "qemu";
	case CCPUID_VENDOR_HYPER_V: return "hyper-v";
	case CCPUID_VENDOR_X86_TO_ARM: return "xta";
	case CCPUID_VENDOR_PARALLELS: return "psrallels";
	case CCPUID_VENDOR_VMWARE: return "vmware";
	case CCPUID_VENDOR_XEN_HVM: return "xen";
	case CCPUID_VENDOR_ACRN: return "acrn";
	case CCPUID_VENDOR_QNX: return "qnx";
	case CCPUID_VENDOR_ROSETTA_2: return "rosetta-2";
	default: return "unknown";
	}
}