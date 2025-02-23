cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.tunit)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
add_references(xtd.core)
add_sources(
  include/xtd/tunit/__console_color.h
  include/xtd/tunit/__demangle.h
  include/xtd/tunit/__google_test_markers.h
  include/xtd/tunit/__tunit_join__items.h
  include/xtd/tunit/abort_error.h
  include/xtd/tunit/assert.h
  include/xtd/tunit/assert_error.h
  include/xtd/tunit/assume.h
  include/xtd/tunit/base_assert.h
  include/xtd/tunit/class_cleanup_attribute.h
  include/xtd/tunit/class_event_args.h
  include/xtd/tunit/class_initialize_attribute.h
  include/xtd/tunit/collection_assert.h
  include/xtd/tunit/collection_assume.h
  include/xtd/tunit/collection_valid.h
  include/xtd/tunit/console_unit_test.h
  include/xtd/tunit/default_insert_basic_ostream_operator.h
  include/xtd/tunit/default_main.h
  include/xtd/tunit/directory_assert.h
  include/xtd/tunit/directory_assume.h
  include/xtd/tunit/directory_valid.h
  include/xtd/tunit/event_listener.h
  include/xtd/tunit/file_assert.h
  include/xtd/tunit/file_assume.h
  include/xtd/tunit/file_valid.h
  include/xtd/tunit/ignore_error.h
  include/xtd/tunit/ostream_event_listener.h
  include/xtd/tunit/ostream_unit_test.h
  include/xtd/tunit/settings.h
  include/xtd/tunit/string_assert.h
  include/xtd/tunit/string_assume.h
  include/xtd/tunit/string_valid.h
  include/xtd/tunit/test.h
  include/xtd/tunit/registered_test_class.h
  include/xtd/tunit/test_cleanup_attribute.h
  include/xtd/tunit/test_event_args.h
  include/xtd/tunit/test_initialize_attribute.h
  include/xtd/tunit/test_method_attribute.h
  include/xtd/tunit/test_class.h
  include/xtd/tunit/test_class_attribute.h
  include/xtd/tunit/test_state.h
  include/xtd/tunit/tunit_event_args.h
  include/xtd/tunit/tunit_main.h
  include/xtd/tunit/unit_test.h
  include/xtd/tunit/valid.h
  include/xtd/xtd.tunit
  include/xtd/xtd.tunit.h
  src/xtd/tunit/__console_color_gcc.cpp
  src/xtd/tunit/__console_color_win32.cpp
  src/xtd/tunit/__demangle_gcc.cpp
  src/xtd/tunit/__demangle_win32.cpp
  src/xtd/tunit/base_assert.cpp
  src/xtd/tunit/settings.cpp
  src/xtd/tunit/tunit_main.cpp
  src/xtd/tunit/test.cpp
  src/xtd/tunit/test_class.cpp
  src/xtd/tunit/unit_test.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
