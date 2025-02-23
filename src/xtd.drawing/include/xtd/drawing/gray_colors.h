/// @file
/// @brief Contains xtd::drawing::gray_colors factory.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include <xtd/static.h>
#include "../drawing_export.h"
#include "color.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Gray and black colors for all the hmtl gray and black colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ gray_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::gray_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ gray_colors final static_ {
    public:
      /// @name Public properties
      
      /// @{                  
      /// @brief A system-defined color object.
      /// @image html colors_black.png
      static xtd::drawing::color black();
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_gray.png
      static xtd::drawing::color dark_gray();

      /// @brief A system-defined color object.
      /// @image html colors_dark_slate_gray.png
      static xtd::drawing::color dark_slate_gray();
      
      /// @brief A system-defined color object.
      /// @image html colors_dim_gray.png
      static xtd::drawing::color dim_gray();
      
      /// @brief A system-defined color object.
      /// @image html colors_gainsboro.png
      static xtd::drawing::color gainsboro();

      /// @brief A system-defined color object.
      /// @image html colors_gray.png
      static xtd::drawing::color gray();
      
      /// @brief A system-defined color object.
      /// @image html colors_light_gray.png
      static xtd::drawing::color light_gray();

      /// @brief A system-defined color object.
      /// @image html colors_light_slate_gray.png
      static xtd::drawing::color light_slate_gray();
      
      /// @brief A system-defined color object.
      /// @image html colors_silver.png
      static xtd::drawing::color silver();

      /// @brief A system-defined color object.
      /// @image html colors_slate_gray.png
      static xtd::drawing::color slate_gray();
      /// @}

      /// @name Public methods
      
      /// @{
      /// @brief Gets an array of known colors.
      static std::vector<xtd::drawing::color> get_colors();
      /// @}
    };
  }
}
