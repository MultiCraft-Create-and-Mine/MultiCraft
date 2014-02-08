/*
Minetest
Copyright (C) 2013 celeron55, Perttu Ahola <celeron55@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "settings.h"
#include "filesys.h"
#include "config.h"

void set_default_settings(Settings *settings)
{
	// Client and server

	settings->setDefault("name", "");

	// Client stuff
	settings->setDefault("remote_port", "30000");
	settings->setDefault("keymap_forward", "KEY_KEY_W");
	settings->setDefault("keymap_backward", "KEY_KEY_S");
	settings->setDefault("keymap_left", "KEY_KEY_A");
	settings->setDefault("keymap_right", "KEY_KEY_D");
	settings->setDefault("keymap_jump", "KEY_SPACE");
	settings->setDefault("keymap_sneak", "KEY_LSHIFT");
	settings->setDefault("keymap_drop", "KEY_KEY_Q");
	settings->setDefault("keymap_inventory", "KEY_KEY_I");
	settings->setDefault("keymap_special1", "KEY_KEY_E");
	settings->setDefault("keymap_chat", "KEY_KEY_T");
	settings->setDefault("keymap_cmd", "/");
	settings->setDefault("keymap_console", "KEY_F10");
	settings->setDefault("keymap_rangeselect", "KEY_KEY_R");
	settings->setDefault("keymap_freemove", "KEY_KEY_K");
	settings->setDefault("keymap_fastmove", "KEY_KEY_J");
	settings->setDefault("keymap_noclip", "KEY_KEY_H");
	settings->setDefault("keymap_screenshot", "KEY_F12");
	settings->setDefault("keymap_toggle_hud", "KEY_F1");
	settings->setDefault("keymap_toggle_chat", "KEY_F2");
	settings->setDefault("keymap_toggle_force_fog_off", "KEY_F3");
	settings->setDefault("keymap_toggle_update_camera", "KEY_F4");
	settings->setDefault("keymap_toggle_debug", "KEY_F5");
	settings->setDefault("keymap_toggle_profiler", "KEY_F6");
	settings->setDefault("keymap_increase_viewing_range_min", "+");
	settings->setDefault("keymap_decrease_viewing_range_min", "-");
	settings->setDefault("anaglyph", "false");
	settings->setDefault("anaglyph_strength", "0.1");
	settings->setDefault("aux1_descends", "false");
	settings->setDefault("doubletap_jump", "false");
	settings->setDefault("always_fly_fast", "true");
	settings->setDefault("directional_colored_fog", "true");

	// Some (temporary) keys for debugging
	settings->setDefault("keymap_print_debug_stacks", "KEY_KEY_P");
	settings->setDefault("keymap_quicktune_prev", "KEY_HOME");
	settings->setDefault("keymap_quicktune_next", "KEY_END");
	settings->setDefault("keymap_quicktune_dec", "KEY_NEXT");
	settings->setDefault("keymap_quicktune_inc", "KEY_PRIOR");

	// Show debug info by default?
	#ifdef NDEBUG
	settings->setDefault("show_debug", "false");
	#else
	settings->setDefault("show_debug", "true");
	#endif

	settings->setDefault("wanted_fps", "30");
	settings->setDefault("fps_max", "60");
	settings->setDefault("pause_fps_max", "20");
	// A bit more than the server will send around the player, to make fog blend well
	settings->setDefault("viewing_range_nodes_max", "240");
	settings->setDefault("viewing_range_nodes_min", "35");
	settings->setDefault("screenW", "800");
	settings->setDefault("screenH", "600");
	settings->setDefault("fullscreen", "false");
	settings->setDefault("fullscreen_bpp", "24");
	settings->setDefault("fsaa", "0");
	settings->setDefault("vsync", "false");
	settings->setDefault("address", "");
	settings->setDefault("random_input", "false");
	settings->setDefault("client_unload_unused_data_timeout", "600");
	settings->setDefault("enable_fog", "true");
	settings->setDefault("fov", "72");
	settings->setDefault("view_bobbing", "true");
	settings->setDefault("new_style_water", "false");
	settings->setDefault("new_style_leaves", "true");
	settings->setDefault("smooth_lighting", "true");
	settings->setDefault("texture_path", "");
	settings->setDefault("shader_path", "");
	settings->setDefault("video_driver", "opengl");
	settings->setDefault("free_move", "false");
	settings->setDefault("noclip", "false");
	settings->setDefault("continuous_forward", "false");
	settings->setDefault("fast_move", "false");
	settings->setDefault("invert_mouse", "false");
	settings->setDefault("enable_clouds", "true");
	settings->setDefault("screenshot_path", ".");
	settings->setDefault("view_bobbing_amount", "1.0");
	settings->setDefault("fall_bobbing_amount", "0.0");
	settings->setDefault("enable_3d_clouds", "true");
	settings->setDefault("cloud_height", "120");
	settings->setDefault("menu_clouds", "true");
	settings->setDefault("opaque_water", "false");
	settings->setDefault("console_color", "(0,0,0)");
	settings->setDefault("console_alpha", "200");
	settings->setDefault("selectionbox_color", "(0,0,0)");
	settings->setDefault("crosshair_color", "(255,255,255)");
	settings->setDefault("crosshair_alpha", "255");
	settings->setDefault("mouse_sensitivity", "0.2");
	settings->setDefault("enable_sound", "true");
	settings->setDefault("sound_volume", "0.8");
	settings->setDefault("desynchronize_mapblock_texture_animation", "true");

	settings->setDefault("mip_map", "false");
	settings->setDefault("anisotropic_filter", "false");
	settings->setDefault("bilinear_filter", "false");
	settings->setDefault("trilinear_filter", "false");
	settings->setDefault("preload_item_visuals", "true");
	settings->setDefault("enable_bumpmapping", "false");
	settings->setDefault("enable_parallax_occlusion", "false");
	settings->setDefault("parallax_occlusion_scale", "0.08");
	settings->setDefault("parallax_occlusion_bias", "0.04");
	settings->setDefault("enable_waving_water", "false");
	settings->setDefault("water_wave_height", "1.0");
	settings->setDefault("water_wave_length", "20.0");
	settings->setDefault("water_wave_speed", "5.0");
	settings->setDefault("enable_waving_leaves", "false");
	settings->setDefault("enable_waving_plants", "false");
	settings->setDefault("enable_shaders", "true");
	settings->setDefault("repeat_rightclick_time", "0.25");
	settings->setDefault("enable_particles", "true");

	settings->setDefault("curl_timeout", "5000");
	settings->setDefault("curl_parallel_limit", "8");

	settings->setDefault("serverlist_url", "servers.minetest.net");
	settings->setDefault("serverlist_file", "favoriteservers.txt");
	settings->setDefault("server_announce", "false");
	settings->setDefault("server_url", "");
	settings->setDefault("server_address", "");
	settings->setDefault("server_name", "");
	settings->setDefault("server_description", "");

#if USE_FREETYPE
	settings->setDefault("freetype", "true");
	settings->setDefault("font_path", porting::getDataPath("fonts" DIR_DELIM "liberationsans.ttf"));
	settings->setDefault("font_size", "13");
	settings->setDefault("font_shadow", "1");
	settings->setDefault("font_shadow_alpha", "128");
	settings->setDefault("mono_font_path", porting::getDataPath("fonts" DIR_DELIM "liberationmono.ttf"));
	settings->setDefault("mono_font_size", "13");
	settings->setDefault("fallback_font_path", porting::getDataPath("fonts" DIR_DELIM "DroidSansFallbackFull.ttf"));
	settings->setDefault("fallback_font_size", "13");
	settings->setDefault("fallback_font_shadow", "1");
	settings->setDefault("fallback_font_shadow_alpha", "128");
#else
	settings->setDefault("freetype", "false");
	settings->setDefault("font_path", porting::getDataPath("fonts" DIR_DELIM "fontlucida.png"));
	settings->setDefault("mono_font_path", porting::getDataPath("fonts" DIR_DELIM "fontdejavusansmono.png"));
#endif

	// Server stuff
	// "map-dir" doesn't exist by default.
	settings->setDefault("workaround_window_size","5");
	settings->setDefault("max_packets_per_iteration","1024");
	settings->setDefault("port", "30000");
	settings->setDefault("bind_address","");
	settings->setDefault("default_game", "minetest");
	settings->setDefault("motd", "");
	settings->setDefault("max_users", "15");
	settings->setDefault("strict_protocol_version_checking", "false");
	settings->setDefault("creative_mode", "false");
	settings->setDefault("enable_damage", "true");
	settings->setDefault("only_peaceful_mobs", "false");
	settings->setDefault("fixed_map_seed", "");
	settings->setDefault("give_initial_stuff", "false");
	settings->setDefault("default_password", "");
	settings->setDefault("default_privs", "interact, shout");
	settings->setDefault("unlimited_player_transfer_distance", "true");
	settings->setDefault("enable_pvp", "true");
	settings->setDefault("disallow_empty_password", "false");
	settings->setDefault("disable_anticheat", "false");
	settings->setDefault("enable_rollback_recording", "false");

	settings->setDefault("profiler_print_interval", "0");
	settings->setDefault("enable_mapgen_debug_info", "false");
	settings->setDefault("active_object_send_range_blocks", "3");
	settings->setDefault("active_block_range", "2");
	//settings->setDefault("max_simultaneous_block_sends_per_client", "1");
	// This causes frametime jitter on client side, or does it?
	settings->setDefault("max_simultaneous_block_sends_per_client", "4");
	settings->setDefault("max_simultaneous_block_sends_server_total", "20");
	settings->setDefault("max_block_send_distance", "9");
	settings->setDefault("max_block_generate_distance", "7");
	settings->setDefault("max_clearobjects_extra_loaded_blocks", "4096");
	settings->setDefault("time_send_interval", "5");
	settings->setDefault("time_speed", "72");
	settings->setDefault("year_days", "30");
	settings->setDefault("server_unload_unused_data_timeout", "29");
	settings->setDefault("max_objects_per_block", "49");
	settings->setDefault("server_map_save_interval", "5.3");
	settings->setDefault("sqlite_synchronous", "2");
	settings->setDefault("full_block_send_enable_min_time_from_building", "2.0");
	settings->setDefault("dedicated_server_step", "0.1");
	settings->setDefault("ignore_world_load_errors", "false");
	settings->setDefault("congestion_control_aim_rtt", "0.2");
	settings->setDefault("congestion_control_max_rate", "400");
	settings->setDefault("congestion_control_min_rate", "10");
	settings->setDefault("remote_media", "");
	settings->setDefault("debug_log_level", "2");
	settings->setDefault("emergequeue_limit_total", "256");
	settings->setDefault("num_emerge_threads", "1");
	
	// physics stuff
	settings->setDefault("movement_acceleration_default", "3");
	settings->setDefault("movement_acceleration_air", "2");
	settings->setDefault("movement_acceleration_fast", "10");
	settings->setDefault("movement_speed_walk", "4");
	settings->setDefault("movement_speed_crouch", "1.35");
	settings->setDefault("movement_speed_fast", "20");
	settings->setDefault("movement_speed_climb", "2");
	settings->setDefault("movement_speed_jump", "6.5");
	settings->setDefault("movement_liquid_fluidity", "1");
	settings->setDefault("movement_liquid_fluidity_smooth", "0.5");
	settings->setDefault("movement_liquid_sink", "10");
	settings->setDefault("movement_gravity", "9.81");

	//liquid stuff
	settings->setDefault("liquid_finite", "false");
	settings->setDefault("liquid_loop_max", "10000");
	settings->setDefault("liquid_update", "1.0");
	settings->setDefault("liquid_relax", "2");
	settings->setDefault("liquid_fast_flood", "1");
	settings->setDefault("underground_springs", "1");
	settings->setDefault("weather", "false");

	//mapgen stuff
	settings->setDefault("mg_name", "v6");
	settings->setDefault("water_level", "1");
	settings->setDefault("chunksize", "5");
	settings->setDefault("mg_flags", "");

	settings->setDefault("mgmath_generator", "mandelbox");


	// IPv6
	settings->setDefault("enable_ipv6", "true");
	settings->setDefault("ipv6_server", "false");

	settings->setDefault("main_menu_script","");
	settings->setDefault("main_menu_mod_mgr","1");
	settings->setDefault("main_menu_game_mgr","0");
	settings->setDefault("modstore_download_url", "https://forum.minetest.net/media/");
	settings->setDefault("modstore_listmods_url", "https://forum.minetest.net/mmdb/mods/");
	settings->setDefault("modstore_details_url", "https://forum.minetest.net/mmdb/mod/*/");

	settings->setDefault("high_precision_fpu", "true");

	settings->setDefault("language", "");
}

void override_default_settings(Settings *settings, Settings *from)
{
	std::vector<std::string> names = from->getNames();
	for(size_t i=0; i<names.size(); i++){
		const std::string &name = names[i];
		settings->setDefault(name, from->get(name));
	}
}

