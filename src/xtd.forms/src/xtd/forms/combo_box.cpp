#include <xtd/argument_out_of_range_exception.h>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/combo_box.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/native/combo_box_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/combo_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

combo_box::combo_box() {
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::user_paint | control_styles::use_text_for_accessibility | control_styles::standard_click, false);
  data_->items.item_added += [&](size_t pos, const item & item) {
    if (is_handle_created()) native::combo_box::insert_item(handle(), pos, item.value());
    combo_box::item selected_item;
    if (selected_index() != npos && selected_index() < data_->items.size()) selected_item = data_->items[selected_index()];
    this->selected_item(selected_item);
  };
  
  data_->items.item_removed += [&](size_t pos, const item & item) {
    if (is_handle_created()) native::combo_box::delete_item(handle(), pos);
    
    combo_box::item selected_item;
    if (selected_index() != npos && selected_index() < data_->items.size()) selected_item = data_->items[selected_index()];
    this->selected_item(selected_item);
    
    if (this->items().size() == 1) // not 0! --> the item_remove occure before erase!
      this->selected_index(npos);
  };
  
  data_->items.item_updated += [&](size_t pos, const item & item) {
    if (is_handle_created()) native::combo_box::update_item(handle(), pos, item.value());
    combo_box::item selected_item;
    if (selected_index() != npos && selected_index() < data_->items.size()) selected_item = data_->items[selected_index()];
    this->selected_item(selected_item);
  };
}

bool combo_box::dropped_down() const {
  return data_->drop_down;
}

combo_box& combo_box::dropped_down(bool value) {
  if (data_->drop_down != value) {
    data_->drop_down = value;
    if (is_handle_created()) native::combo_box::dropped_down(handle(), data_->drop_down);
  }
  return *this;
}

combo_box& combo_box::drop_down_style(combo_box_style drop_down_style) {
  if (data_->drop_down_style != drop_down_style) {
    data_->drop_down_style = drop_down_style;
    post_recreate_handle();
    on_drop_down_style_changed(event_args::empty);
  }
  return *this;
}

list_control& combo_box::selected_index(size_t selected_index) {
  if (this->selected_index() != selected_index) {
    if (selected_index != npos && selected_index >= data_->items.size()) throw argument_out_of_range_exception("Selected index greater than items size"_t, current_stack_frame_);
    set_selected_index(selected_index);
    if (is_handle_created()) native::combo_box::selected_index(handle(), this->selected_index());
    
    item selected_item;
    if (this->selected_index() != npos) selected_item = data_->items[this->selected_index()];
    //this->selected_item(selected_item);
    data_->selected_item = selected_item;
    on_selected_value_changed(event_args::empty);
    
    on_selected_index_changed(event_args::empty);
  }
  return *this;
}

combo_box& combo_box::selected_item(const item& selected_item) {
  if (data_->selected_item != selected_item) {
    auto it = std::find(data_->items.begin(), data_->items.end(), selected_item);
    if (it == data_->items.end())
      data_->selected_item = selected_index() != npos ? items()[selected_index()] : "";
    else {
      size_t index = it - data_->items.begin();
      selected_index(index);
      data_->selected_item = *it;
      on_selected_value_changed(event_args::empty);
    }
  }
  return *this;
}

combo_box& combo_box::sorted(bool sorted) {
  if (data_->sorted != sorted) {
    data_->sorted = sorted;
    data_->items.sorted(data_->sorted);
  }
  return *this;
}

void combo_box::begin_update() {
  if (is_handle_created()) native::combo_box::begin_update(handle());
}

void combo_box::end_update() {
  if (is_handle_created()) native::combo_box::end_update(handle());
}

forms::create_params combo_box::create_params() const {
  forms::create_params create_params = list_control::create_params();
  
  create_params.class_name("combobox");
  
  // Do not use native control sort
  //if (data_->sorted) create_params.style(create_params.style() | CBS_SORT);
  
  switch (data_->drop_down_style) {
    case combo_box_style::drop_down_list: create_params.style(create_params.style() | CBS_DROPDOWNLIST); break;
    case combo_box_style::drop_down: create_params.style(create_params.style() | CBS_DROPDOWN); break;
    case combo_box_style::simple: create_params.style(create_params.style() | CBS_SIMPLE); break;
  }
  
  create_params.size(native::control::default_size(create_params.class_name()));
  
  return create_params;
}

void combo_box::on_drop_down(const event_args& e) {
  data_->drop_down = true;
  drop_down(*this, e);
}

void combo_box::on_drop_down_closed(const event_args& e) {
  data_->drop_down = false;
  drop_down_closed(*this, e);
}

void combo_box::on_drop_down_style_changed(const event_args& e) {
  drop_down_style_changed(*this, e);
}

void combo_box::on_handle_created(const event_args& e) {
  list_control::on_handle_created(e);

  data_->drop_down_width = default_size().width();
  data_->drop_down_height = static_cast<int32_t>(font().get_height()) * 9;
  if (environment::os_version().is_windows_platform() && data_->drop_down_style == combo_box_style::simple && size().height() == default_size().height() && size().height() < data_->drop_down_height)
    size({size().width(), data_->drop_down_height});
    
  data_->items.sorted(data_->sorted);
  for (size_t index = 0; index < data_->items.size(); ++index)
    native::combo_box::insert_item(handle(), index, data_->items[index].value());
  native::combo_box::selected_index(handle(), selected_index());
  if (selected_index() != npos) data_->selected_item = data_->items[selected_index()];
}

void combo_box::on_selected_value_changed(const event_args& e) {
  list_control::text(data_->selected_item.value());
  list_control::on_selected_value_changed(e);
}

void combo_box::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: list_control::wnd_proc(message);
  }
}

void combo_box::wm_command_control(message& message) {
  on_click(event_args::empty);
  switch (HIWORD(message.wparam())) {
    case CBN_DROPDOWN: on_drop_down(event_args::empty); break;
    case CBN_CLOSEUP: on_drop_down_closed(event_args::empty); break;
    case CBN_SELCHANGE: wm_command_control_selchange(message); break;
    default: break;
  }
}

void combo_box::wm_command_control_selchange(message& message) {
  def_wnd_proc(message);
  selected_index(native::combo_box::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
}

void combo_box::wm_mouse_double_click(message& message) {
  selected_index(native::combo_box::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}

void combo_box::wm_mouse_down(message& message) {
  if (allow_selection())
    list_control::wnd_proc(message);
}

void combo_box::wm_mouse_up(message& message) {
  selected_index(native::combo_box::selected_index(handle()));
  if (selected_index() != npos) selected_item(data_->items[selected_index()]);
  if (allow_selection())
    list_control::wnd_proc(message);
}
