#include "ts_lib.h"
#include "ts_ctr.h"
#include "ts_struct.h"
#include "ts_lua.h"
#include <string.h>

extern TS_Handler *tsh;

#ifdef AL4_SUPPORT

void ts_ctr_init(void)
{
	int n_joy=0;
	int res=0;
	#ifdef TARGET_GP2X
	int i=0;
	#endif
	#ifdef TARGET_WII
	int i=0;
	#endif
	#ifdef TARGET_IPHONE
	#endif

	tsh->ctr=(TS_Control *)ts_malloc(sizeof(TS_Control));
	res=install_keyboard();
	if (res) tsh->ctr->keyboard_on=1; else tsh->ctr->keyboard_on=0;
	res=install_joystick(JOY_TYPE_AUTODETECT);
	if (res) tsh->ctr->joystick_on=1; else tsh->ctr->joystick_on=0;
	res=install_mouse();
	if (res) {
		tsh->ctr->mouse_on=1;
	}
	else {
		tsh->ctr->mouse_on=0;
	}
	if (!tsh->ctr->mouse_on && !tsh->ctr->keyboard_on && !tsh->ctr->joystick_on) ts_debug(_("Can't init any control"),TS_FL);
	#ifdef AL5_SUPPORT
	tsh->ctr->mouse_cursor=NULL;
	#endif

// Apropiate for AL4.
//n_joy=al_get_num_joysticks();

	#ifdef TARGET_GP2X
	for (i=0;i<n_joy;i++) tsh->ctr->type[i]=1;
	#endif

	#ifdef TARGET_WII
	for (i=0;i<n_joy;i++) tsh->ctr->type[i]=1;
	#endif
}


void ts_ctr_quit(void)
{
//if (tsh->ctr->mouse_cursor!=NULL) al_destroy_mouse_cursor(tsh->ctr->mouse_cursor);
	tsh->ctr=(TS_Control *)ts_free(tsh->ctr);
}


void ts_ctr_read(void)
{
	int i,a;
	int key=0;

// Limpiar el buffer de la direccion
	for (i=0;i<TS_MAX_PLAYERS;i++) {
		tsh->ctr->up[i]=0;
		tsh->ctr->down[i]=0;
		tsh->ctr->left[i]=0;
		tsh->ctr->right[i]=0;
		for (a=0;a<TS_MAX_ACTION_BUTTONS;a++) tsh->ctr->action[a][i]=0;
	}

	tsh->ctr->cancel=tsh->ctr->accept=key=0;

	poll_keyboard();
/*
	if (al_key_down(&key_state,tsh->cfg->key_cancel)) {
		tsh->ctr->cancel=1;
}
if (al_key_down(&key_state,tsh->cfg->key_accept)) {
tsh->ctr->accept=1;
}

for (i=0;i<TS_MAX_PLAYERS;i++)
{
if (tsh->ctr->type[i]==0)
{
if (al_key_down(&key_state,tsh->cfg->key_up[i])) tsh->ctr->up[i]=1;
if (al_key_down(&key_state,tsh->cfg->key_left[i])) tsh->ctr->left[i]=1;
if (al_key_down(&key_state,tsh->cfg->key_down[i])) tsh->ctr->down[i]=1;
if (al_key_down(&key_state,tsh->cfg->key_right[i])) tsh->ctr->right[i]=1;
for (a=0;a<TS_MAX_ACTION_BUTTONS;a++) {
if (al_key_down(&key_state,tsh->cfg->key_action[a][i])) tsh->ctr->action[a][i]=1;
}
}
}*/
}


unsigned char ts_ctr_key(int akey)
{
	if (key[akey]) return 1;
	return 0;
}
#endif

#ifdef AL5_SUPPORT

unsigned char ts_ctr_key(int key)
{
	ALLEGRO_KEYBOARD_STATE key_state;
	al_get_keyboard_state(&key_state);
	if (al_key_down(&key_state,key)) return 1;
	return 0;
}


