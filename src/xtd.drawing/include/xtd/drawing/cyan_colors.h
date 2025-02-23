/// @file
/// @brief Contains xtd::drawing::cyan_colors factory.
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
    /// @brief Cyan colors for all the hmtl cyan colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ cyan_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::cyan_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ cyan_colors final static_ {
    public:
      /// @name Public properties
      
      /// @{                  
      /// @brief A system-defined color object.
      /// @image html colors_aqua.png
      static xtd::drawing::color aqua();
      
      /// @brief A system-defined color object.
      /// @image html colors_aquamarine.png
      static xtd::drawing::color aquamarine();

      /// @brief A system-defined color object.
      /// @image html colors_cadet_blue.png
      static xtd::drawing::color cadet_blue();
      
      /// @brief A system-defined color object.
      /// @image html colors_cyan.png
      static xtd::drawing::color cyan();

      /// @brief A system-defined color object.
      /// @image html colors_dark_cyan.png
      static xtd::drawing::color dark_cyan();
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_turquoise.png
      static xtd::drawing::color dark_turquoise();
      
      /// @brief A system-defined color object.
      /// @image html colors_light_cyan.png
      static xtd::drawing::color light_cyan();

      /// @brief A system-defined color object.
      /// @image html colors_light_sea_green.png
      static xtd::drawing::color light_sea_green();
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_turquoise.png
      static xtd::drawing::color medium_turquoise();
      
      /// @brief A system-defined color object.
      /// @image html colors_pale_turquoise.png
      static xtd::drawing::color pale_turquoise();

      /// @brief A system-defined color object.
      /// @image html colors_teal.png
      static xtd::drawing::color teal();
      
      /// @brief A system-defined color object.
      /// @image html colors_turquoise.png
      static xtd::drawing::color turquoise();
      /// @}

      /// @name Public methods
      
      /// @{
      /// @brief Gets an array of known colors.
      static std::vector<xtd::drawing::color> get_colors();
      /// @}
    };
  }
}
