#ifndef TS_DEBUG_H
#define TS_DEBUG_H

#include "ts_defs.h"

/*
	Function: ts_debug

Muestra un mensaje de depuracion si se define TS_DEBUG, la funcion es usada
internamente por TSLib, por lo que no deberias usarla en tu codigo. Los 2
ultimos campos se pueden sustituir por la macro TS_FL al estilo:
:ts_debug("Error en funcion X",TS_FL);

Parametros:
cad - Texto para poner con una descripcion del problema.
filename - Nombre del fichero donde se ha producido.
line - Linea del codigo donde se ha producido.

*/
void ts_debug(const char *cad, const char *filename, ulong line);
#endif																						// TS_DEBUG_H
