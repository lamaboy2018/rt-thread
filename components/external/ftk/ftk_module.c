#include <rtthread.h>
#include <rtm.h>

#include "ftk.h"
#include "ftk_log.h"
#include "ftk_util.h"
#include "ftk_xul.h"
#include "ftk_expr.h"
#include "ftk_pipe.h"
#include "ftk_tab.h"
#include "ftk_mmap.h"
#include "ftk_app_demo.h"
#include "ftk_message_box.h"
#include "ftk_animator_expand.h"
#include "ftk_animator_zoom.h"
#include "ftk_animator_alpha.h"
#include "ftk_file_browser.h"
#include "ftk_text_buffer.h"
#include "ftk_xml_parser.h"
#include "Ftk_text_buffer.h"
#include "ftk_font_default.h"
#include "ftk_lookup_table.h"
#include "ftk_display_mem.h"
#include "ftk_display_rotate.h"
#include "ftk_source_primary.h"
#include "ftk_allocator_default.h"
#include "ftk_input_method_py.h"
#include "ftk_input_method_util.h"
#include "ftk_image_bmp_decoder.h"
#include "ftk_image_png_decoder.h"
#include "ftk_image_jpeg_decoder.h"

RTM_EXPORT(ftk_deinit)
RTM_EXPORT(ftk_init)
RTM_EXPORT(ftk_run)
RTM_EXPORT(ftk_quit)
RTM_EXPORT(ftk_allocator_alloc)
RTM_EXPORT(ftk_allocator_realloc)
RTM_EXPORT(ftk_allocator_free)
RTM_EXPORT(ftk_allocator_destroy)
RTM_EXPORT(ftk_allocator_zalloc)
RTM_EXPORT(ftk_allocator_zfree)
RTM_EXPORT(ftk_strdup)
RTM_EXPORT(ftk_allocator_default_create)
RTM_EXPORT(ftk_animator_expand_create)
RTM_EXPORT(ftk_app_window_create)
RTM_EXPORT(ftk_app_window_set_on_prepare_options_menu)
RTM_EXPORT(ftk_bitmap_create)
RTM_EXPORT(ftk_bitmap_width)
RTM_EXPORT(ftk_bitmap_height)
RTM_EXPORT(ftk_bitmap_bits)
RTM_EXPORT(ftk_bitmap_ref)
RTM_EXPORT(ftk_bitmap_unref)
RTM_EXPORT(ftk_bitmap_copy_from_bitmap)
RTM_EXPORT(ftk_bitmap_copy_from_data_bgr24)
RTM_EXPORT(ftk_bitmap_copy_to_data_bgr24)
RTM_EXPORT(ftk_bitmap_copy_from_data_bgra32)
RTM_EXPORT(ftk_bitmap_copy_to_data_bgra32)
RTM_EXPORT(ftk_bitmap_copy_from_data_rgb565)
RTM_EXPORT(ftk_bitmap_copy_to_data_rgb565)
RTM_EXPORT(ftk_bitmap_copy_from_data_argb32)
RTM_EXPORT(ftk_bitmap_copy_to_data_argb32)
RTM_EXPORT(ftk_bitmap_copy_from_data_rgba32)
RTM_EXPORT(ftk_bitmap_copy_to_data_rgba32)
RTM_EXPORT(ftk_bitmap_factory_create)
RTM_EXPORT(ftk_bitmap_factory_load)
RTM_EXPORT(ftk_bitmap_factory_add_decoder)
RTM_EXPORT(ftk_bitmap_factory_destroy)
RTM_EXPORT(ftk_button_create)
RTM_EXPORT(ftk_button_set_clicked_listener)
RTM_EXPORT(ftk_canvas_create)
RTM_EXPORT(ftk_canvas_reset_gc)
RTM_EXPORT(ftk_canvas_set_gc)
RTM_EXPORT(ftk_canvas_get_gc)
RTM_EXPORT(ftk_canvas_put_pixel)
RTM_EXPORT(ftk_canvas_get_pixel)
RTM_EXPORT(ftk_canvas_draw_vline)
RTM_EXPORT(ftk_canvas_draw_hline)
RTM_EXPORT(ftk_canvas_fast_fill_rect)
RTM_EXPORT(ftk_canvas_draw_rect)
RTM_EXPORT(ftk_canvas_draw_round_rect)
RTM_EXPORT(ftk_canvas_draw_string_ex)
RTM_EXPORT(ftk_canvas_draw_string)
RTM_EXPORT(ftk_canvas_draw_bitmap_zoom)
RTM_EXPORT(ftk_canvas_draw_bitmap)
RTM_EXPORT(ftk_canvas_bitmap)
RTM_EXPORT(ftk_canvas_font_height)
RTM_EXPORT(ftk_canvas_get_extent)
RTM_EXPORT(ftk_canvas_get_char_extent)
RTM_EXPORT(ftk_canvas_calc_str_visible_range)
RTM_EXPORT(ftk_canvas_destroy)
RTM_EXPORT(ftk_canvas_draw_bg_image)
RTM_EXPORT(ftk_check_button_create)
RTM_EXPORT(ftk_check_button_create_radio)
RTM_EXPORT(ftk_check_button_get_checked)
RTM_EXPORT(ftk_check_button_set_icon_position)
RTM_EXPORT(ftk_check_button_set_checked)
RTM_EXPORT(ftk_check_button_set_clicked_listener)
RTM_EXPORT(ftk_config_create)
RTM_EXPORT(ftk_config_load)
RTM_EXPORT(ftk_config_init)
RTM_EXPORT(ftk_config_parse)
RTM_EXPORT(ftk_config_get_theme)
RTM_EXPORT(ftk_config_get_data_dir)
RTM_EXPORT(ftk_config_get_test_data_dir)
RTM_EXPORT(ftk_config_get_rotate)
RTM_EXPORT(ftk_config_get_data_root_dir)
RTM_EXPORT(ftk_config_get_enable_cursor)
RTM_EXPORT(ftk_config_get_enable_status_bar)
RTM_EXPORT(ftk_config_set_theme)
RTM_EXPORT(ftk_config_set_data_dir)
RTM_EXPORT(ftk_config_set_test_data_dir)
RTM_EXPORT(ftk_config_set_enable_cursor)
RTM_EXPORT(ftk_config_set_enable_status_bar)
RTM_EXPORT(ftk_config_destroy)
RTM_EXPORT(ftk_dialog_set_icon)
RTM_EXPORT(ftk_dialog_hide_title)
RTM_EXPORT(ftk_dialog_create_ex)
RTM_EXPORT(ftk_dialog_create)
RTM_EXPORT(ftk_dialog_quit)
RTM_EXPORT(ftk_dialog_quit_after)
RTM_EXPORT(ftk_dialog_run)
RTM_EXPORT(ftk_display_reg_update_listener)
RTM_EXPORT(ftk_display_unreg_update_listener)
RTM_EXPORT(ftk_display_notify)
RTM_EXPORT(ftk_display_mem_create)
RTM_EXPORT(ftk_display_mem_set_sync_func)
RTM_EXPORT(ftk_display_mem_is_active)
RTM_EXPORT(ftk_display_mem_get_pixel_format)
RTM_EXPORT(ftk_display_mem_update_directly)
RTM_EXPORT(ftk_display_set_rotate)
RTM_EXPORT(ftk_display_get_rotate)
RTM_EXPORT(ftk_display_get_real_display)
RTM_EXPORT(ftk_display_rotate_create)
RTM_EXPORT(ftk_entry_create)
RTM_EXPORT(ftk_entry_set_text)
RTM_EXPORT(ftk_entry_set_tips)
RTM_EXPORT(ftk_entry_set_input_type)
RTM_EXPORT(ftk_entry_insert_text)
RTM_EXPORT(ftk_entry_get_text)
RTM_EXPORT(ftk_expr_eval)
RTM_EXPORT(ftk_font_get_char_extent)
RTM_EXPORT(ftk_font_get_extent)
RTM_EXPORT(ftk_font_calc_str_visible_range)
RTM_EXPORT(ftk_font_default_create)
RTM_EXPORT(ftk_default_font)
RTM_EXPORT(ftk_default_display)
RTM_EXPORT(ftk_shared_canvas)
RTM_EXPORT(ftk_default_theme)
RTM_EXPORT(ftk_primary_source)
RTM_EXPORT(ftk_default_config)
RTM_EXPORT(ftk_default_allocator)
RTM_EXPORT(ftk_default_text_layout)
RTM_EXPORT(ftk_default_input_method_preeditor)
RTM_EXPORT(ftk_default_input_method_manager)
RTM_EXPORT(ftk_default_main_loop)
RTM_EXPORT(ftk_default_log_level)
RTM_EXPORT(ftk_default_wnd_manager)
RTM_EXPORT(ftk_default_status_panel)
RTM_EXPORT(ftk_default_bitmap_factory)
RTM_EXPORT(ftk_default_sources_manager)
RTM_EXPORT(ftk_set_font)
RTM_EXPORT(ftk_set_display)
RTM_EXPORT(ftk_set_main_loop)
RTM_EXPORT(ftk_set_log_level)
RTM_EXPORT(ftk_set_status_panel)
RTM_EXPORT(ftk_set_wnd_manager)
RTM_EXPORT(ftk_set_bitmap_factory)
RTM_EXPORT(ftk_set_sources_manager)
RTM_EXPORT(ftk_set_shared_canvas)
RTM_EXPORT(ftk_set_theme)
RTM_EXPORT(ftk_set_primary_source)
RTM_EXPORT(ftk_set_config)
RTM_EXPORT(ftk_set_allocator)
RTM_EXPORT(ftk_set_text_layout)
RTM_EXPORT(ftk_set_input_method_preeditor)
RTM_EXPORT(ftk_set_input_method_manager)
RTM_EXPORT(ftk_icon_cache_create)
RTM_EXPORT(ftk_icon_cache_load)
RTM_EXPORT(ftk_icon_cache_destroy)
RTM_EXPORT(ftk_icon_view_create)
RTM_EXPORT(ftk_icon_view_set_clicked_listener)
RTM_EXPORT(ftk_icon_view_set_item_size)
RTM_EXPORT(ftk_icon_view_get_count)
RTM_EXPORT(ftk_icon_view_remove)
RTM_EXPORT(ftk_icon_view_add)
RTM_EXPORT(ftk_icon_view_get)
RTM_EXPORT(ftk_image_create)
RTM_EXPORT(ftk_image_set_image)
RTM_EXPORT(ftk_image_bmp_decoder_create)
RTM_EXPORT(ftk_image_png_decoder_create)
RTM_EXPORT(ftk_image_jpeg_decoder_create)
RTM_EXPORT(ftk_input_method_manager_create)
RTM_EXPORT(ftk_input_method_manager_count)
RTM_EXPORT(ftk_input_method_manager_get)
RTM_EXPORT(ftk_input_method_manager_get_current)
RTM_EXPORT(ftk_input_method_manager_set_current)
RTM_EXPORT(ftk_input_method_manager_set_current_type)
RTM_EXPORT(ftk_input_method_manager_register)
RTM_EXPORT(ftk_input_method_manager_unregister)
RTM_EXPORT(ftk_input_method_manager_destroy)
RTM_EXPORT(ftk_input_method_manager_focus_in)
RTM_EXPORT(ftk_input_method_manager_focus_out)
RTM_EXPORT(ftk_input_method_manager_focus_ack_commit)
RTM_EXPORT(ftk_im_show_preeditor)
RTM_EXPORT(ftk_label_create)
RTM_EXPORT(ftk_label_set_alignment)
RTM_EXPORT(ftk_list_model_default_create)
RTM_EXPORT(ftk_list_render_default_create)
RTM_EXPORT(ftk_list_render_default_set_marquee_attr)
RTM_EXPORT(ftk_list_view_set_cursor)
RTM_EXPORT(ftk_list_view_repaint_focus_item)
RTM_EXPORT(ftk_list_view_create)
RTM_EXPORT(ftk_list_view_init)
RTM_EXPORT(ftk_list_view_get_selected)
RTM_EXPORT(ftk_list_view_get_model)
RTM_EXPORT(ftk_list_view_set_clicked_listener)
RTM_EXPORT(ftk_logv)
RTM_EXPORT(ftk_logd)
RTM_EXPORT(ftk_loge)
RTM_EXPORT(ftk_main_loop_add_source)
RTM_EXPORT(ftk_main_loop_remove_source)
RTM_EXPORT(ftk_menu_item_create)
RTM_EXPORT(ftk_menu_item_set_clicked_listener)
RTM_EXPORT(ftk_menu_panel_relayout)
RTM_EXPORT(ftk_menu_panel_create)
RTM_EXPORT(ftk_menu_panel_add)
RTM_EXPORT(ftk_menu_panel_remove)
RTM_EXPORT(ftk_progress_bar_create)
RTM_EXPORT(ftk_progress_bar_set_percent)
RTM_EXPORT(ftk_progress_bar_get_percent)
RTM_EXPORT(ftk_progress_bar_set_interactive)
RTM_EXPORT(ftk_radio_group_create)
RTM_EXPORT(ftk_radio_group_set_checked)
RTM_EXPORT(ftk_scroll_bar_create)
RTM_EXPORT(ftk_scroll_bar_set_param)
RTM_EXPORT(ftk_scroll_bar_set_listener)
RTM_EXPORT(ftk_scroll_bar_get_value)
RTM_EXPORT(ftk_scroll_bar_get_max_value)
RTM_EXPORT(ftk_scroll_bar_inc)
RTM_EXPORT(ftk_scroll_bar_dec)
RTM_EXPORT(ftk_scroll_bar_pageup)
RTM_EXPORT(ftk_scroll_bar_pagedown)
RTM_EXPORT(ftk_scroll_bar_set_value)
RTM_EXPORT(ftk_sources_manager_create)
RTM_EXPORT(ftk_sources_manager_add)
RTM_EXPORT(ftk_sources_manager_remove)
RTM_EXPORT(ftk_sources_manager_get_count)
RTM_EXPORT(ftk_sources_manager_get)
RTM_EXPORT(ftk_sources_manager_need_refresh)
RTM_EXPORT(ftk_sources_manager_set_need_refresh)
RTM_EXPORT(ftk_sources_manager_destroy)
RTM_EXPORT(ftk_source_idle_create)
RTM_EXPORT(ftk_source_primary_create)
RTM_EXPORT(ftk_source_queue_event)
RTM_EXPORT(ftk_source_timer_reset)
RTM_EXPORT(ftk_source_timer_modify)
RTM_EXPORT(ftk_source_timer_create)
RTM_EXPORT(ftk_sprite_create)
RTM_EXPORT(ftk_sprite_set_icon)
RTM_EXPORT(ftk_sprite_show)
RTM_EXPORT(ftk_sprite_is_visible)
RTM_EXPORT(ftk_sprite_move)
RTM_EXPORT(ftk_sprite_get_x)
RTM_EXPORT(ftk_sprite_get_y)
RTM_EXPORT(ftk_sprite_set_move_listener)
RTM_EXPORT(ftk_sprite_destroy)
RTM_EXPORT(ftk_status_item_create)
RTM_EXPORT(ftk_status_item_set_position)
RTM_EXPORT(ftk_status_item_get_position)
RTM_EXPORT(ftk_status_item_set_clicked_listener)
RTM_EXPORT(ftk_status_panel_create)
RTM_EXPORT(ftk_status_panel_add)
RTM_EXPORT(ftk_status_panel_remove)
RTM_EXPORT(ftk_text_buffer_create)
RTM_EXPORT(ftk_text_buffer_insert)
RTM_EXPORT(ftk_text_buffer_delete)
RTM_EXPORT(ftk_text_buffer_delete_chars)
RTM_EXPORT(ftk_text_buffer_chars_bytes)
RTM_EXPORT(ftk_text_buffer_reset)
RTM_EXPORT(ftk_text_buffer_append_string)
RTM_EXPORT(ftk_text_buffer_destroy)
RTM_EXPORT(ftk_text_layout_create)
RTM_EXPORT(ftk_text_layout_set_font)
RTM_EXPORT(ftk_text_layout_set_width)
RTM_EXPORT(ftk_text_layout_set_text)
RTM_EXPORT(ftk_text_layout_set_wrap_mode)
RTM_EXPORT(ftk_text_layout_init)
RTM_EXPORT(ftk_text_layout_skip_to)
RTM_EXPORT(ftk_text_layout_get_visual_line)
RTM_EXPORT(ftk_text_layout_destroy)
RTM_EXPORT(ftk_theme_create)
RTM_EXPORT(ftk_theme_parse_data)
RTM_EXPORT(ftk_theme_parse_file)
RTM_EXPORT(ftk_theme_get_bg)
RTM_EXPORT(ftk_theme_load_image)
RTM_EXPORT(ftk_theme_get_bg_color)
RTM_EXPORT(ftk_theme_get_border_color)
RTM_EXPORT(ftk_theme_get_fg_color)
RTM_EXPORT(ftk_theme_destroy)
RTM_EXPORT(utf8_get_char)
RTM_EXPORT(utf8_get_prev_char)
RTM_EXPORT(utf8_count_char)
RTM_EXPORT(ftk_parse_color)
RTM_EXPORT(utf8_move_forward)
RTM_EXPORT(ftk_line_break)
RTM_EXPORT(ftk_str2bool)
RTM_EXPORT(ftk_strs_cat)
RTM_EXPORT(ftk_strtol)
RTM_EXPORT(ftk_atoi)
RTM_EXPORT(ftk_atof)
RTM_EXPORT(ftk_itoa)
RTM_EXPORT(ftk_ftoa)
RTM_EXPORT(ftk_wait_box_create)
RTM_EXPORT(ftk_wait_box_start_waiting)
RTM_EXPORT(ftk_wait_box_stop_waiting)
RTM_EXPORT(ftk_widget_init)
RTM_EXPORT(ftk_widget_type)
RTM_EXPORT(ftk_widget_top)
RTM_EXPORT(ftk_widget_left)
RTM_EXPORT(ftk_widget_top_abs)
RTM_EXPORT(ftk_widget_left_abs)
RTM_EXPORT(ftk_widget_top_in_window)
RTM_EXPORT(ftk_widget_left_in_window)
RTM_EXPORT(ftk_widget_width)
RTM_EXPORT(ftk_widget_height)
RTM_EXPORT(ftk_widget_is_insensitive)
RTM_EXPORT(ftk_widget_is_visible)
RTM_EXPORT(ftk_widget_is_focused)
RTM_EXPORT(ftk_widget_is_active)
RTM_EXPORT(ftk_widget_id)
RTM_EXPORT(ftk_widget_invalidate)
RTM_EXPORT(ftk_widget_get_wrap_mode)
RTM_EXPORT(ftk_widget_update)
RTM_EXPORT(ftk_widget_update_rect)
RTM_EXPORT(ftk_widget_canvas)
RTM_EXPORT(ftk_widget_has_attr)
RTM_EXPORT(ftk_widget_state)
RTM_EXPORT(ftk_widget_user_data)
RTM_EXPORT(ftk_widget_get_text)
RTM_EXPORT(ftk_widget_set_attr)
RTM_EXPORT(ftk_widget_unset_attr)
RTM_EXPORT(ftk_widget_set_user_data)
RTM_EXPORT(ftk_widget_move)
RTM_EXPORT(ftk_widget_resize)
RTM_EXPORT(ftk_widget_move_resize)
RTM_EXPORT(ftk_widget_set_type)
RTM_EXPORT(ftk_widget_set_insensitive)
RTM_EXPORT(ftk_widget_show)
RTM_EXPORT(ftk_widget_show_all)
RTM_EXPORT(ftk_widget_set_visible)
RTM_EXPORT(ftk_widget_set_focused)
RTM_EXPORT(ftk_widget_set_active)
RTM_EXPORT(ftk_widget_set_id)
RTM_EXPORT(ftk_widget_set_canvas)
RTM_EXPORT(ftk_widget_set_parent)
RTM_EXPORT(ftk_widget_append_child)
RTM_EXPORT(ftk_widget_append_sibling)
RTM_EXPORT(ftk_widget_remove_child)
RTM_EXPORT(ftk_widget_toplevel)
RTM_EXPORT(ftk_widget_parent)
RTM_EXPORT(ftk_widget_prev)
RTM_EXPORT(ftk_widget_next)
RTM_EXPORT(ftk_widget_child)
RTM_EXPORT(ftk_widget_last_child)
RTM_EXPORT(ftk_widget_lookup)
RTM_EXPORT(ftk_widget_paint)
RTM_EXPORT(ftk_widget_set_gc)
RTM_EXPORT(ftk_widget_reset_gc)
RTM_EXPORT(ftk_widget_set_text)
RTM_EXPORT(ftk_widget_set_event_listener)
RTM_EXPORT(ftk_widget_set_wrap_mode)
RTM_EXPORT(ftk_widget_get_gc)
RTM_EXPORT(ftk_widget_find_target)
RTM_EXPORT(ftk_widget_destroy)
RTM_EXPORT(ftk_widget_ref)
RTM_EXPORT(ftk_widget_unref)
RTM_EXPORT(ftk_widget_paint_self)
RTM_EXPORT(ftk_widget_ref_self)
RTM_EXPORT(ftk_widget_unref_self)
RTM_EXPORT(ftk_widget_event)
RTM_EXPORT(ftk_window_set_focus)
RTM_EXPORT(ftk_window_get_focus)
RTM_EXPORT(ftk_window_grab)
RTM_EXPORT(ftk_window_ungrab)
RTM_EXPORT(ftk_window_update)
RTM_EXPORT(ftk_window_paint_forcely)
RTM_EXPORT(ftk_window_set_fullscreen)
RTM_EXPORT(ftk_window_is_fullscreen)
RTM_EXPORT(ftk_window_invalidate)
RTM_EXPORT(ftk_window_create)
RTM_EXPORT(ftk_window_disable_update)
RTM_EXPORT(ftk_window_enable_update)
RTM_EXPORT(ftk_window_set_background_with_alpha)
RTM_EXPORT(ftk_wnd_manager_set_rotate)
RTM_EXPORT(ftk_wnd_manager_queue_event_auto_rotate)
RTM_EXPORT(ftk_xml_parser_create)
RTM_EXPORT(ftk_xml_parser_set_builder)
RTM_EXPORT(ftk_xml_parser_parse)
RTM_EXPORT(ftk_xml_parser_destroy)
RTM_EXPORT(ftk_xul_load_ex)
RTM_EXPORT(ftk_xul_load)
RTM_EXPORT(ftk_xul_load_file)
RTM_EXPORT(ftk_input_method_py_create)
RTM_EXPORT(ftk_input_method_wb_create)
RTM_EXPORT(ftk_im_candidate_info_parse)
RTM_EXPORT(ftk_lookup_table_create)
RTM_EXPORT(ftk_lookup_table_load)
RTM_EXPORT(ftk_lookup_table_unload)
RTM_EXPORT(ftk_lookup_table_lookup)
RTM_EXPORT(ftk_lookup_table_destroy)
RTM_EXPORT(ftk_mmap_exist)
RTM_EXPORT(ftk_mmap_create)
RTM_EXPORT(ftk_mmap_data)
RTM_EXPORT(ftk_mmap_length)
RTM_EXPORT(ftk_mmap_destroy)
RTM_EXPORT(ftk_pipe_create)
RTM_EXPORT(ftk_pipe_destroy)
RTM_EXPORT(ftk_pipe_get_read_handle)
RTM_EXPORT(ftk_pipe_get_write_handle)
RTM_EXPORT(ftk_pipe_read)
RTM_EXPORT(ftk_pipe_write)
RTM_EXPORT(ftk_pipe_check)
RTM_EXPORT(ftk_get_relative_time)
RTM_EXPORT(ftk_platform_init)
RTM_EXPORT(ftk_platform_deinit)
RTM_EXPORT(ftk_file_browser_load)
RTM_EXPORT(ftk_file_browser_set_path)
RTM_EXPORT(ftk_file_browser_create)
RTM_EXPORT(ftk_file_browser_set_filter)
RTM_EXPORT(ftk_file_browser_set_choosed_handler)
RTM_EXPORT(ftk_app_demo_create)
RTM_EXPORT(ftk_animator_alpha_create)
RTM_EXPORT(ftk_animator_zoom_create)
RTM_EXPORT(ftk_combo_box_append)
RTM_EXPORT(ftk_text_view_set_readonly)
RTM_EXPORT(ftk_text_view_create)
RTM_EXPORT(ftk_tab_set_active_page)
RTM_EXPORT(ftk_tab_create)
RTM_EXPORT(ftk_tab_add_page)
RTM_EXPORT(ftk_popup_menu_create)
RTM_EXPORT(ftk_popup_menu_add)
RTM_EXPORT(ftk_combo_box_create)
RTM_EXPORT(ftk_combo_box_set_text)
RTM_EXPORT(ftk_tips)
RTM_EXPORT(ftk_warning)
RTM_EXPORT(ftk_question)
RTM_EXPORT(ftk_infomation)

