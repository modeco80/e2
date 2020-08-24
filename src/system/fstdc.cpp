// fast Standard C Library replacement routines.

#include <defs.h>
#include <string.h>

// pointer comparision check is cheap (one integer comparision compared to several)
// code may pass the exact same pointer in sometimes too
#define STRCMP_FAST_PTRCHECK(s1, s2) if(s1 == s2) \
										return 0;

int E2strcmp(char* s1, char* s2) {	
	STRCMP_FAST_PTRCHECK(s1, s2)
	return strcmp(s1, s2);
}

int E2strncmp(char* s1, char* s2, size_t n) {
	STRCMP_FAST_PTRCHECK(s1, s2)
	return strncmp(s1, s2, n);
}