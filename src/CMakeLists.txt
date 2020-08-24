
# TODO move to SDL

if(${CMAKE_SIZEOF_VOID_P} MATCHES 8)
	set(BUILDARCH x64)
else()
	set(BUILDARCH x86)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_MODULE_PATH})

add_subdirectory(system)


add_subdirectory(main)