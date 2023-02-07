cmake_minimum_required(VERSION 3.22)
project(search VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unique_ptr
	"unique_ptr.cpp"
)
add_executable(shared_ptr
	"shared_ptr.cpp"
)
add_executable(loop_shared_ptr
	"loop_shared_ptr.cpp"
)
add_executable(solve_loop_shared_ptr
	"solve_loop_shared_ptr.cpp"
)
