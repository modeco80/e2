#include <defs.h>
#include <vector>
#include <string>

#include <system/cmdline.h>

namespace e2 {
namespace system {

	// all default arguments
	constexpr const char* DefaultArguments[] = {
#ifdef _DEBUG
		"-dev"
#else
		"-retail"
#endif
	};

	struct TheCommandLine : public BaseCommandLine {
		DEFINE_CLASS(BaseCommandLine, public)

	bool Initalize(int argc, char** argv) {
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


	std::string GetArgument(std::string param, std::string instead) {
		for (auto it = localArgv.begin(); it != localArgv.end(); ++it) {
			if(*it == param) {
				auto index = std::distance(localArgv.begin(), it);

				if(localArgv.size() < (index +1))
					return instead;

				if(localArgv[index+1][0] == '-')
					return instead;

				return localArgv[index+1];
			}
		}

		return instead;
	}

	void PushArgument(std::string arg) {
		localArgv.push_back(arg);

	}

	private:
		
		std::string program;
		std::vector<std::string> localArgv;
	};

	static TheCommandLine commandline;

	BaseCommandLine* CommandLine() {
		return &commandline;
	}

}
}