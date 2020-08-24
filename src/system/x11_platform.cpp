#include <defs.h>
#include <platform_iface.h>

struct X11Window : public PlatformWindow {

	void Create(int width, int height) {
		return;
	}

	void SetSize(int width, int height) {
		// TODO!!
		return;
	}

	void SetTitle(const char* title) { 
		return;
	}

	void* GetContext() {
		return nullptr;
	}

	void* GetWindow() {
		return nullptr;
	}

	// Attach event listener to this window
	void AttachEventListener(WindowEventListener* listener) {
		return;
	}

	bool RunEvents() {
		return true;
	}

private:
	WindowEventListener* listener;
	
};

struct LinuxPlatform : public Platform {

	bool Initalize() {
		return true;
	}

	PlatformWindow* CreatePlatformWindow() {
		// Only one window is expected to be made, so this is ok
		static X11Window window;
		return (PlatformWindow*)&window;
	}

	void WriteToConsole(String& printStr) {
		return;
	}
};

static LinuxPlatform platformObject;

// Platform exports this!!!!
Platform* E2GetPlatform() {
	return &platformObject;
}