void ts_ctr_init(void)
{
	int n_joy=0;
	int res=0;
	#ifdef TARGET_GP2X
	int i=0;
	#endif
	#ifdef TARGET_WII
	int i=0;
	#endif
	#ifdef TARGET_IPHONE
	#endif

	tsh->ctr=(TS_Control *)ts_malloc(sizeof(TS_Control));
	res=al_install_keyboard();
	if (res) tsh->ctr->keyboard_on=1; else tsh->ctr->keyboard_on=0;
	res=al_install_joystick();
	if (res) tsh->ctr->joystick_on=1; else tsh->ctr->joystick_on=0;
	res=al_install_mouse();
	if (res) {
		tsh->ctr->mouse_on=1;
	}
	else {
		tsh->ctr->mouse_on=0;
	}
	if (!tsh->ctr->mouse_on && !tsh->ctr->keyboard_on && !tsh->ctr->joystick_on) ts_debug(_("Can't init any control"),TS_FL);
	#ifdef AL5_SUPPORT
	tsh->ctr->mouse_cursor=NULL;
	#endif

	n_joy=al_get_num_joysticks();

	#ifdef TARGET_GP2X
	for (i=0;i<n_joy;i++) tsh->ctr->type[i]=1;
	#endif

	#ifdef TARGET_WII
	for (i=0;i<n_joy;i++) tsh->ctr->type[i]=1;
	#endif
}


void ts_ctr_quit(void)
{
	if (tsh->ctr->mouse_cursor!=NULL) al_destroy_mouse_cursor(tsh->ctr->mouse_cursor);
	tsh->ctr=(TS_Control *)ts_free(tsh->ctr);
}


void ts_ctr_read(void)
{
	int i,a;
	int key=0;
	ALLEGRO_KEYBOARD_STATE key_state;

// Limpiar el buffer de la direccion
	for (i=0;i<TS_MAX_PLAYERS;i++) {
		tsh->ctr->up[i]=0;
		tsh->ctr->down[i]=0;
		tsh->ctr->left[i]=0;
		tsh->ctr->right[i]=0;
		for (a=0;a<TS_MAX_ACTION_BUTTONS;a++) tsh->ctr->action[a][i]=0;
	}

	tsh->ctr->cancel=tsh->ctr->accept=key=0;

	al_get_keyboard_state(&key_state);
/*
	if (al_key_down(&key_state,tsh->cfg->key_cancel)) {
		tsh->ctr->cancel=1;
}
if (al_key_down(&key_state,tsh->cfg->key_accept)) {
tsh->ctr->accept=1;
}

for (i=0;i<TS_MAX_PLAYERS;i++)
{
if (tsh->ctr->type[i]==0)
{
if (al_key_down(&key_state,tsh->cfg->key_up[i])) tsh->ctr->up[i]=1;
if (al_key_down(&key_state,tsh->cfg->key_left[i])) tsh->ctr->left[i]=1;
if (al_key_down(&key_state,tsh->cfg->key_down[i])) tsh->ctr->down[i]=1;
if (al_key_down(&key_state,tsh->cfg->key_right[i])) tsh->ctr->right[i]=1;
for (a=0;a<TS_MAX_ACTION_BUTTONS;a++) {
if (al_key_down(&key_state,tsh->cfg->key_action[a][i])) tsh->ctr->action[a][i]=1;
}
}
}*/
}


int ts_ctr_mouse_get_x(void)
{
	al_get_mouse_state(&tsh->ctr->mouse_state);
	return tsh->ctr->mouse_state.x;
}


int ts_ctr_mouse_get_y(void)
{
	al_get_mouse_state(&tsh->ctr->mouse_state);
	return tsh->ctr->mouse_state.y;
}


void ts_ctr_mouse_set_xy(int x, int y)
{
	al_set_mouse_xy(tsh->gfx->display,x,y);
}


