cmake_minimum_required(VERSION 3.3)

project(file_info_open_write)
find_package(xtd REQUIRED)
add_sources(src/file_info_open_write.cpp)
target_type(CONSOLE_APPLICATION)
