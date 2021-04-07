/// @file
/// @brief Contains xtd::forms::common_dialog_closed_event_handler event handler.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/event_handler.h>
#include "common_dialog_closed_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides handler for a common dialog closed event.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @param sender The source of the event.
    /// @param e An common_dialog_closed_event_args that contains event data.
    template<typename type_t>
    using common_dialog_closed_event_handler = delegate<void(type_t sender, const common_dialog_closed_event_args& e)>;
  }
}
