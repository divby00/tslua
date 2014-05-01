#include "ts_malloc.h"
#include "ts_trans.h"
#include <malloc.h>
#include <string.h>

void * ts_malloc(ulong size)
{
	void *aux=NULL;
	aux=malloc(size);
	if (aux==NULL) {
		ts_debug(_("Error allocating %ld bytes of data."),TS_FL);
		return NULL;
	}
	memset(aux,0,size);
	return aux;
}


void * ts_free(void *data)
{
	if (data==NULL) {
		ts_debug(_("Error while freeing a NULL pointer"),TS_FL);
	}
	else {
		free(data);
	}
	return NULL;
}
