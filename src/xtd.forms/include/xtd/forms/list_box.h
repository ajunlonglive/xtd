/// @file
/// @brief Contains xtd::forms::list_box control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.h"
#include "border_style.h"
#include "list_control.h"
#include "selection_mode.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows list box.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of list_box control.
    /// @include list_box.cpp
    /// @par Windows
    /// @image html list_box_w.png
    /// <br>
    /// @image html list_box_wd.png
    /// @par macOS
    /// @image html list_box_m.png
    /// <br>
    /// @image html list_box_md.png
    /// @par Gnome
    /// @image html list_box_g.png
    /// <br>
    /// @image html list_box_gd.png
    class forms_export_ list_box : public list_control {
    public:      
      list_box();

      /// @brief Gets the type of border that is drawn around the list_box.
      /// @return One of the xtd::forms::border_styleforms::border_style values. The default is fixed_single.
      virtual forms::border_style border_style() const {return border_style_;}
      /// @brief Sets the type of border that is drawn around the list_box.
      /// @param border_style One of the xtd::forms::border_styleforms::border_style values. The default is fixed_single.
      virtual list_box& border_style(forms::border_style border_style);
      
      drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().window();}
      
      drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().window_text();}
      
      drawing::size default_size() const override {return {120, 96};}
      
      /// @brief Gets the items of the list_box.
      /// @return An list_boxlist_box::object_collection representing the items in the list_box.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the list_box. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      object_collection& items() {return items_;}
      /// @brief Gets the items of the list_box.
      /// @return An list_boxlist_box::object_collection representing the items in the list_box.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the list_box. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      const object_collection& items() const {return items_;}
      /// @brief Sets the items of the list_box.
      /// @return An list_boxlist_box::object_collection representing the items in the list_box.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the list_box. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      const list_box& items(const object_collection& items) {
        items_ = items;
        return *this;
      }
      
      using list_control::selected_index;
      list_control& selected_index(size_t selected_index) override;
      
      virtual std::vector<size_t> selected_indices() const;

      const item& selected_item() const {return selected_item_;}
      
      list_box& selected_item(const item& selected_item);
      
      std::vector<item> selected_items() const;
      
      virtual forms::selection_mode selection_mode() const {return selection_mode_;}

      virtual list_box& selection_mode(forms::selection_mode selection_mode);

      virtual bool sorted() const {return sorted_;}
      virtual list_box& sorted(bool sorted);
      
      using list_control::text;
      control& text(const std::string& text) override {return *this;}

      void begin_update();
      void end_update();
      
    protected:
      bool allow_selection() override {return selection_mode_ != forms::selection_mode::none;}

      forms::create_params create_params() const override;

      void on_handle_created(const event_args& e) override;

      void on_selected_value_changed(const event_args& e) override;

      void wnd_proc(message& message) override;
      
      virtual void wm_reflect_command(message& message);
      
      virtual void wm_mouse_double_click(message& message);

      virtual void wm_mouse_down(message& message);
      
      virtual void wm_mouse_up(message& message);
      
      forms::border_style border_style_ = forms::border_style::fixed_single;
      object_collection items_;
      item selected_item_;
      forms::selection_mode selection_mode_ = forms::selection_mode::one;
      bool sorted_ = false;
    };
  }
}
