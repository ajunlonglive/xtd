#include <xtd/xtd>

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Buttons example", {100, 200}, {450, 200});
  auto actual_size_button = buttons::actual_size(*main_form, {10, 10}, {100, 25});
  auto zoom_in_button = buttons::zoom_in(*main_form, {120, 10}, {100, 25});
  auto zoom_out_button = buttons::zoom_out(*main_form, {230, 10}, {100, 25});
  auto zoom_to_fit_button = buttons::zoom_to_fit(*main_form, {340, 10}, {100, 25});
  application::run(*main_form);
}
