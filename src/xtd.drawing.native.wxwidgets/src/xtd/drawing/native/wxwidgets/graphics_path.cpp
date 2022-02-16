#include <map>
#include <vector>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics_path.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/graphics.h>
#include <xtd/as.h>

using namespace std;
using namespace xtd::drawing::native;

intptr_t graphics_path::create() {
  toolkit::initialize(); // Must be first
  wxMemoryDC mdc;
  wxGraphicsContext* mgc = wxGraphicsContext::Create(mdc);
  return reinterpret_cast<intptr_t>(new wxGraphicsPath(mgc->CreatePath()));
}

void graphics_path::destroy(intptr_t handle) {
  delete reinterpret_cast<wxGraphicsPath*>(handle);
}

void graphics_path::add_arc(intptr_t handle, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  reinterpret_cast<wxGraphicsPath*>(handle)->AddArc(x, y, width, start_angle, start_angle + sweep_angle, true);
}

void graphics_path::add_bezier(intptr_t handle, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  // Not supported by wxWidgets 3.1.5...
}

void graphics_path::add_beziers(intptr_t handle, std::vector<std::pair<float, float>> points) {
  // Not supported by wxWidgets 3.1.5...
}

void graphics_path::add_closed_curve(intptr_t handle, std::vector<std::pair<float, float>> points, float tension) {
  // Not supported by wxWidgets 3.1.5...
}

void graphics_path::add_curve(intptr_t handle, std::vector<std::pair<float, float>> points, size_t offset, size_t number_of_segments, float tension) {
  // Not supported by wxWidgets 3.1.5...
}

void graphics_path::add_line(intptr_t handle, float x1, float y1, float x2, float y2) {
  reinterpret_cast<wxGraphicsPath*>(handle)->MoveToPoint(x1, y1);
  reinterpret_cast<wxGraphicsPath*>(handle)->AddLineToPoint(x2, y2);
}

void graphics_path::add_ellipse(intptr_t handle, float x, float y, float width, float height) {
  reinterpret_cast<wxGraphicsPath*>(handle)->AddEllipse(x, y, width, height);
}

void graphics_path::add_path(intptr_t handle, intptr_t path, bool connect) {
  if (connect) {
    auto point = reinterpret_cast<wxGraphicsPath*>(handle)->GetCurrentPoint();
    reinterpret_cast<wxGraphicsPath*>(path)->AddLineToPoint(point.m_x, point.m_x);
  }
  reinterpret_cast<wxGraphicsPath*>(handle)->AddPath(*reinterpret_cast<wxGraphicsPath*>(path));
}

void graphics_path::add_pie(intptr_t handle, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  //reinterpret_cast<wxGraphicsPath*>(handle)->AddArc(x, y, width, start_angle, start_angle + sweep_angle, true);
}

void graphics_path::add_rectangle(intptr_t handle, float x, float y, float width, float height) {
  reinterpret_cast<wxGraphicsPath*>(handle)->AddRectangle(x, y, width, height);
}

void graphics_path::add_rounded_rectangle(intptr_t handle, float x, float y, float width, float height, float radius) {
  reinterpret_cast<wxGraphicsPath*>(handle)->AddRoundedRectangle(x, y, width, height, radius);
}

void graphics_path::add_string(intptr_t handle, const xtd::ustring& text, intptr_t font, float x, float y) {
  
}

void graphics_path::add_string(intptr_t handle, const xtd::ustring& text, intptr_t font, float x, float y, float w, float h) {
  
}

void graphics_path::close_all_figures(intptr_t handle) {
  
}

void graphics_path::close_figure(intptr_t handle) {
  
}

void graphics_path::flatten(intptr_t handle) {
  
}

void graphics_path::reverse(intptr_t handle) {
  
}

void graphics_path::start_figure(intptr_t handle) {
  
}

void graphics_path::get_bounds(intptr_t handle, float& x, float& y, float& width, float& height) {
  double wx_x, wx_y, wx_width, wx_height;
  reinterpret_cast<wxGraphicsPath*>(handle)->GetBox(&wx_x, &wx_y, &wx_width, &wx_height);
  x = as<float>(wx_x);
  y = as<float>(wx_y);
  width = as<float>(wx_width);
  height = as<float>(wx_height);
}

void graphics_path::get_last_point(intptr_t handle, float& x, float& y) {
  auto point = reinterpret_cast<wxGraphicsPath*>(handle)->GetCurrentPoint();
  x = static_cast<float>(point.m_x);
  y = static_cast<float>(point.m_y);
}

bool graphics_path::is_vsible(intptr_t handle, float x, float y) {
  return reinterpret_cast<wxGraphicsPath*>(handle)->Contains(x, y);
}