void ts_ctr_mouse_set_cursor(TS_Surface *spr,ushort x, ushort y)
{
	tsh->ctr->mouse_cursor=al_create_mouse_cursor(spr,x,y);
	al_set_mouse_cursor(tsh->gfx->display,tsh->ctr->mouse_cursor);
}


void ts_ctr_mouse_show(void)
{
	al_show_mouse_cursor(tsh->gfx->display);
}


void ts_ctr_mouse_hide(void)
{
	al_hide_mouse_cursor(tsh->gfx->display);
}


uchar ts_ctr_mouse_clicked(uchar button)
{
	al_get_mouse_state(&tsh->ctr->mouse_state);
	if (al_mouse_button_down(&tsh->ctr->mouse_state,button)) return 1;
	return 0;
}
#endif

#ifdef SDL_SUPPORT

void ts_ctr_mouse_set_xy(int x, int y)
{
	SDL_WarpMouse(x,y);
}


int ts_ctr_mouse_get_x(void)
{
	return tsh->ctr->mousex;
}


int ts_ctr_mouse_get_y(void)
{
	return tsh->ctr->mousey;
}


void ts_ctr_mouse_set_cursor(TS_Surface *spr, ushort x, ushort y)
{
	tsh->ctr->cursor=spr;
	tsh->ctr->mousespotx=x;
	tsh->ctr->mousespoty=y;
}


void ts_ctr_mouse_show(void)
{
	SDL_ShowCursor(SDL_ENABLE);
}


void ts_ctr_mouse_hide(void)
{
	SDL_ShowCursor(SDL_DISABLE);
}


uchar ts_ctr_mouse_clicked(uchar button)
{
	switch(button) {
		case 1:
			if (tsh->ctr->mouseb1) return 1;
			break;
		case 2:
			if (tsh->ctr->mouseb2) return 1;
			break;
	}
	return 0;
}


void ts_ctr_init(void)
{
	int n_joy=0;
	#ifdef TARGET_GP2X
	int i=0;
	#endif
	#ifdef TARGET_WII
	int i=0;
	#endif

	tsh->ctr=(TS_Control *)ts_malloc(sizeof(TS_Control));
	n_joy=SDL_NumJoysticks();
	if (n_joy>0) {
		tsh->ctr->joy=SDL_JoystickOpen(0);
		if (tsh->ctr->joy==NULL) {
			ts_debug(_("Joytsick not found!"),TS_FL);
			n_joy=0;
		}
	}
	tsh->ctr->cursor=NULL;

	#ifdef TARGET_GP2X
	for (i=0;i<n_joy;i++) tsh->ctr->type[i]=1;
	#endif

	#ifdef TARGET_WII
	for (i=0;i<n_joy;i++) tsh->ctr->type[i]=1;
	#endif

	#ifdef TARGET_GP2X
	ts_ctr_mouse_hide();
	#endif
}


void ts_ctr_quit(void)
{
	if (tsh->ctr->cursor!=NULL) {
		ts_gfx_free(tsh->ctr->cursor);
	}
	if (tsh->ctr->joy!=NULL) {
		SDL_JoystickClose(tsh->ctr->joy);
	}
	tsh->ctr=(TS_Control *)ts_free(tsh->ctr);
}


