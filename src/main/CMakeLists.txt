# // ====================== E2 Project =========================
# //
# // File: CMakeLists.txt
# //
# // Purpose / Abstract: CMakeLists.txt for the E2 System Library
# //
# // =========================================================== 

include(includes)

# common sources
set(E2MAIN_SOURCES
	main.cpp
)

add_executable(e2_main WIN32 ${E2MAIN_SOURCES})
set_property(TARGET e2_main PROPERTY CXX_STANDARD 17)
set_property(TARGET e2_main PROPERTY CXX_STANDARD_REQUIRED ON)

make_includes(e2_main)
target_link_libraries(e2_main e2_system)
