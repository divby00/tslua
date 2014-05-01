#ifndef TS_GFX_H
#define TS_GFX_H

#include "ts_lua.h"
#include "ts_struct.h"

/*
	Function: ts_gfx_blit

Descripcion:
Dibuja un trozo de una imagen en otra.

Parametros:
src - La imagen que contiene el trozo que queremos dibujar.
x1 - La coordenada x de donde parte el trozo de imagen que queremos dibujar.
y1 - La coordenada y de donde parte el trozo de imagen que queremos dibujar.
w - Anchura en pixels del trozo que queremos dibujar.
h - Altura en pixels del trozo que queremos dibujar.
dst - La imagen donde queremos dibujar.
x2 - La coordenada x donde dibujar la imagen en dst.
y2 - La coordenada y donde dibujar la imagen en dst.
*/
void ts_gfx_blit(TS_Surface *src, sshort x1, sshort y1, sshort w, sshort h, TS_Surface *dst, sshort x2, sshort y2);
EXPORT int tl_gfx_blit(TS_Lua *ls);

/*
	Function: ts_gfx_clear

Descripcion:
Limpia una imagen con el color negro.

Parametros:
s - La imagen que queremos limpiar.
*/
void ts_gfx_clear(TS_Surface *s);
EXPORT int tl_gfx_clear(TS_Lua *ls);

/*
	Function: ts_gfx_new_image

Descripcion:
Crea una nueva imagen vacia.

Parametros:
w - La anchura de la nueva imagen.
h - La altura de la nueva imagen.

Devuelve:
Un puntero con la imagen. Date cuenta de que tienes que liberar la memoria una vez
termines de usarlo.
*/
TS_Surface * ts_gfx_new_image(sshort w, sshort h);
int tl_gfx_new_image(TS_Lua *ls);

/*
	Function: ts_gfx_draw

Descripcion:
Dibuja una imagen en unas determinadas coordenadas en la imagen apuntada por dst.

Parametros:
src - La imagen que queremos dibujar.
dst - La imagen donde queremos dibujar.
x - La coordenada x donde dibujar la imagen.
y - La coordenada y donde dibujar la imagen.
*/
void ts_gfx_draw(TS_Surface *src, TS_Surface *dst, sshort x, sshort y);
EXPORT int tl_gfx_draw(TS_Lua *ls);

/*
	Function: ts_gfx_draw_circle

Descripcion:
Dibuja un circulo.

Parametros:
src - La imagen donde queremos dibujar el circulo.
ox - La coordenada x de origen donde se dibujara el circulo.
oy - La coordenada y de origen donde se dibujara el circulo.
r - Radio del circulo.
color - Color del circulo que queremos dibujar.
*/
void ts_gfx_draw_circle(TS_Surface *src, int ox, int oy, int r, TS_Color *color);
EXPORT int tl_gfx_draw_circle(TS_Lua *ls);

/*
	Function: ts_gfx_draw_ellipse

Descripcion:
Dibuja una elipse.

Parametros:
src - La imagen donde queremos dibujar la elipse.
ox - La coordenada x de origen donde se dibujara la elipse.
oy - La coordenada y de origen donde se dibujara la elipse.
r1 - Radio 1.
r2 - Radio 2.
color - Color de la elipse que queremos dibujar.
*/
void ts_gfx_draw_ellipse(TS_Surface *src, int ox, int oy, int r1, int r2, TS_Color *color);
EXPORT int tl_gfx_draw_ellipse(TS_Lua *ls);

/*
	Function: ts_gfx_draw_filled_circle

Descripcion:
Dibuja un circulo relleno con el color dado.

Parametros:
src - La imagen donde queremos dibujar el circulo.
ox - La coordenada x de origen donde se dibujara el circulo.
oy - La coordenada y de origen donde se dibujara el circulo.
r - Radio del circulo.
color - Color del circulo que queremos dibujar.
*/
void ts_gfx_draw_filled_circle(TS_Surface *src, int ox, int oy, int r, TS_Color *color);
EXPORT int tl_gfx_draw_filled_circle(TS_Lua *ls);

