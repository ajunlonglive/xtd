#include "../../../include/xtd/forms/button_renderer.h"
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/style_sheets/button_selector.h"
#include "../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include <map>
#include <xtd/environment.h>
#include <xtd/invalid_operation_exception.h>
#include <xtd/drawing/pen.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;
using namespace xtd::forms::style_sheets;

class control_styles {
public:
  using button_selectors_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::button_selector>;
  
  static const button_selectors_t& button_selectors() {
    static button_selectors_t datas = {
      // :standard
      {xtd::forms::style_sheets::pseudo_state::standard, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), image_value(image_type::linear_gradient, {system_colors::button_face(), system_colors::button_face()}, 180), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(78, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), system_colors::button_face(), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(35, 255, 255, 255), std::nullopt, std::nullopt, system_colors::gray_text(), content_alignment::middle_center, system_fonts::default_font()}},
      // :standard:default
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), image_value(image_type::linear_gradient, {color::from_argb(0xFF177AE5), color::from_argb(0xFF166ECD)}, 180), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), image_value(image_type::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), image_value(image_type::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), image_value(image_type::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), image_value(image_type::linear_gradient, {color::from_argb(0xFF177AE5), color::from_argb(0xFF166ECD)}, 180), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_selector {padding(0, 1, 0, 1), style_sheets::border_style(border_type::outset), border_color(system_colors::control_dark()), border_width(1), border_radius(5), padding(1, 1, 1, 3), image_value(image_type::linear_gradient, {color::from_argb(35, 255, 255, 255), color::from_argb(35, 255, 255, 255)}, 180), std::nullopt, std::nullopt, system_colors::gray_text(), content_alignment::middle_center, system_fonts::default_font()}},
      // :flat
      {xtd::forms::style_sheets::pseudo_state::flat, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), system_colors::control(), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(78, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(30, 255, 255, 255), std::nullopt, std::nullopt, system_colors::gray_text(), content_alignment::middle_center, system_fonts::default_font()}},
      // :flat:default
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), system_colors::control(), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(78, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::flat | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(30, 255, 255, 255), std::nullopt, std::nullopt, system_colors::gray_text(), content_alignment::middle_center, system_fonts::default_font()}},
      // :popup
      {xtd::forms::style_sheets::pseudo_state::popup, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), system_colors::control(), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::inset), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::inset), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::inset), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(78, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::outset), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(30, 255, 255, 255), std::nullopt, std::nullopt, system_colors::gray_text(), content_alignment::middle_center, system_fonts::default_font()}},
      // :popup:default
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), system_colors::control(), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::inset), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::inset), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::inset), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(78, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hover, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::outset), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(93, 255, 255, 255), std::nullopt, std::nullopt, system_colors::control_text(), content_alignment::middle_center, system_fonts::default_font()}},
      {xtd::forms::style_sheets::pseudo_state::popup | xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_selector {padding(0), style_sheets::border_style(border_type::solid), border_color(system_colors::control_text()), border_width(1), border_radius(5), padding(1, 1, 1, 3), color::from_argb(30, 255, 255, 255), std::nullopt, std::nullopt, system_colors::gray_text(), content_alignment::middle_center, system_fonts::default_font()}},
    };
    return datas;
  }
};

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds) {
  draw_button(graphics, bounds, flat_style::standard, push_button_state::normal, false, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style) {
  draw_button(graphics, bounds, button_style, push_button_state::normal, false, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, bool default_button) {
  draw_button(graphics, bounds, button_style, button_state, default_button, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, bool default_button, const optional<color>& back_color) {
  draw_button(graphics, bounds, button_style, button_state, default_button, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, bool default_button, const optional<color>& back_color, const ustring& text, const optional<text_format_flags>& text_flags, const optional<color>& fore_color, const optional<font>& font) {
  auto pseudo_state_base = pseudo_state::standard;
  if (button_style == flat_style::flat) pseudo_state_base = pseudo_state::flat;
  if (button_style == flat_style::popup) pseudo_state_base = pseudo_state::popup;
  if (default_button) pseudo_state_base += pseudo_state::default_state;
  
  auto button_selector_iterator = control_styles::button_selectors().end();
  switch (button_state) {
    case push_button_state::normal: button_selector_iterator = control_styles::button_selectors().find(pseudo_state_base); break;
    case push_button_state::hot: button_selector_iterator = control_styles::button_selectors().find(pseudo_state_base | pseudo_state::hover); break;
    case push_button_state::pressed: button_selector_iterator = control_styles::button_selectors().find(pseudo_state_base | pseudo_state::pressed); break;
    case push_button_state::checked: button_selector_iterator = control_styles::button_selectors().find(pseudo_state_base | pseudo_state::checked); break;
    case push_button_state::disabled: button_selector_iterator = control_styles::button_selectors().find(pseudo_state_base | pseudo_state::disabled); break;
    case push_button_state::default_state: button_selector_iterator = control_styles::button_selectors().find(pseudo_state_base | pseudo_state::default_state); break;
  }
  if (button_selector_iterator == control_styles::button_selectors().end()) throw invalid_operation_exception(csf_);
  
  auto current_button_selector = button_selector_iterator->second;
  if ((button_state == push_button_state::normal || button_state == push_button_state::default_state) && back_color.has_value()) current_button_selector.box().background_color(back_color.value());
  if (fore_color.has_value()) current_button_selector.text().color(fore_color.value());
  if (font.has_value()) current_button_selector.text().font(font.value());
  
  box_renderer::draw_box(graphics, bounds, current_button_selector.box());
  text_renderer::draw_text(graphics, current_button_selector.box().get_content_rectangle(bounds), text, current_button_selector.text());
}


namespace {
  xtd::ustring get_hotkey_prefix_locations(const xtd::ustring& str, std::vector<size_t>& locations) {
    auto offset = 0U;
    for (auto index = 0U; index < str.size(); index++) {
      if (str[index] == '&' && str[index + 1] != '&')
        locations.push_back(index + offset);
      else if (str[index] == '&' && str[index + 1] == '&') {
        offset -= 2;
        ++index;
      }
    }
    auto new_str = str.replace("&&", "&");
    for (auto index = 0U; index < locations.size(); ++index)
      new_str = new_str.remove(locations[index], 1);
    return new_str;
  }
  
  void draw_string(graphics g, const ustring& text, const font& font, const color& text_color, const rectangle_f& button_rect, text_format_flags flags) {
    vector<size_t> hotkey_prefix_locations;
    ustring text_without_hotkey_prefix = get_hotkey_prefix_locations(text, hotkey_prefix_locations);
    if ((flags & text_format_flags::prefix_only) == text_format_flags::prefix_only && hotkey_prefix_locations.size()) g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[0], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, control_paint::string_format(flags));
    else g.draw_string(text, font, solid_brush(text_color), button_rect, control_paint::string_format(flags));
  }
}

void button_renderer::draw_button(const ustring& theme, graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (theme == "gnome") draw_button_gnome(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome (dark)") draw_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "gnome (light)") draw_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde") draw_button_kde(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde (dark)") draw_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "kde (light)") draw_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos") draw_button_macos(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos (dark)") draw_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "macos (light)") draw_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic") draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic (dark)") draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "symbolic (light)") draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows") draw_button_windows(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows (dark)") draw_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "windows (light)") draw_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd") draw_button_xtd(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd (dark)") draw_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else if (theme == "xtd (light)") draw_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else draw_button_symbolic(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_gnome(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_gnome_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_gnome_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_gnome_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = theme_colors::current_theme().control_dark();
  auto button_color = control_paint::dark(background_color, 0.1);
  auto text_color = foreground_color;
  
  if (state == visual_styles::push_button_state::hot)
    button_color = control_paint::light(button_color, 0.02);
  else if (state == visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked)
    button_color = theme_colors::current_theme().control_dark();
  else if (state == visual_styles::push_button_state::disabled)
    text_color = theme_colors::current_theme().gray_text();
  else if (state == visual_styles::push_button_state::default_state)
    border_color = control_paint::dark(theme_colors::current_theme().accent(), 2.0 / 3);
    
  if (state == visual_styles::push_button_state::pressed)
    g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  else
    g.fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, 0.05), button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_gnome_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = theme_colors::current_theme().control_dark();
  auto button_color = control_paint::light(background_color, 0.05);
  auto text_color = foreground_color;
  
  if (state == visual_styles::push_button_state::hot)
    button_color = control_paint::light(button_color, 0.5);
  else if (state == visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked)
    button_color = theme_colors::current_theme().control_dark();
  else if (state == visual_styles::push_button_state::disabled)
    text_color = theme_colors::current_theme().gray_text();
  else if (state == visual_styles::push_button_state::default_state)
    border_color = control_paint::dark(theme_colors::current_theme().accent(), 2.0 / 3);
    
  if (state == visual_styles::push_button_state::pressed)
    g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  else
    g.fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, 0.25), button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_kde(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_kde_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_kde_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_kde_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().control_dark();
  auto button_color = background_color;
  auto text_color = foreground_color;
  int32_t offset = 0;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot)
    border_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    offset += 1;
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled)
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  }
  
  if (focused) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  }
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x() + offset, bounds.y() + offset, bounds.width() - 1, bounds.height() - 1, 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x() + offset, bounds.y() + offset, bounds.width() - 2, bounds.height() - 2, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + offset + 5, bounds.y() + offset + 3, bounds.width() - 11, bounds.height() - 8);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_kde_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().control_dark();
  auto button_color = background_color;
  auto text_color = foreground_color;
  int32_t offset = 0;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot)
    border_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    offset += 1;
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled)
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  }
  
  if (focused) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  }
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x() + offset, bounds.y() + offset, bounds.width() - 1, bounds.height() - 1, 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x() + offset, bounds.y() + offset, bounds.width() - 2, bounds.height() - 2, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + offset + 5, bounds.y() + offset + 3, bounds.width() - 11, bounds.height() - 8);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_macos(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_macos_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_macos_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_macos_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto border_color = xtd::drawing::color::from_argb(35, 0, 0, 0);
  auto button_color = xtd::forms::theme_colors::current_theme().button_face();
  auto text_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();;
  
  if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked)
    button_color = color::from_argb(93, xtd::forms::theme_colors::current_theme().button_face());
  else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    button_color = color::from_argb(30, xtd::forms::theme_colors::current_theme().button_face());
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state)
    button_color = control_paint::dark(xtd::forms::theme_colors::current_theme().accent(), 0.15);
    
  auto button_rect = bounds;
  if (bounds.height() > 25) {
    button_rect.offset({1, 0});
    button_rect.inflate({-2, -1});
  }
  
  g.fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {button_rect.x(), button_rect.top()}, point {button_rect.x(), button_rect.bottom()}, button_color, button_color), button_rect.x(), button_rect.y() + 2, button_rect.width() - 1, button_rect.height() - 4, 5);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rect.x(), button_rect.y() + 2, button_rect.width() - 1, button_rect.height() - 4, 5);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(button_rect.x() + 5, button_rect.y() + 3, button_rect.width() - 10, button_rect.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_macos_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : color::transparent;
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = color::from_argb(200, 200, 200);
  auto button_color = color::from_argb(128, xtd::forms::theme_colors::current_theme().button_face());
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    //if (bounds.height() <= 25) {
    //  button_color = xtd::forms::theme_colors::current_theme().accent();
    //  text_color = xtd::forms::theme_colors::current_theme().accent_text();
    //} else
    button_color = color::from_argb(240, 240, 240);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    button_color = back_color.has_value() ? color::from_argb(210, 255, 255, 255) : control_paint::dark(button_color, 0.04);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    if (bounds.height() <= 25) {
      button_color = control_paint::light(xtd::forms::theme_colors::current_theme().accent(), 0.15);
      if (!fore_color.has_value()) text_color = xtd::forms::theme_colors::current_theme().accent_text();
    }
  }
  
  auto button_rect = bounds;
  if (bounds.height() > 25) {
    button_rect.offset({1, 0});
    button_rect.inflate({-2, -1});
  }
  
  if (background_color != color::transparent) g.fill_rounded_rectangle(solid_brush(background_color), button_rect.x(), button_rect.y() + 2, button_rect.width(), button_rect.height() - 4, 5);
  g.fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {button_rect.x(), button_rect.top()}, point {button_rect.x(), button_rect.bottom()}, button_color, control_paint::dark(button_color, .03)), button_rect.x(), button_rect.y() + 2, button_rect.width() - 1, button_rect.height() - 4, 5);
  g.draw_rounded_rectangle(pen(border_color, 1), button_rect.x(), button_rect.y() + 2, button_rect.width() - 1, button_rect.height() - 4, 5);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(button_rect.x() + 5, button_rect.y() + 3, button_rect.width() - 10, button_rect.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_symbolic(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_symbolic_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto button_color = control_paint::light(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = control_paint::light(xtd::forms::theme_colors::current_theme().active_border(), 2.0 / 3);
    button_color = control_paint::light(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state)
    border_color = control_paint::dark(xtd::forms::theme_colors::current_theme().accent(), 2.0 / 3);
    
  g.fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, .1), control_paint::dark(button_color)), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), 0.25);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_symbolic_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto button_color = control_paint::dark(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = control_paint::light(xtd::forms::theme_colors::current_theme().active_border(), 2.0 / 3);
    button_color = control_paint::dark(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
    text_color = xtd::forms::theme_colors::current_theme().accent_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state)
    border_color = control_paint::dark(xtd::forms::theme_colors::current_theme().accent(), 2.0 / 3);
    
  g.fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {bounds.x(), bounds.top()}, point {bounds.x(), bounds.bottom()}, control_paint::light(button_color, .1), control_paint::dark(button_color)), bounds.x(), bounds.y(), bounds.width(), bounds.height(), 4);
  g.draw_rounded_rectangle(pen(border_color, 1), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_windows(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_windows_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_windows_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_windows_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().button_face();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto border_color = background_color;
  auto button_color = background_color;
  auto text_color = foreground_color;
  
  if (state == push_button_state::hot)
    active_border_color = border_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked)
    active_border_color = border_color = button_color = xtd::forms::theme_colors::current_theme().accent();
  else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = xtd::forms::theme_colors::current_theme().active_border();
    if (!back_color.has_value()) border_color = color::from_argb(90, 90, 90);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state)
    active_border_color = border_color = control_paint::dark(xtd::forms::theme_colors::current_theme().accent());
    
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 1, bounds.y() + 2, bounds.width() - 2, bounds.height() - 4);
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 2, bounds.width() - 3, bounds.height() - 5);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 3, bounds.width() - 5, bounds.height() - 7);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_windows_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().button_face();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().active_border();
  auto border_color = xtd::forms::theme_colors::current_theme().button_face();
  auto button_color = background_color;
  auto text_color = foreground_color;
  if (state == push_button_state::hot) {
    active_border_color = xtd::forms::theme_colors::current_theme().accent();
    border_color = color::from_argb(232, 243, 251);
    if (!back_color.has_value()) button_color = color::from_argb(232, 243, 251);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    active_border_color = xtd::forms::theme_colors::current_theme().highlight();
    border_color = xtd::forms::theme_colors::current_theme().accent();
    if (!back_color.has_value()) button_color = xtd::forms::theme_colors::current_theme().accent();
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = xtd::forms::theme_colors::current_theme().active_border();
    if (!back_color.has_value()) button_color = color::from_argb(204, 204, 204);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) {
    active_border_color = xtd::forms::theme_colors::current_theme().highlight();
    border_color = xtd::forms::theme_colors::current_theme().highlight();
    auto text_rect = rectangle(bounds.x() + 3, bounds.y() + 3, bounds.width() - 6, bounds.height() - 6);
    draw_string(g, text, font, text_color, text_rect, flags);
  }
  
  g.fill_rectangle(solid_brush(button_color), bounds.x() + 1, bounds.y() + 2, bounds.width() - 2, bounds.height() - 4);
  g.draw_rectangle(pen(active_border_color, 1), bounds.x() + 1, bounds.y() + 2, bounds.width() - 3, bounds.height() - 5);
  g.draw_rectangle(pen(border_color, 1), bounds.x() + 2, bounds.y() + 3, bounds.width() - 5, bounds.height() - 7);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  auto text_rect = rectangle(bounds.x() + 5, bounds.y() + 3, bounds.width() - 10, bounds.height() - 7);
  draw_string(g, text, font, text_color, text_rect, flags);
}

