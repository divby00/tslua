#include "ts_trans.h"
#include "ts_translator.h"

const char * ts_translate(const char *cad)
{
	return gettext(cad);
}


EXPORT int tl_translate(TS_Lua *ls)
{
	if (ls!=NULL) {
		lua_pushstring(ls,ts_translate(ts_lua_tostring(ls,1)));
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}
