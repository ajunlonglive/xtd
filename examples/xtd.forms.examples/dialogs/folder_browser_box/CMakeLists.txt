cmake_minimum_required(VERSION 3.3)

project(folder_browser_box)
find_package(xtd REQUIRED)
add_sources(src/folder_browser_box.cpp)
target_type(GUI_APPLICATION)
