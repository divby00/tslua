#include "ts_lib.h"
#include "ts_malloc.h"
#include "ts_struct.h"
#include "ts_trans.h"
#include "SDL/SDL.h"

extern TS_Handler *tsh;

void ts_gfx_free_color(TS_Color *c)
{
	c=(struct TS_Color *)ts_free(c);
}


uchar ts_gfx_get_alpha(TS_Color *color)
{
	if (color!=NULL) {
		return (uchar)color->a;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return 0;
	}
}


uchar ts_gfx_get_blue(TS_Color *color)
{
	if (color!=NULL) {
		return (uchar)color->b;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return 0;
	}
}


uchar ts_gfx_get_green(TS_Color *color)
{
	if (color!=NULL) {
		return (uchar)color->g;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return 0;
	}
}


uchar ts_gfx_get_red(TS_Color *color)
{
	if (color!=NULL) {
		return (uchar)color->r;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return 0;
	}
}


schar ts_gfx_init(void)
{
	tsh->gfx=(struct TS_Gfx *)ts_malloc(sizeof(struct TS_Gfx));
	tsh->gfx->virt=NULL;
	#ifdef AL5_SUPPORT
	tsh->gfx->display=NULL;
	#endif
	#ifdef SDL_SUPPORT
	tsh->gfx->display=NULL;
	#endif
	return TS_OK;
}


TS_Color * ts_gfx_new_color(uchar r, uchar g, uchar b, uchar a)
{
	TS_Color *c=NULL;
	c=(struct TS_Color *)ts_malloc(sizeof(struct TS_Color));
	c->r=r;
	c->g=g;
	c->b=b;
	c->a=a;
	return c;
}


#ifdef AL4_SUPPORT

