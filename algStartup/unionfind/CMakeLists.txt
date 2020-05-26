option(BUILD_UNION_FIND "Build UNIONFIND Component" ON)


if(BUILD_UNION_FIND)
	project(unionfind)
	
	add_executable(union_find_test union_find_test.cpp)
	target_link_libraries(union_find_test )
	
endif()

