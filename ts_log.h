#ifndef TS_LOG_H
#define TS_LOG_H

#include "ts_lua.h"

/*
	Function: ts_log

Escribe una cadena de texto en el fichero de registro.

Parametros:
format - Cadena de estilo 'printf' con el texto que queremos poner en
el fichero de registro. El fichero de registro se llama nombre_de_programa.log,
siendo nombre_de_programa el nombre que se le pasa al programa con la funcion
<ts_lib_init>

Ver tambien:
<ts_lib_init>
*/
void ts_log ( char *format,... );
EXPORT int tl_log(TS_Lua *ls);

/*
	Function: ts_log_init

Inicia la memoria utilizada por la estructura TS_Log y crea el nombre del fichero
de registro. Esta funcion se usa internamente por TSLib y no deberia ser utilizada
en tu programa.

Devuelve:

TS_OK si todo ha ido bien, TS_ERROR si se ha producido algun error.
*/
schar ts_log_init(void);

/*
	Function: ts_log_quit

Libera la memoria utilizada por la estructura TS_Log. Esta funcion se usa internamente
por TSLib y no deberia ser utilizada en tu programa.
*/
void ts_log_quit(void);

/*
	Function: ts_log_set_active

Se utiliza para decir si queremos que el programa cree un archivo de registro o no.

Parametros:
log_active - Si es 0 no se crea el archivo de registro, de lo contrario si. El valor
por defecto de esta variable viene dada por la constante TS_LOG.
*/
void ts_log_set_active(schar log_active);
EXPORT int tl_log_set_active(TS_Lua *ls);
#endif																						// TS_LOG_H