void button_renderer::draw_button_xtd(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_button_xtd_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
  else  draw_button_xtd_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_xtd_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_button_xtd_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color) {
  draw_button_symbolic_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void button_renderer::draw_flat_button(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_flat_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color, flat_appearance);
  else  draw_flat_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color, flat_appearance);
}

void button_renderer::draw_flat_button_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  auto background_color = back_color.value_or(xtd::forms::theme_colors::current_theme().control());
  auto foreground_color = fore_color.value_or(xtd::forms::theme_colors::current_theme().control_text());
  auto active_border_color = flat_appearance.border_color().value_or(xtd::forms::theme_colors::current_theme().control_text());
  auto border_color = flat_appearance.border_color().value_or(xtd::forms::theme_colors::current_theme().control_text());
  auto button_color = background_color;
  auto text_color = foreground_color;
  
  if (environment::os_version().is_macos_platform()) {
    background_color = back_color.value_or(color::transparent);
    button_color = back_color.value_or(color::transparent);
  }
  
  if (state == xtd::forms::visual_styles::push_button_state::hot)
    button_color = flat_appearance.mouse_over_back_color().value_or(xtd::forms::theme_colors::current_theme().accent());
  else if (state == xtd::forms::visual_styles::push_button_state::checked)
    button_color = flat_appearance.checked_back_color().value_or(xtd::forms::theme_colors::current_theme().accent());
  else if (state == xtd::forms::visual_styles::push_button_state::pressed)
    button_color = flat_appearance.mouse_down_back_color().value_or(background_color);
  else if (state == xtd::forms::visual_styles::push_button_state::disabled)
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  else if (state == xtd::forms::visual_styles::push_button_state::default_state) border_color = control_paint::light(xtd::forms::theme_colors::current_theme().control_text(), .2);
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, environment::os_version().is_windows_platform() ? 0 : 4);
  if (flat_appearance.border_size()) g.draw_rounded_rectangle(pen(border_color, static_cast<float>(flat_appearance.border_size())), rectangle::inflate(bounds, -1, -1), environment::os_version().is_windows_platform() ? 0 : 4);
  if (focused) g.draw_rounded_rectangle(pen(active_border_color, 1), rectangle::offset(rectangle::inflate(bounds, drawing::size(flat_appearance.border_size() - 2, flat_appearance.border_size() - 2)), drawing::point(drawing::size(flat_appearance.border_size(), flat_appearance.border_size()))), environment::os_version().is_windows_platform() ? 0 : 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, bounds, flags);
}