void ts_gfx_blit(TS_Surface *src, sshort x1, sshort y1, sshort w, sshort h, TS_Surface *dst, sshort x2, sshort y2)
{
	if (src!=NULL && dst!=NULL) {
		masked_blit(src,dst,x1,y1,x2,y2,w,h);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_clear(TS_Surface *s)
{
	if (s!=NULL) {
		clear(s);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


TS_Surface * ts_gfx_new_image(sshort w, sshort h)
{
	TS_Surface *s=NULL;
	if (w<=0 || h<=0) {
		ts_debug(_("Error trying to create the new image"),TS_FL);
		return NULL;
	}
	s=create_bitmap(w,h);
	if (s==NULL) {
		ts_debug(_("Error trying to create the new image"),TS_FL);
		return NULL;
	}
	clear_to_color(s,makecol(255,0,255));
	return s;
}


TS_Surface * ts_gfx_get_image(TS_Surface *src, sshort x, sshort y, sshort w, sshort h)
{
	TS_Surface *s=NULL;
	if (src!=NULL) {
		s=ts_gfx_new_image(w,h);
		blit(src,s,x,y,0,0,w,h);
		return s;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return NULL;
	}
}


void ts_gfx_draw(TS_Surface *src, TS_Surface *dst, sshort x, sshort y)
{
	if (src!=NULL && dst!=NULL) {
		draw_sprite(dst,src,x,y);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_circle(TS_Surface *src, int ox, int oy, int r, TS_Color *color)
{
	int c=0;
	if (src==NULL || color==NULL) {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
	else {
		c=ts_gfx_make_rgba(color);
		if (color->a==255) {
			circle(src,ox,oy,r,c);
		}
		else {
			set_trans_blender(255,255,255,(int)color->a);
			drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
			circle(src,ox,oy,r,c);
			set_trans_blender(255,255,255,255);
			drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
		}
	}
}


void ts_gfx_draw_ellipse(TS_Surface *src, int ox, int oy, int r1, int r2, TS_Color *color)
{
	int c=0;
	if (src==NULL || color==NULL) {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
	else {
		c=ts_gfx_make_rgba(color);
		if (color->a==255) {
			ellipse(src,ox,oy,r1,r2,c);
		}
		else {
			set_trans_blender(255,255,255,(int)color->a);
			drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
			ellipse(src,ox,oy,r1,r2,c);
			set_trans_blender(255,255,255,255);
			drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
		}
	}
}


void ts_gfx_draw_filled_circle(TS_Surface *src, int ox, int oy, int r, TS_Color *color)
{
	int c=0;
	if (src==NULL || color==NULL) {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
	else {
		c=ts_gfx_make_rgba(color);
		if (color->a==255) {
			circlefill(src,ox,oy,r,c);
		}
		else {
			set_trans_blender(255,255,255,(int)color->a);
			drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
			circlefill(src,ox,oy,r,c);
			set_trans_blender(255,255,255,255);
			drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
		}
	}
}


void ts_gfx_draw_filled_ellipse(TS_Surface *src, int ox, int oy, int r1, int r2, TS_Color *color)
{
	int c=0;
	if (src==NULL || color==NULL) {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
	else {
		c=ts_gfx_make_rgba(color);
		if (color->a==255) {
			ellipsefill(src,ox,oy,r1,r2,c);
		}
		else {
			set_trans_blender(255,255,255,(int)color->a);
			drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
			ellipsefill(src,ox,oy,r1,r2,c);
			set_trans_blender(255,255,255,255);
			drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
		}
	}
}


void ts_gfx_draw_filled_rect(TS_Surface *src,int ox,int oy,int dx,int dy,TS_Color *color)
{
	TS_Surface *s=NULL;
	if (color->a==255) {
		rectfill(src,ox,oy,dx,dy,ts_gfx_make_rgba(color));
	}
	else {
		s=create_bitmap(TS_MAX(dx,ox)-TS_MIN(dx,ox),TS_MAX(dy,oy)-TS_MIN(dy,oy));
		if (s==NULL) {
			ts_debug(_("Error trying to create the new image"),TS_FL);
		}
		clear_to_color(s,makecol((int)color->r,(int)color->g,(int)color->b));
		set_trans_blender(255,255,255,(int)color->a);
		draw_trans_sprite(src,s,ox,oy);
		set_trans_blender(255,255,255,255);
		destroy_bitmap(s);
	}
}


void ts_gfx_draw_line(TS_Surface *dst, int ox, int oy, int dx, int dy, TS_Color *color)
{
	if (color!=NULL) {
		if (color->a==255) {
			line(dst,ox,oy,dx,dy,makecol((int)color->r,(int)color->g,(int)color->b));
		}
		else {
			set_trans_blender(255,255,255,(int)color->a);
			drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
			line(dst,ox,oy,dx,dy,makecol((int)color->r,(int)color->g,(int)color->b));
			set_trans_blender(255,255,255,255);
			drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
}


void ts_gfx_draw_pixel(TS_Surface *dst, int ox, int oy, TS_Color *color)
{
	if (dst!=NULL && color!=NULL) {
		if (color->a==255) {
			putpixel(dst,ox,oy,ts_gfx_make_rgba(color));
		}
		else {
			drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
			set_trans_blender(255,255,255,(int)color->a);
			putpixel(dst,ox,oy,ts_gfx_make_rgba(color));
			set_trans_blender(255,255,255,255);
			drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha)
{
	drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
	set_trans_blender(255,255,255,alpha);
	draw_trans_sprite(dst,src,x,y);
	set_trans_blender(255,255,255,255);
	drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
}


void ts_gfx_draw_rect(TS_Surface *src, int ox, int oy, int dx, int dy, TS_Color *color)
{
	int c=0;
	if (src==NULL) {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
	c=ts_gfx_make_rgba(color);
	if (color->a==255) {
		rect(src,ox,oy,dx,dy,c);
	}
	else {
		set_trans_blender(255,255,255,(int)color->a);
		drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
		rect(src,ox,oy,dx,dy,c);
		set_trans_blender(255,255,255,255);
		drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
	}
}


void ts_gfx_draw_rotated(TS_Surface *src, int x, int y, TS_Surface *dst, float angle)
{
	float a=0;
	if (src!=NULL && dst!=NULL) {
		a=((angle*256)/360)*-1;
		rotate_sprite(dst,src,x,y,ftofix(a));
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_scaled(TS_Surface *src, int x, int y, TS_Surface *dst, int w, int h)
{
	if (src!=NULL && dst!=NULL) {
		stretch_sprite(dst,src,x,y,w,h);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_x_flipped(TS_Surface *src, TS_Surface *dst, sshort x, sshort y)
{
	if (src!=NULL && dst!=NULL) {
		draw_sprite_h_flip(dst,src,x,y);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_x_flipped_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha)
{
	BITMAP *aux=NULL;
	if (src!=NULL && dst!=NULL) {
		aux=create_bitmap(src->w,src->h);
		if (aux==NULL) {
			ts_debug(_("Error creating an auxiliar image"),TS_FL);
			return;
		}
		clear_to_color(aux,makecol(255,0,255));
		draw_sprite_h_flip(aux,src,0,0);
		drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
		set_trans_blender(255,255,255,alpha);
		draw_trans_sprite(dst,aux,x,y);
		set_trans_blender(255,255,255,255);
		drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
		destroy_bitmap(aux);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_y_flipped(TS_Surface *src, TS_Surface *dst, sshort x, sshort y)
{
	if (src!=NULL && dst!=NULL) {
		draw_sprite_v_flip(dst,src,x,y);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_y_flipped_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha)
{
	BITMAP *aux=NULL;
	if (src!=NULL && dst!=NULL) {
		aux=create_bitmap(src->w,src->h);
		if (aux==NULL) {
			ts_debug(_("Error creating an auxiliar image"),TS_FL);
			return;
		}
		clear_to_color(aux,makecol(255,0,255));
		draw_sprite_v_flip(aux,src,0,0);
		drawing_mode(DRAW_MODE_TRANS,NULL,0,0);
		set_trans_blender(255,255,255,alpha);
		draw_trans_sprite(dst,aux,x,y);
		set_trans_blender(255,255,255,255);
		drawing_mode(DRAW_MODE_SOLID,NULL,0,0);
		destroy_bitmap(aux);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_flip(void)
{
	if (tsh->gfx->virt!=NULL && screen!=NULL) {
		blit(tsh->gfx->virt,screen,0,0,0,0,screen->w,screen->h);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_free(TS_Surface *s)
{
	if (s!=NULL) {
		destroy_bitmap(s);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


TS_Color * ts_gfx_get_color(TS_Surface *s, int ox, int oy)
{
	int c=0;
	TS_Color *color=NULL;
	if (s!=NULL) {
		c=getpixel(s,ox,oy);
		color=ts_gfx_new_color(getr(c),getg(c),getb(c),geta(c));
		return color;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return NULL;
	}
}


sshort ts_gfx_get_height(TS_Surface *s)
{
	if (s!=NULL) {
		return s->h;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return TS_ERROR;
	}
}


TS_Surface * ts_gfx_get_virtual(void)
{
	if (tsh->gfx->virt!=NULL) {
		return tsh->gfx->virt;
	}
	else {
		ts_debug(_("Error tryint to use a NULL pointer"),TS_FL);
		return NULL;
	}
}


sshort ts_gfx_get_width(TS_Surface *s)
{
	if (s!=NULL) {
		return s->w;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return TS_ERROR;
	}
}


TS_Surface * ts_gfx_load(const char *filename)
{
	TS_Surface *src,*opt_src=NULL;
	char *buf=NULL;
	int i,a=0;
	if (filename==NULL) {
		ts_debug(_("Invalid file name"),TS_FL);
		return NULL;
	}
	src=load_bitmap(filename,NULL);
	if (src==NULL) {
		buf=(char *)ts_malloc(TS_MAX_STRING);
		sprintf(buf,_("Error loading the image %s"),filename);
		ts_debug(buf,TS_FL);
		buf=(char *)ts_free(buf);
		return NULL;
	}
	opt_src=create_bitmap(src->w,src->h);
	if (opt_src==NULL) {
		ts_debug(_("Error making a new bitmap."),TS_FL);
	}
	clear_to_color(opt_src,makecol(255,0,255));
	draw_sprite(opt_src,src,0,0);
	lock_bitmap(opt_src);
	for (a=0;a<opt_src->h;a++) {
		for (i=0;i<opt_src->w;i++) {
			if (!getpixel(opt_src,i,a)) {
				putpixel(opt_src,i,a,makecol(255,0,255));
			}
		}
	}
	release_bitmap(opt_src);
	destroy_bitmap(src);
	return opt_src;
}


int ts_gfx_make_rgba(TS_Color *c)
{
	return makecol((int)c->r,(int)c->g,(int)c->b);
}


schar ts_gfx_quit(void)
{
	if (tsh->gfx->virt!=NULL) {
		destroy_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
	tsh->gfx=(TS_Gfx *)ts_free(tsh->gfx);
	return TS_OK;
}


void ts_gfx_set_title(const char *title)
{
	if (title!=NULL) {
		set_window_title(title);
	}
	else {
		ts_debug(_("Invalid string"),TS_FL);
	}
}


schar ts_gfx_set_video_mode(ushort width, ushort height, uchar bpp, uchar fullscreen)
{
	schar res=0;
	ushort mode=0;
	if (fullscreen) {
		mode=GFX_AUTODETECT_FULLSCREEN;
	}
	else {
		mode=GFX_AUTODETECT_WINDOWED;
	}
	set_color_depth(bpp);
	res=set_gfx_mode(mode,width,height,0,0);
	if (res==-1) {
		ts_debug(_("Error initiating the graphics mode"),TS_FL);
		return TS_ERROR;
	}
	tsh->gfx->virt=create_bitmap(width,height);
	if (tsh->gfx->virt==NULL) {
		ts_debug(_("Error initiating the back buffer"),TS_FL);
		return TS_ERROR;
	}
	return TS_OK;
}
#endif

#ifdef AL5_SUPPORT

void ts_gfx_blit(TS_Surface *src, sshort x1, sshort y1, sshort w, sshort h, TS_Surface *dst, sshort x2, sshort y2)
{
	if (dst!=NULL && src!=NULL && tsh->gfx->virt!=NULL) {
		al_set_target_bitmap(dst);
		al_draw_bitmap_region(src,x1,y1,w,h,x2,y2,0);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_clear(TS_Surface *s)
{
	if (s!=NULL && tsh->gfx->virt!=NULL) {
		al_set_target_bitmap(s);
		al_clear_to_color(al_map_rgb(0,0,0));
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


TS_Surface * ts_gfx_get_image(TS_Surface *src, sshort x, sshort y, sshort w, sshort h)
{
	TS_Surface *dst=NULL;
	dst=ts_gfx_new_image(w,h);
	al_set_target_bitmap(dst);
	al_draw_bitmap_region(src,x,y,w,h,0,0,0);
	al_set_target_bitmap(tsh->gfx->virt);
	return dst;
}


TS_Surface * ts_gfx_new_image(sshort w, sshort h)
{
	TS_Surface *src=NULL;
	ALLEGRO_COLOR pink;

	if (w<=0 || h<=0) {
		ts_debug(_("Error trying to create the new image"),TS_FL);
		return NULL;
	}

	if (tsh->gfx->virt!=NULL) {
		src=al_create_bitmap(w,h);
		if (src==NULL) {
			ts_debug(_("Error trying to create the new image"),TS_FL);
			return NULL;
		}
		al_set_target_bitmap(src);
		pink=al_map_rgb(255,0,255);
		al_clear_to_color(pink);
		al_convert_mask_to_alpha(src,pink);
		al_set_target_bitmap(tsh->gfx->virt);
		return src;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return NULL;
	}
}


void ts_gfx_draw(TS_Surface *src, TS_Surface *dst, sshort x, sshort y)
{
	if (src!=NULL && dst!=NULL) {
		al_set_target_bitmap(dst);
		al_draw_bitmap(src,x,y,0);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_circle(TS_Surface *src, int ox, int oy, int r, TS_Color *color)
{
	ALLEGRO_COLOR c;
	if (src!=NULL && color!=NULL && tsh->gfx->virt!=NULL) {
		al_set_target_bitmap(src);
		c=ts_gfx_make_rgba(color);
		al_draw_circle(ox,oy,r,c,0);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
}


void ts_gfx_draw_ellipse(TS_Surface *src, int ox, int oy, int r1, int r2, TS_Color *color)
{
	ALLEGRO_COLOR c;
	if (src!=NULL && color!=NULL) {
		al_set_target_bitmap(src);
		c=ts_gfx_make_rgba(color);
		al_draw_ellipse(ox,oy,r1,r2,c,0);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
}


void ts_gfx_draw_filled_circle(TS_Surface *src, int ox, int oy, int r, TS_Color *color)
{
	ALLEGRO_COLOR c;
	if (src!=NULL && color!=NULL) {
		al_set_target_bitmap(src);
		c=ts_gfx_make_rgba(color);
		al_draw_filled_circle(ox,oy,r,c);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
}


void ts_gfx_draw_filled_ellipse(TS_Surface *src, int ox, int oy, int r1, int r2, TS_Color *color)
{
	ALLEGRO_COLOR c;
	if (src!=NULL && color!=NULL) {
		al_set_target_bitmap(src);
		c=ts_gfx_make_rgba(color);
		al_draw_filled_ellipse(ox,oy,r1,r2,c);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
}


void ts_gfx_draw_filled_rect(TS_Surface *src, int ox, int oy, int dx, int dy, TS_Color *color)
{
	if (src!=NULL && tsh->gfx->virt!=NULL) {
		al_set_target_bitmap(src);
		al_draw_filled_rectangle(ox,oy,dx,dy,ts_gfx_make_rgba(color));
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_line(TS_Surface *dst, int ox, int oy, int dx, int dy, TS_Color *color)
{
	ALLEGRO_COLOR c;
	if (color!=NULL) {
		c=ts_gfx_make_rgba(color);
		al_draw_line(ox,oy,dx,dy,c,0);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_pixel(TS_Surface *dst, int ox, int oy, TS_Color *color)
{
	if (dst!=NULL && color!=NULL && tsh->gfx->virt!=NULL) {
		al_set_target_bitmap(dst);
		al_draw_pixel(ox,oy,ts_gfx_make_rgba(color));
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_rotated(TS_Surface *src, int x, int y, TS_Surface *dst, float angle)
{
	double degrees=0;
	if (src!=NULL && dst!=NULL) {
		degrees=(((2*ALLEGRO_PI)*angle)/360)*-1;
		al_set_target_bitmap(dst);
		al_draw_rotated_bitmap(src,ts_gfx_get_width(src)/2,ts_gfx_get_height(src)/2,x+(ts_gfx_get_height(src)/2),y+(ts_gfx_get_width(src)/2),degrees,0);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_scaled(TS_Surface *src, int x, int y, TS_Surface *dst, int w, int h)
{
	if (src!=NULL && dst!=NULL) {
		al_set_target_bitmap(dst);
		al_draw_scaled_bitmap(src,0,0,ts_gfx_get_width(src),ts_gfx_get_height(src),x,y,w,h,0);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha)
{
	TS_Color *col=NULL;
	ALLEGRO_COLOR c;
	if (src!=NULL && dst!=NULL) {
		al_set_target_bitmap(dst);
		col=ts_gfx_new_color(255,255,255,alpha);
		c=ts_gfx_make_rgba(col);
		al_draw_tinted_bitmap(src, c, x, y, 0);
		al_set_target_bitmap(tsh->gfx->virt);
		ts_gfx_free_color(col);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_rect(TS_Surface *src, int ox, int oy, int dx, int dy, TS_Color *color)
{
	if (src!=NULL && tsh->gfx->virt!=NULL) {
		al_set_target_bitmap(src);
		al_draw_rectangle(ox,oy,dx,dy,ts_gfx_make_rgba(color),0);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_x_flipped(TS_Surface *src, TS_Surface *dst, sshort x, sshort y)
{
	if (src!=NULL && dst!=NULL) {
		al_set_target_bitmap(dst);
		al_draw_bitmap(src,x,y,ALLEGRO_FLIP_HORIZONTAL);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_x_flipped_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha)
{
	TS_Color *col=NULL;
	ALLEGRO_COLOR c;
	if (src!=NULL && dst!=NULL) {
		al_set_target_bitmap(dst);
		col=ts_gfx_new_color(255,255,255,alpha);
		c=ts_gfx_make_rgba(col);
		al_draw_tinted_bitmap(src, c, x, y, ALLEGRO_FLIP_HORIZONTAL);
		al_set_target_bitmap(tsh->gfx->virt);
		ts_gfx_free_color(col);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_y_flipped(TS_Surface *src, TS_Surface *dst, sshort x, sshort y)
{
	if (src!=NULL && dst!=NULL) {
		al_set_target_bitmap(dst);
		al_draw_bitmap(src,x,y,ALLEGRO_FLIP_VERTICAL);
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_y_flipped_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha)
{
	TS_Color *col=NULL;
	ALLEGRO_COLOR c;
	if (src!=NULL && dst!=NULL) {
		al_set_target_bitmap(dst);
		col=ts_gfx_new_color(255,255,255,alpha);
		c=ts_gfx_make_rgba(col);
		al_draw_tinted_bitmap(src, c, x, y, ALLEGRO_FLIP_VERTICAL);
		al_set_target_bitmap(tsh->gfx->virt);
		ts_gfx_free_color(col);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


ALLEGRO_COLOR ts_gfx_make_rgba(TS_Color *c)
{
	ALLEGRO_COLOR col;
	float red,green,blue,alpha=0;
	red=c->r;
	green=c->g;
	blue=c->b;
	alpha=c->a;
	red/=255;
	green/=255;
	blue/=255;
	alpha/=255;
	col=al_map_rgba_f(red,green,blue,alpha);
	return col;
}


void ts_gfx_flip(void)
{
	if (tsh->gfx->display!=NULL && tsh->gfx->virt!=NULL) {
		al_set_target_bitmap(al_get_backbuffer(tsh->gfx->display));
		al_draw_bitmap(tsh->gfx->virt,0,0,0);
		al_flip_display();
		al_set_target_bitmap(ts_gfx_get_virtual());
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_free(TS_Surface *s)
{
	if (s!=NULL) {
		al_destroy_bitmap(s);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


sshort ts_gfx_get_height(TS_Surface *s)
{
	if (s!=NULL) {
		return al_get_bitmap_height(s);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return TS_ERROR;
	}
}


TS_Color * ts_gfx_get_color(TS_Surface *s, int ox, int oy)
{
	TS_Color *aux=NULL;
	ALLEGRO_COLOR c;
	if (s!=NULL) {
		aux=ts_gfx_new_color(0,0,0,255);
		c=al_get_pixel(s,ox,oy);
		aux->r=(c.r);
		aux->g=(c.g);
		aux->b=(c.b);
		aux->a=(c.a);
		return aux;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return NULL;
	}
}


TS_Surface * ts_gfx_get_virtual(void)
{
	if (tsh->gfx->virt!=NULL) {
		return tsh->gfx->virt;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return NULL;
	}
}


sshort ts_gfx_get_width(TS_Surface *s)
{
	if (s!=NULL) {
		return al_get_bitmap_width(s);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return TS_ERROR;
	}
}


TS_Surface * ts_gfx_load(const char *filename)
{
	TS_Surface *src=NULL;
	ALLEGRO_COLOR pink;
	char *buf=NULL;
// Descomenta la linea de abajo para que Allegro 5 no use aceleracion grafica.
// al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
	if (filename==NULL) {
		ts_debug(_("Invalid file name"),TS_FL);
		return NULL;
	}
	src=al_load_bitmap(filename);
	if (src==NULL) {
		buf=(char *)ts_malloc(TS_MAX_STRING);
		sprintf(buf,_("Error loading the image %s"),filename);
		ts_debug(buf,TS_FL);
		buf=(char *)ts_free(buf);
		return NULL;
	}
	pink=al_map_rgb_f(1,0,1);
	al_convert_mask_to_alpha(src,pink);
	if (tsh->gfx->virt!=NULL) {
		al_set_target_bitmap(tsh->gfx->virt);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
	return src;
}


schar ts_gfx_quit(void)
{
	if (tsh->gfx->virt!=NULL && tsh->gfx->display!=NULL) {
		al_destroy_bitmap(tsh->gfx->virt);
		al_destroy_display(tsh->gfx->display);
		tsh->gfx=(TS_Gfx *)ts_free(tsh->gfx);
		return TS_OK;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return TS_ERROR;
	}
}


void ts_gfx_set_title(const char *title)
{
	if (tsh->gfx->display!=NULL) {
		if (title!=NULL) {
			al_set_window_title(tsh->gfx->display,title);
		}
		else {
			ts_debug(_("Invalid string"),TS_FL);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


schar ts_gfx_set_video_mode(ushort width, ushort height, uchar bpp, uchar fullscreen)
{
	#ifdef WIN32
	int mode=ALLEGRO_DIRECT3D;
	#else
	int mode=ALLEGRO_OPENGL;
	#endif
	if (fullscreen) mode |= ALLEGRO_FULLSCREEN;
	al_set_new_display_flags(mode);
	tsh->gfx->display=al_create_display(width,height);
	if (tsh->gfx->display==NULL) {
		ts_debug(_("Error initiating the graphics mode"),TS_FL);
		return TS_ERROR;
	}
	tsh->gfx->virt=al_create_bitmap(tsh->cfg->xres,tsh->cfg->yres);
	if (tsh->gfx->virt==NULL) {
		ts_debug(_("Error initiating the back buffer"),TS_FL);
		return TS_ERROR;
	}
	return TS_OK;
}
#endif

#ifdef SDL_SUPPORT

void ts_gfx_blit(TS_Surface *src, sshort x1, sshort y1, sshort w, sshort h, TS_Surface *dst, sshort x2, sshort y2)
{
	if (src!=NULL && dst!=NULL) {
		SDL_Rect offset;
		SDL_Rect offset1;
		offset.x=x1;
		offset.y=y1;
		offset.w=w;
		offset.h=h;
		offset1.x=x2;
		offset1.y=y2;
		SDL_BlitSurface(src,&offset,dst,&offset1);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_clear(TS_Surface *s)
{
	if (s!=NULL) {
		SDL_FillRect(s,NULL,0x000000);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


Uint32 ts_gfx_make_rgba(TS_Color *c)
{
	return SDL_MapRGB(tsh->gfx->virt->format,(Uint8)c->r,(Uint8)c->g,(Uint8)c->b);
}


TS_Surface * ts_gfx_new_image(sshort w, sshort h)
{
	TS_Surface *src,*opt_src=NULL;
	if (w<=0 || h<=0) {
		ts_debug(_("Error trying to create the new image"),TS_FL);
		return NULL;
	}
	if (tsh->gfx->virt!=NULL) {
		src=SDL_CreateRGBSurface(tsh->gfx->virt->flags,w,h,tsh->gfx->virt->format->BitsPerPixel,\
			tsh->gfx->virt->format->Rmask,\
			tsh->gfx->virt->format->Gmask,\
			tsh->gfx->virt->format->Bmask,
			tsh->gfx->virt->format->Amask);
		if (src==NULL) {
			ts_debug(_("Error trying to create the new image"),TS_FL);
			return NULL;
		}
		opt_src=SDL_DisplayFormat(src);
		if (opt_src) {
			SDL_FreeSurface(src);
			SDL_FillRect(opt_src,NULL,0xFF00FF);
			SDL_SetColorKey(opt_src,SDL_SRCCOLORKEY,0xFF00FF);
		}
		return opt_src;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return NULL;
	}
}


void ts_gfx_draw(TS_Surface *src, TS_Surface *dst, sshort x, sshort y)
{
	SDL_Rect offset1;
	if (src!=NULL && dst!=NULL) {
		offset1.x=x;
		offset1.y=y;
		offset1.w=src->w;
		offset1.h=src->h;
		SDL_BlitSurface(src,NULL,dst,&offset1);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_circle(TS_Surface *src, int ox, int oy, int r, TS_Color *color)
{
	if (src!=NULL) {
		if (color->a==255) {
			circleRGBA(src,ox,oy,r,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,255);
		}
		else {
			circleRGBA(src,ox,oy,r,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,(Uint8)color->a);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_ellipse(TS_Surface *src, int ox, int oy, int r1, int r2, TS_Color *color)
{
	if (src!=NULL) {
		if (color->a==255) {
			ellipseRGBA(src,ox,oy,r1,r2,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,255);
		}
		else {
			ellipseRGBA(src,ox,oy,r1,r2,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,(Uint8)color->a);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_filled_circle(TS_Surface *src, int ox, int oy, int r, TS_Color *color)
{
	if (src!=NULL) {
		if (color->a==255) {
			filledCircleRGBA(src,ox,oy,r,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,255);
		}
		else {
			filledCircleRGBA(src,ox,oy,r,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,(Uint8)color->a);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_filled_ellipse(TS_Surface *src, int ox, int oy, int r1, int r2, TS_Color *color)
{
	if (src!=NULL) {
		if (color->a==255) {
			filledEllipseRGBA(src,ox,oy,r1,r2,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,255);
		}
		else {
			filledEllipseRGBA(src,ox,oy,r1,r2,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,(Uint8)color->a);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_filled_rect(TS_Surface *src, int ox, int oy, int dx, int dy, TS_Color *color)
{
	Uint32 c;
	SDL_Rect rect;
	SDL_Surface *s=NULL;
	if (src!=NULL) {
		if (color->a==255) {
			c=ts_gfx_make_rgba(color);
			rect.x=ox;
			rect.y=oy;
			rect.w=dx-ox;
			rect.h=dy-oy;
			SDL_FillRect(src,&rect,c);
		}
		else {
			s=SDL_CreateRGBSurface(tsh->gfx->virt->flags,TS_MAX(dx,ox)-TS_MIN(dx,ox),TS_MAX(dy,oy)-TS_MIN(dy,oy),tsh->gfx->virt->format->BitsPerPixel,\
				tsh->gfx->virt->format->Rmask,\
				tsh->gfx->virt->format->Gmask,\
				tsh->gfx->virt->format->Bmask,
				tsh->gfx->virt->format->Amask);
			if (s==NULL) {
				ts_debug(_("Error trying to create the new image"),TS_FL);
			}
			SDL_FillRect(s,NULL,ts_gfx_make_rgba(color));
			SDL_SetAlpha(s,SDL_SRCALPHA,(Uint8)color->a);
			rect.x=ox;
			rect.y=oy;
			rect.w=TS_MAX(ox,dx);
			rect.h=TS_MAX(oy,dy);
			SDL_BlitSurface(s,NULL,src,&rect);
			SDL_FreeSurface(s);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_line(TS_Surface *dst, int ox, int oy, int dx, int dy, TS_Color *color)
{
	if (color!=NULL) {
		if (color->a==255) {
			lineColor(dst,ox,oy,dx,dy,ts_gfx_make_rgba(color));
		}
		else {
			lineRGBA(dst,ox,oy,dx,dy,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,(Uint8)color->a);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
}


void ts_gfx_draw_pixel(TS_Surface *dst, int ox, int oy, TS_Color *color)
{
	if (dst!=NULL && color!=NULL) {
		pixelRGBA(dst,ox,oy,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,(Uint8)color->a);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return;
	}
}


void ts_gfx_draw_rect(TS_Surface *src, int ox, int oy, int dx, int dy, TS_Color *color)
{
	SDL_Rect rect;
	if (src!=NULL) {
		rect.x=ox;
		rect.y=oy;
		rect.w=dx-ox;
		rect.h=dy-oy;
		if (color->a==255) {
			rectangleRGBA(src,ox,oy,dx,dy,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,255);
		}
		else {
			rectangleRGBA(src,ox,oy,dx,dy,(Uint8)color->r,(Uint8)color->g,(Uint8)color->b,(Uint8)color->a);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_rotated(TS_Surface *src, int x, int y, TS_Surface *dst, float angle)
{
	TS_Surface *aux=NULL;
	TS_Surface *img=NULL;
	if (src!=NULL && dst!=NULL) {
		img=ts_gfx_new_image(src->w,src->h);
		ts_gfx_draw(src,img,0,0);
		aux=rotozoomSurface(img,angle,1,0);
		SDL_SetColorKey(aux,SDL_SRCCOLORKEY,0xFF00FF);
		ts_gfx_draw(aux,dst,x,y);
		SDL_FreeSurface(aux);
		SDL_FreeSurface(img);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_scaled(TS_Surface *src, int x, int y, TS_Surface *dst, int w, int h)
{
	TS_Surface *aux=NULL;
	float xdr,ydr,xd,yd;
	if (src!=NULL && dst!=NULL) {
		xdr=w;
		ydr=h;
		xd=src->w;
		yd=src->h;
		xd=xdr/xd;
		yd=ydr/yd;
		aux=zoomSurface(src,xd,yd,0);
		SDL_SetColorKey(aux,SDL_SRCCOLORKEY,0xFF00FF);
		ts_gfx_draw(aux,dst,x,y);
		SDL_FreeSurface(aux);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha)
{
	SDL_Rect offset1;
	SDL_Surface *aux,*opt_aux=NULL;
	if (src!=NULL && dst!=NULL) {
		offset1.x=x;
		offset1.y=y;
		offset1.w=src->w;
		offset1.h=src->h;
		aux=SDL_CreateRGBSurface(src->flags,src->w,src->h,src->format->BitsPerPixel,src->format->Rmask,src->format->Gmask,src->format->Bmask,src->format->Amask);
		if (aux!=NULL) {
			opt_aux=SDL_DisplayFormat(aux);
			SDL_FillRect(opt_aux,NULL,0xFF00FF);
			SDL_BlitSurface(src,NULL,opt_aux,NULL);
			SDL_SetColorKey(opt_aux,SDL_SRCCOLORKEY,0xFF00FF);
			SDL_SetAlpha(opt_aux,SDL_SRCALPHA,alpha);
			SDL_BlitSurface(opt_aux,NULL,dst,&offset1);
			SDL_FreeSurface(opt_aux);
			SDL_FreeSurface(aux);
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_x_flipped(TS_Surface *src, TS_Surface *dst, sshort x, sshort y)
{
	SDL_Rect offset,offset1;
	SDL_Surface *aux=NULL;
	Uint8 alpha=0;
	int i=0;

	if (src!=NULL && dst!=NULL) {
		offset.y=offset1.y=0;
		offset.w=offset1.w=1;
		offset.h=offset1.h=src->h;

		aux=SDL_CreateRGBSurface(src->flags,\
			src->w,\
			src->h,\
			src->format->BitsPerPixel,\
			src->format->Rmask,\
			src->format->Gmask,\
			src->format->Bmask,\
			src->format->Amask);

		if (aux==NULL) {
			ts_debug(_("Error flipping the image, it doesn't exist"),TS_FL);
			return;
		}
		if ((src->flags & SDL_SRCALPHA)>0) {
			alpha=src->format->alpha;
			SDL_SetAlpha(src,0,0);
		}
		SDL_FillRect(aux,NULL,0xFF00FF);
		for (i=0;i<src->w;i++) {
			offset.x=i;
			offset1.x=(src->w-i)-1;
			SDL_BlitSurface(src,&offset,aux,&offset1);
		}
		if ((aux->flags & SDL_SRCALPHA)>0) {
			SDL_SetAlpha(src,SDL_SRCALPHA,alpha);
			SDL_SetAlpha(aux,SDL_SRCALPHA,alpha);
		}
		else {
			SDL_SetColorKey(aux,SDL_SRCCOLORKEY,0xFF00FF);
		}
		offset.x=x;
		offset.y=y;
		offset.w=aux->w;
		offset.h=aux->h;
		SDL_BlitSurface(aux,NULL,dst,&offset);
		SDL_FreeSurface(aux);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_y_flipped(TS_Surface *src, TS_Surface *dst, sshort x, sshort y)
{
	SDL_Rect offset,offset1;
	SDL_Surface *aux=NULL;
	Uint8 alpha=0;
	int i=0;

	if (src!=NULL && dst!=NULL) {
		offset.x=offset1.x=0;
		offset.w=offset1.w=src->w;
		offset.h=offset1.h=1;

		aux=SDL_CreateRGBSurface(src->flags,\
			src->w,\
			src->h,\
			src->format->BitsPerPixel,\
			src->format->Rmask,\
			src->format->Gmask,\
			src->format->Bmask,\
			src->format->Amask);

		if (aux==NULL) {
			ts_debug(_("Error flipping the image, it doesn't exist"),TS_FL);
			return;
		}
		if ((src->flags & SDL_SRCALPHA)>0) {
			alpha=src->format->alpha;
			SDL_SetAlpha(src,0,0);
		}
		SDL_FillRect(aux,NULL,0xFF00FF);

		for (i=0;i<src->h;i++) {
			offset.y=i;
			offset1.y=(src->h-i)-1;
			SDL_BlitSurface(src,&offset,aux,&offset1);
		}

		if ((aux->flags & SDL_SRCALPHA)>0) {
			SDL_SetAlpha(src,SDL_SRCALPHA,alpha);
			SDL_SetAlpha(aux,SDL_SRCALPHA,alpha);
		}
		else {
			SDL_SetColorKey(aux,SDL_SRCCOLORKEY,0xFF00FF);
		}
		offset.x=x;
		offset.y=y;
		offset.w=aux->w;
		offset.h=aux->h;
		SDL_BlitSurface(aux,NULL,dst,&offset);
		SDL_FreeSurface(aux);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_draw_x_flipped_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha)
{
	SDL_Surface *s=NULL;
	s=ts_gfx_new_image(src->w,src->h);
	ts_gfx_draw_x_flipped(src,s,0,0);
	ts_gfx_draw_trans(s,dst,x,y,alpha);
	SDL_FreeSurface(s);
}


void ts_gfx_draw_y_flipped_trans(TS_Surface *src, TS_Surface *dst, sshort x, sshort y, uchar alpha)
{
	SDL_Surface *s=NULL;
	s=ts_gfx_new_image(src->w,src->h);
	ts_gfx_draw_y_flipped(src,s,0,0);
	ts_gfx_draw_trans(s,dst,x,y,alpha);
	SDL_FreeSurface(s);
}


void ts_gfx_flip(void)
{
	if (tsh->gfx->virt!=NULL && tsh->gfx->display!=NULL) {
		SDL_BlitSurface(tsh->gfx->virt,NULL,tsh->gfx->display,NULL);
		SDL_Flip(tsh->gfx->display);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


void ts_gfx_free(TS_Surface *s)
{
	if (s!=NULL) {
		SDL_FreeSurface(s);
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
	}
}


TS_Color * ts_gfx_get_color(TS_Surface *s, int ox, int oy)
{
	TS_Color *c=NULL;
	Uint8 *p=NULL;
	int bpp=0;
	Uint32 col=0;
	SDL_Color aux;
	if (s!=NULL) {
		bpp = s->format->BytesPerPixel;
		p = (Uint8 *)s->pixels + oy * s->pitch + ox * bpp;
		switch(bpp) {
			case 4:
				col=*(Uint32 *)p;
				SDL_GetRGB(col,tsh->gfx->display->format,&aux.r,&aux.g,&aux.b);
				c=ts_gfx_new_color(aux.r,aux.g,aux.b,255);
				return c;
				break;
			default:
				return NULL;
		}
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return NULL;
	}
}


sshort ts_gfx_get_height(TS_Surface *s)
{
	if (s!=NULL) {
		return s->h;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return TS_ERROR;
	}
}


TS_Surface * ts_gfx_get_image(TS_Surface *src, sshort x, sshort y, sshort w, sshort h)
{
	TS_Surface *dst=NULL;
	SDL_Rect offset;
	dst=ts_gfx_new_image(w,h);
	offset.x=x;
	offset.y=y;
	offset.w=w;
	offset.h=h;
	SDL_BlitSurface(src,&offset,dst,NULL);
	return dst;
}


TS_Surface * ts_gfx_get_virtual(void)
{
	if (tsh->gfx->virt!=NULL) {
		return tsh->gfx->virt;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return NULL;
	}
}


sshort ts_gfx_get_width(TS_Surface *s)
{
	if (s!=NULL) {
		return s->w;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return TS_ERROR;
	}
}


TS_Surface * ts_gfx_load(const char *filename)
{
	SDL_Surface *src,*src_opt=NULL;
	char *buf=NULL;
	if (filename==NULL) {
		ts_debug(_("Invalid file name"),TS_FL);
		return NULL;
	}
	src=IMG_Load(filename);
	if (src==NULL) {
		buf=(char *)ts_malloc(TS_MAX_STRING);
		sprintf(buf,_("Error loading the image %s"),filename);
		ts_debug(buf,TS_FL);
		buf=(char *)ts_free(buf);
		return NULL;
	}
	if ((src->flags & SDL_SRCALPHA)>0) {
		src_opt=SDL_DisplayFormatAlpha(src);
	}
	else {
		src_opt=SDL_DisplayFormat(src);
		SDL_SetColorKey(src_opt,SDL_SRCCOLORKEY,0xFF00FF);
	}
	SDL_FreeSurface(src);
	if (src_opt==NULL) {
		buf=(char *)ts_malloc(TS_MAX_STRING);
		sprintf(buf,_("Error converting the image %s"),filename);
		ts_debug(buf,TS_FL);
		buf=(char *)ts_free(buf);
		return NULL;
	}
	return src_opt;
}


schar ts_gfx_quit(void)
{
	if (tsh->gfx->virt!=NULL && tsh->gfx->display!=NULL) {
		SDL_FreeSurface(tsh->gfx->virt);
		SDL_FreeSurface(tsh->gfx->display);
		tsh->gfx=(TS_Gfx *)ts_free(tsh->gfx);
		return TS_OK;
	}
	else {
		ts_debug(_("Error trying to use a NULL pointer"),TS_FL);
		return TS_ERROR;
	}
}


void ts_gfx_set_title(const char *title)
{
	if (title!=NULL) {
		SDL_WM_SetCaption(title,NULL);
	}
	else {
		ts_debug(_("Invalid string"),TS_FL);
	}
}


schar ts_gfx_set_video_mode(ushort w, ushort h, uchar bpp, uchar fullscreen)
{
	char *buf=NULL;
	int mode=SDL_HWSURFACE;
	if (fullscreen) mode |= SDL_FULLSCREEN;
	tsh->gfx->display=SDL_SetVideoMode(w,h,bpp,mode);
	if (tsh->gfx->display==NULL) {
		buf=(char *)ts_malloc(TS_MAX_STRING);
		ts_debug(_("Error initiating the graphics mode"),TS_FL);
		return TS_ERROR;
	}
	tsh->gfx->virt=SDL_CreateRGBSurface(SDL_HWSURFACE,tsh->cfg->xres,tsh->cfg->yres,tsh->cfg->color_depth,\
		tsh->gfx->display->format->Rmask,\
		tsh->gfx->display->format->Gmask,\
		tsh->gfx->display->format->Bmask,\
		tsh->gfx->display->format->Amask);
	if (tsh->gfx->virt==NULL) {
		ts_debug(_("Error initiating the back buffer"),TS_FL);
		return TS_ERROR;
	}
	return TS_OK;
}
#endif

EXPORT int tl_gfx_blit(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_blit((TS_Surface *)ts_lua_touserdata(ls,1),(sshort)ts_lua_tonumber(ls,2),(sshort)ts_lua_tonumber(ls,3),(sshort)ts_lua_tonumber(ls,4),(sshort)ts_lua_tonumber(ls,5),(TS_Surface *)ts_lua_touserdata(ls,6),(sshort)ts_lua_tonumber(ls,7),(sshort)ts_lua_tonumber(ls,8));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_clear(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_clear((TS_Surface *)ts_lua_touserdata(ls,1));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw((TS_Surface *)ts_lua_touserdata(ls,1),(TS_Surface *)ts_lua_touserdata(ls,2),(sshort)ts_lua_tonumber(ls,3),(sshort)ts_lua_tonumber(ls,4));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_circle(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_circle((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3),(int)ts_lua_tonumber(ls,4),(TS_Color *)ts_lua_touserdata(ls,5));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_ellipse(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_ellipse((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3),(int)ts_lua_tonumber(ls,4),(int)ts_lua_tonumber(ls,5),(TS_Color *)ts_lua_touserdata(ls,6));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_filled_circle(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_filled_circle((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3),(int)ts_lua_tonumber(ls,4),(TS_Color *)ts_lua_touserdata(ls,5));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_line(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_line((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3),(int)ts_lua_tonumber(ls,4),(int)ts_lua_tonumber(ls,5),(TS_Color *)ts_lua_touserdata(ls,6));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_filled_ellipse(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_filled_ellipse((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3),(int)ts_lua_tonumber(ls,4),(int)ts_lua_tonumber(ls,5),(TS_Color *)ts_lua_touserdata(ls,6));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_trans(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_trans((TS_Surface *)ts_lua_touserdata(ls,1),(TS_Surface *)ts_lua_touserdata(ls,2),(sshort)ts_lua_tonumber(ls,3),(sshort)ts_lua_tonumber(ls,4),(uchar)ts_lua_tonumber(ls,5));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_filled_rect(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_filled_rect((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3),(int)ts_lua_tonumber(ls,4),(int)ts_lua_tonumber(ls,5),(TS_Color *)ts_lua_touserdata(ls,6));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_rect(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_rect((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3),(int)ts_lua_tonumber(ls,4),(int)ts_lua_tonumber(ls,5),(TS_Color *)ts_lua_touserdata(ls,6));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_rotated(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_rotated((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3),(TS_Surface *)ts_lua_touserdata(ls,4),ts_lua_tonumber(ls,5));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_scaled(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_scaled((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3),(TS_Surface *)ts_lua_touserdata(ls,4),(int)ts_lua_tonumber(ls,5),(int)ts_lua_tonumber(ls,6));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_x_flipped(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_x_flipped((TS_Surface *)ts_lua_touserdata(ls,1),(TS_Surface *)ts_lua_touserdata(ls,2),(sshort)ts_lua_tonumber(ls,3),(sshort)ts_lua_tonumber(ls,4));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_x_flipped_trans(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_x_flipped_trans((TS_Surface *)ts_lua_touserdata(ls,1),(TS_Surface *)ts_lua_touserdata(ls,2),(sshort)ts_lua_tonumber(ls,3),(sshort)ts_lua_tonumber(ls,4),(uchar)ts_lua_tonumber(ls,5));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_y_flipped(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_y_flipped((TS_Surface *)ts_lua_touserdata(ls,1),(TS_Surface *)ts_lua_touserdata(ls,2),(sshort)ts_lua_tonumber(ls,3),(sshort)ts_lua_tonumber(ls,4));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_y_flipped_trans(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_y_flipped_trans((TS_Surface *)ts_lua_touserdata(ls,1),(TS_Surface *)ts_lua_touserdata(ls,2),(sshort)ts_lua_tonumber(ls,3),(sshort)ts_lua_tonumber(ls,4),(uchar)ts_lua_tonumber(ls,5));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_flip(TS_Lua *ls)
{
	ts_gfx_flip();
	return 0;
}


EXPORT int tl_gfx_free(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_free((TS_Surface *)ts_lua_touserdata(ls,1));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_free_color(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_free_color((TS_Color *)ts_lua_touserdata(ls,1));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_get_color(TS_Lua *ls)
{
	TS_Color *c=NULL;
	if (ls!=NULL) {
		c=ts_gfx_get_color((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3));
		ts_lua_pushuserdata(ls,(TS_Color *)c);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_get_alpha(TS_Lua *ls)
{
	uchar res=0;
	if (ls!=NULL) {
		res=ts_gfx_get_alpha((TS_Color *)lua_touserdata(ls,1));
		lua_pushnumber(ls,res);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_get_blue(TS_Lua *ls)
{
	uchar res=0;
	if (ls!=NULL) {
		res=ts_gfx_get_blue((TS_Color *)lua_touserdata(ls,1));
		lua_pushnumber(ls,res);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_get_green(TS_Lua *ls)
{
	uchar res=0;
	if (ls!=NULL) {
		res=ts_gfx_get_green((TS_Color *)lua_touserdata(ls,1));
		lua_pushnumber(ls,res);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_get_height(TS_Lua *ls)
{
	int res=0;
	if (ls!=NULL) {
		res=ts_gfx_get_height((TS_Surface *)ts_lua_touserdata(ls,1));
		ts_lua_pushnumber(ls,res);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_get_image(TS_Lua *ls)
{
	TS_Surface *s=NULL;
	if (ls!=NULL) {
		s=ts_gfx_get_image((TS_Surface *)ts_lua_touserdata(ls,1),(sshort)ts_lua_tonumber(ls,2),(sshort)ts_lua_tonumber(ls,3),(sshort)ts_lua_tonumber(ls,4),(sshort)ts_lua_tonumber(ls,5));
		ts_lua_pushuserdata(ls,(TS_Surface *)s);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_get_red(TS_Lua *ls)
{
	uchar res=0;
	if (ls!=NULL) {
		res=ts_gfx_get_red((TS_Color *)lua_touserdata(ls,1));
		lua_pushnumber(ls,res);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_get_virtual(TS_Lua *ls)
{
	TS_Surface *s=NULL;
	if (ls!=NULL) {
		s=ts_gfx_get_virtual();
		ts_lua_pushuserdata(ls,(TS_Surface *)s);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_get_width(TS_Lua *ls)
{
	int res=0;
	if (ls!=NULL) {
		res=ts_gfx_get_width((TS_Surface *)ts_lua_touserdata(ls,1));
		ts_lua_pushnumber(ls,res);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_load(TS_Lua *ls)
{
	TS_Surface *s=NULL;
	if (ls!=NULL) {
		s=ts_gfx_load((const char *)ts_lua_tostring(ls,1));
		ts_lua_pushuserdata(ls,(TS_Surface *)s);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_new_color(TS_Lua *ls)
{
	TS_Color *c=NULL;
	if (ls!=NULL) {
		c=ts_gfx_new_color((uchar)ts_lua_tonumber(ls,1),(uchar)ts_lua_tonumber(ls,2),(uchar)ts_lua_tonumber(ls,3),(uchar)ts_lua_tonumber(ls,4));
		ts_lua_pushuserdata(ls,(TS_Color *)c);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_new_image(TS_Lua *ls)
{
	TS_Surface *s=NULL;
	if (ls!=NULL) {
		s=ts_gfx_new_image((sshort)ts_lua_tonumber(ls,1),(sshort)ts_lua_tonumber(ls,2));
		ts_lua_pushuserdata(ls,(TS_Surface *)s);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_set_title(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_set_title((const char *)ts_lua_tostring(ls,1));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_set_video_mode(TS_Lua *ls)
{
	schar res=TS_ERROR;
	if (ls!=NULL) {
		res=ts_gfx_set_video_mode((ushort)ts_lua_tonumber(ls,1),(ushort)ts_lua_tonumber(ls,2),(uchar)ts_lua_tonumber(ls,3),(uchar)ts_lua_tonumber(ls,4));
		ts_lua_pushnumber(ls,res);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_gfx_draw_pixel(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_gfx_draw_pixel((TS_Surface *)ts_lua_touserdata(ls,1),(int)ts_lua_tonumber(ls,2),(int)ts_lua_tonumber(ls,3),(TS_Color *)ts_lua_touserdata(ls,4));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}
