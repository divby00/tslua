#include "ts_lua.h"
#include "ts_debug.h"
#include "ts_defs.h"
#include "ts_trans.h"

extern TS_Handler *tsh;

void ts_lua_init(void)
{
	tsh->ls=luaL_newstate();
	if (tsh->ls==NULL) {
		ts_debug(_("Error initiating Lua interpreter."),TS_FL);
	}
	else {
		luaL_openlibs(tsh->ls);
		ts_lua_register_functions(tsh->ls);
	}
}


void ts_lua_quit(void)
{
	if (tsh->ls!=NULL) {
		lua_close(tsh->ls);
	}
	else {
		ts_debug(_("Error trying to free a NULL pointer"),TS_FL);
	}
}


uchar ts_lua_dofile(TS_Lua *ls, char *buf)
{
	uchar res=1;
	res=luaL_dofile(ls,buf);
	return res;
}


double ts_lua_tonumber(TS_Lua *ls, int index)
{
	double a=0;
	if (lua_isnumber(ls,index)) {
		a=lua_tonumber(ls,index);
	}
	return a;
}


void ts_lua_register_functions(TS_Lua *ls)
{
	lua_register(ls,"ts_lib_init",tl_lib_init);
	lua_register(ls,"ts_lib_quit",tl_lib_quit);
}


char * ts_lua_tostring(TS_Lua *ls, int index)
{
	if (lua_isstring(ls,index)) {
		return (char *)lua_tostring(ls,index);
	}
	return NULL;
}


void * ts_lua_touserdata(TS_Lua *ls, int index)
{
	if (lua_isuserdata(ls,index)) {
		return lua_touserdata(ls,index);
	}
	return NULL;
}


void ts_lua_pushuserdata(TS_Lua *ls, void *p)
{
	lua_pushlightuserdata(ls,p);
	return;
}


void ts_lua_pushnumber(TS_Lua *ls, double n)
{
	lua_pushnumber(ls,n);
}