void button_renderer::draw_flat_button_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  draw_flat_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color, flat_appearance);
}

void button_renderer::draw_popup_button(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  if (xtd::forms::theme_colors::current_theme().window().get_lightness() < 0.5) draw_popup_button_dark(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color, flat_appearance);
  else  draw_popup_button_light(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color, flat_appearance);
}

void button_renderer::draw_popup_button_dark(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = control_paint::light(background_color, .05);
  auto button_color = control_paint::light(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = control_paint::light(xtd::forms::theme_colors::current_theme().control_text(), .2);
    button_color = control_paint::light(background_color, .2);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    border_color = active_border_color = control_paint::light(xtd::forms::theme_colors::current_theme().control_text(), .2);
    button_color = control_paint::light(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = control_paint::light(xtd::forms::theme_colors::current_theme().control_text(), .2);
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width(), bounds.height(), environment::os_version().is_windows_platform() ? 0 : 4);
  g.draw_rounded_rectangle(pen(active_border_color, 1), rectangle::inflate(bounds, {-2, 2}), environment::os_version().is_windows_platform() ? 0 : 4);
  g.draw_rounded_rectangle(pen(border_color, 1), rectangle::offset(rectangle::inflate(bounds, {-3, -3}), {1, 1}), environment::os_version().is_windows_platform() ? 0 : 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, bounds, flags);
}

void button_renderer::draw_popup_button_light(graphics g, const rectangle& bounds, const ustring& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const optional<color>& back_color, const optional<color>& fore_color, const flat_button_appearance& flat_appearance) {
  auto background_color = back_color.has_value() ? back_color.value() : xtd::forms::theme_colors::current_theme().control();
  auto foreground_color = fore_color.has_value() ? fore_color.value() : xtd::forms::theme_colors::current_theme().control_text();
  auto active_border_color = xtd::forms::theme_colors::current_theme().control_text();
  auto border_color = control_paint::dark(background_color, .05);
  auto button_color = control_paint::dark(background_color, .05);
  auto text_color = foreground_color;
  
  if (state == xtd::forms::visual_styles::push_button_state::hot) {
    border_color = active_border_color = control_paint::dark(xtd::forms::theme_colors::current_theme().control_text(), .2);
    button_color = control_paint::dark(background_color, .2);
  } else if (state == xtd::forms::visual_styles::push_button_state::pressed || state == xtd::forms::visual_styles::push_button_state::checked) {
    border_color = active_border_color = control_paint::dark(xtd::forms::theme_colors::current_theme().control_text(), .2);
    button_color = control_paint::dark(background_color, .1);
  } else if (state == xtd::forms::visual_styles::push_button_state::disabled) {
    active_border_color = color::from_argb(85, 85, 55);
    text_color = xtd::forms::theme_colors::current_theme().gray_text();
  } else if (state == xtd::forms::visual_styles::push_button_state::default_state) active_border_color = border_color = control_paint::dark(xtd::forms::theme_colors::current_theme().control_text(), .2);
  
  g.fill_rounded_rectangle(solid_brush(button_color), bounds.x(), bounds.y(), bounds.width() - 1, bounds.height() - 1, environment::os_version().is_windows_platform() ? 0 : 4);
  g.draw_rounded_rectangle(pen(active_border_color, 1), rectangle::inflate(bounds, {-2, -2}), environment::os_version().is_windows_platform() ? 0 : 4);
  g.draw_rounded_rectangle(pen(border_color, 1), rectangle::offset(rectangle::inflate(bounds, {-3, -3}), {1, 1}), environment::os_version().is_windows_platform() ? 0 : 4);
  if (image != image::empty && state == xtd::forms::visual_styles::push_button_state::disabled) control_paint::draw_image_disabled(g, image, image_bounds.location(), button_color);
  else if (image != image::empty) g.draw_image(image, image_bounds.location());
  draw_string(g, text, font, text_color, bounds, flags);
}
