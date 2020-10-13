// possibly not obsolete
// but maybe
#include <defs.h>

#include <system/platform.h>
#include <system/wndeventlistener.h>

#if IsWindows()
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX
	#include <windows.h>
	#undef NOMINMAX
	#undef WIN32_LEAN_AND_MEAN
#endif

namespace e2 {
namespace system {

	void WriteToConsole(std::string printStr) {
		// Add newlines so developer doesn't need to care
		printStr += '\n';

#ifdef IsWindows()
		WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), printStr.c_str(), (DWORD)printStr.length(), NULL, NULL);
#ifdef _DEBUG
		OutputDebugStringA(printStr.c_str());
#endif
#else
		printf("%s\n", printStr.c_str());
#endif
	}

	void ShowMessageBox(std::string caption, std::string Message) {
		// Windows
	}

	void Error(std::string errorMessage) {
		WriteToConsole("======================= Engine Error ============================");
		WriteToConsole(errorMessage);
		WriteToConsole("==================================================================");

		ShowMessageBox("Engine Error", errorMessage);

#ifdef IsWindows()
		ExitProcess(1);
#else
		exit(1);
#endif
	}

}
}
