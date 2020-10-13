#include <defs.h>
//#include <platform.h>
#include <cmdline.h>

#if IsWindows()
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX
	#include <windows.h>
	#undef NOMINMAX
	#undef WIN32_LEAN_AND_MEAN
#endif

int main(int argc, char** argv) {
	auto cmdLine = e2::system::CommandLine();

	if(!cmdLine->Initalize(argc, argv))
		e2::system::Error("CommandLine()->Initalize() returned false");

	std::string searchPath = cmdLine->GetArgument("-contentSearchPath", "devtest");

	e2::system::WriteToConsole("This is a test 1");

	while(true) {
	}

	return 0;
}