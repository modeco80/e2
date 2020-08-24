#pragma once
#include <defs.h>

namespace e2 {
namespace system {
	
	// Window event listener struct.
	abstract_struct WindowEventListener {

		virtual void OnMouseMove(int dx, int dy) = 0;

		virtual void OnKeyEvent(int key, bool wasPressed) = 0;

		// TODO: 

		virtual void OnWindowResize(int width, int height) = 0;
	};
	
}
}