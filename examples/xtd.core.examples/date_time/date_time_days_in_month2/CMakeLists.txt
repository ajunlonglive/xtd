cmake_minimum_required(VERSION 3.3)

project(date_time_days_in_month2)
find_package(xtd REQUIRED)
add_sources(src/date_time_days_in_month2.cpp)
target_type(CONSOLE_APPLICATION)
