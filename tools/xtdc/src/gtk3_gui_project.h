#pragma once
#include "base_project.h"

namespace xtdc_command {
  class gtk3_gui_project : public base_project {
  public:
    explicit gtk3_gui_project(const xtd::ustring& path) : base_project(path) {}

    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
  private:
    void create_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/program.c",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(PkgConfig)",
        "pkg_check_modules(GTK gtk+-3.0)",
        "include_directories(${GTK_INCLUDE_DIRS})",
        "link_directories(${GTK_LIBRARY_DIRS})",
        "link_libraries(${GTK_LIBRARIES})",
        "",
        "# Options",
        "set(CMAKE_C_STANDARD 11)",
        "set(CMAKE_C_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#include <gtk/gtk.h>",
        "",
        "/* The main entry point for the application. */",
        "int main(int argc, char* argv[]) {",
        "  gtk_init(&argc, &argv);",
        "  GtkWidget* window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);",
        "  gtk_window_set_title(GTK_WINDOW(window1), \"Window1\");",
        "  gtk_window_move(GTK_WINDOW(window1), 100, 100);",
        "  gtk_window_resize(GTK_WINDOW(window1), 800, 450);",
        "  g_signal_connect (window1, \"destroy\", G_CALLBACK(gtk_main_quit), NULL);",
        "  gtk_widget_show(window1);",
        "  gtk_main();",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "program.c"), lines);
    }
  };
}
