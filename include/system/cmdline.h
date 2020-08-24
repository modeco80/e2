// ====================== E2 Project =========================
//
// File: null_platform.cpp
//
// Purpose / Abstract: Command line utilities.
//
// =========================================================== 

#ifndef _E2_CMDLINE
#define _E2_CMDLINE

#include <defs.h>
#include <string>

namespace e2 {
namespace system {

	// Initalize the local argv.
	bool CmdlInitArgv(int argc, char** argv);

	// Returns index in local argv[] where the param is,
	// -1 otherwise.
	int CmdlGetParm(std::string param);

	// returns argv[paramIndex+1] if it's not null or starts with -
	std::string CmdlGetArgument(int paramIndex);

}
}


#endif