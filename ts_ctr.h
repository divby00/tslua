#ifndef TS_CTR_H
#define TS_CTR_H

#include "ts_dll.h"
#include "ts_lua.h"
#include "ts_defs.h"
#include "ts_struct.h"

#ifdef AL4_SUPPORT
#define TS_KEY_A KEY_A
#define TS_KEY_B KEY_B
#define TS_KEY_C KEY_C
#define TS_KEY_D KEY_D
#define TS_KEY_E KEY_E
#define TS_KEY_F KEY_F
#define TS_KEY_G KEY_G
#define TS_KEY_H KEY_H
#define TS_KEY_I KEY_I
#define TS_KEY_J KEY_J
#define TS_KEY_K KEY_K
#define TS_KEY_L KEY_L
#define TS_KEY_M KEY_M
#define TS_KEY_N KEY_N
#define TS_KEY_O KEY_O
#define TS_KEY_P KEY_P
#define TS_KEY_Q KEY_Q
#define TS_KEY_R KEY_R
#define TS_KEY_S KEY_S
#define TS_KEY_T KEY_T
#define TS_KEY_U KEY_U
#define TS_KEY_V KEY_V
#define TS_KEY_W KEY_W
#define TS_KEY_X KEY_X
#define TS_KEY_Y KEY_Y
#define TS_KEY_Z KEY_Z
#define TS_KEY_1 KEY_1
#define TS_KEY_2 KEY_2
#define TS_KEY_3 KEY_3
#define TS_KEY_4 KEY_4
#define TS_KEY_5 KEY_5
#define TS_KEY_6 KEY_6
#define TS_KEY_7 KEY_7
#define TS_KEY_8 KEY_8
#define TS_KEY_9 KEY_9
#define TS_KEY_0 KEY_0
#define TS_KEY_F1 KEY_F1
#define TS_KEY_F2 KEY_F2
#define TS_KEY_F3 KEY_F3
#define TS_KEY_F4 KEY_F4
#define TS_KEY_F5 KEY_F5
#define TS_KEY_F6 KEY_F6
#define TS_KEY_F7 KEY_F7
#define TS_KEY_F8 KEY_F8
#define TS_KEY_F9 KEY_F9
#define TS_KEY_F10 KEY_F10
#define TS_KEY_F11 KEY_F11
#define TS_KEY_F12 KEY_F12
#define TS_KEY_UP KEY_UP
#define TS_KEY_DOWN KEY_DOWN
#define TS_KEY_RIGHT KEY_RIGHT
#define TS_KEY_LEFT KEY_LEFT
#define TS_KEY_TAB KEY_TAB
#define TS_KEY_ESCAPE KEY_ESC
#define TS_KEY_SPACE KEY_SPACE
#define TS_KEY_ENTER KEY_ENTER
#define TS_KEY_KP1 KEY_1_PAD
#define TS_KEY_KP2 KEY_2_PAD
#define TS_KEY_KP3 KEY_3_PAD
#define TS_KEY_KP4 KEY_4_PAD
#define TS_KEY_KP5 KEY_5_PAD
#define TS_KEY_KP6 KEY_6_PAD
#define TS_KEY_KP7 KEY_7_PAD
#define TS_KEY_KP8 KEY_8_PAD
#define TS_KEY_KP9 KEY_9_PAD
#define TS_KEY_KP0 KEY_0_PAD
#define TS_KEY_LEFT_SHIFT KEY_LSHIFT
#define TS_KEY_LEFT_CONTROL KEY_LCONTROL
#define TS_KEY_LEFT_ALT KEY_ALT
#define TS_KEY_RIGHT_SHIFT KEY_RSHIFT
#define TS_KEY_RIGHT_CONTROL KEY_RCONTROL
#define TS_KEY_RIGHT_ALT KEY_ALTGR
#define TS_KEY_PG_UP KEY_PGUP
#define TS_KEY_PG_DOWN KEY_PGDN
#endif

