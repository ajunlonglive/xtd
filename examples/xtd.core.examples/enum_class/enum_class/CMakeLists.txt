cmake_minimum_required(VERSION 3.3)

project(enum_class)
find_package(xtd REQUIRED)
add_sources(src/enum_class.cpp)
target_type(CONSOLE_APPLICATION)