void ts_ctr_read(void)
{
	int i,a;
	Uint8 *key=NULL;

// Limpiar el buffer de la direccion

//
	SDL_PollEvent(&tsh->ctr->event);
	switch(tsh->ctr->event.type) {
		case SDL_QUIT:
			tsh->ctr->cancel=1;
			ts_lib_quit();
			break;
		#ifdef TARGET_GP2X
/*			case SDL_JOYAXISMOTION:
				if (tsh->ctr->event.jaxis.which==0) {
					if (tsh->ctr->event.jaxis.axis==0) {
if ((tsh->ctr->event.jaxis.value<-4000) || (tsh->ctr->event.jaxis.value>4000)) {
if (tsh->ctr->event.jaxis.value<0) {
tsh->ctr->left[0]=1;
} else {
tsh->ctr->right[0]=1;
}
}
}
if (tsh->ctr->event.jaxis.axis==1) {
if ((tsh->ctr->event.jaxis.value<-4000) || (tsh->ctr->event.jaxis.value>4000)) {
if (tsh->ctr->event.jaxis.value<0) {
tsh->ctr->up[0]=1;
} else {
tsh->ctr->down[0]=1;
}
}
}
}
break;
*/
		case SDL_JOYBUTTONDOWN:
			if (tsh->ctr->event.jbutton.which==0) {
				if (tsh->ctr->event.jbutton.button==0) {
					tsh->ctr->action[0][0]=1;
				}
				if (tsh->ctr->event.jbutton.button==4) {
					tsh->ctr->action[1][0]=1;
				}
				if (tsh->ctr->event.jbutton.button==2) {
					tsh->ctr->left[0]=1;
				}
				if (tsh->ctr->event.jbutton.button==6) {
					tsh->ctr->right[0]=1;
				}
			}
			break;
		case SDL_JOYBUTTONUP:
			if (tsh->ctr->event.jbutton.which==0) {
				if (tsh->ctr->event.jbutton.button==0) {
					tsh->ctr->action[0][0]=0;
				}
				if (tsh->ctr->event.jbutton.button==4) {
					tsh->ctr->action[1][0]=0;
				}
				if (tsh->ctr->event.jbutton.button==2) {
					tsh->ctr->left[0]=0;
				}
				if (tsh->ctr->event.jbutton.button==6) {
					tsh->ctr->right[0]=0;
				}
			}
			break;
		#endif
	}
	if (tsh->ctr->joy==NULL) {
		for (i=0;i<TS_MAX_PLAYERS;i++) {
			tsh->ctr->up[i]=0;
			tsh->ctr->down[i]=0;
			tsh->ctr->left[i]=0;
			tsh->ctr->right[i]=0;
			for (a=0;a<TS_MAX_ACTION_BUTTONS;a++) tsh->ctr->action[a][i]=0;
		}
		tsh->ctr->cancel=tsh->ctr->accept=0;
		tsh->ctr->mouseb1=0;
		tsh->ctr->mouseb2=0;
	}
//}

	if (SDL_GetMouseState(&tsh->ctr->mousex,&tsh->ctr->mousey) & SDL_BUTTON(1)) {
		tsh->ctr->mouseb1=1;
	}
	if (SDL_GetMouseState(&tsh->ctr->mousex,&tsh->ctr->mousey) & SDL_BUTTON(2)) {
		tsh->ctr->mouseb2=1;
	}
	key=SDL_GetKeyState(NULL);

//if (key[tsh->cfg->key_cancel]) tsh->ctr->cancel=1;
//if (key[tsh->cfg->key_accept]) tsh->ctr->accept=1;
//if (key[SDLK_RETURN] && key[SDLK_SPACE]) ts_gfx_switch_screen_mode();
//if (key[SDLK_PLUS]) ts_sfx_set_volume(1);
//if (key[SDLK_MINUS]) ts_sfx_set_volume(0);
//if (key[SDLK_PAGEUP]) ts_music_set_volume(1);
//if (key[SDLK_PAGEDOWN]) ts_music_set_volume(0);

/*
for (i=0;i<TS_MAX_PLAYERS;i++)
{
if (tsh->ctr->type[i]==0)
{
if (key[tsh->cfg->key_up[i]]) tsh->ctr->up[i]=1;
if (key[tsh->cfg->key_down[i]]) tsh->ctr->down[i]=1;
if (key[tsh->cfg->key_left[i]]) tsh->ctr->left[i]=1;
if (key[tsh->cfg->key_right[i]]) tsh->ctr->right[i]=1;
for (a=0;a<TS_MAX_ACTION_BUTTONS;a++) if (key[tsh->cfg->key_action[a][i]]) tsh->ctr->action[a][i]=1;
}
}
*/
}


