#include "ts_cfg.h"
#include "ts_struct.h"
#include "ts_malloc.h"
#include "ts_trans.h"
#include "ts_lua.h"
#include <string.h>

extern TS_Handler *tsh;

void ts_cfg_init(void)
{
	tsh->cfg=(struct TS_Config *)ts_malloc(sizeof(struct TS_Config));
	tsh->cfg->config_filename=(char *)ts_malloc(TS_MAX_STRING);
	tsh->cfg->locale_path=(char *)ts_malloc(TS_MAX_STRING);
	strcpy(tsh->cfg->config_filename,tsh->program_name);
	strcat(tsh->cfg->config_filename,".cfg");
	strcpy(tsh->cfg->locale_path,".");
	ts_cfg_set_defaults();
}


void ts_cfg_quit(void)
{
	tsh->cfg->locale_path=(char *)ts_free(tsh->cfg->locale_path);
	tsh->cfg->config_filename=(char *)ts_free(tsh->cfg->config_filename);
	tsh->cfg=(TS_Config *)ts_free(tsh->cfg);
}


void ts_cfg_set_defaults(void)
{
	tsh->cfg->color_depth=TS_CFG_COLOR_DEPTH;
	tsh->cfg->fullscreen=TS_CFG_FULLSCREEN;
	tsh->cfg->xres=TS_CFG_XRES;
	tsh->cfg->xres_scaled=TS_CFG_XRES_SCALED;
	tsh->cfg->yres=TS_CFG_YRES;
	tsh->cfg->yres_scaled=TS_CFG_YRES_SCALED;
	tsh->cfg->sfx_on=TS_CFG_SFX_ON;
	tsh->cfg->music_on=TS_CFG_MUSIC_ON;
	tsh->cfg->sfx_vol=TS_CFG_SFX_VOL;
	tsh->cfg->music_vol=TS_CFG_MUSIC_VOL;
	strcpy(tsh->cfg->locale_path,TS_CFG_LOCALE_PATH);
}


schar ts_cfg_save(void)
{
	FILE *f=NULL;
	f=fopen(tsh->cfg->config_filename,"wt");
	if (f!=NULL) {
		fprintf(f,_("-- Configuration file for %s. Version:%s.\n"),tsh->program_name,tsh->version);
		fprintf(f,_("-- Lines starting with -- like this are comments.\n\n"));
		fprintf(f,_("-- [Graphics section]\n"));
		fprintf(f,_("Horizontal_resolution = %d\n"),tsh->cfg->xres);
		fprintf(f,_("Vertical_resolution = %d\n"),tsh->cfg->yres);
		fprintf(f,_("Horizontal_scaled_resolution = %d\n"),tsh->cfg->xres_scaled);
		fprintf(f,_("Vertical_scaled_resolution = %d\n"),tsh->cfg->yres_scaled);
		fprintf(f,_("Color_depth = %d\n"),tsh->cfg->color_depth);
		fprintf(f,_("Fullscreen = %d\n"),tsh->cfg->fullscreen);
		fprintf(f,_("\n-- [Sound section]\n"));
		fprintf(f,_("Sound_effects = %d\n"),tsh->cfg->sfx_on);
		fprintf(f,_("Music = %d\n"),tsh->cfg->music_on);
		fprintf(f,_("Sound_effects_volume = %d\n"),tsh->cfg->sfx_vol);
		fprintf(f,_("Music_volume = %d\n"),tsh->cfg->music_vol);
		fprintf(f,_("\n-- [Path section]\n"));
		fprintf(f,_("Locale_path = %s\n"),tsh->cfg->locale_path);
		fclose(f);
	}
	else {
		ts_debug(_("Error writing the configuration file."),TS_FL);
		return TS_ERROR;
	}
	return TS_OK;
}


schar ts_cfg_load(void)
{
	FILE *f=NULL;
    uint res=0;
	f=fopen(tsh->cfg->config_filename,"r");
	if (f!=NULL) {
		fclose(f);
        res = luaL_dofile(tsh->ls,tsh->cfg->config_filename);
		lua_getglobal(tsh->ls,_("Horizontal_resolution"));
		if (lua_isnumber(tsh->ls,-1)) tsh->cfg->xres=(ushort)lua_tonumber(tsh->ls,-1);
		lua_remove(tsh->ls,-1);
		lua_getglobal(tsh->ls,_("Vertical_resolution"));
		if (lua_isnumber(tsh->ls,-1)) tsh->cfg->yres=(ushort)lua_tonumber(tsh->ls,-1);
		lua_remove(tsh->ls,-1);
		lua_getglobal(tsh->ls,_("Horizontal_scaled_resolution"));
		if (lua_isnumber(tsh->ls,-1)) tsh->cfg->xres_scaled=(ushort)lua_tonumber(tsh->ls,-1);
		lua_remove(tsh->ls,-1);
		lua_getglobal(tsh->ls,_("Vertical_scaled_resolution"));
		if (lua_isnumber(tsh->ls,-1)) tsh->cfg->yres_scaled=(ushort)lua_tonumber(tsh->ls,-1);
		lua_remove(tsh->ls,-1);
		lua_getglobal(tsh->ls,_("Color_depth"));
		if (lua_isnumber(tsh->ls,-1)) tsh->cfg->color_depth=(uchar)lua_tonumber(tsh->ls,-1);
		lua_remove(tsh->ls,-1);
		lua_getglobal(tsh->ls,_("Fullscreen"));
		if (lua_isnumber(tsh->ls,-1)) tsh->cfg->fullscreen=(uchar)lua_tonumber(tsh->ls,-1);
		lua_remove(tsh->ls,-1);
		lua_getglobal(tsh->ls,_("Locale_path"));
		if (lua_isstring(tsh->ls,-1)) {
			strcpy(tsh->cfg->locale_path,lua_tostring(tsh->ls,-1));
		}
		lua_remove(tsh->ls,-1);
	}
	else {
		ts_debug(_("Error reading or parsing the configuration file. Assuming defaults."),TS_FL);
		ts_cfg_set_defaults();
		return TS_ERROR;
	}
	return TS_OK;
}
