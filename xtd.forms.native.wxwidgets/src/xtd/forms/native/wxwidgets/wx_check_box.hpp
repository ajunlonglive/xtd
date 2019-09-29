#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <wx/checkbox.h>
#include <wx/tglbtn.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_check_box : public control_handler {
      public:
        wx_check_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          if ((create_params.style() & BS_PUSHLIKE) == BS_PUSHLIKE)
            this->control_handler::create<wxToggleButton>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), 0);
          else
            this->control_handler::create<wxCheckBox>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), check_box_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long check_box_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxCHK_3STATE;
          
          if ((style & BS_AUTO3STATE) == BS_AUTO3STATE) wx_style |= wxCHK_ALLOW_3RD_STATE_FOR_USER;
          else if ((style & BS_3STATE) == BS_3STATE) wx_style |= wxCHK_ALLOW_3RD_STATE_FOR_USER;

          if ((style & BS_RIGHTBUTTON) == BS_RIGHTBUTTON) wx_style |= wxALIGN_RIGHT;

          return wx_style | common_window_style_to_wx_style(style, ex_style);
        }
      };
    }
  }
}