unsigned char ts_ctr_key(int key)
{
	Uint8 *keys=NULL;
	SDL_PollEvent(&tsh->ctr->event);
	keys=SDL_GetKeyState(NULL);
	return keys[key];
}
#endif

unsigned char ts_ctr_accept(void) { return tsh->ctr->accept; }

unsigned char ts_ctr_cancel(void) { return tsh->ctr->cancel; }

unsigned char ts_ctr_up(unsigned char player) { return tsh->ctr->up[player]; }

unsigned char ts_ctr_down(unsigned char player) { return tsh->ctr->down[player]; }

unsigned char ts_ctr_left(unsigned char player) { return tsh->ctr->left[player]; }

unsigned char ts_ctr_right(unsigned char player) { return tsh->ctr->right[player]; }

unsigned char ts_ctr_action(unsigned char player, unsigned char act_button) { return tsh->ctr->action[act_button][player]; }

void ts_ctr_clear(void)
{
	int i,a=0;
	for (i=0;i<TS_MAX_PLAYERS;i++) {
		tsh->ctr->up[i]=0;
		tsh->ctr->down[i]=0;
		tsh->ctr->left[i]=0;
		tsh->ctr->right[i]=0;
		for (a=0;a<TS_MAX_ACTION_BUTTONS;a++) tsh->ctr->action[a][i]=0;
	}
	tsh->ctr->cancel=tsh->ctr->accept=0;
}


