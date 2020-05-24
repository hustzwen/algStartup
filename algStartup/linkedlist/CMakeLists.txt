option(BUILD_LINKEDLIST "Build LINKEDLIST Component" ON)


if(BUILD_LINKEDLIST)
	project(linkedlist)

	file(GLOB LINKEDLIST_HEADER_FILES csrc/*.h)
	file(GLOB LINKEDLIST_SOURCE_FILES csrc/*.cpp)

	add_library(linkedlist SHARED ${LINKEDLIST_HEADER_FILES} ${LINKEDLIST_SOURCE_FILES})
	target_link_libraries(linkedlist )
	add_executable(linkedlist_test linkedlist_test.cpp)
	target_link_libraries(linkedlist_test linkedlist)
	
endif()

