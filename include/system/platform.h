#pragma once
#include <defs.h>
#include <system/wndeventlistener.h>
#include <string>

namespace e2 {
namespace platform {

	// Base class for Platform API Windows.
	abstract_struct Window {

		// *Actually* create the window.
		virtual void Create(int width, int height) = 0;

		// Set width and height of window ahead of time
		virtual void SetSize(int width, int height) = 0;
	
		// Set the title of this window.
		virtual void SetTitle(const std::string& title) = 0;

		// Get a handle to the window.
		// On Windows this gets the HWND.
		virtual void* GetWindow() = 0;

		// Get drawing context.
		// On Windows this gets the HDC.
		virtual void* GetContext() = 0;

		// Attach a WindowEventListener to this window.
		virtual void AttachEventListener(e2::system::WindowEventListener* listener) = 0;

		// Run window events.
		// Returns false on a quit event.
		virtual bool RunEvents() = 0;
	};

	// Platform API interface.
	abstract_struct Interface {

		// Initalize the platform subsystem.
		//
		// Returns true on platform initalization success,
		// false upon any errors.
		//
		// An error initalizing the platform subsystem should be treated as fatal.
		virtual bool Initalize() = 0;

		// Creates an window object.
		virtual Window* CreateWindow(int width, int height) = 0;

		// Write to the native console.
		// This is mostly provided to give a platform-independent
		// way to write to the console.
		virtual void WriteToConsole(std::string printStr) = 0;

		// Show a message box to the user.
		virtual void ShowMessageBox(std::string caption, std::string Message) = 0;

		// Print a message, show a message box with the message,
		// and then exit with a failure code.
		virtual void Error(std::string errorMessage) = 0;
	};

}
}

// Returns platform object.
// This should (and *WILL*) never return null (Even for the null platform).
// If it does, run for the hills.
e2::platform::Interface* E2GetPlatformInterface();