/// @file
/// @brief Contains xtd::forms::character_casing enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating upper, Apple macOS and Linux like Ubuntu operating upper.
  namespace forms {
    /// @brief Specifies the case of characters in a text_box control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the value of the character_casing property of the text_box control.
    enum class character_casing {
      /// @brief The case of characters is left unchanged.
      normal = 0,
      /// @brief Converts all characters to uppercase.
      upper = 1,
      /// @brief Converts all characters to lowercase.
      lower = 2,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::character_casing> {
  explicit operator auto() const {return xtd::enum_collection<xtd::forms::character_casing> {{xtd::forms::character_casing::normal, "normal"}, {xtd::forms::character_casing::upper, "upper"}, {xtd::forms::character_casing::lower, "lower"}};}
};
/// @endcond