/*
	Function: ts_gfx_draw_filled_ellipse

Descripcion:
Dibuja una elipse rellana con color.

Parametros:
src - La imagen donde queremos dibujar la elipse.
ox - La coordenada x de origen donde se dibujara la elipse.
oy - La coordenada y de origen donde se dibujara la elipse.
r1 - Radio 1.
r2 - Radio 2.
color - Color de la elipse que queremos dibujar.
*/
void ts_gfx_draw_filled_ellipse(TS_Surface *src, int ox, int oy, int r1, int r2, TS_Color *color);
EXPORT int tl_gfx_draw_filled_ellipse(TS_Lua *ls);

/*
	Function: ts_gfx_draw_filled_rect

Descripcion:
Dibuja un rectangulo relleno

Parametros:
src - La imagen donde queremos dibujar el rectangulo.
ox - La coordenada x de origen desde donde dibujar el rectangulo.
oy - La coordenada y de origen desde donde dibujar el rectangulo.
dx - La coordenada x de destino hasta donde dibujar el rectangulo.
dy - La coordenada y de destino hasta donde dibujar el rectangulo.
color - Color del rectangulo que queremos dibujar.
*/
void ts_gfx_draw_filled_rect(TS_Surface *src,int ox,int oy,int dx,int dy,TS_Color *color);
EXPORT int tl_gfx_draw_filled_rect(TS_Lua *ls);

/*
	Function: ts_gfx_draw_line

Descripcion:
Dibuja una linea.

Parametros:
src - La imagen donde queremos dibujar la linea.
ox - La coordenada x de origen donde se dibujara la linea.
oy - La coordenada y de origen donde se dibujara la linea.
dx - La coordenada x de destino donde se dibujara la linea.
dy - La coordenada y de destino donde se dibujara la linea.
color - Color de la linea que queremos dibujar.
*/
void ts_gfx_draw_line(TS_Surface *dst, int ox, int oy, int dx, int dy, TS_Color *color);
EXPORT int tl_gfx_draw_line(TS_Lua *ls);

/*
	Function: ts_gfx_draw_pixel

Descripcion:
Dibuja un pixel.

Parametros:
dst - Imagen donde queremos dibujar el pixel.
ox - Coordenada X donde queremos dibujarlo.
oy - Coordenada Y donde queremos dibujarlo.
color - Color del pixel.
*/
void ts_gfx_draw_pixel(TS_Surface *dst, int ox, int oy, TS_Color *color);
EXPORT int tl_gfx_draw_pixel(TS_Lua *ls);

/*
	Function: ts_gfx_draw_trans

Descripcion:
Dibuja una imagen de forma transparente en unas determinadas coordenadas en la imagen apuntada por dst.

Parametros:
src - La imagen que queremos dibujar.
dst - La imagen donde queremos dibujar.
x - La coordenada x donde dibujar la imagen.
y - La coordenada y donde dibujar la imagen.
alpha - La cantidad de transparencia con la que dibujar la imagen.
*/
void ts_gfx_draw_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha);
EXPORT int tl_gfx_draw_trans(TS_Lua *ls);

/*
	Function: ts_gfx_draw_rect

Descripcion:
Dibuja un rectangulo

Parametros:
src - La imagen donde queremos dibujar el rectangulo.
ox - La coordenada x de origen desde donde dibujar el rectangulo.
oy - La coordenada y de origen desde donde dibujar el rectangulo.
dx - La coordenada x de destino hasta donde dibujar el rectangulo.
dy - La coordenada y de destino hasta donde dibujar el rectangulo.
color - Color del rectangulo que queremos dibujar.
*/
void ts_gfx_draw_rect(TS_Surface *src, int ox, int oy, int dx, int dy, TS_Color *color);
EXPORT int tl_gfx_draw_rect(TS_Lua *ls);

/*
	Function: ts_gfx_draw_rotated

Descripcion:
Dibuja una imagen rotada.

Parametros:
src - La imagen que queremos rotar.
x - La coordenada x donde comenzar la rotacion en src.
y - La coordenada y donde comenzar la rotacion en src.
dst - La imagen donde queremos dibujar la imagen rotada.
angle - Angulo que queremos rotar.
*/
void ts_gfx_draw_rotated(TS_Surface *src, int x, int y, TS_Surface *dst, float angle);
EXPORT int tl_gfx_draw_rotated(TS_Lua *ls);

/*
	Function: ts_gfx_draw_scaled

Descripcion:
Dibuja una imagen escalada a los valores especificados en w y h.

Parametros:
src - La imagen que queremos dibujar.
x - La coordenada x donde dibujar la imagen.
y - La coordenada y donde dibujar la imagen.
dst - La imagen donde queremos dibujar.
w - Ancho al que queremos escalar la imagen.
h - Alto al que queremos escalar la imagen.
*/
void ts_gfx_draw_scaled(TS_Surface *src, int x, int y, TS_Surface *dst, int w, int h);
EXPORT int tl_gfx_draw_scaled(TS_Lua *ls);

