#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/menu.h>
#include <xtd/forms/native/menu_item.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/menu_item.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

menu_item::menu_item() {
}

menu_item::menu_item(const xtd::ustring& text) : text_(text) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::shortcut shortcut) : text_(text), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image) : text_(text),image_(image)  {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::shortcut shortcut) : text_(text),image_(image), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind) : text_(text), kind_(kind) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : text_(text), kind_(kind), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind) : text_(text), image_(image), kind_(kind) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : text_(text), image_(image), kind_(kind), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind, bool checked) : text_(text), kind_(kind), checked_(checked) {
}

menu_item::menu_item(const xtd::ustring& text, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : text_(text), kind_(kind), checked_(checked), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked) : text_(text), image_(image), kind_(kind), checked_(checked) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : text_(text), image_(image), kind_(kind), checked_(checked), shortcut_(shortcut) {
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click) : text_(text) {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, xtd::forms::shortcut shortcut) : text_(text), shortcut_(shortcut) {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, const xtd::drawing::image& image) : text_(text),image_(image)  {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, const xtd::drawing::image& image, xtd::forms::shortcut shortcut) : text_(text),image_(image), shortcut_(shortcut) {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, xtd::forms::menu_item_kind kind) : menu(menu::menu_item_collection {}), text_(text), kind_(kind) {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : text_(text), kind_(kind), shortcut_(shortcut) {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind) : text_(text), image_(image), kind_(kind) {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : text_(text), image_(image), kind_(kind), shortcut_(shortcut) {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, xtd::forms::menu_item_kind kind, bool checked) : text_(text), kind_(kind), checked_(checked) {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : text_(text), kind_(kind), checked_(checked), shortcut_(shortcut) {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked) : text_(text), image_(image), kind_(kind), checked_(checked) {
  data_->on_click_ = on_click;
}

menu_item::menu_item(const xtd::ustring& text, const xtd::event_handler& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : text_(text), image_(image), kind_(kind), checked_(checked), shortcut_(shortcut) {
  data_->on_click_ = on_click;
  create_menu();
}

menu_item::menu_item(const xtd::ustring& text, const std::vector<menu_item>& items) : text_(text) {
  is_parent_ = true;
  create_menu();
  data_->menu_items_.push_back_range(items);
}

menu_item& menu_item::enabled(bool value) {
  if (enabled_ != value) {
    enabled_ = value;
    if (handle()) native::menu_item::enabled(handle(), enabled_);
    on_menu_item_updated(event_args::empty);
  }
  return *this;
}

menu_item& menu_item::checked(bool value) {
  if (checked_ != value) {
    checked_ = value;
    if (handle()) native::menu_item::checked(handle(), checked_);
    on_menu_item_updated(event_args::empty);
  }
  return *this;
}

bool menu_item::is_parent() const {
  return is_parent_ || menu::is_parent();
}

intptr_t menu_item::create_menu_handle() {
  if (is_parent() || data_->main_menu_.has_value() || data_->context_menu_.has_value()) return native::menu::create(text_);
  
  if (text_ == "-") kind_ = xtd::forms::menu_item_kind::separator;
  auto handle = native::menu_item::create(data_->parent_.value()->handle(), text_, image_, static_cast<int>(kind_), checked_, static_cast<size_t>(shortcut_), enabled_);
  handles_[native::menu_item::menu_id(handle)] = make_shared<menu_item>(*this);
  return handle;
}

void menu_item::destroy_menu_handle(intptr_t handle) {
  if (!handle) return;
  if (is_parent()) return native::menu::destroy(data_->handle_);
  handles_.erase(native::menu_item::menu_id(handle));
  native::menu_item::destroy(handle);
}

int menu_item::menu_id() const {
  return native::menu_item::menu_id(data_->handle_);
}

void menu_item::on_item_added(size_t pos, std::reference_wrapper<menu_item> item) {
  menu::on_item_added(pos, item);
  item.get().data_->parent_ = make_unique<menu_item>(*this);
  if (!item.get().handle()) item.get().create_menu();
  if (item.get().is_parent() || item.get().data_->main_menu_.has_value()) native::menu::insert_menu(handle(), pos, item.get().handle());
  else native::menu::insert_item(handle(), pos, item.get().handle());
}

void menu_item::on_item_removed(size_t pos, std::reference_wrapper<menu_item> item) {
  menu::on_item_removed(pos, item);
  //item.get().data_->parent_.reset();
  //item.get().destroy_menu();
}

ustring menu_item::to_string() const noexcept {
  return ustring::format("{}, text: {}", menu::to_string(), text_);
}
