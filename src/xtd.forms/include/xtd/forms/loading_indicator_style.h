/// @file
/// @brief Contains xtd::forms::loading_indicator_style enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of a loading indicator control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks If the system style is used, the appearance of the control is determined by the user's operating system and the following property values will be ignored: control_background_image, image_align, image, image_index, image_list, and text_align. In addition, the control.back_color property will be ignored for button controls. If supported, users can change the appearance of controls by adjusting the appearance settings of their operating system.
    enum class loading_indicator_style {
      /// @brief The control appears with dots style.
      dots = 0,
      /// @brief The control appears with standard style.
      standard,
      /// @brief The appearance of the control is determined by the user's operating system.
      system,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::loading_indicator_style> {
  explicit operator auto() const {return xtd::enum_collection<xtd::forms::loading_indicator_style> {{xtd::forms::loading_indicator_style::dots, "dots"}, {xtd::forms::loading_indicator_style::standard, "standard"}, {xtd::forms::loading_indicator_style::system, "system"}};}
};
/// @endcond
