/// @file
/// @brief Contains xtd::drawing::purple_colors factory.
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
    /// @brief Purple, violet and magenta colors for all the hmtl purple, violet and magenta colors. This class cannot be inherited.
    /// @code
    /// class drawing_export_ purple_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::purple_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ purple_colors final static_ {
    public:
      /// @name Public properties
      
      /// @{
      /// @brief A system-defined color object.
      /// @image html colors_blue_violet.png
      static xtd::drawing::color blue_violet();
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_magenta.png
      static xtd::drawing::color dark_magenta();
      
      /// @brief A system-defined color object.
      /// @image html colors_dark_orchid.png
      static xtd::drawing::color dark_orchid();

      /// @brief A system-defined color object.
      /// @image html colors_dark_slate_blue.png
      static xtd::drawing::color dark_slate_blue();

      /// @brief A system-defined color object.
      /// @image html colors_dark_violet.png
      static xtd::drawing::color dark_violet();
      
      /// @brief A system-defined color object.
      /// @image html colors_fuchsia.png
      static xtd::drawing::color fuchsia();

      /// @brief A system-defined color object.
      /// @image html colors_indigo.png
      static xtd::drawing::color indigo();
      
      /// @brief A system-defined color object.
      /// @image html colors_lavender.png
      static xtd::drawing::color lavender();

      /// @brief A system-defined color object.
      /// @image html colors_magenta.png
      static xtd::drawing::color magenta();
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_orchid.png
      static xtd::drawing::color medium_orchid();
      
      /// @brief A system-defined color object.
      /// @image html colors_medium_purple.png
      static xtd::drawing::color medium_purple();

      /// @brief A system-defined color object.
      /// @image html colors_medium_slate_blue.png
      static xtd::drawing::color medium_slate_blue();
      
      /// @brief A system-defined color object.
      /// @image html colors_orchid.png
      static xtd::drawing::color orchid();
      
      /// @brief A system-defined color object.
      /// @image html colors_plum.png
      static xtd::drawing::color plum();

      /// @brief A system-defined color object.
      /// @image html colors_purple.png
      static xtd::drawing::color purple();

      /// @brief A system-defined color object.
      /// @image html colors_rebecca_purple.png
      static xtd::drawing::color rebecca_purple();

      /// @brief A system-defined color object.
      /// @image html colors_slate_blue.png
      static xtd::drawing::color slate_blue();
      
      /// @brief A system-defined color object.
      /// @image html colors_thistle.png
      static xtd::drawing::color thistle();

      /// @brief A system-defined color object.
      /// @image html colors_violet.png
      static xtd::drawing::color violet();
      /// @}

      /// @name Public methods
      
      /// @{
      /// @brief Gets an array of known colors.
      static std::vector<xtd::drawing::color> get_colors();
      /// @}
    };
  }
}
