option(BUILD_TREE "Build SORT Component" ON)


if(BUILD_TREE)
	project(tree)

	file(GLOB SORT_HEADER_FILES csrc/*.h )
	file(GLOB SORT_SOURCE_FILES csrc/*.cpp)

	add_library(tree SHARED ${SORT_HEADER_FILES} ${SORT_SOURCE_FILES})
	target_link_libraries(tree )
	add_executable(tree_traversal_test tree_traversal_test.cpp)
	target_link_libraries(tree_traversal_test tree)
	
endif()

