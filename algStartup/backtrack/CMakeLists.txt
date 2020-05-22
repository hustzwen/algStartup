option(BUILD_BACKTRACK "Build BACKTRACK Component" ON)


if(BUILD_BACKTRACK)
	project(backtrack)

	file(GLOB BACKTRACK_HEADER_FILES csrc/*.h)
	file(GLOB BACKTRACK_SOURCE_FILES csrc/*.cpp)

	add_library(backtrack SHARED ${BACKTRACK_HEADER_FILES} ${BACKTRACK_SOURCE_FILES})
	target_link_libraries(backtrack )
	add_executable(backtrack_test backtrack_test.cpp)
	target_link_libraries(backtrack_test backtrack)
	
endif()

