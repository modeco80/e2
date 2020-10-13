#pragma once
#include <defs.h>
#include <string>

namespace e2 {
namespace system {
	
	void WriteToConsole(std::string printStr);

	// Show a message box to the user.
	void ShowMessageBox(std::string caption, std::string Message);

	// Print a message, show a message box with the message,
	// and then exit with a failure code.
	void Error(std::string errorMessage);

}
}
