# // ====================== E2 Project =========================
# //
# // File: includes.cmake
# //
# // Purpose / Abstract: Function to give common includes to targets.
# //
# // =========================================================== 

# Usage:
# make_includes(TARGET_NAME)
function(make_includes TARGET)
	target_include_directories(${TARGET} PUBLIC ${PROJECT_SOURCE_DIR}/include)
endfunction()