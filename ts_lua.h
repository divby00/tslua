#ifndef TS_LUA_H
#define TS_LUA_H

#include "ts_dll.h"
#include "ts_struct.h"
#include "ts_lib.h"

#ifdef __cpluplus
extern "C"
{
	#endif
	#ifdef UBUNTU_LINUX
	#include <lua5.1/lua.h>
	#include <lua5.1/lualib.h>
	#include <lua5.1/lauxlib.h>
	#else
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
	#endif
	#ifdef __cpluplus
}
#endif

/*
	Function: ts_lua_init

Prepara el interprete de Lua. Reserva la memoria y todo eso. El manejador que utiliza
la libreria TSLib solo se usa internamente para la lectura del fichero de configuracion.
Esta funcion se usa internamente por TSLib y no deberias utilizarla en tu programa.
*/
void ts_lua_init(void);

/*
	Function: ts_lua_quit

Libera los recursos utilizados por el interprete de Lua. Esta funcion se usa internamente
por TSLib y no deberias utilizarla en tu programa.
*/
void ts_lua_quit(void);

uchar ts_lua_dofile(TS_Lua *ls, char *buf);
double ts_lua_tonumber(TS_Lua *ls, int index);
void ts_lua_register_functions(TS_Lua *ls);
char * ts_lua_tostring(TS_Lua *ls, int index);
void * ts_lua_touserdata(TS_Lua *ls, int index);
void ts_lua_pushuserdata(TS_Lua *ls, void *p);
void ts_lua_pushnumber(TS_Lua *ls, double n);
#endif																						// TS_LUA_H
