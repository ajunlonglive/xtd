#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/drawing/system_pens.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/tool_bar.h>
#include <xtd/forms/native/tool_bar_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/tool_bar.h"
#include "../../../include/xtd/forms/tool_bar_renderer.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  struct parent_client_size_guard {
    explicit parent_client_size_guard(control& control) : control_(&control) {
      client_size_ = control_->parent().value().get().client_size();
    }
    
    ~parent_client_size_guard() {
      control_->parent().value().get().client_size(client_size_);
    }
    
  private:
    control* control_;
    drawing::size client_size_;
  };
}

tool_bar::tool_bar_button_control::tool_bar_button_control() {
  set_can_focus(false);
  auto current_font = font();
  current_font = drawing::font(current_font, 8.5);
  font(current_font);
}

tool_bar::tool_bar_separator_control::tool_bar_separator_control() {
  set_can_focus(false);
}

void tool_bar::tool_bar_separator_control::on_paint(paint_event_args& e) {
  control::on_paint(e);
  auto percent_of_color = 1.0 / 3;
  auto color = back_color().get_lightness() < 0.5 ? xtd::forms::control_paint::light(back_color(), percent_of_color) : xtd::forms::control_paint::dark(back_color(), percent_of_color);
  if (dock() == dock_style::top || dock() == dock_style::bottom) {
    auto left = 4;
    auto top = e.clip_rectangle().height() / 2;
    auto right = e.clip_rectangle().width() - 4;
    auto bottom = top;
    e.graphics().draw_line(pen {color}, point {left, top}, point {right, bottom});
  } else {
    auto left = e.clip_rectangle().width() / 2;
    auto top = 4;
    auto right = left;
    auto bottom = e.clip_rectangle().height() - 4;
    e.graphics().draw_line(pen {color}, point {left, top}, point {right, bottom});
  }
}

tool_bar::tool_bar() {
  data_->items.item_added += {*this, &tool_bar::on_item_added};
  data_->items.item_updated += {*this, &tool_bar::on_item_updated};
  data_->items.item_removed += {*this, &tool_bar::on_item_removed};
  
  data_->image_list.image_size(environment::os_version().is_windows_platform() ? drawing::size {16, 16} : drawing::size {24, 24});
  dock(xtd::forms::dock_style::top);
  padding(forms::padding {2});
  set_can_focus(false);
}

xtd::forms::tool_bar_appearance tool_bar::appearnce() const {
  return data_->appearnce;
}

tool_bar& tool_bar::appearnce(xtd::forms::tool_bar_appearance value) {
  if (data_->appearnce != value) {
    data_->appearnce = value;
    if (value != tool_bar_appearance::system) {
      control::dock(data_->non_system_dock);
      invalidate();
    } else {
      data_->non_system_dock = control::dock();
      control::dock(dock_style::none);
      post_recreate_handle();
    }
  }
  return *this;
}

tool_bar& tool_bar::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides != border_sides) {
    data_->border_sides = border_sides;
    if (control_appearance() == forms::control_appearance::standard) invalidate();
  }
  return *this;
}

