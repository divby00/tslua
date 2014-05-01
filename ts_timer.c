#include "ts_defs.h"
#include "ts_lua.h"
#include "ts_timer.h"
#include "ts_malloc.h"
#include "ts_struct.h"

extern TS_Handler *tsh;

#ifdef AL4_SUPPORT

void ts_timer_incrementor(void)
{
	tsh->timer->counter++;
} END_OF_FUNCTION(ts_timer_incrementor);

void ts_timer_init(void)
{
	tsh->timer=(TS_Timer *)ts_malloc(sizeof(struct TS_Timer));
	tsh->timer->fps=TS_FPS;
	tsh->timer->framerate=0;
	tsh->timer->counter=0;
	LOCK_VARIABLE(tsh->timer->counter);
	LOCK_FUNCTION(ts_timer_incrementor);
}


void ts_timer_init_speed_regulation(void)
{
	tsh->timer->framerate=tsh->timer->counter;
}


void ts_timer_quit(void)
{
	remove_int(ts_timer_incrementor);
	tsh->timer=(TS_Timer *)ts_free(tsh->timer);
}


void ts_timer_rest(double miliseconds)
{
	rest((unsigned int)miliseconds);
}


void ts_timer_set_speed_regulation(int t)
{
	tsh->timer->fps=t;
}


void ts_timer_wait_speed_regulation(void)
{
	int a=0;
	tsh->timer->framerate=tsh->timer->counter-tsh->timer->framerate;
	if (tsh->timer->framerate<tsh->timer->fps) {
		a=tsh->timer->fps-tsh->timer->framerate;
		rest(a);
		//fprintf(stdout,"\n%d",a);
	}
}
#endif

#ifdef AL5_SUPPORT

void ts_timer_init(void)
{
	tsh->timer=(TS_Timer *)ts_malloc(sizeof(struct TS_Timer));
	tsh->timer->fps=TS_FPS;
	tsh->timer->framerate=0;
}


void ts_timer_init_speed_regulation(void)
{
	tsh->timer->framerate=al_get_time();
	//fprintf(stdout,"\nStart: %lf",al_get_time());
}


void ts_timer_quit(void)
{
	tsh->timer=(TS_Timer *)ts_free(tsh->timer);
}


void ts_timer_rest(double miliseconds)
{
	double t=0;
	t=(double)(miliseconds/1000);
	al_rest(t);
}


void ts_timer_set_speed_regulation(int t)
{
	double a=0;
	a=t;
	a=a/1000;
	tsh->timer->fps=a;
}


void ts_timer_wait_speed_regulation(void)
{
	double x,x2=0;
	x=al_get_time();
	x2=x-tsh->timer->framerate;
	if (x2<tsh->timer->fps) {
		al_rest((double)tsh->timer->fps-x2);
		//fprintf(stdout,"\n%lf",(tsh->timer->fps-x2)*1000);
	}
}
#endif

#ifdef SDL_SUPPORT

void ts_timer_init(void)
{
	tsh->timer=(TS_Timer *)ts_malloc(sizeof(struct TS_Timer));
	tsh->timer->fps=TS_FPS;
	tsh->timer->framerate=0;
}


void ts_timer_init_speed_regulation(void)
{
	tsh->timer->framerate=SDL_GetTicks();
}


void ts_timer_quit(void)
{
	tsh->timer=(TS_Timer *)ts_free(tsh->timer);
}


void ts_timer_rest(double miliseconds)
{
	SDL_Delay((Uint32)miliseconds);
}


void ts_timer_set_speed_regulation(int t)
{
	tsh->timer->fps=t;
}


void ts_timer_wait_speed_regulation(void)
{
	int a=0;
	tsh->timer->framerate=SDL_GetTicks()-tsh->timer->framerate;
	if (tsh->timer->framerate<tsh->timer->fps) {
		a=tsh->timer->fps-tsh->timer->framerate;
		SDL_Delay((ushort)(a));
		//fprintf(stdout,"\n%d",a);
	}
}
#endif

EXPORT int tl_timer_init_speed_regulation(TS_Lua *ls)
{
	ts_timer_init_speed_regulation();
	return 0;
}


EXPORT int tl_timer_rest(TS_Lua *ls)
{
	ts_timer_rest(ts_lua_tonumber(ls,1));
	return 0;
}


EXPORT int tl_timer_set_speed_regulation(TS_Lua *ls)
{
	ts_timer_set_speed_regulation((int)ts_lua_tonumber(ls,1));
	return 0;
}


EXPORT int tl_timer_wait_speed_regulation(TS_Lua *ls)
{
	ts_timer_wait_speed_regulation();
	return 0;
}
