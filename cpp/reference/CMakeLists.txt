cmake_minimum_required(VERSION 3.22)
project(search VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options("-fno-elide-constructors")

add_executable(l_r_reference
	"l_r_reference.cpp"
)
add_executable(value_pass
	"value_pass.cpp"
)
