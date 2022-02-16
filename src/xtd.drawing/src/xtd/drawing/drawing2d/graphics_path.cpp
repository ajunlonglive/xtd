#include <stdexcept>
#include "../../../../include/xtd/drawing/drawing2d/graphics_path.h"
#include "../../../../include/xtd/drawing/graphics.h"
#include <xtd/argument_exception.h>
#include <xtd/as.h>
#include <xtd/is.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics_path.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

graphics_path::graphics_path() : graphics_path(drawing2d::fill_mode::alternate) {
}

graphics_path::graphics_path(drawing2d::fill_mode mode) {
  data_->fill_mode = mode;
  data_->handle = native::graphics_path::create();
}

graphics_path::~graphics_path() {
  if (data_.use_count() == 1 && data_->handle != 0) native::graphics_path::destroy(data_->handle);
}

bool graphics_path::operator==(const graphics_path& value) const {
  return data_ == value.data_;
}

bool graphics_path::operator!=(const graphics_path& value) const {
  return !operator==(value);
}

intptr_t graphics_path::handle() const noexcept {
  return data_->handle;
}

xtd::drawing::drawing2d::fill_mode graphics_path::fill_mode() const noexcept {
  return data_->fill_mode;
}

graphics_path& graphics_path::fill_mode(xtd::drawing::drawing2d::fill_mode value) noexcept {
  data_->fill_mode = value;
  return *this;
}

void graphics_path::add_arc(const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  add_arc(rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics_path::add_arc(const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  add_arc(rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics_path::add_arc(int32_t x, int32_t y, int32_t width, int32_t height, float start_angle, float sweep_angle) {
  add_arc(as<float>(x), as<float>(y), as<float>(width), as<float>(height), start_angle, sweep_angle);
}

void graphics_path::add_arc(float x, float y, float width, float height, float start_angle, float sweep_angle) {
  native::graphics_path::add_arc(data_->handle, x, y, width, height, start_angle, sweep_angle);
}

void graphics_path::add_ellipse(const xtd::drawing::rectangle& rect) {
  add_ellipse(rectangle_f(rect));
}

void graphics_path::add_ellipse(const xtd::drawing::rectangle_f& rect) {
  add_ellipse(rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics_path::add_ellipse(int32_t x, int32_t y, int32_t width, int32_t height) {
  add_ellipse(as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics_path::add_ellipse(float x, float y, float width, float height) {
  native::graphics_path::add_ellipse(data_->handle, x, y, width, height);
}

void graphics_path::add_rectangle(const rectangle& rect) {
  add_rectangle(rectangle_f(rect));
}
void graphics_path::add_rectangle(const rectangle_f& rect) {
  add_rectangle(rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics_path::add_rectangle(int32_t x, int32_t y, int32_t width, int32_t height) {
  add_rectangle(as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics_path::add_rectangle(float x, float y, float width, float height) {
  native::graphics_path::add_rectangle(data_->handle, x, y, width, height);
}

xtd::drawing::rectangle_f graphics_path::get_bounds() const {
  float x, y, width, height;
  native::graphics_path::get_bounds(data_->handle, x, y, width, height);
  return {x, y, width, height};
}

xtd::ustring graphics_path::to_string() const noexcept {
  return ustring::full_class_name(*this);
}
