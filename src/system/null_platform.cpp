// This source file is not compiled into the system library,
// rather it is provided as an example of how to port system library to your stuff
// it is obsolete

#include <defs.h>

#include <system/platform.h>
#include <system/wndeventlistener.h>

struct NullWindow : public e2::platform::Window {

	void Create(int width, int height) {
	}

	void SetSize(int width, int height) {
		// TODO!!
	}

	void SetTitle(const char* title) { 
	}

	void* GetContext() {
		return nullptr;
	}

	void* GetWindow() {
		return nullptr;
	}

	// Attach a event listener to the window
	void AttachEventListener(e2::system::WindowEventListener* listener) {
		if(listener)
			eventListener = listener;
	}


	bool RunEvents() {
		return true;
	}


	e2::system::WindowEventListener* eventListener;
	
};


struct NullPlatform : public e2::platform::Interface {

	bool Initalize() {
		return true;
	}

	e2::platform::Window* CreateWindow() {
		// Only one window is expected to be made, so this is ok
		static NullWindow window;
		return (e2::platform::Window*)&window;
	}

	void WriteToConsole(std::string printStr) {
	}
};


static NullPlatform platformObject;

e2::platform::Interface* E2GetPlatformInterface() {
	return &platformObject;
}