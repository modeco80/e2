include(includes)

# common sources
set(E2MAIN_SOURCES
	main.cpp
)

add_executable(e2project WIN32 ${E2MAIN_SOURCES})
set_property(TARGET e2project PROPERTY CXX_STANDARD 17)
set_property(TARGET e2project PROPERTY CXX_STANDARD_REQUIRED ON)

make_includes(e2project)
target_link_libraries(e2project e2_system)
