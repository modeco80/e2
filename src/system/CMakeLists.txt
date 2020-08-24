# // ====================== E2 Project =========================
# //
# // File: CMakeLists.txt
# //
# // Purpose / Abstract: CMakeLists.txt for the E2 System Library
# //
# // =========================================================== 

include(includes)

# common sources
set(E2SYSTEM_SOURCES
	fstdc.cpp
	cmdline.cpp
)

# and then, win32/linux source
if(WIN32)
	set(E2SYSTEM_SOURCES 
		${E2SYSTEM_SOURCES}
		windows_platform.cpp
	)
endif()
		
add_library(e2_system STATIC ${E2SYSTEM_SOURCES})
set_property(TARGET e2_system PROPERTY CXX_STANDARD 17)
set_property(TARGET e2_system PROPERTY CXX_STANDARD_REQUIRED ON)
make_includes(e2_system)
