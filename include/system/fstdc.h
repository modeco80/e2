#pragma once
#include <stdlib.h>

// Make code that uses standard C functions error out, with an explainable reason (USE_E2STRCMP)
#define strcmp _USE_E2strcmp
#define strncmp _USE_E2strncmp

// Function defintions

int E2strcmp(char* s1, char* s2);
int E2strncmp(char* s1, char* s2, size_t n);
