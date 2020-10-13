// fast Standard C Library replacement routines.

#include <defs.h>
#include <string.h>

// macros of easy fast checks

// pointer comparision check is relatively cheap 
// (one pointer-sized integer comparision compared to several char_type sized ones)
// there is a valid reason code may pass the exact same pointer in, so it's
#define STRCMP_FAST_PTRCHECK(s1, s2) if(s1 == s2) \
										return 0; // exact match

int E2strcmp(char* s1, char* s2) {	
	STRCMP_FAST_PTRCHECK(s1, s2)

	return strcmp(s1, s2);
}

int E2strncmp(char* s1, char* s2, size_t n) {
	STRCMP_FAST_PTRCHECK(s1, s2)

	return strncmp(s1, s2, n);
}