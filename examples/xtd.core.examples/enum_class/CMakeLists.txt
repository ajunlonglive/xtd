cmake_minimum_required(VERSION 3.3)

project(enum_class)
find_package(xtd REQUIRED)

add_projects(
  enum_class
  enum_class_flags
  enum_class_flags_without_helpers
  enum_class_parse
  enum_class_without_helper
)

