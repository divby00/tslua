#ifndef TS_FONT_H
#define TS_FONT_H

#include "ts_dll.h"
#include "ts_defs.h"
#include "ts_struct.h"

TS_Font * ts_font_load(const char *filename);
void ts_font_free(TS_Font *fnt);
void ts_font_draw_text(TS_Font *font, TS_Surface *dst, sint x, sint y, int flags, const char *text);
ushort ts_font_get_width(TS_Font *font, const char *text);
ushort ts_font_get_height(TS_Font *font, const char *text);
TS_Surface * ts_font_render_text(TS_Font *font, const char *text);

EXPORT int tl_font_load(TS_Lua *ls);
EXPORT int tl_font_free(TS_Lua *ls);
EXPORT int tl_font_draw_text(TS_Lua *ls);
EXPORT int tl_font_render_text(TS_Lua *ls);
EXPORT int tl_font_get_width(TS_Lua *ls);
EXPORT int tl_font_get_height(TS_Lua *ls);
#endif																						// TS_FONT_H