tool_bar& tool_bar::border_style(forms::border_style border_style) {
  if (data_->border_style != border_style) {
    data_->border_style = border_style;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

tool_bar& tool_bar::border_style(nullptr_t) {
  if (data_->border_style) {
    data_->border_style.reset();
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

xtd::drawing::size tool_bar::button_size() const {
  return data_->button_size.value_or(image_size() + drawing::size(12, 12));
}

tool_bar& tool_bar::button_size(const xtd::drawing::size& value) {
  if (!data_->button_size.has_value() || data_->button_size != value) {
    data_->button_size = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

xtd::drawing::size tool_bar::image_size() const {
  return data_->image_list.image_size();
}

bool tool_bar::show_icon() const {
  return data_->show_icon;
}

tool_bar& tool_bar::show_icon(bool value) {
  if (data_->show_icon != value) {
    data_->show_icon = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

bool tool_bar::show_text() const {
  return data_->show_text;
}

tool_bar& tool_bar::show_text(bool value) {
  if (data_->show_text != value) {
    data_->show_text = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

xtd::forms::tool_bar_text_align tool_bar::text_align() const {
  return data_->text_align;
}

tool_bar& tool_bar::text_align(xtd::forms::tool_bar_text_align value) {
  if (data_->text_align != value) {
    data_->text_align = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

forms::create_params tool_bar::create_params() const {
  forms::create_params create_params = control::create_params();
  
  if (is_system_tool_bar())
    create_params.class_name("toolbar");
  
  if (data_->appearnce == tool_bar_appearance::flat) create_params.style(create_params.style() | TBSTYLE_FLAT);
  if (data_->non_system_dock == dock_style::left) create_params.style(create_params.style() | TBSTYLE_LEFT);
  else if (data_->non_system_dock == dock_style::right) create_params.style(create_params.style() | TBSTYLE_RIGHT);
  else if (data_->non_system_dock == dock_style::bottom) create_params.style(create_params.style() | TBSTYLE_BOTTOM);
  if (data_->show_text) create_params.style(create_params.style() | TBSTYLE_SHOWTEXT);
  if (!data_->show_icon) create_params.style(create_params.style() | TBSTYLE_NOSHOWICON);
  if (data_->text_align == tool_bar_text_align::right) create_params.style(create_params.style() | TBSTYLE_TEXTRIGHTALIGN);
  return create_params;
}

void tool_bar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  fill();
}

void tool_bar::on_handle_destroyed(const event_args& e) {
  control::on_handle_destroyed(e);
  if (is_system_tool_bar()) {
    native::tool_bar::set_system_tool_bar(parent().value().get().handle(), 0);
    data_->system_tool_bar_item_handles.clear();
  }
}

void tool_bar::on_paint(xtd::forms::paint_event_args& e) {
  control::on_paint(e);
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (control_appearance() == forms::control_appearance::standard) tool_bar_renderer::draw_tool_bar(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, data_->border_style, data_->border_sides);
}

bool tool_bar::is_system_tool_bar() const {
  auto result = data_->is_system_tool_bar || data_->appearnce == tool_bar_appearance::system;
  return result;
}

tool_bar& tool_bar::is_system_tool_bar(bool value) {
  if (data_->is_system_tool_bar != value) {
    if (!value) control::dock(data_->non_system_dock);
    else {
      data_->non_system_dock = control::dock();
      control::dock(dock_style::none);
    }
    data_->is_system_tool_bar = value;
    post_recreate_handle();
  }
  return *this;
}

void tool_bar::fill() {
  suspend_layout();
  controls().clear();
  data_->tool_bar_items.clear();
  auto reversed_items = data_->items;
  if (!is_system_tool_bar()) std::reverse(reversed_items.begin(), reversed_items.end());
  for (size_t index = 0; index < reversed_items.size(); ++index) {
    if (is<tool_bar_button>(reversed_items[index].get())) {
      auto& button_item = as<tool_bar_button>(reversed_items[index].get());
      if (is_system_tool_bar())
        data_->system_tool_bar_item_handles.push_back(native::tool_bar::add_tool_bar_button(handle(), button_item.text(), button_item.image_index() < data_->image_list.images().size() ? data_->image_list.images()[button_item.image_index()].handle() : image::empty.handle(), button_item.enabled()));
      else {
        auto button_control = std::make_shared<tool_bar_button_control>();
        button_control->parent(*this);
        button_control->tool_bar_item(button_item);
        if (dock() == dock_style::left || dock() == dock_style::right) button_control->dock(dock_style::top);
        else button_control->dock(dock_style::left);
        button_control->flat_style(xtd::forms::flat_style::flat);
        button_control->flat_appearance().border_size(0);
        
        button_control->size(button_size());

        if ((data_->show_icon || !data_->show_text) && button_item.image_index() < data_->image_list.images().size()) button_control->image(data_->image_list.images()[button_item.image_index()]);
        if (data_->show_text) button_control->text(button_item.text());
        auto text_size = button_control->measure_text();

        if (data_->show_text == false) {
          button_control->image_align(content_alignment::middle_center);
          if (button_control->width() < image_size().width()) button_control->width(image_size().width() + 12);
          if (button_control->height() < image_size().height()) button_control->height(image_size().height() + 12);
        } else if (data_->show_text == true && data_->show_icon == false) {
          button_control->text_align(content_alignment::middle_center);
          if (button_control->width() < text_size.width()) button_control->width(text_size.width());
          if (button_control->height() < text_size.height()) button_control->height(text_size.height());
        } else if (data_->show_text == true && data_->show_icon == true && data_->text_align == tool_bar_text_align::right) {
          button_control->image_align(content_alignment::middle_left);
          button_control->text_align(content_alignment::middle_right);
          if (button_control->width() < (image_size().width() + text_size.width())) button_control->width(image_size().width() + text_size.width());
          if (button_control->height() < text_size.height()) button_control->height(text_size.height());
        }  else {
          button_control->image_align(content_alignment::top_center);
          button_control->text_align(content_alignment::bottom_center);
          if (button_control->width() < text_size.width()) button_control->width(text_size.width());
          if (button_control->height() < (image_size().height() + text_size.height())) button_control->height(image_size().height() + text_size.height());
        }

        if (this->dock() == dock_style::top || this->dock() ==  dock_style::bottom) {
          if (height() < button_control->height()) height(button_control->height() + 4);
        } else {
          if (width() < button_control->width()) width(button_control->width() + 4);
        }

        data_->tool_bar_items.push_back(button_control);
      }
    } else if (is<tool_bar_separator>(reversed_items[index].get())) {
      if (is_system_tool_bar())
        data_->system_tool_bar_item_handles.push_back(native::tool_bar::add_tool_bar_separator(handle()));
      else {
        auto separator_control = std::make_shared<tool_bar_separator_control>();
        separator_control->parent(*this);
        separator_control->height(image_size().height() / 2);
        separator_control->width(image_size().width() / 2);
        if (dock() == dock_style::left || dock() == dock_style::right) separator_control->dock(dock_style::top);
        else separator_control->dock(dock_style::left);
        data_->tool_bar_items.push_back(separator_control);
      }
    }
  }
  if (is_system_tool_bar()) {
    parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
    native::tool_bar::set_system_tool_bar(parent().value().get().handle(), handle());
  }
  
  resume_layout();
}

void tool_bar::on_item_added(size_t pos, tool_bar_item_ref item) {
  parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  item.get().parent = this;
  post_recreate_handle();
}

void tool_bar::on_item_updated(size_t pos, tool_bar_item_ref item) {
  parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  post_recreate_handle();
}

void tool_bar::on_item_removed(size_t pos, tool_bar_item_ref item) {
  parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  item.get().parent = nullptr;
  post_recreate_handle();
}

dock_style tool_bar::dock() const {
  //if (is_system_tool_bar()) return data_->non_system_dock;
  return control::dock();
}

control& tool_bar::dock(dock_style dock) {
  if (is_system_tool_bar()) {
    data_->non_system_dock = dock;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  } else {
    int32_t current_size = this->dock() == dock_style::top || this->dock() == dock_style::bottom ? height() : width();
    control::dock(dock);
    if (this->dock() == dock_style::top || this->dock() ==  dock_style::bottom) height(current_size);
    else width(current_size);
  }
  return *this;
}

const xtd::forms::image_list& tool_bar::image_list() const {
  return data_->image_list;
}

xtd::forms::image_list& tool_bar::image_list() {
  return data_->image_list;
}

xtd::forms::tool_bar& tool_bar::image_list(const xtd::forms::image_list& value) {
  if (data_->image_list != value) {
    data_->image_list = value;
    height(data_->image_list.image_size().height() + 8);
  }
  return *this;
}

const tool_bar::tool_bar_item_collection& tool_bar::items() const {
  return data_->items;
}

tool_bar::tool_bar_item_collection& tool_bar::items() {
  return data_->items;
}

void tool_bar::wnd_proc(message& message) {
  if (is_system_tool_bar() && message.msg() == WM_MENUCOMMAND && handle() == message.hwnd()) wm_click(message);
  else control::wnd_proc(message);
}

void tool_bar::wm_click(const message& message) {
  for (size_t index = 0; index < data_->system_tool_bar_item_handles.size(); ++index) {
    if (index < data_->system_tool_bar_item_handles.size() && message.wparam() == data_->system_tool_bar_item_handles[index]) {
      data_->items[index].get().perform_click();
      break;
    }
  }
}
