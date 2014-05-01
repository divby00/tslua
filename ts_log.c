#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "ts_trans.h"
#include "ts_struct.h"
#include "ts_malloc.h"
#include "ts_lua.h"

extern TS_Handler *tsh;

void ts_log(char *format,...)
{
	FILE *file;
	va_list args;
	static char init=1;
	time_t ti;
	char msg[TS_MAX_STRING];

	if (!tsh->log->log_on) return;

	if (init) {
		file=fopen(tsh->log->log_filename,"at+");
		if (file==NULL) {
			tsh->log->log_on=0;
		}
	}

	if (tsh->log->log_on) {
		va_start(args,format);
		file=fopen(tsh->log->log_filename,"at+");

		if (init) {
			ti = time((time_t *)NULL);
			sprintf(msg,"%s",_("\n\n- - - Begin the log - - -\n"));
			fprintf(file,"%s",msg);
			fprintf(file,_("Date and time: %s\n"),ctime(&ti));
			init=0;
		}
		vfprintf(file,format,args);
		fflush(file);
		fclose(file);
		va_end(args);
	}
}


schar ts_log_init(void)
{
	tsh->log=(TS_Log *)ts_malloc(sizeof(struct TS_Log));
	if (tsh->log==NULL) return TS_ERROR;
	tsh->log->log_filename=(char *)ts_malloc(TS_MAX_STRING);
	if (tsh->log->log_filename==NULL) return TS_ERROR;
	tsh->log->log_on=TS_LOG;
	strcpy(tsh->log->log_filename,tsh->program_name);
	strcat(tsh->log->log_filename,".log");
	return TS_OK;
}


void ts_log_quit(void)
{
	tsh->log->log_filename=(char *)ts_free(tsh->log->log_filename);
	tsh->log=(TS_Log *)ts_free(tsh->log);
}


void ts_log_set_active(schar log_active)
{
	tsh->log->log_on=log_active;
}


EXPORT int tl_log_set_active(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_log_set_active((schar)ts_lua_tonumber(ls,1));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}


EXPORT int tl_log(TS_Lua *ls)
{
	if (ls!=NULL) {
		ts_log((char *)ts_lua_tostring(ls,1));
		return 0;
	}
	else {
		ts_debug(_("Invalid Lua handler"),TS_FL);
		return 0;
	}
}
