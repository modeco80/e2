// This is a test main entry for testing the E2 System Library.
// Not really meant for usage :P

#include <defs.h>
#include <system/platform.h>
#include <system/cmdline.h>

#if IsWindows()
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	#undef CreateWindow // Microsoft at work.
#endif

e2::platform::Interface* platformInterface;

// A test window event listnere
struct TestEventListener : public e2::system::WindowEventListener {

	void OnMouseMove(int dx, int dy) {
		platformInterface->WriteToConsole("OnMouseMove()\n");
	};

	void OnKeyEvent(int key, bool bPressed) {
		platformInterface->WriteToConsole("OnKeyEvent(");

		if(bPressed)
			platformInterface->WriteToConsole("pressed)\n");
		else
			platformInterface->WriteToConsole("unpressed)\n");
	};
	
	void OnWindowResize(int width, int height) {
		platformInterface->WriteToConsole("OnWindowResize()\n");
	}

};

// Test of the superclass system

struct SuperclassTestSuper {
	int val;
};

struct SuperclassTest : public SuperclassTestSuper {
	DEFINE_SUPERCLASS(SuperclassTestSuper)
public:

	int val2;

	void Test() {
		super.val = 3;
		//super.val2;
	}
};

// Check paramater,
// bombing out if there was an argument
// TODO: MOVE INTO CMDL!!!!!!!!!!!!!!!!
std::string CheckParmArgument(std::string parm) {
	int parmIndex = e2::system::CmdlGetParm(parm);

	if (parmIndex == -1)
		return ""; // parm was never in there

	std::string arg = e2::system::CmdlGetArgument(parmIndex);

	if (arg.empty())
		platformInterface->Error("Parmameter " + parm + " requires argument, which was not given");

	return arg;

}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR CmdLine, int nCmdShow) {
	// use CRT variables to provide argc and argv,
	// so we can write portable code between WinMain() (windows specificality) 
	// and main() (everyone else, because they don't feel a need to have to be different).
	int argc = __argc;
	char** argv = __argv;
#else
int main(int argc, char** argv) {
#endif
	// Get the applicable platform interface
	platformInterface = E2GetPlatformInterface();

	// Initalize cmdl system
	if(!e2::system::CmdlInitArgv(argc, argv))
		platformInterface->Error("Failure in CmdlInitArgv()");

	std::string contentSearchPath = CheckParmArgument("-contentSearchPath");
	platformInterface->WriteToConsole("Content search path is " + contentSearchPath);


	// TODO the input system (initalized by engine) would handle this
	// and it also wouldn't be window input either

	// Stack allocate event listener,
	// it's just sizeof(char) anyways depending on padding
	TestEventListener el;


	if(!platformInterface->Initalize())
		platformInterface->Error("Could not initalize platform system");

	// Create a little window
	e2::platform::Window* window = platformInterface->CreateWindow(800, 600);
	window->SetTitle("E2 Test Main");
	window->AttachEventListener(&el);

	while(true) {
		// run events until window tells us it's time to stop
		// TODO: Engine would have quit state so that we could have
		// quit event sent from either VR or window, instead of just relying
		// on our event running code

		if(!window->RunEvents())
			break;

		// Engine would tick here
	}

	return 0;
}