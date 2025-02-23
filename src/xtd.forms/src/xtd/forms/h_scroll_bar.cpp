#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/scroll_bar.h>
#include <xtd/forms/native/scroll_bar_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/h_scroll_bar.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

h_scroll_bar::h_scroll_bar() {
  control_appearance(forms::control_appearance::system);
  v_scroll_ = false;
  set_can_focus(false);
}

forms::create_params h_scroll_bar::create_params() const {
  forms::create_params create_params = scroll_bar::create_params();
  
  create_params.style(create_params.style() | SBS_HORZ);
  
  return create_params;
}

xtd::drawing::size h_scroll_bar::default_size() const {
  return {80, control::default_size().height()};
}
