/// @file
/// @brief Contains xtd::tracestreambuf class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <iostream>
#include "object.h"
#include "diagnostics/trace.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides an std::stringbuf for xtd::diagnostics::trace.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class tracestreambuf : public object, public std::stringbuf {
  public:
    /// @name Methods
    
    /// @{
    /// @brief Synchronizes the buffers with the associated character sequence
    int sync() override {
      #if defined(TRACE)
      if (!str().empty()) {
        if (str() == "\n") xtd::diagnostics::trace::write_line();
        else if (ustring(str()).ends_with('\n')) xtd::diagnostics::trace::write_line(ustring(str()).trim_end('\n'));
        else xtd::diagnostics::trace::write(str());
        str("");
      }
      #endif
      return 0;
    }
  };
}
