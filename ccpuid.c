#include <ccpuid.h>

char * ccpuid_fetch_vendor(char * vendor)
{
	ccpuid_result_t info;
	ccpuid_cpuid_1((ccpuid_result_t *) &info, 0);
	(*(int *) &vendor[0]) = info.ebx;
	(*(int *) &vendor[4]) = info.edx;
	(*(int *) &vendor[8]) = info.ecx;
	return vendor;
}
