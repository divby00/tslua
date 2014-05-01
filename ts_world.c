#include "ts_world.h"
#include "ts_malloc.h"
#include "ts_lua.h"
#include <string.h>
#include <math.h>

extern TS_Handler *tsh;

TS_World * ts_world_load(const char *filename)
{
	TS_World *w=NULL;
	FILE *f=NULL;
	char *buf=NULL;
	TS_WorldLayerList *aux=NULL;
	TS_WorldLayerList *prev=NULL;
	ushort xtiles=0;
	ushort ytiles=0;
	ushort xtilesize=0;
	ushort ytilesize=0;
	ushort xviewport=0;
	ushort yviewport=0;
	int v;
	buf=(char *)ts_malloc(sizeof(char)*1024);
	sprintf(buf,_("The file %s cannot be loaded"),filename);
	f=fopen(filename,"rb");
	if (f==NULL) {
		ts_debug(buf,TS_FL);
		return NULL;
	}
	else {
		v=fread(&xtiles,sizeof(ushort),1,f);
		v=fread(&ytiles,sizeof(ushort),1,f);
		v=fread(&xtilesize,sizeof(ushort),1,f);
		v=fread(&ytilesize,sizeof(ushort),1,f);
		v=fread(&xviewport,sizeof(ushort),1,f);
		v=fread(&yviewport,sizeof(ushort),1,f);
		//fprintf(stdout,"\n%d",xviewport);
		w=ts_world_create(xtiles,ytiles,xtilesize,ytilesize,xviewport,yviewport);
		//fprintf(stdout,"\n%d",w->xviewport);
		v=fread(w->layer_list->wl->name,sizeof(uchar)*50,1,f);
		v=fread(w->layer_list->wl->data,sizeof(ushort)*w->xtiles*w->ytiles,1,f);
		prev=w->layer_list;

		do {
			aux=(struct TS_WorldLayerList *)ts_malloc(sizeof(struct TS_WorldLayerList));
			aux->wl=(struct TS_WorldLayer *)ts_malloc(sizeof(struct TS_WorldLayer));
			aux->wl->data=(ushort *)ts_malloc(sizeof(ushort)*xtiles*ytiles);
			aux->wl->name=(char *)ts_malloc(sizeof(char)*50);
			aux->next=NULL;
			v=fread(aux->wl->name,sizeof(char)*50,1,f);
			v=fread(aux->wl->data,sizeof(ushort)*xtiles*ytiles,1,f);
			prev->next=aux;
			prev=aux;
		} while(!feof(f));
		fclose(f);
	}
	//tsh->sfx->vol_factor=sqrt(((w->xviewport*w->xtilesize)*(w->xviewport*w->xtilesize))+((w->yviewport*w->ytilesize)*(w->yviewport*w->ytilesize)));
	fprintf(stdout,"\n%f\n",sqrt(((w->xviewport*w->xtilesize)*(w->xviewport*w->xtilesize))+((w->yviewport*w->ytilesize)*(w->yviewport*w->ytilesize))));
	return w;
}


void ts_world_save(TS_World *w, const char *filename)
{
	FILE *f=NULL;
	char *buf=NULL;
	TS_WorldLayerList *l=NULL;
	buf=(char *)ts_malloc(sizeof(char)*1024);
	sprintf(buf,_("The file %s cannot be saved."),filename);
	f=fopen(filename,"wb");
	if (f==NULL) {
		ts_debug(buf,TS_FL);
	}
	else {
		fwrite(&w->xtiles,sizeof(ushort),1,f);
		fwrite(&w->ytiles,sizeof(ushort),1,f);
		fwrite(&w->xtilesize,sizeof(ushort),1,f);
		fwrite(&w->ytilesize,sizeof(ushort),1,f);
		fwrite(&w->xviewport,sizeof(ushort),1,f);
		fwrite(&w->yviewport,sizeof(ushort),1,f);
		l=w->layer_list;
		while(l->next!=NULL) {
			fwrite(l->wl->name,sizeof(uchar)*50,1,f);
			fwrite(l->wl->data,sizeof(ushort)*w->xtiles*w->ytiles,1,f);
			l=l->next;
		}
		fclose(f);
	}
	buf=(char *)ts_free(buf);
}


TS_World * ts_world_create(unsigned short int xtiles, unsigned short int ytiles, unsigned short xtilesize, unsigned short ytilesize, unsigned short xviewport, unsigned short yviewport)
{
	TS_World *w=NULL;
	w=(struct TS_World *)ts_malloc(sizeof(struct TS_World));
	w->xtiles=xtiles;
	w->ytiles=ytiles;
	w->xtilesize=xtilesize;
	w->ytilesize=ytilesize;
	w->xviewport=xviewport;
	w->yviewport=yviewport;
	w->layer_list=(struct TS_WorldLayerList *)ts_malloc(sizeof(struct TS_WorldLayerList));
	w->layer_list->wl=(struct TS_WorldLayer *)ts_malloc(sizeof(struct TS_WorldLayer));
	w->layer_list->wl->data=(ushort *)ts_malloc(sizeof(ushort)*xtiles*ytiles);
	w->layer_list->wl->name=(char *)ts_malloc(sizeof(char)*50);
	strcpy(w->layer_list->wl->name,"default");
	w->layer_list->next=(struct TS_WorldLayerList *)ts_malloc(sizeof(struct TS_WorldLayerList));
	return w;
}


