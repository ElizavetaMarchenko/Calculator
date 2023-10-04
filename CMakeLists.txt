cmake_minimum_required (VERSION 3.8)
project(Calculator_lab1)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS Calculator_lab1.h)
add_executable(Calculator_lab1 ${PROJECT_SOURCE_DIR}/ main.cpp Calculator_lab1.cpp "read_plugin.cpp" "read_plugin.h")

add_library(sin SHARED ./plugins/sin.cpp "plugins/sin.cpp" "read_plugin.cpp" "read_plugin.h")
add_library(cos SHARED ./plugins/cos.cpp "plugins/cos.cpp" "read_plugin.cpp" "read_plugin.h")
add_library(ln SHARED ./plugins/ln.cpp "plugins/ln.cpp" "read_plugin.cpp" "read_plugin.h")
add_library(sqrt SHARED ./plugins/sqrt.cpp "plugins/sqrt.cpp" "read_plugin.cpp" "read_plugin.h")

target_link_libraries(Calculator_lab1 sin cos ln sqrt)
