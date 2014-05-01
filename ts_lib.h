#ifndef TS_LIB_H
#define TS_LIB_H

#include "ts_dll.h"
#include "ts_defs.h"
#include "ts_malloc.h"
#include "ts_lua.h"
#include "ts_log.h"
#include "ts_cfg.h"
#include "ts_ctr.h"
#include "ts_world.h"
#include "ts_gfx.h"
#include "ts_sfx.h"
#include "ts_font.h"
#include "ts_timer.h"
#include "ts_translator.h"
#include "ts_debug.h"
#include "ts_trans.h"
#include "ts_struct.h"

/*
	Function: ts_lib_open

Descripcion:
Esta funcion se encarga de añadir la estructura ts en el codigo en Lua cuando se
cargue la DLL de TSLib.
*/
//LUALIB_API EXPORT int luaopen_ts(lua_State *ls);
LUAMOD_API int luaopen_ts (lua_State *ls);

/*
	Function: ts_lib_init

Descripcion:
Inicia la libreria TSLib y todos los subsistemas. Debes llamar a esta funcion
antes que a cualquier otra de TSLib.

Parametros:
program_name - Nombre del programa que vamos a crear.
version_string - Cadena de caracteres con la version.

Devuelve:
TS_OK si todo ha ido bien, TS_ERROR si ha habido algun error.
*/
schar ts_lib_init(const char *name, const char *version);
EXPORT int tl_lib_init(TS_Lua *ls);

/*
	Function: ts_lib_quit

Descripcion:
Quita la libreria TSLib y todos los subsistemas, libera la memoria utilizada.
*/
schar ts_lib_quit(void);
EXPORT int tl_lib_quit(TS_Lua *ls);

/*
	Function: ts_lib_uses

Descripcion:
Devuelve cual es la biblioteca de funciones con la que se ha enlazado la version
que se esta utilizando de TSLib.

Devuelve:
TS_USES_SDL si usa SDL 1.2, TS_USES_AL5 si usa Allegro 5 o TS_USES_AL4 si usa Allegro 4.
*/
schar ts_lib_uses(void);
EXPORT int tl_lib_uses(TS_Lua *ls);

