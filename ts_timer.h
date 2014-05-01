#ifndef TS_TIMER_H
#define TS_TIMER_H

#include "ts_defs.h"
#include "ts_lua.h"

/*
	Function: ts_timer_incrementor

Descripcion:
Solo esta disponible si se usa Allegro 4.
Se usa internamente por TSLib y no deberias usarla en tu programa.
*/
void ts_timer_incrementor(void);

/*
	Function: ts_timer_init

Descripcion:
Inicia la estructura TS_Timer, es una funcion de uso
interno de TSLib y no deberias usarla en tu programa.
*/
void ts_timer_init(void);

/*
	Function: ts_timer_init_speed_regulation

Descripcion:
Utiliza esta funcion en conjunto con <ts_timer_wait_speed_regulation> para
controlar el framerate de tu programa. Esta funcion debes ponerla al inicio
del bucle principal.

Ver tambien:
<ts_timer_wait_speed_regulation>,
<ts_timer_set_speed_regulation>
*/
void ts_timer_init_speed_regulation(void);
EXPORT int tl_timer_init_speed_regulation(TS_Lua *ls);

/*
	Function: ts_timer_quit

Descripcion:
Libera la memoria utilizada por la estructura TS_Timer, es una funcion de uso
interno de TSLib y no deberias usarla en tu programa.
*/
void ts_timer_quit(void);

/*
	Function: ts_timer_rest

Descripcion:
Espera miliseconds milisegundos antes de proseguir la ejecucion del programa.

Parametros:
miliseconds - Milisegundos que quieres esperar.
*/
void ts_timer_rest(double miliseconds);
EXPORT int tl_timer_rest(TS_Lua *ls);

/*
	Function: ts_timer_set_speed_regulation

Descripcion:
Utiliza esta funcion antes del bucle principal para ajustar el framerate al que
quieres que se ejecute el programa. En caso de que no lo especifiques aqui el
framerate por defecto viene dado por la constante <TS_FPS>.

Parametros:
t - El framerate al que quieres ajustar tu programa.

Ver tambien:
<ts_timer_wait_speed_regulation>,
<ts_timer_init_speed_regulation>,
<TS_FPS>
*/
void ts_timer_set_speed_regulation(int t);
EXPORT int tl_timer_set_speed_regulation(TS_Lua *ls);

/*
	Function: ts_timer_wait_speed_regulation

Descripcion:
Utiliza esta funcion en conjunto con <ts_timer_init_speed_regulation> para
controlar el framerate de tu programa. Esta funcion debes ponerla al final
del bucle principal.

Ver tambien:
<ts_timer_set_speed_regulation>,
<ts_timer_init_speed_regulation>
*/
void ts_timer_wait_speed_regulation(void);
EXPORT int tl_timer_wait_speed_regulation(TS_Lua *ls);
#endif																						// TS_TIMER_H
