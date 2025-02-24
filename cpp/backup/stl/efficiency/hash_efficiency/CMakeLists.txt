cmake_minimum_required(VERSION 3.22.0)
project(HashEfficiency VERSION 1.0)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
	${PROJECT_NAME}
	"main.cpp"
	"../utils/time_recorder.cpp"
)