/*
	Constant: tslib_functions

Contiene la lista de las funciones que se pueden llamar desde un interprete de Lua.
El primer nombre en cada campo de la estructura es el nombre que usaremos desde Lua,
el segundo es un puntero a la funcion a la que se llamara.
*/
static const luaL_Reg tslib[] =
{
	{"lib_init",tl_lib_init},
	{"lib_quit",tl_lib_quit},
	{"lib_uses",tl_lib_uses},
	{"ctr_accept",tl_ctr_accept},
	{"ctr_action",tl_ctr_action},
	{"ctr_cancel",tl_ctr_cancel},
	{"ctr_clear",tl_ctr_clear},
	{"ctr_down",tl_ctr_down},
	{"ctr_get_key",tl_ctr_get_key},
	{"ctr_key",tl_ctr_key},
	{"ctr_left",tl_ctr_left},
	{"ctr_mouse_clicked",tl_ctr_mouse_clicked},
	{"ctr_mouse_get_x",tl_ctr_mouse_get_x},
	{"ctr_mouse_get_y",tl_ctr_mouse_get_y},
	{"ctr_mouse_hide",tl_ctr_mouse_hide},
	{"ctr_mouse_set_xy",tl_ctr_mouse_set_xy},
	{"ctr_mouse_show",tl_ctr_mouse_show},
	{"ctr_read",tl_ctr_read},
	{"ctr_right",tl_ctr_right},
	{"ctr_up",tl_ctr_up},
	{"font_load",tl_font_load},
	{"font_free",tl_font_free},
	{"font_draw_text",tl_font_draw_text},
	{"font_get_height",tl_font_get_height},
	{"font_get_width",tl_font_get_width},
	{"font_render_text",tl_font_render_text},
	{"gfx_blit",tl_gfx_blit},
	{"gfx_clear",tl_gfx_clear},
	{"gfx_draw",tl_gfx_draw},
	{"gfx_draw_line",tl_gfx_draw_line},
	{"gfx_draw_circle",tl_gfx_draw_circle},
	{"gfx_draw_ellipse",tl_gfx_draw_ellipse},
	{"gfx_draw_filled_circle",tl_gfx_draw_filled_circle},
	{"gfx_draw_filled_ellipse",tl_gfx_draw_filled_ellipse},
	{"gfx_draw_filled_rect",tl_gfx_draw_filled_rect},
	{"gfx_draw_rect",tl_gfx_draw_rect},
	{"gfx_draw_trans",tl_gfx_draw_trans},
	{"gfx_draw_pixel",tl_gfx_draw_pixel},
	{"gfx_draw_rotated",tl_gfx_draw_rotated},
	{"gfx_draw_scaled",tl_gfx_draw_scaled},
	{"gfx_draw_x_flipped",tl_gfx_draw_x_flipped},
	{"gfx_draw_x_flipped_trans",tl_gfx_draw_x_flipped_trans},
	{"gfx_draw_y_flipped",tl_gfx_draw_y_flipped},
	{"gfx_draw_y_flipped_trans",tl_gfx_draw_y_flipped_trans},
	{"gfx_flip",tl_gfx_flip},
	{"gfx_free",tl_gfx_free},
	{"gfx_free_color",tl_gfx_free_color},
	{"gfx_get_height",tl_gfx_get_height},
	{"gfx_get_image",tl_gfx_get_image},
	{"gfx_get_virtual",tl_gfx_get_virtual},
	{"gfx_get_width",tl_gfx_get_width},
	{"gfx_get_red",tl_gfx_get_red},
	{"gfx_get_alpha",tl_gfx_get_alpha},
	{"gfx_get_blue",tl_gfx_get_blue},
	{"gfx_get_green",tl_gfx_get_green},
	{"gfx_get_color",tl_gfx_get_color},
	{"gfx_load",tl_gfx_load},
	{"gfx_new_color",tl_gfx_new_color},
	{"gfx_new_image",tl_gfx_new_image},
	{"gfx_set_title",tl_gfx_set_title},
	{"gfx_set_video_mode",tl_gfx_set_video_mode},
	{"log",tl_log},
	{"log_set_active",tl_log_set_active},
	{"sfx_load",tl_sfx_load},
	{"sfx_free",tl_sfx_free},
	{"sfx_play",tl_sfx_play},
	{"sfx_play_volume",tl_sfx_play_volume},
//{"sfx_set_volume",tl_sfx_set_volume},
	{"timer_init_speed_regulation",tl_timer_init_speed_regulation},
	{"timer_rest",tl_timer_rest},
	{"timer_set_speed_regulation",tl_timer_set_speed_regulation},
	{"timer_wait_speed_regulation",tl_timer_wait_speed_regulation},
	{"translate",tl_translate},
	{"world_create",tl_world_create},
	{"world_free",tl_world_free},
	{"world_get_height",tl_world_get_height},
	{"world_get_tile_height",tl_world_get_tile_height},
	{"world_get_tile_width",tl_world_get_tile_width},
	{"world_get_viewport_height",tl_world_get_viewport_height},
	{"world_get_viewport_width",tl_world_get_viewport_width},
	{"world_get_width",tl_world_get_width},
	{"world_layer_create",tl_world_layer_create},
	{"world_layer_free",tl_world_layer_free},
	{"world_layer_get_data",tl_world_layer_get_data},
	{"world_layer_get_offset",tl_world_layer_get_offset},
	{"world_layer_get_data_from_offset",tl_world_layer_get_data_from_offset},
	{"world_layer_set_data_from_offset",tl_world_layer_set_data_from_offset},
	{"world_layer_get_layer",tl_world_layer_get_layer},
	{"world_layer_set_data",tl_world_layer_set_data},
	{"world_load",tl_world_load},
	{"world_save",tl_world_save},
	{"world_view",tl_world_view},
	{NULL,NULL}
};
#endif																						// TS_LIB_H
