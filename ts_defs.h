#ifndef TS_DEFS_H
#define TS_DEFS_H

//#define UBUNTU_LINUX

#define SDL_SUPPORT

#ifdef AL4_SUPPORT
#undef AL5_SUPPORT
#undef SDL_SUPPORT
#endif

#ifdef AL5_SUPPORT
#undef AL4_SUPPORT
#undef SDL_SUPPORT
#endif

#ifdef SDL_SUPPORT
#undef AL5_SUPPORT
#undef AL4_SUPPORT
#endif

#define TS_MAX_STRING 1024

#ifdef AL4_SUPPORT
#include <allegro.h>
#include <loadpng.h>
#endif

#ifdef AL5_SUPPORT
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#ifndef WIN32
#include <allegro5/allegro_opengl.h>
#else
#include <allegro5/allegro_direct3d.h>
#endif
#endif

#ifdef SDL_SUPPORT
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#endif

#ifdef __cplusplus
extern "C"
{
	#endif

	#ifdef UBUNTU_LINUX
	#include <lua5.1/lua.h>
	#include <lua5.1/lauxlib.h>
	#include <lua5.1/lualib.h>
	#else
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
	#endif

	#ifdef __cplusplus
}
#endif

/*
	Constants: Valores de retorno

TS_OK - Se devuelve cuando todo va bien, 0 por defecto.
TS_ERROR - Se devuelve cuando ha habido algun problema, -1 por defecto.
*/
#define TS_OK 0
#define TS_ERROR -1

// Define: TS_USES_SDL
// La funcion ts_lib_uses devuelve este valor si se ha enlazado con SDL 1.2
#define TS_USES_SDL 0
// Define: TS_USES_AL5
// La funcion ts_lib_uses devuelve este valor si se ha enlazado con Allegro 5
#define TS_USES_AL5 1
// Define: TS_USES_AL4
// La funcion ts_lib_uses devuelve este valor si se ha enlazado con Allegro 4
#define TS_USES_AL4 2

// Macro: TS_FL
// Macro usada internamente para no usar constantemente __FILE__,__LINE__ en las llamadas a ts_debug.
#define TS_FL __FILE__,__LINE__

// Define: TS_DEBUG
// Si la libreria se compila con TS_DEBUG definida, las llamadas a ts_debug mostraran la informacion
// de depuracion por la salida estandar.
#define TS_DEBUG

/*
	Constants: Valores del fichero de configuracion por defecto

TS_CFG_COLOR_DEPTH - Profundidad de color en bits por pixel.
TS_CFG_FULLSCREEN - Un valor mayor que 0 es ejecutar a pantalla completa, 0 en ventana.
TS_CFG_XRES - Resolucion horizontal del programa.
TS_CFG_YRES - Resolucion vertical del programa.
TS_CFG_XRES_SCALED - Resolucion horizontal del programa escalado, esta es la resolucion a la que
se creara la ventana de la aplicacion.
TS_CFG_YRES_SCALED - Resolucion vertical del programa escalado, esta es la resolucion a la que
se creara la ventana de la aplicacion.
TS_CFG_LOCALE_PATH - Directorio donde se buscaran las traducciones.
*/
#define TS_CFG_COLOR_DEPTH 32
#define TS_CFG_FULLSCREEN 0
#define TS_CFG_XRES 1024
#define TS_CFG_YRES 768
#define TS_CFG_XRES_SCALED 1024
#define TS_CFG_YRES_SCALED 768
#define TS_CFG_SFX_ON 1
#define TS_CFG_MUSIC_ON 1
#define TS_CFG_SFX_VOL 255
#define TS_CFG_MUSIC_VOL 255
#define TS_CFG_LOCALE_PATH "data/locale"

// Constant: TS_LOG
// Valor por defecto de la variable que controla si las llamadas a ts_log deben escribir el registro o no.
#define TS_LOG 1

// Constant: TS_FPS
// Valor por defecto que se le dara al framerate del programa. Se puede cambiar este valor con la
// funcion <ts_timer_set_speed_regulation>.
#define TS_FPS 30

// Define: TS_MAX
// Macro que devuelve el valor maximo de 2 valores dados.
#define TS_MAX(a, b) (a > b ? a : b)

// Define: TS_MIN
// Macro que devuelve el valor minimo de 2 valores dados.
#define TS_MIN(a, b) (a < b ? a : b)

#define TS_MAX_PLAYERS 1
#define TS_MAX_ACTION_BUTTONS 8

typedef unsigned short int ushort;
typedef signed short int sshort;
typedef unsigned char uchar;
typedef signed char schar;
typedef unsigned int uint;
typedef signed int sint;
typedef unsigned long int ulong;
typedef signed long int slong;
#endif
