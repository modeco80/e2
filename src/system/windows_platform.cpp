#include <defs.h>

#if !IsWindows()
#error How is this source file being compiled?
#endif

#include <system/platform.h>
#include <system/wndeventlistener.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef CreateWindow // mucks up Platform

// stolen from winuser.h, apparently doesn't exist? idk
#define GWL_USERDATA (-21)


#define E2WINDOWCLASS "@E2Game"


LRESULT CALLBACK E2WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

struct WindowsWindow : public e2::platform::Window {

	void Create(int width, int height) {
		window = CreateWindowExA(0, E2WINDOWCLASS, "", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, nullptr, NULL);

		// Weird casting is just to try and tell the compiler that I mean
		// that I want it to stuff the pointer into a LONG
		if(window)
			SetWindowLongA(window, GWL_USERDATA, (ptrdiff_t)(WindowsWindow*)this);

	}

	void SetSize(int width, int height) {
		// TODO!!
	}

	void SetTitle(const std::string& title) {
		windowTitle = title;
		SetWindowTextA(window, windowTitle.c_str());
	}

	void* GetContext() {
		return (void*)drawingContext;
	}

	void* GetWindow() {
		return (void*)window;
	}

	// Attach a event listener to the window
	void AttachEventListener(e2::system::WindowEventListener* listener) {
		if(listener)
			eventListener = listener;
	}


	bool RunEvents() {
		MSG msg;

		// Attempt to dispatch a single message to the window.
		// This *may* cause some slowdown if engine is taking too long.
		if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT)
				return false;
			DispatchMessageA(&msg);
		}

		return true;
	}

	HWND window;
	HDC drawingContext;

	e2::system::WindowEventListener* eventListener;
	std::string windowTitle;

	// Stored window width/height
	int width;
	int height;
};


struct WindowsPlatform : public e2::platform::Interface {

	bool Initalize() {
		WNDCLASSEXA WindowClass;
		WindowClass.cbSize = sizeof(WNDCLASSEXA);
		WindowClass.style = CS_OWNDC;
		WindowClass.lpfnWndProc = E2WndProc;
		WindowClass.cbClsExtra = 0;
		WindowClass.cbWndExtra = 0;
		WindowClass.hInstance = nullptr;
		WindowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		WindowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		WindowClass.lpszMenuName = NULL;
		WindowClass.lpszClassName = E2WINDOWCLASS;
		WindowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		if(!RegisterClassExA(&WindowClass))
			return false;

		WriteToConsole("Initalized E2 Platform subsystem <3");
		return true;
	}

	e2::platform::Window* CreateWindow(int width, int height) {
		// Only one window is expected to be made, so this is ok
		static WindowsWindow window;
		window.Create(width, height);
		WriteToConsole("CreateWindow() Created window!");
		return (e2::platform::Window*)&window;
	}

	void WriteToConsole(std::string printStr) {
		// Add newlines so developer doesn't need to care
		printStr += '\n';
		WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), printStr.c_str(), (DWORD)printStr.length(), NULL, NULL);
#ifdef _DEBUG
		OutputDebugStringA(printStr.c_str());
#endif
	}

	void ShowMessageBox(std::string caption, std::string Message) {
		MessageBoxA(NULL, Message.c_str(), caption.c_str(), MB_OK);
	}

	void Error(std::string errorMessage) {
		WriteToConsole("======================= Platform Error!!! ========================");
		WriteToConsole(errorMessage);
		WriteToConsole("==================================================================");

		ShowMessageBox("Error!", errorMessage);
		ExitProcess(1);
	}
};

LRESULT CALLBACK E2WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	// Get Platform API window object
	WindowsWindow* window = (WindowsWindow*)(ptrdiff_t)GetWindowLong(hWnd, GWL_USERDATA);

	switch (msg) {
		case WM_CLOSE:
			DestroyWindow(hWnd);
		break;

		case WM_DESTROY:
			PostQuitMessage(0);
		break;


		case WM_MOUSEMOVE:

			break;

		case WM_KEYUP:
		case WM_KEYDOWN:
			if(window && window->eventListener)
					window->eventListener->OnKeyEvent((int)wParam, (msg == WM_KEYDOWN) ? true : false);
			break;

		case WM_SIZE:
			if(window) {
				// set the width and height here 
				// by the time this message is sent the OS has adjusted everything
				window->width = LOWORD(lParam);
				window->height = HIWORD(lParam);
			}

			if(window && window->eventListener)
					window->eventListener->OnWindowResize(LOWORD(lParam), HIWORD(lParam));
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

static WindowsPlatform platformObject;

e2::platform::Interface* E2GetPlatformInterface() {
	// This is kind of cheating,
	// but whatever. Cross platform output before we actually initalize it,
	// whatever.
	platformObject.WriteToConsole("E2GetPlatformInterface");
	return &platformObject;
}