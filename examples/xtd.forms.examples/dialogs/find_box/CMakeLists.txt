cmake_minimum_required(VERSION 3.3)

project(find_box)
find_package(xtd REQUIRED)
add_sources(src/find_box.cpp)
target_type(GUI_APPLICATION)
