#include "ts_dll.h"
#include "ts_defs.h"
#include "ts_font.h"
#include "ts_lib.h"
#include <string.h>
#include <stdlib.h>

extern TS_Handler *tsh;

TS_Font * ts_font_load(const char *filename)
{
	TS_Surface *src=NULL;
	TS_Font *aux=NULL;
	int imgw,imgh,i,a=0;
	src=ts_gfx_load(filename);
	imgw=ts_gfx_get_width(src);
	imgh=ts_gfx_get_height(src);
	aux=(struct TS_Font *)ts_malloc(sizeof(struct TS_Font));
	aux->gw=0;
	aux->gh=0;
	aux->gw=imgw/32;
	aux->gh=imgh/8;
	for (a=0;a<8;a++) {
		for (i=0;i<32;i++) {
			aux->glyph[(32*a)+i]=ts_gfx_get_image(src,i*aux->gw,a*aux->gh,aux->gw,aux->gh);
		}
	}
	ts_gfx_free(src);
	return aux;
}


void ts_font_free(TS_Font *fnt)
{
	int i=0;
	if (fnt!=NULL) {
		for (i=0;i<256;i++) ts_gfx_free(fnt->glyph[i]);
		fnt=(TS_Font *)ts_free(fnt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


TS_Surface * ts_font_render_text(TS_Font *font, const char *text)
{
	TS_Surface *aux=NULL;
	aux=ts_gfx_new_image(ts_font_get_width(font,text),ts_font_get_height(font,text));
	if (aux==NULL) {
		ts_debug(_("Can't create the image to render the text"),TS_FL);
		return NULL;
	}
	ts_font_draw_text(font,aux,0,0,0,text);
	return aux;
}


void ts_font_draw_text(TS_Font *font, TS_Surface *dst, sint x, sint y, int flags, const char *text)
{
	int i,size=0;
	int ax=0;
	size=strlen(text);
	if (font==NULL) exit(-13);
	for (i=0;i<size;i++) {
		ts_gfx_draw(font->glyph[(int)text[i]],dst,x+ax,y);
		ax+=font->gw;
	}
}


ushort ts_font_get_width(TS_Font *font, const char *text)
{
	unsigned long int size=0;
	size=strlen(text);
	return size*font->gw;
}


ushort ts_font_get_height(TS_Font *font, const char *text)
{
	return font->gh;
}


EXPORT int tl_font_render_text(TS_Lua *ls)
{
	TS_Surface *dst=NULL;
	dst=ts_font_render_text((TS_Font *)ts_lua_touserdata(ls,1),ts_lua_tostring(ls,2));
	ts_lua_pushuserdata(ls,dst);
	return 1;
}


EXPORT int tl_font_get_height(TS_Lua *ls)
{
	ts_lua_pushnumber(ls,ts_font_get_height((TS_Font *)ts_lua_touserdata(ls,1),ts_lua_tostring(ls,2)));
	return 1;
}


EXPORT int tl_font_get_width(TS_Lua *ls)
{
	ts_lua_pushnumber(ls,ts_font_get_width((TS_Font *)ts_lua_touserdata(ls,1),ts_lua_tostring(ls,2)));
	return 1;
}


EXPORT int tl_font_draw_text(TS_Lua *ls)
{
	ts_font_draw_text((TS_Font *)ts_lua_touserdata(ls,1),(TS_Surface *)ts_lua_touserdata(ls,2),(sint)ts_lua_tonumber(ls,3),(sint)ts_lua_tonumber(ls,4),(sint)ts_lua_tonumber(ls,5),ts_lua_tostring(ls,6));
	return 0;
}


EXPORT int tl_font_free(TS_Lua *ls)
{
	ts_font_free((TS_Font *)ts_lua_touserdata(ls,1));
	return 0;
}


EXPORT int tl_font_load(TS_Lua *ls)
{
	TS_Font *fnt=NULL;
	fnt=ts_font_load(ts_lua_tostring(ls,1));
	ts_lua_pushuserdata(ls,fnt);
	return 1;
}
