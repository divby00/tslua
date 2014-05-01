#ifndef TS_STRUCT_H
#define TS_STRUCT_H

#include "ts_defs.h"

typedef struct TS_Color
{
	float r;
	float g;
	float b;
	float a;
} TS_Color;

#ifdef AL4_SUPPORT
typedef BITMAP TS_Surface;
#endif
#ifdef AL5_SUPPORT
typedef ALLEGRO_BITMAP TS_Surface;
#endif
#ifdef SDL_SUPPORT
typedef SDL_Surface TS_Surface;
#endif
typedef lua_State TS_Lua;

#ifdef AL4_SUPPORT
typedef SAMPLE TS_Sample;
#endif
#ifdef SDL_SUPPORT
typedef Mix_Chunk TS_Sample;
#endif
#ifdef AL5_SUPPORT
typedef ALLEGRO_SAMPLE TS_Sample;
#endif

typedef struct TS_Font
{
	TS_Surface * glyph[256];
	int gw,gh;
} TS_Font;

typedef struct TS_WorldLayer
{
	char *name;
	ushort *data;
} TS_WorldLayer;

typedef struct TS_WorldLayerList
{
	TS_WorldLayer *wl;
	struct TS_WorldLayerList *next;
} TS_WorldLayerList;

typedef struct TS_Control
{
	#ifdef SDL_SUPPORT
	SDL_Event event;
	SDL_Joystick *joy;
	TS_Surface *cursor;
	int mousex,mousey;
	Uint16 mousespotx, mousespoty;
	uchar mouseb1;
	uchar mouseb2;
	#endif
	#ifdef AL5_SUPPORT
	ALLEGRO_EVENT event;
	ALLEGRO_MOUSE_STATE mouse_state;
	ALLEGRO_MOUSE_CURSOR *mouse_cursor;
	#endif
	unsigned char mouse_on;
	unsigned char joystick_on;
	unsigned char keyboard_on;
	unsigned char max_players;
	unsigned char type[TS_MAX_PLAYERS];
	unsigned char right[TS_MAX_PLAYERS];
	unsigned char left[TS_MAX_PLAYERS];
	unsigned char up[TS_MAX_PLAYERS];
	unsigned char down[TS_MAX_PLAYERS];
	unsigned char action[TS_MAX_ACTION_BUTTONS][TS_MAX_PLAYERS];
	unsigned char accept;
	unsigned char cancel;
} TS_Control;

typedef struct TS_World
{
	ushort xtiles;
	ushort ytiles;
	ushort xtilesize;
	ushort ytilesize;
	ushort xviewport;
	ushort yviewport;
	TS_WorldLayerList *layer_list;
} TS_World;

typedef struct TS_Timer
{
	#ifdef SDL_SUPPORT
	Uint32 framerate;
	Uint32 fps;
	#endif
	#ifdef AL4_SUPPORT
	int framerate;
	int fps;
	#endif
	#ifdef AL5_SUPPORT
	double framerate;
	double fps;
	#endif
	volatile int counter;
} TS_Timer;

typedef struct TS_Sfx
{
	ushort vol_factor;
} TS_Sfx;

typedef struct TS_Gfx
{
	TS_Surface *virt;
	#ifdef AL5_SUPPORT
	ALLEGRO_DISPLAY *display;
	#endif
	#ifdef SDL_SUPPORT
	TS_Surface *display;
	#endif
} TS_Gfx;

typedef struct TS_Log
{
	uchar log_on;
	char *log_filename;
} TS_Log;

typedef struct TS_Config
{
	char *config_filename;
	uchar fullscreen;
	uchar color_depth;
	ushort xres;
	ushort yres;
	ushort xres_scaled;
	ushort yres_scaled;
	uchar sfx_on;
	uchar music_on;
	uchar sfx_vol;
	uchar music_vol;
	char *locale_path;
} TS_Config;

typedef struct TS_Handler
{
	TS_Config *cfg;
	TS_Control *ctr;
	TS_Gfx *gfx;
	TS_Sfx *sfx;
	TS_Lua *ls;
	TS_Log *log;
	TS_Timer *timer;
	char *program_name;
	char *version;
} TS_Handler;
#endif																						// TS_STRUCT_H
