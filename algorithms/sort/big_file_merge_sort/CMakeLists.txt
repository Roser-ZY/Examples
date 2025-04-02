cmake_minimum_required(VERSION 3.22)
project(big_file_merge_sort VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(big_file_merge_sort
	"app/big_file_merge_sort.cpp"
)
