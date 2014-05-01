#include "ts_sfx.h"
#include "ts_lua.h"
#include "ts_trans.h"
#include "ts_debug.h"
#include "ts_malloc.h"
#include <math.h>

extern TS_Handler *tsh;

#ifdef AL4_SUPPORT

schar ts_sfx_init(void)
{
	if (install_sound(DIGI_AUTODETECT,MIDI_NONE,NULL)==-1) {
		tsh->cfg->sfx_on=0;
		ts_debug(_("Error starting the sound device"),TS_FL);
	}
	else {
		tsh->cfg->sfx_on=1;
	}
	return TS_OK;
}


void ts_sfx_quit(void)
{
	if (tsh->cfg->sfx_on) {

	}
}


TS_Sample *ts_sfx_load(const char *filename)
{
	if (tsh->cfg->sfx_on) {
		SAMPLE *aux=NULL;
		if (filename!=NULL) {
			aux=(SAMPLE *)load_sample(filename);
			if (aux==NULL) {
				ts_debug(_("Error loading a sound"),TS_FL);
				return NULL;
			}
			else {
				return aux;
			}
		}
		else {
			ts_debug(_("The file doesn't exist"),TS_FL);
			return NULL;
		}
	}
}


void ts_sfx_free(TS_Sample *sample)
{
	if (tsh->cfg->sfx_on) {
		if (sample!=NULL) {
			destroy_sample(sample);
		}
		else {
			ts_debug(_("Error trying to free a NULL pointer"),TS_FL);
		}
	}
}


