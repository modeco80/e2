#ifndef _E2_CMDLINE
#define _E2_CMDLINE

#include <defs.h>
#include <string>

namespace e2 {
namespace system {

	interface BaseCommandLine {

		// Initalize the local argv.
		virtual bool Initalize(int argc, char** argv) = 0;

		//virtual bool ParmExists(std::string param, std::string instead);

		virtual std::string GetArgument(std::string param, std::string instead) = 0;

		// add an argument
		virtual void PushArgument(std::string argument) = 0;

	};

	// access command line
	// Make sure to cache this if you're going to (ab)use it
	BaseCommandLine* CommandLine();
}
}


#endif