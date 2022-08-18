/// @file
/// @brief Contains  xtd.forms library headers.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include <xtd/xtd.core>
#include <xtd/xtd.drawing>
#include <xtd/forms/create_params.h>
#include <xtd/forms/window_messages.h>

#include "xtd/forms/about_box.h"
#include "xtd/forms/about_dialog.h"
#include "xtd/forms/anchor_styles.h"
#include "xtd/forms/animation_update_event_args.h"
#include "xtd/forms/animation_update_event_handler.h"
#include "xtd/forms/animation.h"
#include "xtd/forms/appearance.h"
#include "xtd/forms/application_context.h"
#include "xtd/forms/application.h"
#include "xtd/forms/arrange_direction.h"
#include "xtd/forms/arrange_starting_position.h"
#include "xtd/forms/auto_size_mode.h"
#include "xtd/forms/background_worker.h"
#include "xtd/forms/boot_mode.h"
#include "xtd/forms/border_sides.h"
#include "xtd/forms/border_style.h"
#include "xtd/forms/bounds_specified.h"
#include "xtd/forms/box_renderer.h"
#include "xtd/forms/busy_box.h"
#include "xtd/forms/busy_dialog.h"
#include "xtd/forms/button_base.h"
#include "xtd/forms/button_images.h"
#include "xtd/forms/button_renderer.h"
#include "xtd/forms/button_state.h"
#include "xtd/forms/button.h"
#include "xtd/forms/buttons.h"
#include "xtd/forms/cancel_event_args.h"
#include "xtd/forms/cancel_event_handler.h"
#include "xtd/forms/character_casing.h"
#include "xtd/forms/check_box_renderer.h"
#include "xtd/forms/check_box.h"
#include "xtd/forms/check_boxes.h"
#include "xtd/forms/check_state.h"
#include "xtd/forms/checked_list_box.h"
#include "xtd/forms/choice.h"
#include "xtd/forms/close_reason.h"
#include "xtd/forms/collapsible_panel.h"
#include "xtd/forms/color_box_styles.h"
#include "xtd/forms/color_box.h"
#include "xtd/forms/color_dialog.h"
#include "xtd/forms/color_picker.h"
#include "xtd/forms/combo_box_style.h"
#include "xtd/forms/combo_box.h"
#include "xtd/forms/command_link_button.h"
#include "xtd/forms/command_link_buttons.h"
#include "xtd/forms/common_dialog.h"
#include "xtd/forms/component.h"
#include "xtd/forms/container_control.h"
#include "xtd/forms/content_alignment.h"
#include "xtd/forms/context_menu.h"
#include "xtd/forms/control_appearance.h"
#include "xtd/forms/control_event_args.h"
#include "xtd/forms/control_event_handler.h"
#include "xtd/forms/control_layout_style.h"
#include "xtd/forms/control_paint.h"
#include "xtd/forms/control_ref.h"
#include "xtd/forms/control_renderer.h"
#include "xtd/forms/control_styles.h"
#include "xtd/forms/control_trace_listener.h"
#include "xtd/forms/control.h"
#include "xtd/forms/countries.h"
#include "xtd/forms/country.h"
#include "xtd/forms/cursor.h"
#include "xtd/forms/cursors.h"
#include "xtd/forms/date_range_event_args.h"
#include "xtd/forms/date_range_event_handler.h"
#include "xtd/forms/date_time_picker_format.h"
#include "xtd/forms/date_time_picker.h"
#include "xtd/forms/day.h"
#include "xtd/forms/debug_form.h"
#include "xtd/forms/debug_message_box.h"
#include "xtd/forms/dialog_closed_event_args.h"
#include "xtd/forms/dialog_closed_event_handler.h"
#include "xtd/forms/dialog_result.h"
#include "xtd/forms/dialog_style.h"
#include "xtd/forms/do_work_event_args.h"
#include "xtd/forms/do_work_event_handler.h"
#include "xtd/forms/dock_style.h"
#include "xtd/forms/domain_up_down.h"
#include "xtd/forms/dot_matrix_display.h"
#include "xtd/forms/dot_matrix_style.h"
#include "xtd/forms/draw_item_event_args.h"
#include "xtd/forms/draw_item_event_handler.h"
#include "xtd/forms/emoticon.h"
#include "xtd/forms/emoticons.h"
#include "xtd/forms/enable_debug.h"
#include "xtd/forms/exception_box.h"
#include "xtd/forms/exception_dialog.h"
#include "xtd/forms/file_dialog.h"
#include "xtd/forms/find_box.h"
#include "xtd/forms/find_dialog.h"
#include "xtd/forms/find_event_args.h"
#include "xtd/forms/find_event_handler.h"
#include "xtd/forms/fixed_layout_panel.h"
#include "xtd/forms/flat_button_appearance.h"
#include "xtd/forms/flat_style.h"
#include "xtd/forms/flow_layout_panel.h"
#include "xtd/forms/folder_browser_box.h"
#include "xtd/forms/folder_browser_dialog.h"
#include "xtd/forms/font_box_options.h"
#include "xtd/forms/font_box.h"
#include "xtd/forms/font_dialog.h"
#include "xtd/forms/font_picker.h"
#include "xtd/forms/form_border_style.h"
#include "xtd/forms/form_button_images.h"
#include "xtd/forms/form_closed_event_args.h"
#include "xtd/forms/form_closed_event_handler.h"
#include "xtd/forms/form_closing_event_args.h"
#include "xtd/forms/form_closing_event_handler.h"
#include "xtd/forms/form_renderer.h"
#include "xtd/forms/form_start_position.h"
#include "xtd/forms/form_window_state.h"
#include "xtd/forms/form.h"
#include "xtd/forms/fourteen_segment_display.h"
#include "xtd/forms/group_box.h"
#include "xtd/forms/h_scroll_bar.h"
#include "xtd/forms/help_event_args.h"
#include "xtd/forms/help_event_handler.h"
#include "xtd/forms/horizontal_alignment.h"
#include "xtd/forms/horizontal_control_layout_style_collection.h"
#include "xtd/forms/horizontal_control_layout_style.h"
#include "xtd/forms/horizontal_layout_panel.h"
#include "xtd/forms/ibutton_control.h"
#include "xtd/forms/icontrol_trace.h"
#include "xtd/forms/image_layout.h"
#include "xtd/forms/image_list.h"
#include "xtd/forms/image_renderer.h"
#include "xtd/forms/imessage_filter.h"
#include "xtd/forms/input_box_style.h"
#include "xtd/forms/input_box.h"
#include "xtd/forms/input_dialog.h"
#include "xtd/forms/item_check_event_args.h"
#include "xtd/forms/item_check_event_handler.h"
#include "xtd/forms/iwin32_window.h"
#include "xtd/forms/key_event_args.h"
#include "xtd/forms/key_event_handler.h"
#include "xtd/forms/key_press_event_args.h"
#include "xtd/forms/key_press_event_handler.h"
#include "xtd/forms/keys.h"
#include "xtd/forms/known_themed_color.h"
#include "xtd/forms/label_renderer.h"
#include "xtd/forms/label.h"
#include "xtd/forms/lcd_label.h"
#include "xtd/forms/lcd_style.h"
#include "xtd/forms/light_button.h"
#include "xtd/forms/light_buttons.h"
#include "xtd/forms/link_label_clicked_event_args.h"
#include "xtd/forms/link_label_clicked_event_handler.h"
#include "xtd/forms/link_label.h"
#include "xtd/forms/link.h"
#include "xtd/forms/list_box.h"
#include "xtd/forms/list_control.h"
#include "xtd/forms/loading_indicator_style.h"
#include "xtd/forms/loading_indicator.h"
#include "xtd/forms/main_menu.h"
#include "xtd/forms/menu_images.h"
#include "xtd/forms/menu_item_kind.h"
#include "xtd/forms/menu_item.h"
#include "xtd/forms/menu.h"
#include "xtd/forms/message_box_buttons.h"
#include "xtd/forms/message_box_default_button.h"
#include "xtd/forms/message_box_icon.h"
#include "xtd/forms/message_box_options.h"
#include "xtd/forms/message_box.h"
#include "xtd/forms/message_dialog_buttons.h"
#include "xtd/forms/message_dialog_default_button.h"
#include "xtd/forms/message_dialog_icon.h"
#include "xtd/forms/message_dialog_options.h"
#include "xtd/forms/message_dialog.h"
#include "xtd/forms/message_notifier.h"
#include "xtd/forms/message_loop_callback.h"
#include "xtd/forms/message.h"
#include "xtd/forms/month_calendar.h"
#include "xtd/forms/mouse_buttons.h"
#include "xtd/forms/mouse_event_args.h"
#include "xtd/forms/mouse_event_handler.h"
#include "xtd/forms/nine_segment_display.h"
#include "xtd/forms/notifier_style.h"
#include "xtd/forms/numeric_up_down.h"
#include "xtd/forms/open_file_box_options.h"
#include "xtd/forms/open_file_box.h"
#include "xtd/forms/open_file_dialog.h"
#include "xtd/forms/orientation.h"
#include "xtd/forms/padding.h"
#include "xtd/forms/paint_event_args.h"
#include "xtd/forms/paint_event_handler.h"
#include "xtd/forms/panel_renderer.h"
#include "xtd/forms/panel.h"
#include "xtd/forms/picture_box_size_mode.h"
#include "xtd/forms/picture_box.h"
#include "xtd/forms/popup_panel.h"
#include "xtd/forms/progress_bar_style.h"
#include "xtd/forms/progress_bar.h"
#include "xtd/forms/progress_box_options.h"
#include "xtd/forms/progress_box.h"
#include "xtd/forms/progress_changed_event_args.h"
#include "xtd/forms/progress_changed_event_handler.h"
#include "xtd/forms/progress_dialog.h"
#include "xtd/forms/radio_button_renderer.h"
#include "xtd/forms/radio_button.h"
#include "xtd/forms/radio_buttons.h"
#include "xtd/forms/renderer.h"
#include "xtd/forms/replace_box.h"
#include "xtd/forms/replace_dialog.h"
#include "xtd/forms/replace_event_args.h"
#include "xtd/forms/replace_event_handler.h"
#include "xtd/forms/run_worker_completed_event_args.h"
#include "xtd/forms/run_worker_completed_event_handler.h"
#include "xtd/forms/save_file_box_options.h"
#include "xtd/forms/save_file_box.h"
#include "xtd/forms/save_file_dialog.h"
#include "xtd/forms/screen.h"
#include "xtd/forms/scroll_bar.h"
#include "xtd/forms/scrollable_control.h"
#include "xtd/forms/search_direction.h"
#include "xtd/forms/segment_style.h"
#include "xtd/forms/segments.h"
#include "xtd/forms/selection_mode.h"
#include "xtd/forms/selection_range.h"
#include "xtd/forms/settings.h"
#include "xtd/forms/seven_segment_display.h"
#include "xtd/forms/shortcut.h"
#include "xtd/forms/sixteen_segment_display.h"
#include "xtd/forms/size_type.h"
#include "xtd/forms/split_container.h"
#include "xtd/forms/splitter_panel.h"
#include "xtd/forms/splitter_style.h"
#include "xtd/forms/splitter.h"
#include "xtd/forms/status_bar.h"
#include "xtd/forms/status_bar_draw_item_event_args.h"
#include "xtd/forms/status_bar_draw_item_event_handler.h"
#include "xtd/forms/status_bar_panel.h"
#include "xtd/forms/status_bar_panel_auto_size.h"
#include "xtd/forms/status_bar_panel_border_style.h"
#include "xtd/forms/status_bar_panel_click_event_args.h"
#include "xtd/forms/status_bar_panel_click_event_handler.h"
#include "xtd/forms/status_bar_panel_style.h"
#include "xtd/forms/switch_button_renderer.h"
#include "xtd/forms/switch_button.h"
#include "xtd/forms/system_information.h"
#include "xtd/forms/system_texts.h"
#include "xtd/forms/tab_alignment.h"
#include "xtd/forms/tab_control.h"
#include "xtd/forms/tab_page.h"
#include "xtd/forms/table_layout_panel.h"
#include "xtd/forms/text_box_base.h"
#include "xtd/forms/text_box.h"
#include "xtd/forms/text_format_flags.h"
#include "xtd/forms/text_renderer.h"
#include "xtd/forms/theme_base.h"
#include "xtd/forms/theme_images.h"
#include "xtd/forms/theme_renderers.h"
#include "xtd/forms/theme_style.h"
#include "xtd/forms/theme.h"
#include "xtd/forms/tick_style.h"
#include "xtd/forms/timer.h"
#include "xtd/forms/toggle_button_renderer.h"
#include "xtd/forms/toggle_button.h"
#include "xtd/forms/toggle_buttons.h"
#include "xtd/forms/tool_bar.h"
#include "xtd/forms/tool_bar_appearance.h"
#include "xtd/forms/tool_bar_button.h"
#include "xtd/forms/tool_bar_button_click_event_args.h"
#include "xtd/forms/tool_bar_button_click_event_handler.h"
#include "xtd/forms/tool_bar_button_style.h"
#include "xtd/forms/tool_bar_images.h"
#include "xtd/forms/tool_bar_renderer.h"
#include "xtd/forms/tool_bar_text_align.h"
#include "xtd/forms/trace_form_base.h"
#include "xtd/forms/trace_form.h"
#include "xtd/forms/trace_message_box.h"
#include "xtd/forms/track_bar.h"
#include "xtd/forms/up_down_base.h"
#include "xtd/forms/up_down_button.h"
#include "xtd/forms/use_wait_cursor.h"
#include "xtd/forms/user_control_renderer.h"
#include "xtd/forms/user_control.h"
#include "xtd/forms/v_scroll_bar.h"
#include "xtd/forms/vertical_control_layout_style_collection.h"
#include "xtd/forms/vertical_control_layout_style.h"
#include "xtd/forms/vertical_layout_panel.h"
#include "xtd/forms/layout/arranged_element_collection.h"
#include "xtd/forms/layout/sorter_none.h"
#include "xtd/forms/properties/resources.h"
#include "xtd/forms/style_sheets/background_image.h"
#include "xtd/forms/style_sheets/border_color.h"
#include "xtd/forms/style_sheets/border_radius.h"
#include "xtd/forms/style_sheets/border_style.h"
#include "xtd/forms/style_sheets/border_type.h"
#include "xtd/forms/style_sheets/border_width.h"
#include "xtd/forms/style_sheets/button.h"
#include "xtd/forms/style_sheets/control.h"
#include "xtd/forms/style_sheets/form.h"
#include "xtd/forms/style_sheets/ibox_model.h"
#include "xtd/forms/style_sheets/iimage_model.h"
#include "xtd/forms/style_sheets/image_type.h"
#include "xtd/forms/style_sheets/itext_model.h"
#include "xtd/forms/style_sheets/label.h"
#include "xtd/forms/style_sheets/length_unit.h"
#include "xtd/forms/style_sheets/length.h"
#include "xtd/forms/style_sheets/lengths.h"
#include "xtd/forms/style_sheets/margin.h"
#include "xtd/forms/style_sheets/outline_color.h"
#include "xtd/forms/style_sheets/outline_offset.h"
#include "xtd/forms/style_sheets/outline_radius.h"
#include "xtd/forms/style_sheets/outline_style.h"
#include "xtd/forms/style_sheets/outline_width.h"
#include "xtd/forms/style_sheets/padding.h"
#include "xtd/forms/style_sheets/panel.h"
#include "xtd/forms/style_sheets/pseudo_state.h"
#include "xtd/forms/style_sheets/style_sheet.h"
#include "xtd/forms/style_sheets/system_colors.h"
#include "xtd/forms/style_sheets/text_decoration.h"
#include "xtd/forms/style_sheets/text_transformation.h"
#include "xtd/forms/style_sheets/theme.h"
#include "xtd/forms/style_sheets/toggle_button.h"
#include "xtd/forms/style_sheets/tool_bar.h"
#include "xtd/forms/style_sheets/user_control.h"
#include "xtd/forms/visual_styles/check_box_state.h"
#include "xtd/forms/visual_styles/control_state.h"
#include "xtd/forms/visual_styles/panel_state.h"
#include "xtd/forms/visual_styles/form_state.h"
#include "xtd/forms/visual_styles/tool_bar_state.h"
#include "xtd/forms/visual_styles/label_state.h"
#include "xtd/forms/visual_styles/push_button_state.h"
#include "xtd/forms/visual_styles/radio_button_state.h"
#include "xtd/forms/visual_styles/toggle_button_state.h"
#include "xtd/forms/visual_styles/user_control_state.h"
