#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/tab_page.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_page.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/convert_string.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void tab_page::image_index(intptr_t control, size_t image_index) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  auto page = static_cast<wxNotebookPage*>(reinterpret_cast<control_handler*>(control)->control());
  auto note_book = static_cast<wxNotebookBase*>(page->GetParent());
  if (note_book && note_book->GetImageList() && image_index < static_cast<size_t>(note_book->GetImageList()->GetImageCount())) note_book->SetPageImage(note_book->FindPage(page), static_cast<int>(image_index));
}

void tab_page::text(intptr_t control, const ustring& text) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  auto page = static_cast<wxNotebookPage*>(reinterpret_cast<control_handler*>(control)->control());
  auto note_book = static_cast<wxNotebookBase*>(page->GetParent());
  if (note_book) note_book->SetPageText(note_book->FindPage(page), convert_string::to_wstring(text));
}
