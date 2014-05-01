#ifndef TS_MALLOC_H
#define TS_MALLOC_H

#include "ts_defs.h"
#include "ts_debug.h"

void * ts_malloc(ulong size);
void * ts_free(void *data);
#endif																						// TS_MALLOC_H
