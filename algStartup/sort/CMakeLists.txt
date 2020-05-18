option(BUILD_SORT "Build SORT Component" ON)


if(BUILD_SORT)
	project(sort)

	file(GLOB SORT_HEADER_FILES csrc/*.h )
	file(GLOB SORT_SOURCE_FILES csrc/*.cpp)

	add_library(sort SHARED ${SORT_HEADER_FILES} ${SORT_SOURCE_FILES})
	target_link_libraries(sort )
	add_executable(sort_test sort_test.cpp)
	target_link_libraries(sort_test sort)
	
endif()