void ts_world_view(TS_World *world)
{
	TS_WorldLayerList *l=NULL;
	l=world->layer_list;
	fprintf(stdout,"\n");
	if (l->next==NULL) {
		fprintf(stdout,"%s\n",l->wl->name);
	}
	else {
		while(l->next!=NULL) {
			fprintf(stdout,"%s\n",l->wl->name);
			l=l->next;
		}
	}
}


void ts_world_free(TS_World *world)
{
	int item=0;
	TS_WorldLayerList *l,*a=NULL;
	l=world->layer_list;
	if (l->next==NULL) {
		ts_world_layer_free(l->wl);
		item++;
		world->layer_list=(TS_WorldLayerList *)ts_free(l);
		world=(TS_World *)ts_free(world);
	}
	else {
		while(l->next!=NULL) {
			a=l;
			l=l->next;
			ts_world_layer_free(a->wl);
			item++;
			a=(TS_WorldLayerList *)ts_free(a);
		}
	}
}


void ts_world_layer_create(TS_World *w, const char *name)
{
	TS_WorldLayerList *l=NULL;
	l=w->layer_list;
	while(l->next!=NULL) {
		l=l->next;
	}
	l->wl=(struct TS_WorldLayer *)ts_malloc(sizeof(struct TS_WorldLayer));
	l->wl->data=(ushort *)ts_malloc(sizeof(ushort)*w->xtiles*w->ytiles);
	l->wl->name=(char *)ts_malloc(sizeof(char)*50);
	strcpy(l->wl->name,name);
	l->next=(struct TS_WorldLayerList *)ts_malloc(sizeof(struct TS_WorldLayerList));;
}


void ts_world_layer_free(TS_WorldLayer *wlayer)
{
	wlayer->name=(char *)ts_free(wlayer->name);
	wlayer->data=(ushort *)ts_free(wlayer->data);
	wlayer=(TS_WorldLayer *)ts_free(wlayer);
}


void ts_world_layer_set_data(TS_World *world, TS_WorldLayer *wlayer, ushort x, ushort y, ushort value)
{
	*((wlayer->data)+(world->xtiles*y)+x)=value;
}


ulong ts_world_layer_get_offset(TS_World *world, TS_WorldLayer *wlayer, ushort xroom, ushort yroom, ushort x, ushort y)
{
	ulong res=0;
	res=(world->xtiles*((yroom*world->yviewport)+y))+((world->xviewport*xroom)+x);
	return (res);
}


ushort ts_world_layer_get_data(TS_World *world, TS_WorldLayer *wlayer, ushort x, ushort y)
{
	ushort v=0;
	v= *((wlayer->data)+(world->xtiles*y)+x);
	return v;
}


ushort ts_world_layer_get_data_from_offset(TS_World *world, TS_WorldLayer *wlayer, ulong offset)
{
	ushort v=0;
	v= wlayer->data[offset];
	return v;
}


TS_WorldLayer * ts_world_layer_get_layer(TS_World *world, const char *name)
{
	TS_WorldLayerList *l=NULL;
	l=world->layer_list;

	while(l->next!=NULL) {
		if (!strcmp(name,l->wl->name)) {
			return l->wl;
		}
		l=l->next;
	}
	ts_debug(_("The layer is not found in this map."),TS_FL);
	return NULL;
}


void ts_world_layer_set_data_from_offset(TS_World *world, TS_WorldLayer *wlayer, ulong offset, ushort value)
{
	wlayer->data[offset]=value;
}


ushort ts_world_get_width(TS_World *w)
{
	return w->xtiles;
}


ushort ts_world_get_height(TS_World *w)
{
	return w->ytiles;
}


ushort ts_world_get_tile_width(TS_World *w)
{
	return w->xtilesize;
}


ushort ts_world_get_tile_height(TS_World *w)
{
	return w->ytilesize;
}


ushort ts_world_get_viewport_width(TS_World *w)
{
	return w->xviewport;
}


ushort ts_world_get_viewport_height(TS_World *w)
{
	return w->yviewport;
}


EXPORT int tl_world_create(TS_Lua *ls)
{
	TS_World *w=NULL;
	w=ts_world_create((ushort)ts_lua_tonumber(ls,1),(ushort)ts_lua_tonumber(ls,2),(ushort)ts_lua_tonumber(ls,3),(ushort)ts_lua_tonumber(ls,4),(ushort)ts_lua_tonumber(ls,5),(ushort)ts_lua_tonumber(ls,6));
	ts_lua_pushuserdata(ls,w);
	return 1;
}


