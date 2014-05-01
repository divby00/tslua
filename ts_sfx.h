#ifndef _TS_SFX_H
#define _TS_SFX_H

#include "ts_defs.h"
#include "ts_struct.h"
#include "ts_dll.h"

/*
	Function: ts_sfx_init

Descripcion:
Inicia el sonido y los efectos sonoros. Esta funcion es de uso interno de TSLib y
no deberias usarla en tu programa.
*/
schar ts_sfx_init(void);

/*
	Function: ts_sfx_quit

Descripcion:
Quita el sistema de sonido. Esta funcion es de uso interno de TSLib y no deberias
usarla en tu programa.
*/
void ts_sfx_quit(void);

/*
	Function: ts_sfx_load

Descripcion:
Carga un archivo de sonido.

Parametros:
filename - Nombre del archivo con el wav que queremos cargar.

Devuelve:
Un TS_Sample listo para ser reproducido, o NULL si ha habido
algun error.
*/
TS_Sample * ts_sfx_load(const char *filename);
EXPORT int tl_sfx_load(TS_Lua *ls);

/*
	Function: ts_sfx_free

Descripcion:
Libera la memoria usada por un TS_Sample

Parametros:
sample - El TS_Sample que queremos liberar.
*/
void ts_sfx_free(TS_Sample *sample);
EXPORT int tl_sfx_free(TS_Lua *ls);

/*
	Function: ts_sfx_play

Descripcion: Reproduce un sonido

Parametros:
sample - El TS_Sample que queremos reproducir.
*/
void ts_sfx_play(TS_Sample *sample);
EXPORT int tl_sfx_play(TS_Lua *ls);

/*
	Function: ts_sfx_play_volume

Descripcion: Reproduce un sonido con un volumen que queda definido por la
distancia que separa al emisor (en el juego) del receptor (en el juego).
El algoritmo para calcular el volumen es el siguiente: se calcula el modulo
del vector que forma los puntos (x1,y1) e (x2,y2) con el teorema de pitagoras:
modulo=sqrt((|(x1-x2)|^2)+(|(y1-y2)|^2)), por otro lado se precalcula el
valor máximo que puede tener la hipotenusa según el campo de visión del
juego:
valor_maximo_hipotenusa=sqrt((horizontal^2)+(vertical^2)) siendo horizontal
el valor en pixels del campo de juego en la coordenada X y vertical el valor
de la coordenada Y.
Con este resultado se realiza la regla de 3:
volumen=(max_volume*modulo)/valor_maximo_hipotenusa, siendo max_volume-volumen
el resultado final que se usará y max_volume un valor que es 128 para SDL y
255 para Allegro.

Parametros:
sample - El TS_Sample que queremos reproducir.
x1 - Coordenada x del primer punto.
y1 - Coordenada y del primer punto.
x2 - Coordenada x del segundo punto.
y2 - Coordenada y del segundo punto.
*/
void ts_sfx_play_volume(TS_Sample *sample, sshort x1, sshort y1, sshort x2, sshort y2);
EXPORT int tl_sfx_play_volume(TS_Lua *ls);

/*
 */
void ts_sfx_set_volume(uchar vol);
EXPORT int tl_sfx_set_volume(TS_Lua *ls);

void ts_sfx_play_freq(TS_Sample *sample, ushort freq);
#endif
