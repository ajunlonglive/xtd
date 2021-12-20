#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/month_calendar.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/month_calendar.h"

using namespace xtd;
using namespace xtd::forms;

namespace {
  static std::tm make_tm(int32_t year, int32_t month, int32_t day) {
    std::tm date = {};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    return date;
  }
}

month_calendar::time_point month_calendar::max_date() const {
  return data_->max_date;
}

month_calendar& month_calendar::max_date(time_point value) {
  value = clear_hours_minutes_seconds(value);
  if (data_->max_date != value) {
    data_->max_date = value;
    if (data_->max_date < data_->min_date) data_->min_date = data_->max_date;
    if (is_handle_created()) native::month_calendar::allowable_dates(handle(), data_->min_date, data_->max_date);
    selection_start(data_->selection_start);
    selection_end(data_->selection_end);
  }
  return *this;
}

month_calendar& month_calendar::max_date(time_t value) {
  return max_date(std::chrono::system_clock::from_time_t(value));
}

month_calendar& month_calendar::max_date(const std::tm& value) {
  std::tm date = value;
  return this->max_date(mktime(&date));
}

month_calendar& month_calendar::max_date(int32_t year, int32_t month, int32_t day) {
  std::tm date = make_tm(year, month, day);
  return max_date(std::mktime(&date));
}

month_calendar::time_point month_calendar::min_date() const {
  return data_->min_date;
}

month_calendar& month_calendar::month_calendar::min_date(time_point value) {
  value = clear_hours_minutes_seconds(value);
  if (data_->min_date != value) {
    data_->min_date = value;
    if (data_->max_date < data_->min_date) data_->max_date = data_->min_date;
    if (is_handle_created()) native::month_calendar::allowable_dates(handle(), data_->min_date, data_->max_date);
    selection_start(data_->selection_start);
    selection_end(data_->selection_end);
  }
  return *this;
}

month_calendar& month_calendar::min_date(time_t value) {
  return min_date(std::chrono::system_clock::from_time_t(value)); 
}

month_calendar& month_calendar::min_date(const std::tm& value) {
  std::tm date = value;
  return min_date(std::mktime(&date));
}
month_calendar& month_calendar::min_date(int32_t year, int32_t month, int32_t day) {
  std::tm date = make_tm(year, month, day);
  return min_date(std::mktime(&date));
}

month_calendar::time_point month_calendar::selection_end() const {
  return data_->selection_end;
}

month_calendar& month_calendar::selection_end(std::chrono::system_clock::time_point value) {
  value = clear_hours_minutes_seconds(value);
  if (value < data_->min_date) value = data_->min_date;
  if (value > data_->max_date) value = data_->max_date;
  if (data_->selection_end != value) {
    data_->selection_end = value;
    if (is_handle_created()) native::month_calendar::selection_range(handle(), data_->selection_start, data_->selection_end);
    on_date_selected(event_args::empty);
  }
  return *this;
}

month_calendar& month_calendar::selection_end(time_t value) {
  return selection_end(std::chrono::system_clock::from_time_t(value));
}

month_calendar& month_calendar::selection_end(const std::tm& value) {
  std::tm date = value;
  return selection_end(std::mktime(&date));
}

month_calendar& month_calendar::selection_end(int32_t year, int32_t month, int32_t day) {
  std::tm date = make_tm(year, month, day);
  return selection_end(std::mktime(&date));
}

month_calendar::time_point month_calendar::selection_start() const {
  return data_->selection_start;
}

month_calendar& month_calendar::selection_start(time_point value) {
  value = clear_hours_minutes_seconds(value);
  if (value < data_->min_date) value = data_->min_date;
  if (value > data_->max_date) value = data_->max_date;
  if (data_->selection_start != value) {
    data_->selection_start = value;
    if (is_handle_created()) native::month_calendar::selection_range(handle(), data_->selection_start, data_->selection_end);
    on_date_selected(event_args::empty);
  }
  return *this;
}

month_calendar& month_calendar::selection_start(time_t value) {
  return selection_start(std::chrono::system_clock::from_time_t(value));
}

month_calendar& month_calendar::selection_start(const std::tm& value) {
  std::tm date = value;
  return selection_start(std::mktime(&date));
}

month_calendar& month_calendar::selection_start(int32_t year, int32_t month, int32_t day) {
  std::tm date = make_tm(year, month, day);
  return selection_start(std::mktime(&date));
}

forms::selection_range month_calendar::selection_range() const {
  return {data_->selection_start, data_->selection_end};
}

month_calendar& month_calendar::selection_range(const forms::selection_range& value) {
  data_->selection_start = value.start();
  data_->selection_end = value.end();
  return *this;
}

forms::create_params month_calendar::create_params() const {
  forms::create_params create_params = control::create_params();
  create_params.class_name("monthcalendar");
  return create_params;
}

void month_calendar::on_date_changed(const event_args& e) {
  if (can_raise_events()) date_changed(*this, e);
}

void month_calendar::on_date_selected(const event_args& e) {
  if (can_raise_events()) date_selected(*this, e);
}

void month_calendar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::month_calendar::allowable_dates(handle(), data_->min_date, data_->max_date);
  native::month_calendar::selection_range(handle(), data_->selection_start, data_->selection_end);
}

void month_calendar::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_NOTIFY: wm_notify(message); break;
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_XBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_XBUTTONUP:
    case WM_LBUTTONDBLCLK:
    case WM_MBUTTONDBLCLK:
    case WM_RBUTTONDBLCLK:
    case WM_XBUTTONDBLCLK: def_wnd_proc(message); break; // Mouse events are not supported
    default: control::wnd_proc(message);
  }
}

void month_calendar::wm_notify(message& message) {
  NMHDR* nmhdr = reinterpret_cast<NMHDR*>(message.lparam());
  switch (nmhdr->code) {
    case MCN_SELECT: wm_date_selected(message); break;
    case MCN_SELCHANGE: wm_date_changed(message); break;
    case MCN_VIEWCHANGE: wm_view_changed(message); break;
    default: break;
  }
}

void month_calendar::wm_date_selected(message& message) {
  auto selection_range = native::month_calendar::selection_range(handle());
  data_->selection_start = selection_range.first;
  data_->selection_end = selection_range.second;
  on_date_selected(event_args::empty);
}

void month_calendar::wm_date_changed(message& message) {
  auto selection_range = native::month_calendar::selection_range(handle());
  data_->selection_start = selection_range.first;
  data_->selection_end = selection_range.second;
  on_date_changed(event_args::empty);
}

void month_calendar::wm_view_changed(message& message) {
  // Do something or not if view changed
}