/*
	Function: ts_gfx_draw_x_flipped

Descripcion:
Dibuja una imagen volteada horizontalmente en unas determinadas coordenadas en la imagen apuntada por dst.

Parametros:
src - La imagen que queremos dibujar.
dst - La imagen donde queremos dibujar.
x - La coordenada x donde dibujar la imagen.
y - La coordenada y donde dibujar la imagen.
*/
void ts_gfx_draw_x_flipped(TS_Surface *src, TS_Surface *dst, sshort x, sshort y);
EXPORT int tl_gfx_draw_x_flipped(TS_Lua *ls);

/*
	Function: ts_gfx_draw_y_flipped

Descripcion:
Dibuja una imagen volteada verticalmente en unas determinadas coordenadas en la imagen apuntada por dst.

Parametros:
src - La imagen que queremos dibujar.
dst - La imagen donde queremos dibujar.
x - La coordenada x donde dibujar la imagen.
y - La coordenada y donde dibujar la imagen.
*/
void ts_gfx_draw_y_flipped(TS_Surface *src, TS_Surface *dst, sshort x, sshort y);
EXPORT int tl_gfx_draw_y_flipped(TS_Lua *ls);

/*
	Function: ts_gfx_draw_x_flipped_trans

Descripcion:
Dibuja una imagen volteada horizontalmente en unas determinadas coordenadas en la imagen apuntada por dst con
la trasparencia especificada en alpha.

Parametros:
src - La imagen que queremos dibujar.
dst - La imagen donde queremos dibujar.
x - La coordenada x donde dibujar la imagen.
y - La coordenada y donde dibujar la imagen.
alpha - Transparencia que queremos aplicar.
*/
void ts_gfx_draw_x_flipped_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha);
EXPORT int tl_gfx_draw_x_flipped_trans(TS_Lua *ls);

/*
	Function: ts_gfx_draw_y_flipped_trans

Descripcion:
Dibuja una imagen volteada verticalmente en unas determinadas coordenadas en la imagen apuntada por dst con
la trasparencia especificada en alpha.

Parametros:
src - La imagen que queremos dibujar.
dst - La imagen donde queremos dibujar.
x - La coordenada x donde dibujar la imagen.
y - La coordenada y donde dibujar la imagen.
alpha - Transparencia que queremos aplicar.
*/
void ts_gfx_draw_y_flipped_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha);
EXPORT int tl_gfx_draw_y_flipped_trans(TS_Lua *ls);

/*
	Function: ts_gfx_flip

Descripcion:
Vuelca la imagen devuelta por la funcion <ts_gfx_get_virtual> en la pantalla fisica.

Ver tambien:
<ts_gfx_get_virtual>
*/
void ts_gfx_flip(void);
EXPORT int tl_gfx_flip(TS_Lua *ls);

/*
	Function: ts_gfx_free

Descripcion:
Libera la memoria utilizada por una TS_Surface.

Parametros:
s - Puntero a la TS_Surface que queremos liberar.
*/
void ts_gfx_free(TS_Surface *s);
EXPORT int tl_gfx_free(TS_Lua *ls);

/*
	Function: ts_gfx_free_color

Descripcion:
Libera la memoria utilizada por un TS_Color.

Parametros:
c - Puntero al TS_Color que queremos liberar.
*/
void ts_gfx_free_color(TS_Color *c);
EXPORT int tl_gfx_free_color(TS_Lua *ls);

/*
	Function: ts_gfx_get_alpha

Descripcion:
Extrae la cantidad de transparencia del TS_Color que pasamos como parametro.
Esta funcion tiene mas utilidad en Lua, en C, quizas te interese extraer
los colores directamente de la estructura <TS_Color>.

Parametros:
color - El color del que queremos extraer la cantidad de trasparencia.

Devuelve:
La cantidad de transparencia que hay en el color.
*/
uchar ts_gfx_get_alpha(TS_Color * color);
EXPORT int tl_gfx_get_alpha(TS_Lua *ls);

