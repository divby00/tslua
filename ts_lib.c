#include "ts_lib.h"
#include "lualib.h"
#include <string.h>
#include <libintl.h>
#include <locale.h>

const char * ts_trans(const char *cad);
EXPORT int tl_trans(TS_Lua *ls);

TS_Handler *tsh;

schar ts_lib_uses(void)
{
	#ifdef SDL_SUPPORT
	return TS_USES_SDL;
	#endif
	#ifdef AL5_SUPPORT
	return TS_USES_AL5;
	#endif
	#ifdef AL4_SUPPORT
	return TS_USES_AL4;
	#endif
}


EXPORT int tl_lib_uses(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_lua_pushnumber(ls,ts_lib_uses());
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


void ts_trans_init(void)
{
	setlocale(LC_ALL, "");
	bindtextdomain(tsh->program_name, TS_CFG_LOCALE_PATH);
	textdomain(tsh->program_name);
}


#ifdef AL4_SUPPORT

schar ts_lib_init(const char *name, const char *version)
{
	if (name!=NULL && version!=NULL) {
		tsh=(struct TS_Handler *)ts_malloc(sizeof(struct TS_Handler));
		tsh->program_name=(char *)ts_malloc(TS_MAX_STRING);
		tsh->version=(char *)ts_malloc(TS_MAX_STRING);
		strcpy(tsh->program_name,name);
		strcpy(tsh->version,version);
//bindtextdomain(PACKAGE,LOCALEDIR);
		ts_lua_init();
		ts_cfg_init();
		ts_trans_init();
		ts_log_init();
		ts_gfx_init();
		ts_timer_init();
		allegro_init();
		install_timer();
		install_int(ts_timer_incrementor,1);
		register_png_file_type();
		ts_ctr_init();
		ts_sfx_init();
		return TS_OK;
	}
	else {
		ts_debug(_("Invalid program name or program version"),TS_FL);
		return TS_ERROR;
	}
}


schar ts_lib_quit(void)
{
	ts_gfx_quit();
	ts_sfx_quit();
	ts_cfg_quit();
	ts_ctr_quit();
	tsh->version=(char *)ts_free(tsh->version);
	tsh->program_name=(char *)ts_free(tsh->program_name);
	ts_log_quit();
	ts_timer_quit();
	ts_lua_quit();
	tsh=(TS_Handler *)ts_free(tsh);
	allegro_exit();
	return TS_OK;
}
#endif

#ifdef AL5_SUPPORT

schar ts_lib_init(const char *name, const char *version)
{
	if (name!=NULL && version!=NULL) {
		tsh=(struct TS_Handler *)ts_malloc(sizeof(struct TS_Handler));
		tsh->program_name=(char *)ts_malloc(TS_MAX_STRING);
		tsh->version=(char *)ts_malloc(TS_MAX_STRING);
		strcpy(tsh->program_name,name);
		strcpy(tsh->version,version);
//bindtextdomain(PACKAGE,LOCALEDIR);
		ts_lua_init();
		ts_cfg_init();
		ts_trans_init();
		ts_log_init();
		ts_gfx_init();
		ts_sfx_init();
		ts_timer_init();
		al_init();
		al_init_image_addon();
		al_init_primitives_addon();
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
		ts_ctr_init();
		return TS_OK;
	}
	else {
		ts_debug(_("Invalid program name or program version"),TS_FL);
		return TS_ERROR;
	}
}


schar ts_lib_quit(void)
{
	ts_gfx_quit();
	ts_sfx_quit();
	ts_cfg_quit();
	ts_ctr_quit();
	tsh->version=(char *)ts_free(tsh->version);
	tsh->program_name=(char *)ts_free(tsh->program_name);
	ts_log_quit();
	ts_lua_quit();
	ts_timer_quit();
	tsh=(TS_Handler *)ts_free(tsh);
	al_shutdown_image_addon();
	al_shutdown_primitives_addon();
	return TS_OK;
}
#endif

#ifdef SDL_SUPPORT

schar ts_lib_init(const char *name, const char *version)
{
	if (name!=NULL && version!=NULL) {
		tsh=(struct TS_Handler *)ts_malloc(sizeof(struct TS_Handler));
		tsh->program_name=(char *)ts_malloc(TS_MAX_STRING);
		tsh->version=(char *)ts_malloc(TS_MAX_STRING);
		strcpy(tsh->program_name,name);
		strcpy(tsh->version,version);
//bindtextdomain(PACKAGE,LOCALEDIR);
		ts_lua_init();
		ts_cfg_init();
		ts_trans_init();
		ts_log_init();
		ts_gfx_init();
		ts_sfx_init();
		ts_timer_init();
		if (SDL_Init(SDL_INIT_EVERYTHING)==-1) {
			ts_debug(_("Error starting SDL"),TS_FL);
			return TS_ERROR;
		}
		ts_ctr_init();
		return TS_OK;
	}
	else {
		ts_debug(_("Invalid program name or program version"),TS_FL);
		return TS_ERROR;
	}
}


schar ts_lib_quit(void)
{
	ts_gfx_quit();
	ts_sfx_quit();
	ts_cfg_quit();
	ts_ctr_quit();
	tsh->version=(char *)ts_free(tsh->version);
	tsh->program_name=(char *)ts_free(tsh->program_name);
	ts_log_quit();
	ts_lua_quit();
	ts_timer_quit();
	tsh=(TS_Handler *)ts_free(tsh);
	SDL_Quit();
	return TS_OK;
}
#endif

EXPORT int tl_lib_init(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_lib_init(ts_lua_tostring(ls,1),ts_lua_tostring(ls,2));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_lib_quit(TS_Lua *ls)
{
	ts_lib_quit();
	return 0;
}


LUAMOD_API int luaopen_ts (lua_State *ls)
{
	if (ls!=NULL) {
		luaL_newlib(ls,tslib);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


/*
LUALIB_API EXPORT int luaopen_ts(lua_State *ls) {
	if (ls!=NULL) {
luaL_register(ls, ts, 0);
luaL_setfuncs();
luaL_openlib(ls,"ts",ts,0);
return 1;
} else {
ts_debug(_("Invalid Lua handler"),TS_FL);
return 0;
}
}
*/

/*
int main() {
	int j=0;
TS_Surface *s=NULL;
TS_Color *c,*d=NULL;
TS_Font *fnt=NULL;
int x,y=0;
ts_lib_init("programa","0,0");
ts_gfx_set_video_mode(960,640,32,0);
s=ts_gfx_load("img1.bmp");
fnt=ts_font_load("phfont.png");

while(j<50) {
c=ts_gfx_new_color(0,rand()%255,0,145);
ts_gfx_draw_filled_rect(ts_gfx_get_virtual(),rand()%500,rand()%350,(rand()%500)+500,(rand()%350)+350,c);
j++;
ts_gfx_flip();
ts_gfx_free_color(c);
}
j=0;
while(j<50) {
c=ts_gfx_new_color(255,50,100,255);
x=rand()%1024;
y=rand()%768;
//ts_gfx_draw_filled_ellipse(ts_gfx_get_virtual(),rand()%640,rand()%480,45,90,c);
//ts_gfx_draw_x_flipped_trans(s,ts_gfx_get_virtual(),rand()%600,rand()%400,120);
ts_gfx_draw_pixel(ts_gfx_get_virtual(),x,y,c);
d=ts_gfx_get_color(ts_gfx_get_virtual(),x,y);
fprintf(stdout,"\n%lf %lf %lf %lf",d->r,d->g,d->b,d->a);
j++;
ts_gfx_flip();
ts_gfx_free_color(c);
ts_gfx_free_color(d);
}
ts_gfx_draw_scaled(s,10,10,ts_gfx_get_virtual(),200,150);
ts_gfx_draw_rotated(s,100,100,ts_gfx_get_virtual(),10);
ts_gfx_draw_rotated(s,140,100,ts_gfx_get_virtual(),20);
ts_gfx_draw_rotated(s,180,100,ts_gfx_get_virtual(),90);
ts_gfx_draw_rotated(s,220,100,ts_gfx_get_virtual(),45);
ts_font_draw_text(fnt,ts_gfx_get_virtual(),0,0,0,"Mierda pa tu kulo");
ts_gfx_flip();
ts_timer_rest(2000);
ts_gfx_free(s);
ts_font_free(fnt);
ts_lib_quit();
return 0;
}

*/