#ifdef AL5_SUPPORT
#define TS_KEY_A ALLEGRO_KEY_A
#define TS_KEY_B ALLEGRO_KEY_B
#define TS_KEY_C ALLEGRO_KEY_C
#define TS_KEY_D ALLEGRO_KEY_D
#define TS_KEY_E ALLEGRO_KEY_E
#define TS_KEY_F ALLEGRO_KEY_F
#define TS_KEY_G ALLEGRO_KEY_G
#define TS_KEY_H ALLEGRO_KEY_H
#define TS_KEY_I ALLEGRO_KEY_I
#define TS_KEY_J ALLEGRO_KEY_J
#define TS_KEY_K ALLEGRO_KEY_K
#define TS_KEY_L ALLEGRO_KEY_L
#define TS_KEY_M ALLEGRO_KEY_M
#define TS_KEY_N ALLEGRO_KEY_N
#define TS_KEY_O ALLEGRO_KEY_O
#define TS_KEY_P ALLEGRO_KEY_P
#define TS_KEY_Q ALLEGRO_KEY_Q
#define TS_KEY_R ALLEGRO_KEY_R
#define TS_KEY_S ALLEGRO_KEY_S
#define TS_KEY_T ALLEGRO_KEY_T
#define TS_KEY_U ALLEGRO_KEY_U
#define TS_KEY_V ALLEGRO_KEY_V
#define TS_KEY_W ALLEGRO_KEY_W
#define TS_KEY_X ALLEGRO_KEY_X
#define TS_KEY_Y ALLEGRO_KEY_Y
#define TS_KEY_Z ALLEGRO_KEY_Z
#define TS_KEY_1 ALLEGRO_KEY_1
#define TS_KEY_2 ALLEGRO_KEY_2
#define TS_KEY_3 ALLEGRO_KEY_3
#define TS_KEY_4 ALLEGRO_KEY_4
#define TS_KEY_5 ALLEGRO_KEY_5
#define TS_KEY_6 ALLEGRO_KEY_6
#define TS_KEY_7 ALLEGRO_KEY_7
#define TS_KEY_8 ALLEGRO_KEY_8
#define TS_KEY_9 ALLEGRO_KEY_9
#define TS_KEY_0 ALLEGRO_KEY_0
#define TS_KEY_F1 ALLEGRO_KEY_F1
#define TS_KEY_F2 ALLEGRO_KEY_F2
#define TS_KEY_F3 ALLEGRO_KEY_F3
#define TS_KEY_F4 ALLEGRO_KEY_F4
#define TS_KEY_F5 ALLEGRO_KEY_F5
#define TS_KEY_F6 ALLEGRO_KEY_F6
#define TS_KEY_F7 ALLEGRO_KEY_F7
#define TS_KEY_F8 ALLEGRO_KEY_F8
#define TS_KEY_F9 ALLEGRO_KEY_F9
#define TS_KEY_F10 ALLEGRO_KEY_F10
#define TS_KEY_F11 ALLEGRO_KEY_F11
#define TS_KEY_F12 ALLEGRO_KEY_F12
#define TS_KEY_UP ALLEGRO_KEY_UP
#define TS_KEY_DOWN ALLEGRO_KEY_DOWN
#define TS_KEY_RIGHT ALLEGRO_KEY_RIGHT
#define TS_KEY_LEFT ALLEGRO_KEY_LEFT
#define TS_KEY_TAB ALLEGRO_KEY_TAB
#define TS_KEY_ESCAPE ALLEGRO_KEY_ESCAPE
#define TS_KEY_SPACE ALLEGRO_KEY_SPACE
#define TS_KEY_ENTER ALLEGRO_KEY_ENTER
#define TS_KEY_KP1 ALLEGRO_KEY_PAD_1
#define TS_KEY_KP2 ALLEGRO_KEY_PAD_2
#define TS_KEY_KP3 ALLEGRO_KEY_PAD_3
#define TS_KEY_KP4 ALLEGRO_KEY_PAD_4
#define TS_KEY_KP5 ALLEGRO_KEY_PAD_5
#define TS_KEY_KP6 ALLEGRO_KEY_PAD_6
#define TS_KEY_KP7 ALLEGRO_KEY_PAD_7
#define TS_KEY_KP8 ALLEGRO_KEY_PAD_8
#define TS_KEY_KP9 ALLEGRO_KEY_PAD_9
#define TS_KEY_KP0 ALLEGRO_KEY_PAD_0
#define TS_KEY_LEFT_SHIFT ALLEGRO_KEY_LSHIFT
#define TS_KEY_LEFT_CONTROL ALLEGRO_KEY_LCTRL
#define TS_KEY_LEFT_ALT ALLEGRO_KEY_ALT
#define TS_KEY_RIGHT_SHIFT ALLEGRO_KEY_RSHIFT
#define TS_KEY_RIGHT_CONTROL ALLEGRO_KEY_RCTRL
#define TS_KEY_RIGHT_ALT ALLEGRO_KEY_ALTGR
#define TS_KEY_PG_UP ALLEGRO_KEY_PGUP
#define TS_KEY_PG_DOWN ALLEGRO_KEY_PGDN
#endif