void ts_sfx_play(TS_Sample *sample)
{
	if (sample!=NULL) {
		play_sample(sample,tsh->cfg->sfx_vol,0,1000,0);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_sfx_set_volume(uchar vol)
{
	if (tsh->cfg->sfx_on) {
		tsh->cfg->sfx_vol=vol;
	}
}
#endif

#ifdef AL5_SUPPORT

schar ts_sfx_init(void)
{
	if (!al_install_audio()) {
		ts_debug(_("Error starting the sound device"),TS_FL);
		tsh->cfg->sfx_on=0;
	}
	else {
		tsh->cfg->sfx_on=1;
	}
	al_init_acodec_addon();
	al_reserve_samples(32);
	return TS_OK;
}


void ts_sfx_quit(void)
{
	if (tsh->cfg->sfx_on) {
		al_uninstall_audio();
	}
	if (tsh->sfx!=NULL) {
		ts_free(tsh->sfx);
	}
	else {
		ts_debug(_("Trying to free a NULL pointer"),TS_FL);
	}
}


TS_Sample *ts_sfx_load(const char *filename)
{
	TS_Sample *aux=NULL;
	aux=(TS_Sample *)al_load_sample(filename);
	if (aux!=NULL) {
		return aux;
	}
	else {
		ts_debug(_("Error loading a sound"),TS_FL);
		return NULL;
	}
}


void ts_sfx_free(TS_Sample *sample)
{
	if (tsh->cfg->sfx_on) {
		if (sample!=NULL) {
			al_destroy_sample(sample);
		}
		else {
			ts_debug(_("Error trying to free a NULL pointer"),TS_FL);
		}
	}
}


void ts_sfx_play(TS_Sample *sample)
{
	if (tsh->cfg->sfx_on) {
		if (sample!=NULL) {
			al_play_sample(sample,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
		}
		else {
			ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		}
	}
}


void ts_sfx_set_volume(uchar v)
{
}


void ts_sfx_play_volume(TS_Sample *sample, sshort x1, sshort y1, sshort x2, sshort y2)
{
	float p1=0;
	float p2=0;
	float res=0;
	float vol=0;
	int v=0;
	p1=abs(x1-x2);
	p2=abs(y1-y2);
	res=sqrt((p1*p1)+(p2*p2));
	vol=(res*128)/tsh->sfx->vol_factor;
	if (tsh->cfg->sfx_on) {
		if (sample!=NULL) {
			v=(int)(128-vol);
			al_play_sample(sample,(float)(v/128),0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
		}
		else {
			ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		}
	}
}
#endif

#ifdef SDL_SUPPORT

schar ts_sfx_init(void)
{
	tsh->sfx=(struct TS_Sfx *)ts_malloc(sizeof(struct TS_Sfx));
//	if (Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,2048)==-1) {
//	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,6,2048)<0) {
	if (Mix_OpenAudio(22050,AUDIO_S16,2,1024)<0) {
		ts_debug(_("Error starting the sound device"),TS_FL);
		tsh->cfg->sfx_on=0;
	}
	else {
		tsh->cfg->sfx_on=1;
		Mix_AllocateChannels(6);
		tsh->sfx->vol_factor=0;
	}
	return TS_OK;
}


void ts_sfx_quit(void)
{
	if (tsh->cfg->sfx_on) {
		Mix_CloseAudio();
		if (tsh->sfx!=NULL) {
			ts_free(tsh->sfx);
		}
		else {
			ts_debug(_("Trying to free a NULL pointer"),TS_FL);
		}
	}
}


TS_Sample * ts_sfx_load(const char *filename)
{
	Mix_Chunk *snd=NULL;
	if (tsh->cfg->sfx_on) {
		if (filename!=NULL) {
			snd=Mix_LoadWAV(filename);
			if (snd==NULL) {
				ts_debug(_("Error loading a sound"),TS_FL);
				return NULL;
			}
			else {
				return snd;
			}
		}
		else {
			ts_debug(_("The file doesn't exist"),TS_FL);
			return NULL;
		}
	}
	return NULL;
}


void ts_sfx_free(TS_Sample *sample)
{
	if (tsh->cfg->sfx_on) {
		if (sample!=NULL) {
			Mix_FreeChunk(sample);
		}
		else {
			ts_debug(_("Error trying to free a NULL pointer"),TS_FL);
		}
	}
}


void ts_sfx_play(TS_Sample *sample)
{
	if (tsh->cfg->sfx_on) {
		if (sample!=NULL) {
			Mix_PlayChannel(-1,sample,0);
		}
		else {
			ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		}
	}
}


void ts_sfx_set_volume(uchar vol)
{
	if (tsh->cfg->sfx_on) {
		Mix_Volume(-1,vol);
		tsh->cfg->sfx_vol=vol;
	}
}


void ts_sfx_play_freq(TS_Sample *sample, ushort freq)
{
	if (tsh->cfg->sfx_on) {
		if (sample!=NULL) {
			Mix_PlayChannel(-1,sample,0);
		}
		else {
			ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		}
	}
}


void ts_sfx_play_volume(TS_Sample *sample, sshort x1, sshort y1, sshort x2, sshort y2)
{
	float p1=0;
	float p2=0;
	float res=0;
	float vol=0;
	int v=0;
	p1=abs(x1-x2);
	p2=abs(y1-y2);
	res=sqrt((p1*p1)+(p2*p2));
	vol=(res*128)/tsh->sfx->vol_factor;
	if (tsh->cfg->sfx_on) {
		if (sample!=NULL) {
			v=(int)(128-vol);
			Mix_VolumeChunk(sample,v);
			Mix_PlayChannel(-1,sample,0);
		}
		else {
			ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		}
	}
}
#endif

EXPORT int tl_sfx_load(TS_Lua *ls)
{
	if (ls!=NULL) {
		TS_Sample *sample=NULL;
		sample=ts_sfx_load((const char *)ts_lua_tostring(ls,1));
		ts_lua_pushuserdata(ls,(TS_Sample *)sample);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_sfx_free(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_sfx_free((TS_Sample *)lua_touserdata(ls,1));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_sfx_play(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_sfx_play((TS_Sample *)ts_lua_touserdata(ls,1));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_sfx_play_volume(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_sfx_play_volume((TS_Sample *)ts_lua_touserdata(ls,1),ts_lua_tonumber(ls,2),ts_lua_tonumber(ls,3),ts_lua_tonumber(ls,4),ts_lua_tonumber(ls,5));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_sfx_set_volume(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_sfx_set_volume((uchar)ts_lua_tonumber(ls,1));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}
