option(BUILD_SEARCH "Build Search Component" ON)


if(BUILD_SEARCH)
	project(search)

	file(GLOB SEARCH_HEADER_FILES csrc/*.h )
	file(GLOB SEARCH_SOURCE_FILES csrc/*.cpp)

	add_library(search SHARED ${SEARCH_HEADER_FILES} ${SEARCH_SOURCE_FILES})
	target_link_libraries(search )
	add_executable(search_test search_test.cpp)
	target_link_libraries(search_test search)
	
endif()