#ifdef SDL_SUPPORT
#include <SDL/SDL.h>
#define TS_KEY_A SDLK_a
#define TS_KEY_B SDLK_b
#define TS_KEY_C SDLK_c
#define TS_KEY_D SDLK_d
#define TS_KEY_E SDLK_e
#define TS_KEY_F SDLK_f
#define TS_KEY_G SDLK_g
#define TS_KEY_H SDLK_h
#define TS_KEY_I SDLK_i
#define TS_KEY_J SDLK_j
#define TS_KEY_K SDLK_k
#define TS_KEY_L SDLK_l
#define TS_KEY_M SDLK_m
#define TS_KEY_N SDLK_n
#define TS_KEY_O SDLK_o
#define TS_KEY_P SDLK_p
#define TS_KEY_Q SDLK_q
#define TS_KEY_R SDLK_r
#define TS_KEY_S SDLK_s
#define TS_KEY_T SDLK_t
#define TS_KEY_U SDLK_u
#define TS_KEY_V SDLK_v
#define TS_KEY_W SDLK_w
#define TS_KEY_X SDLK_x
#define TS_KEY_Y SDLK_y
#define TS_KEY_Z SDLK_z
#define TS_KEY_1 SDLK_1
#define TS_KEY_2 SDLK_2
#define TS_KEY_3 SDLK_3
#define TS_KEY_4 SDLK_4
#define TS_KEY_5 SDLK_5
#define TS_KEY_6 SDLK_6
#define TS_KEY_7 SDLK_7
#define TS_KEY_8 SDLK_8
#define TS_KEY_9 SDLK_9
#define TS_KEY_0 SDLK_0
#define TS_KEY_UP SDLK_UP
#define TS_KEY_DOWN SDLK_DOWN
#define TS_KEY_LEFT SDLK_LEFT
#define TS_KEY_RIGHT SDLK_RIGHT
#define TS_KEY_PG_UP SDLK_PAGEUP
#define TS_KEY_PG_DOWN SDLK_PAGEDOWN
#define TS_KEY_F1 SDLK_F1
#define TS_KEY_F2 SDLK_F2
#define TS_KEY_F3 SDLK_F3
#define TS_KEY_F4 SDLK_F4
#define TS_KEY_F5 SDLK_F5
#define TS_KEY_F6 SDLK_F6
#define TS_KEY_F7 SDLK_F7
#define TS_KEY_F8 SDLK_F8
#define TS_KEY_F9 SDLK_F9
#define TS_KEY_F10 SDLK_F10
#define TS_KEY_F11 SDLK_F11
#define TS_KEY_F12 SDLK_F12
#define TS_KEY_ENTER SDLK_RETURN
#define TS_KEY_ESCAPE SDLK_ESCAPE
#define TS_KEY_TAB SDLK_TAB
#define TS_KEY_SPACE SDLK_SPACE
#define TS_KEY_KP0 SDLK_KP0
#define TS_KEY_KP1 SDLK_KP1
#define TS_KEY_KP2 SDLK_KP2
#define TS_KEY_KP3 SDLK_KP3
#define TS_KEY_KP4 SDLK_KP4
#define TS_KEY_KP5 SDLK_KP5
#define TS_KEY_KP6 SDLK_KP6
#define TS_KEY_KP7 SDLK_KP7
#define TS_KEY_KP8 SDLK_KP8
#define TS_KEY_KP9 SDLK_KP9
#define TS_KEY_LEFT_CONTROL SDLK_LCTRL
#define TS_KEY_LEFT_ALT SDLK_LALT
#define TS_KEY_RIGHT_CONTROL SDLK_RCTRL
#define TS_KEY_RIGHT_ALT SDLK_RALT
#define TS_KEY_LEFT_SHIFT SDLK_LSHIFT
#define TS_KEY_RIGHT_SHIFT SDLK_RSHIFT
#define TS_BUTTON1  SDL_BUTTON_LEFT
#define TS_BUTTON2  SDL_BUTTON_RIGHT
#endif