/*
	Function: ts_gfx_get_blue

Descripcion:
Extrae la cantidad de azul del TS_Color que pasamos como parametro.
Esta funcion tiene mas utilidad en Lua, en C, quizas te interese extraer
los colores directamente de la estructura <TS_Color>.

Parametros:
color - El color del que queremos extraer la cantidad de azul.

Devuelve:
La cantidad de azul que hay en el color.
*/
uchar ts_gfx_get_blue(TS_Color * color);
EXPORT int tl_gfx_get_blue(TS_Lua *ls);

/*
	Function: ts_gfx_get_color

Descripcion:
Obtiene el color de un pixel en una imagen.

Parametros:
s - Imagen de donde queremos obtener el pixel.
ox - Coordenada X.
oy - Coordenada Y.

Devuelve:
Un TS_Color con el color del pixel.

Ver tambien:
<ts_gfx_get_green>
<ts_gfx_get_red>
<ts_gfx_get_blue>
<ts_gfx_get_alpha>
*/
TS_Color * ts_gfx_get_color(TS_Surface *s, int ox, int oy);
EXPORT int tl_gfx_get_color(TS_Lua *ls);

/*
	Function: ts_gfx_get_green

Descripcion:
Extrae la cantidad de verde del TS_Color que pasamos como parametro.
Esta funcion tiene mas utilidad en Lua, en C, quizas te interese extraer
los colores directamente de la estructura <TS_Color>.

Parametros:
color - El color del que queremos extraer la cantidad de verde.

Devuelve:
La cantidad de verde que hay en el color.
*/
uchar ts_gfx_get_green(TS_Color * color);
EXPORT int tl_gfx_get_green(TS_Lua *ls);

/*
	Function: ts_gfx_get_height

Descripcion:
Devuelve un sshort con el alto de la imagen en pixels, o TS_ERROR si no existe
la imagen.

Parametros:
s - Un TS_Surface con la imagen de la que queremos conocer la altura.

Devuelve:
Un sshort con el alto de la imagen en pixels o TS_ERROR si no existe la imagen.
*/
sshort ts_gfx_get_height(TS_Surface *s);
EXPORT int tl_gfx_get_height(TS_Lua *ls);

/*
	Function: ts_gfx_get_red

Descripcion:
Extrae la cantidad de rojo del TS_Color que pasamos como parametro.
Esta funcion tiene mas utilidad en Lua, en C, quizas te interese extraer
los colores directamente de la estructura <TS_Color>.

Parametros:
color - El color del que queremos extraer la cantidad de verde.

Devuelve:
La cantidad de rojo que hay en el color.
*/
uchar ts_gfx_get_red(TS_Color * color);
EXPORT int tl_gfx_get_red(TS_Lua *ls);

/*
	Function: ts_gfx_get_virtual

Descripcion:
Usa esta funcion para obtener la pantalla virtual.

Devuelve:
Devuelve un TS_Surface con la pantalla virtual donde se dibujan los monigotes.
*/
TS_Surface * ts_gfx_get_virtual(void);
EXPORT int tl_gfx_get_virtual(TS_Lua *ls);

/*
	Function: ts_gfx_get_width

Descripcion:
Devuelve un sshort con el ancho de la imagen en pixels, o TS_ERROR si no existe
la imagen.

Parametros:
s - Un TS_Surface con la imagen de la que queremos conocer la anchura.

Devuelve:
Un sshort con el ancho de la imagen en pixels o TS_ERROR si no existe la imagen.
*/
sshort ts_gfx_get_width(TS_Surface *s);
EXPORT int tl_gfx_get_width(TS_Lua *ls);

/*
	Function: ts_gfx_init

Descripcion:
Inicia los datos de la estructura TS_Gfx encargada de los graficos, reserva la memoria
para ellos, etc. Esta funcion se usa internamente por TSLib y no deberias
utilizarla.

Devuelve:
TS_OK si todo ha ido bien, TS_ERROR si se ha producido algun error.
*/
schar ts_gfx_init(void);

/*
	Function: ts_gfx_new_color

Descripcion:
Devuelve un puntero con una estructura TS_Color que almacena los valores r,g,b,a que le
pasemos.

Parametros:
r - Valor de rojo, desde 0 hasta 255.
g - Valor de verde, desde 0 hasta 255.
b - Valor de azul, desde 0 hasta 255.
a - Valor de transparencia, desde 0 hasta 255.

Devuelve:
Un puntero a TS_Color.
*/
TS_Color * ts_gfx_new_color(uchar r, uchar g, uchar b, uchar a);
EXPORT int tl_gfx_new_color(TS_Lua *ls);

