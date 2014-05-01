#ifndef TS_CFG_H
#define TS_CFG_H

#include "ts_defs.h"

/*
	Function: ts_cfg_init

Descripcion:
Inicia los datos de la estructura de configuracion, reserva la memoria para ellos,
y hace alguna cosilla mas. Esta funcion se usa internamente por TSLib y no deberias
utilizarla.
*/
void ts_cfg_init(void);

/*
	Function: ts_cfg_quit

Descripcion:
Libera la memoria usada por la estructura de configuracion. Esta funcion se usa
internamente por TSLib y no deberias utilizarla.
*/
void ts_cfg_quit(void);

/*
	Function: ts_cfg_defaults

Descripcion:
Pone los datos por defecto en la estructura de configuracion. Esta funcion se usa
internamente por TSLib y no deberias utilizarla.
*/
void ts_cfg_set_defaults(void);

/*
	Function: ts_cfg_save

Descripcion:
Graba el archivo de configuracion en el directorio de trabajo. Este archivo se denomina
nombre_de_programa.cfg, siendo nombre de programa el nombre que se le pasa al programa
en la funcion <ts_lib_init>.

Devuelve:
TS_OK si no ha habido ningun problema, TS_ERROR en caso de que no pueda grabar el archivo,
si esto ocurre, pone los valores por defecto en la estructura de configuracion.

Ver tambien:
<ts_lib_init>
*/
schar ts_cfg_save(void);

/*
	Function: ts_cfg_load

Descripcion:
Carga el archivo de configuracion. Este archivo se denomina nombre_de_programa.cfg, siendo
nombre de programa el nombre que se le pasa al programa en la funcion <ts_lib_init> y es un
simple archivo con codigo en Lua, se espera que se encuentre en el directorio de trabajo.

Devuelve:
TS_OK si todo va bien, TS_ERROR en caso de que no pueda cargar el archivo bien porque no exista,
bien porque la sintaxis del archivo no sea compatible con el interprete de Lua.

Ver tambien:
<ts_lib_init>
*/
schar ts_cfg_load(void);
#endif																						// TS_CFG_H
