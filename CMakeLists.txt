cmake_minimum_required (VERSION 3.8)
project(Calculator_lab1)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS Calculator_lab1.h)
add_executable(Calculator_lab1 ${PROJECT_SOURCE_DIR}/ main.cpp Calculator_lab1.cpp "read_plugin.cpp" "read_plugin.h")


