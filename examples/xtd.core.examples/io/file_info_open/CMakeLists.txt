cmake_minimum_required(VERSION 3.3)

project(file_info_open)
find_package(xtd REQUIRED)
add_sources(src/file_info_open.cpp)
target_type(CONSOLE_APPLICATION)
