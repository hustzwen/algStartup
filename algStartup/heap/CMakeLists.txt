option(BUILD_HEAP "Build HEAP Component" ON)


if(BUILD_HEAP)
	project(heap)
	
	add_executable(heap_test heap_test.cpp)
	target_link_libraries(heap_test )
	
endif()