/*
	Function: ts_ctr_init

Descripcion:
Inicia el sistema de control de TSLib. Esta funcion la llama internamente TSLib y
no deberias usarla en tu codigo.
*/
void ts_ctr_init(void);

/*
	Function: ts_ctr_quit

Descripcion:
Finaliza el sistema de control de TSLib. Esta funcion la llama internamente TSLib y
no deberias usarla en tu codigo.
*/
void ts_ctr_quit(void);

unsigned char ts_ctr_accept(void);
unsigned char ts_ctr_cancel(void);
unsigned char ts_ctr_up(unsigned char player);
unsigned char ts_ctr_down(unsigned char player);
unsigned char ts_ctr_left(unsigned char player);
unsigned char ts_ctr_right(unsigned char player);
unsigned char ts_ctr_action(unsigned char player, unsigned char act_button);

/*
	Function: ts_ctr_quit

Descripcion:
Lee los dispositivos de control. Debes llamar a esta funcion para
actualizar los valores de la estructura TS_Control, que se consulta
mediante la funcion ts_ctr_key.

Ver tambien:
<ts_ctr_key>
*/
void ts_ctr_read(void);
void ts_ctr_clear(void);
unsigned char ts_ctr_key(int key);
ushort ts_ctr_get_key(const char *key_name);
int ts_ctr_mouse_get_x(void);
int ts_ctr_mouse_get_y(void);
void ts_ctr_mouse_set_xy(int x, int y);
void ts_ctr_mouse_show(void);
void ts_ctr_mouse_hide(void);
uchar ts_ctr_mouse_clicked(uchar button);

EXPORT int tl_ctr_key(TS_Lua *ls);
EXPORT int tl_ctr_read(TS_Lua *ls);
EXPORT int tl_ctr_accept(TS_Lua *ls);
EXPORT int tl_ctr_cancel(TS_Lua *ls);
EXPORT int tl_ctr_up(TS_Lua *ls);
EXPORT int tl_ctr_down(TS_Lua *ls);
EXPORT int tl_ctr_left(TS_Lua *ls);
EXPORT int tl_ctr_right(TS_Lua *ls);
EXPORT int tl_ctr_action(TS_Lua *ls);
EXPORT int tl_ctr_clear(TS_Lua *ls);
EXPORT int tl_ctr_get_key(TS_Lua *ls);
EXPORT int tl_ctr_mouse_clicked(TS_Lua *ls);
EXPORT int tl_ctr_mouse_show(TS_Lua *ls);
EXPORT int tl_ctr_mouse_hide(TS_Lua *ls);
EXPORT int tl_ctr_mouse_get_x(TS_Lua *ls);
EXPORT int tl_ctr_mouse_get_y(TS_Lua *ls);
EXPORT int tl_ctr_mouse_set_xy(TS_Lua *ls);
#endif																						// TS_CTR_H
