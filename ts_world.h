#ifndef TS_WORLD_H
#define TS_WORLD_H

#include "ts_dll.h"
#include "ts_defs.h"
#include "ts_struct.h"
//#include "ts_lua.h"

TS_World * ts_world_load(const char *filename);
void ts_world_save(TS_World *w, const char *filename);
TS_World * ts_world_create(unsigned short int xtiles, unsigned short int ytiles, unsigned short xtilesize, unsigned short ytilesize, unsigned short xviewport, unsigned short yviewport);
void ts_world_free(TS_World *world);
void ts_world_layer_create(TS_World *w, const char *name);
void ts_world_layer_free(TS_WorldLayer *wlayer);
TS_WorldLayer * ts_world_layer_get_layer(TS_World *world, const char *name);
void ts_world_layer_set_data(TS_World *world, TS_WorldLayer *wlayer, ushort x, ushort y, ushort value);
ushort ts_world_layer_get_data(TS_World *world, TS_WorldLayer *wlayer, ushort x, ushort y);
ushort ts_world_layer_get_data_from_offset(TS_World *world, TS_WorldLayer *wlayer, ulong offset);
void ts_world_layer_set_data_from_offset(TS_World *world, TS_WorldLayer *wlayer, ulong offset, ushort value);
ushort ts_world_get_width(TS_World *w);
ushort ts_world_get_height(TS_World *w);
ushort ts_world_get_tile_width(TS_World *w);
ushort ts_world_get_tile_height(TS_World *w);
ushort ts_world_get_viewport_width(TS_World *w);
ushort ts_world_get_viewport_height(TS_World *w);
void ts_world_view(TS_World *world);
void ts_world_scene_free(ushort *data);
ushort * ts_world_scene_get(TS_World *w, TS_WorldLayer *layer, ushort x, ushort y);
ulong ts_world_layer_get_offset(TS_World *world, TS_WorldLayer *wlayer, ushort xroom, ushort yroom, ushort x, ushort y);

EXPORT int tl_world_create(TS_Lua *ls);
EXPORT int tl_world_free(TS_Lua *ls);
EXPORT int tl_world_get_width(TS_Lua *ls);
EXPORT int tl_world_get_height(TS_Lua *ls);
EXPORT int tl_world_get_tile_width(TS_Lua *ls);
EXPORT int tl_world_get_tile_height(TS_Lua *ls);
EXPORT int tl_world_layer_create(TS_Lua *ls);
EXPORT int tl_world_layer_free(TS_Lua *ls);
EXPORT int tl_world_layer_get_layer(TS_Lua *ls);
EXPORT int tl_world_layer_get_data(TS_Lua *ls);
EXPORT int tl_world_layer_get_data_from_offset(TS_Lua *ls);
EXPORT int tl_world_layer_set_data(TS_Lua *ls);
EXPORT int tl_world_layer_set_data_from_offset(TS_Lua *ls);
EXPORT int tl_world_save(TS_Lua *ls);
EXPORT int tl_world_load(TS_Lua *ls);
EXPORT int tl_world_get_viewport_width(TS_Lua *ls);
EXPORT int tl_world_get_viewport_height(TS_Lua *ls);
EXPORT int tl_world_view(TS_Lua *ls);
EXPORT int tl_world_layer_get_offset(TS_Lua *ls);
#endif