ushort ts_ctr_get_key(const char *key_name)
{
	if (!strcmp(key_name,"TS_KEY_KP0")) return TS_KEY_KP0;
	if (!strcmp(key_name,"TS_KEY_KP1")) return TS_KEY_KP1;
	if (!strcmp(key_name,"TS_KEY_KP2")) return TS_KEY_KP2;
	if (!strcmp(key_name,"TS_KEY_KP3")) return TS_KEY_KP3;
	if (!strcmp(key_name,"TS_KEY_KP4")) return TS_KEY_KP4;
	if (!strcmp(key_name,"TS_KEY_KP5")) return TS_KEY_KP5;
	if (!strcmp(key_name,"TS_KEY_KP6")) return TS_KEY_KP6;
	if (!strcmp(key_name,"TS_KEY_KP7")) return TS_KEY_KP7;
	if (!strcmp(key_name,"TS_KEY_KP8")) return TS_KEY_KP8;
	if (!strcmp(key_name,"TS_KEY_KP9")) return TS_KEY_KP9;
	if (!strcmp(key_name,"TS_KEY_0")) return TS_KEY_0;
	if (!strcmp(key_name,"TS_KEY_1")) return TS_KEY_1;
	if (!strcmp(key_name,"TS_KEY_2")) return TS_KEY_2;
	if (!strcmp(key_name,"TS_KEY_3")) return TS_KEY_3;
	if (!strcmp(key_name,"TS_KEY_4")) return TS_KEY_4;
	if (!strcmp(key_name,"TS_KEY_5")) return TS_KEY_5;
	if (!strcmp(key_name,"TS_KEY_6")) return TS_KEY_6;
	if (!strcmp(key_name,"TS_KEY_7")) return TS_KEY_7;
	if (!strcmp(key_name,"TS_KEY_8")) return TS_KEY_8;
	if (!strcmp(key_name,"TS_KEY_9")) return TS_KEY_9;
	if (!strcmp(key_name,"TS_KEY_A")) return TS_KEY_A;
	if (!strcmp(key_name,"TS_KEY_B")) return TS_KEY_B;
	if (!strcmp(key_name,"TS_KEY_C")) return TS_KEY_C;
	if (!strcmp(key_name,"TS_KEY_D")) return TS_KEY_D;
	if (!strcmp(key_name,"TS_KEY_E")) return TS_KEY_E;
	if (!strcmp(key_name,"TS_KEY_F")) return TS_KEY_F;
	if (!strcmp(key_name,"TS_KEY_G")) return TS_KEY_G;
	if (!strcmp(key_name,"TS_KEY_H")) return TS_KEY_H;
	if (!strcmp(key_name,"TS_KEY_I")) return TS_KEY_I;
	if (!strcmp(key_name,"TS_KEY_J")) return TS_KEY_J;
	if (!strcmp(key_name,"TS_KEY_K")) return TS_KEY_K;
	if (!strcmp(key_name,"TS_KEY_L")) return TS_KEY_L;
	if (!strcmp(key_name,"TS_KEY_M")) return TS_KEY_M;
	if (!strcmp(key_name,"TS_KEY_N")) return TS_KEY_N;
	if (!strcmp(key_name,"TS_KEY_O")) return TS_KEY_O;
	if (!strcmp(key_name,"TS_KEY_P")) return TS_KEY_P;
	if (!strcmp(key_name,"TS_KEY_Q")) return TS_KEY_Q;
	if (!strcmp(key_name,"TS_KEY_R")) return TS_KEY_R;
	if (!strcmp(key_name,"TS_KEY_S")) return TS_KEY_S;
	if (!strcmp(key_name,"TS_KEY_T")) return TS_KEY_T;
	if (!strcmp(key_name,"TS_KEY_U")) return TS_KEY_U;
	if (!strcmp(key_name,"TS_KEY_V")) return TS_KEY_V;
	if (!strcmp(key_name,"TS_KEY_W")) return TS_KEY_W;
	if (!strcmp(key_name,"TS_KEY_X")) return TS_KEY_X;
	if (!strcmp(key_name,"TS_KEY_Y")) return TS_KEY_Y;
	if (!strcmp(key_name,"TS_KEY_Z")) return TS_KEY_Z;
	if (!strcmp(key_name,"TS_KEY_ENTER")) return TS_KEY_ENTER;
	if (!strcmp(key_name,"TS_KEY_ESCAPE")) return TS_KEY_ESCAPE;
	if (!strcmp(key_name,"TS_KEY_SPACE")) return TS_KEY_SPACE;
	if (!strcmp(key_name,"TS_KEY_TAB")) return TS_KEY_TAB;
	if (!strcmp(key_name,"TS_KEY_LEFT_CONTROL")) return TS_KEY_LEFT_CONTROL;
	if (!strcmp(key_name,"TS_KEY_LEFT_ALT")) return TS_KEY_LEFT_ALT;
	if (!strcmp(key_name,"TS_KEY_LEFT_SHIFT")) return TS_KEY_LEFT_SHIFT;
	if (!strcmp(key_name,"TS_KEY_RIGHT_CONTROL")) return TS_KEY_RIGHT_CONTROL;
	if (!strcmp(key_name,"TS_KEY_RIGHT_ALT")) return TS_KEY_RIGHT_ALT;
	if (!strcmp(key_name,"TS_KEY_RIGHT_SHIFT")) return TS_KEY_RIGHT_SHIFT;
	if (!strcmp(key_name,"TS_KEY_F1")) return TS_KEY_F1;
	if (!strcmp(key_name,"TS_KEY_F2")) return TS_KEY_F2;
	if (!strcmp(key_name,"TS_KEY_F3")) return TS_KEY_F3;
	if (!strcmp(key_name,"TS_KEY_F4")) return TS_KEY_F4;
	if (!strcmp(key_name,"TS_KEY_F5")) return TS_KEY_F5;
	if (!strcmp(key_name,"TS_KEY_F6")) return TS_KEY_F6;
	if (!strcmp(key_name,"TS_KEY_F7")) return TS_KEY_F7;
	if (!strcmp(key_name,"TS_KEY_F8")) return TS_KEY_F8;
	if (!strcmp(key_name,"TS_KEY_F9")) return TS_KEY_F9;
	if (!strcmp(key_name,"TS_KEY_F10")) return TS_KEY_F10;
	if (!strcmp(key_name,"TS_KEY_F11")) return TS_KEY_F11;
	if (!strcmp(key_name,"TS_KEY_F12")) return TS_KEY_F12;
	if (!strcmp(key_name,"TS_KEY_UP")) return TS_KEY_UP;
	if (!strcmp(key_name,"TS_KEY_DOWN")) return TS_KEY_DOWN;
	if (!strcmp(key_name,"TS_KEY_LEFT")) return TS_KEY_LEFT;
	if (!strcmp(key_name,"TS_KEY_RIGHT")) return TS_KEY_RIGHT;
	if (!strcmp(key_name,"TS_KEY_PG_UP")) return TS_KEY_PG_UP;
	if (!strcmp(key_name,"TS_KEY_PG_DOWN")) return TS_KEY_PG_DOWN;

	return 0;
}


