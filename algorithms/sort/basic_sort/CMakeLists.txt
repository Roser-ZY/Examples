cmake_minimum_required(VERSION 3.22)
project(sort VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(sort
	SHARED
	"algorithm/quick_sort.cpp"
	"algorithm/insert_sort.cpp"
	"algorithm/shell_sort.cpp"
)

add_executable(verify_correctness
	"app/verify_correctness.cpp"
)
target_link_libraries(verify_correctness
	PRIVATE
	sort
)
