#ifndef _E2_DEFS_H
#define _E2_DEFS_H

#include <stdint.h>

// These don't do anything - they're just hints to potentional code users
// that they're interfaces which are completely abstract.

#define interface struct

#define abstract_class interface
#define abstract_struct interface


#include <class.h>

// Platform detection

#ifdef _WIN32
	#define E2_WINDOWS
	
	// win64
	#ifdef _WIN64
		#define E2_WINDOWS64
	#endif
#endif

#ifdef __linux__
	#define E2_LINUX
	#ifdef __x86_64__
		#define E2_LINUX64
	#endif
#endif

// Compiler detection

// This one's easy.
#ifdef _MSC_VER
	#define E2_MSVC
#endif

// Clang masqurades as a version of GCC so we check for that
// and don't define E2_GCC if it is.
#if defined(__GNUC__) && !defined(__clang__)
	#define E2_GCC
#endif

// .. but, if __clang__ *is* defined,
// then it most likely is in fact clang.
#ifdef __clang__
	#define E2_CLANG
#endif

// Some "function" macros that resolve to bool constants.


#ifdef E2_WINDOWS
	#define IsWindows() 1
#else
	#define IsWindows() 0
#endif

#ifdef E2_WINDOWS64
	#define IsWindows64() 1
#else
	#define IsWindows64() 0
#endif

#ifdef E2_LINUX
	#define IsLinux() 1
#else
	#define IsLinux() 0
#endif

#ifdef E2_LINUX64
	#define IsLinux64() 1
#else
	#define IsLinux64() 0
#endif

// Now, the same thing, except it's for compiler detection!

#ifdef E2_MSVC
	#define IsMSVC() 1
#else
	#define IsMSVC() 0
#endif

#ifdef E2_GCC
	#define IsGCC() 1
#else
	#define IsGCC() 0
#endif

#ifdef E2_CLANG
	#define IsClang() 1
#else
	#define IsClang() 0
#endif

#endif