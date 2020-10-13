include(includes)

# common sources
set(E2SYSTEM_SOURCES
	fstdc.cpp
	cmdline.cpp
	platform.cpp
)
		
add_library(e2_system STATIC ${E2SYSTEM_SOURCES})
set_property(TARGET e2_system PROPERTY CXX_STANDARD 17)
set_property(TARGET e2_system PROPERTY CXX_STANDARD_REQUIRED ON)
make_includes(e2_system)
