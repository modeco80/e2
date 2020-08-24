#include <defs.h>
#include <vector>
#include <string>

namespace e2 {
namespace system {

	
// Console paramater definition
// -conparam
// -conparam <av+1> (if av+1 == nullptr || av+1[0] == '-', then error saying that param needs an argument should be made)


	// all default arguments
	const char* DefaultArguments[] = {
		"-contentSearchPath",
		
		// add devtest/ to the game FS search path (where e2 will attempt to load the game and content from) by default
		"devtest"
	};

	// argv[0] seperated.
	std::string program;

	// local argv[] copied from main().
	std::vector<std::string> localArgv;

	bool CmdlInitArgv(int argc, char** argv) {
		if (!argv)
			return false;

		program = argv[0];

		// Initalize local argv with arguments from the program's argv[].
		for (int i = 1; i < argc; ++i)
			if (argv[i])
				localArgv.push_back(argv[i]);

		// Then add the default arguments.
		//
		// Arguments in the program argv (say `-contentSearchPath test2`)
		// will override the default arguments because they will be found first.
		// This is intentional.
		for (int i = 0; i < sizeof(DefaultArguments) / sizeof(char*); ++i)
			localArgv.push_back(DefaultArguments[i]);

		return true;
	}

	int CmdlGetParm(std::string param) {
		for (auto it = localArgv.begin(); it != localArgv.end(); ++it) {
			if(*it == param)
				return (int)std::distance(localArgv.begin(), it);
		}

		return -1;
	}

	std::string CmdlGetArgument(int paramIndex) {

		// if the index is past local argv size
		// then bomb out
		if(localArgv.size() < (paramIndex))
			return "";

		// If another parm is after then it's not an argument to this param.
		if(localArgv[paramIndex+1][0] == '-')
			return "";

		return localArgv[paramIndex+1];
	}

}
}