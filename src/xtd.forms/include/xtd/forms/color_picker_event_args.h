/// @file
/// @brief Contains xtd::forms::color_picker_event_args event args.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <xtd/event_args.h>
#include <xtd/drawing/color.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Provides data for the control_added and control_removed events.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class color_picker_event_args : public event_args {
    public:
      /// @cond
      color_picker_event_args(const color_picker_event_args& color_picker_event_args) = default;
      color_picker_event_args& operator =(const color_picker_event_args& color_picker_event_args) = default;
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the color_picker_event_args class for the specified control.
      /// @param color The xtd::drawing::color that represent the xtd::forms::color_picker::color.
      explicit color_picker_event_args(const xtd::drawing::color& color) : color_(color) {}
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the xtd::drawing::color that represent the xtd::forms::color_picker::color.
      /// @return The xtd::drawing::color that represent the xtd::forms::color_picker::color.
      const xtd::drawing::color& color() const {return color_;}
      //// @}
      
    private:
      xtd::drawing::color color_;
    };
  }
}
