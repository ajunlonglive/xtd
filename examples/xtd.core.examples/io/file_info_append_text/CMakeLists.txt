cmake_minimum_required(VERSION 3.3)

project(file_info_append_text)
find_package(xtd REQUIRED)
add_sources(src/file_info_append_text.cpp)
target_type(CONSOLE_APPLICATION)
