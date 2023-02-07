cmake_minimum_required(VERSION 3.22)
project(search VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(binary_search
	"binary_search.cpp"
)
add_executable(advanced_binary_search
	"advanced_binary_search.cpp"
)