/*
	Function: ts_gfx_load

Descripcion:
Carga una imagen a partir de un fichero. La imagen puede tener transparencia o
no, en caso de que no tenga, se usara el color magenta (R:255, G:0, B:255) como
color transparente. Si cargas una imagen y despues se muestra incorrectamente
con este color, en lugar de mostrarlo transparente, asegurate de que has
eliminado el canal alpha del archivo con el grafico original.

Parametros:
filename - La ruta a la imagen que queremos cargar

Devuelve:
Un puntero con la TS_Surface correspondiente lista para ser utilizada. Tu eres
responsable de liberar la memoria usada por este puntero. Devuelve NULL si ha
habido algun error.
*/
TS_Surface * ts_gfx_load(const char *filename);
EXPORT int tl_gfx_load(TS_Lua *ls);

/*
	Function: ts_gfx_make_rgba

Descripcion:
Convierte un puntero con un TS_Color al color nativo de cada plataforma. Se usa
internamente por TS_Lib y no deberias usarla en tu programa.

Parametros:
c - Puntero a TS_Color con el color que queremos convertir.

Devuelve:
El color en el formato nativo de la plataforma, en el caso de Allegro 4 será un
int, un ALLEGRO_COLOR en el caso de Allegro 5 y un Uint32 en el caso de SDL.
*/
#ifdef AL4_SUPPORT
int ts_gfx_make_rgba(TS_Color *c);
#endif

#ifdef AL5_SUPPORT
ALLEGRO_COLOR ts_gfx_make_rgba(TS_Color *c);
#endif

#ifdef SDL_SUPPORT
Uint32 ts_gfx_make_rgba(TS_Color *c);
#endif

/*
	Function: ts_gfx_quit

Descripcion:
Libera la memoria usada por la estructura TS_Gfx encargada de los graficos.
Esta funcion se usa	internamente por TSLib y no deberias utilizarla.

Devuelve:
TS_OK si todo ha ido bien, TS_ERROR si ha habido algun error.
*/
schar ts_gfx_quit(void);

/*
	Function: ts_gfx_set_title

Descripcion:
Pone el titulo en la ventana de la aplicacion, en caso de que parametro no sea
valido no hace nada y muestra un mensaje de depuracion.

Parametros:
title - Cadena de texto con el titulo que queremos poner.
*/
void ts_gfx_set_title(const char *title);
EXPORT int tl_gfx_set_title(TS_Lua *ls);

/*
	Function: ts_gfx_set_video_mode

Descripcion:
Pone el modo grafico que se le solicite mediante los parametros. Esta funcion
ademas crea la pantalla virtual con la que se trabaja constantemente, esta
pantalla se puede obtener con la funcion <ts_gfx_get_virtual>. Es donde se
dibuja todo antes de llamar a <ts_gfx_flip>.

Parametros:
width - Ancho de la resolucion que queremos.
height - Alto de la resolucion que queremos.
bpp - Bits por pixel, TSLib solo soporta de momento 16 y 32.
fullscreen - Si esta variable es mayor que 0, se pondra el modo grafico a
pantalla completa, si no, se usara una ventana.

Devuelve:
TS_OK si todo ha ido bien, TS_ERROR si ha habido algun error.

Ver tambien:
<ts_gfx_get_virtual>
*/
schar ts_gfx_set_video_mode(ushort width, ushort height, uchar bpp, uchar fullscreen);
EXPORT int tl_gfx_set_video_mode(TS_Lua *ls);

/*
	Function: ts_gfx_get_image

Descripcion:
Extrae una TS_Surface de otra a partir de las coordenadas dadas.

Parametros:
src - TS_Surface de la que queramos extraer la imagen.
x - Coordenada X donde queramos comenzar la extraccion.
y - Coordenada Y donde queramos comenzar la extraccion.
w - Anchura en pixeles para extraer.
h - Altura en pixeles para extraer.

Devuelve:
Una TS_Surface lista para ser utilizada si todo ha ido bien, NULL si ha
habido algun error.

Ver tambien:
<ts_gfx_new_image>
*/
TS_Surface * ts_gfx_get_image(TS_Surface *src, sshort x, sshort y, sshort w, sshort h);
EXPORT int tl_gfx_get_image(TS_Lua *ls);
#endif																						// TS_GFX_H
