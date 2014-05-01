#ifndef TS_TRANSLATOR_H
#define TS_TRANSLATOR_H

#include "ts_lua.h"

/*
Function: ts_translate

Descripcion:
Traduce una cadena de texto mediante gettext, TSLib usa como nombre de
dominio para la funcion bindtextdomain la primera cadena que se pasa a
<ts_lib_init>, esto basicamente quiere decir que los ficheros .mo se deberan
llamar igual que el nombre de dominio + .mo. El directorio para buscar las
traducciones es la cadena definida por <TS_CFG_LOCALE_PATH>

Parametros:
cad - Es la cadena que pasaremos a la funcion gettext para que la busque
en el fichero de traducciones.

Devuelve:
La cadena traducida o la misma sin traducir si ha habido algun error.

Ver tambien:
<ts_lib_init>
*/
const char * ts_translate(const char *cad);
EXPORT int tl_translate(TS_Lua *ls);
#endif																						// TS_TRANSLATOR_H
