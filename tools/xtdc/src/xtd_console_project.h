#pragma once
#include "base_project.h"

namespace xtdc_command {
  class xtd_console_project : public base_project {
  public:
    explicit xtd_console_project(const xtd::ustring& path) : base_project(path) {}

    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "properties") : xtd::io::path::combine(current_path(), "properties"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_cmakelists_txt(name);
      create_xtd_console_application_properties(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_xtd_console_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_xtd_console_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_xtd_console_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
  private:
    void create_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::ustring::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_xtd_console_application_properties(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines{
        xtd::ustring::format("target_default_namespace(\"{}\")", name),
        xtd::ustring::format("target_name(\"{}\")", name),
        xtd::ustring::format("target_startup(\"{}::program\" src/program.h)", name),
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "target_properties.cmake"), lines);
    }
    
    void create_xtd_console_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Project",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        "  src/program.h",
        "  src/program.cpp",
        ")",
        "target_type(CONSOLE_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_xtd_console_include(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains program class.",
        "#pragma once",
        "#include <xtd/ustring.h>",
        "#include <vector>",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the main class.",
        "  class program {",
        "  public:",
        "    /// @brief The main entry point for the application.",
        "    static void main(const std::vector<xtd::ustring>& args);",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "program.h"), lines);
    }
    
    void create_xtd_console_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"program.h\"",
        "#include <xtd/console.h>",
        "",
        "using namespace std;",
        "using namespace xtd;",
        xtd::ustring::format("using namespace {};", name),
        "",
        "void program::main(const vector<ustring>& args) {",
        "  console::write_line(\"Hello, World!\");",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "program.cpp"), lines);
    }
  };
}