EXPORT int tl_world_free(TS_Lua *ls)
{
	ts_world_free((TS_World *)ts_lua_touserdata(ls,1));
	return 0;
}


EXPORT int tl_world_get_width(TS_Lua *ls)
{
	ushort res=0;
	res=ts_world_get_width((TS_World *)ts_lua_touserdata(ls,1));
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_world_get_height(TS_Lua *ls)
{
	ushort res=0;
	res=ts_world_get_height((TS_World *)ts_lua_touserdata(ls,1));
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_world_get_viewport_width(TS_Lua *ls)
{
	ushort res=0;
	res=ts_world_get_viewport_width((TS_World *)ts_lua_touserdata(ls,1));
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_world_get_viewport_height(TS_Lua *ls)
{
	ushort res=0;
	res=ts_world_get_viewport_height((TS_World *)ts_lua_touserdata(ls,1));
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_world_get_tile_width(TS_Lua *ls)
{
	ushort res=0;
	res=ts_world_get_tile_width((TS_World *)ts_lua_touserdata(ls,1));
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_world_get_tile_height(TS_Lua *ls)
{
	ushort res=0;
	res=ts_world_get_tile_height((TS_World *)ts_lua_touserdata(ls,1));
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_world_layer_create(TS_Lua *ls)
{
	ts_world_layer_create((TS_World *)ts_lua_touserdata(ls,1),ts_lua_tostring(ls,2));
	return 0;
}


EXPORT int tl_world_layer_get_layer(TS_Lua *ls)
{
	TS_WorldLayer *layer=NULL;
	layer=ts_world_layer_get_layer((TS_World *)ts_lua_touserdata(ls,1),ts_lua_tostring(ls,2));
	ts_lua_pushuserdata(ls,layer);
	return 1;
}


EXPORT int tl_world_layer_get_data(TS_Lua *ls)
{
	ushort res=0;
	res=ts_world_layer_get_data((TS_World *)ts_lua_touserdata(ls,1),(TS_WorldLayer *)ts_lua_touserdata(ls,2),(ushort)ts_lua_tonumber(ls,3),(ushort)ts_lua_tonumber(ls,4));
	ts_lua_pushnumber(ls,res);
	return 1;
}


EXPORT int tl_world_layer_get_data_from_offset(TS_Lua *ls)
{
	ushort res=0;
	if (ls!=NULL) {
		res=ts_world_layer_get_data_from_offset((TS_World *)ts_lua_touserdata(ls,1),(TS_WorldLayer *)ts_lua_touserdata(ls,2),(ulong)ts_lua_tonumber(ls,3));
		ts_lua_pushnumber(ls,res);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_world_layer_set_data(TS_Lua *ls)
{
	ts_world_layer_set_data((TS_World *)ts_lua_touserdata(ls,1),(TS_WorldLayer *)ts_lua_touserdata(ls,2),(ushort)ts_lua_tonumber(ls,3),(ushort)ts_lua_tonumber(ls,4),(ushort)ts_lua_tonumber(ls,5));
	return 0;
}


EXPORT int tl_world_layer_set_data_from_offset(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_world_layer_set_data_from_offset((TS_World *)ts_lua_touserdata(ls,1),(TS_WorldLayer *)ts_lua_touserdata(ls,2),(ulong)ts_lua_tonumber(ls,3),(ushort)ts_lua_tonumber(ls,4));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_world_save(TS_Lua *ls)
{
	ts_world_save((TS_World *)ts_lua_touserdata(ls,1),ts_lua_tostring(ls,2));
	return 0;
}


EXPORT int tl_world_load(TS_Lua *ls)
{
	TS_World *w=NULL;
	w=ts_world_load(ts_lua_tostring(ls,1));
	ts_lua_pushuserdata(ls,w);
	return 1;
}


EXPORT int tl_world_view(TS_Lua *ls)
{
	ts_world_view((TS_World *)ts_lua_touserdata(ls,1));
	return 0;
}


EXPORT int tl_world_layer_free(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_world_layer_free((TS_WorldLayer *)ts_lua_touserdata(ls,1));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_world_layer_get_offset(TS_Lua *ls)
{
	ulong res=0;
	if (ls!=NULL) {
		res=ts_world_layer_get_offset((TS_World *)ts_lua_touserdata(ls,1),(TS_WorldLayer *)ts_lua_touserdata(ls,2),\
			(ushort)ts_lua_tonumber(ls,3),(ushort)ts_lua_tonumber(ls,4),(ushort)ts_lua_tonumber(ls,5),(ushort)ts_lua_tonumber(ls,6));
		ts_lua_pushnumber(ls,res);
		return 1;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}