EXPORT int tl_ctr_read(TS_Lua *ls)
{
	ts_ctr_read();
	return 0;
}


EXPORT int tl_ctr_clear(TS_Lua *ls)
{
	ts_ctr_clear();
	return 0;
}


EXPORT int tl_ctr_accept(TS_Lua *ls)
{
	int res=0;
	res=ts_ctr_accept();
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_ctr_cancel(TS_Lua *ls)
{
	int res=0;
	res=ts_ctr_cancel();
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_ctr_up(TS_Lua *ls)
{
	int res=0;
	int player=0;
	player=(int)ts_lua_tonumber(ls,1);
	res=ts_ctr_up(player);
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_ctr_down(TS_Lua *ls)
{
	int res=0;
	int player=0;
	player=(int)ts_lua_tonumber(ls,1);
	res=ts_ctr_down(player);
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_ctr_left(TS_Lua *ls)
{
	int res=0;
	int player=0;
	player=(int)ts_lua_tonumber(ls,1);
	res=ts_ctr_left(player);
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_ctr_right(TS_Lua *ls)
{
	int res=0;
	int player=0;
	player=(int)ts_lua_tonumber(ls,1);
	res=ts_ctr_right(player);
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_ctr_action(TS_Lua *ls)
{
	int res=0;
	int player=0;
	int button=0;
	player=(int)ts_lua_tonumber(ls,1);
	button=(int)ts_lua_tonumber(ls,2);
	res=ts_ctr_action(player,button);
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_ctr_key(TS_Lua *ls)
{
	int res=0;
	res=ts_ctr_key((int)ts_lua_tonumber(ls,1));
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_ctr_get_key(TS_Lua *ls)
{
	ushort res=0;
	res=ts_ctr_get_key(ts_lua_tostring(ls,1));
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_ctr_mouse_clicked(TS_Lua *ls)
{
	uchar res=0;
//res=ts_ctr_mouse_clicked(ts_lua_tonumber(ls,1));
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_ctr_mouse_show(TS_Lua *ls)
{
//ts_ctr_mouse_show();
	return 0;
}


EXPORT int tl_ctr_mouse_hide(TS_Lua *ls)
{
//ts_ctr_mouse_hide();
	return 0;
}


EXPORT int tl_ctr_mouse_get_x(TS_Lua *ls)
{
	int a=0;
//a=ts_ctr_mouse_get_x();
	ts_lua_pushnumber(ls,a);
	return 1;
}


EXPORT int tl_ctr_mouse_get_y(TS_Lua *ls)
{
	int a=0;
//a=ts_ctr_mouse_get_y();
	ts_lua_pushnumber(ls,a);
	return 1;
}


EXPORT int tl_ctr_mouse_set_xy(TS_Lua *ls)
{
//	ts_ctr_mouse_set_xy(ts_lua_tonumber(ls,1),ts_lua_tonumber(ls,2));
	return 0;
}
