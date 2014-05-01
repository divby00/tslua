#include "ts_debug.h"
#include "ts_trans.h"

void ts_debug(const char *cad, const char *filename, ulong line)
{
	#ifdef TS_DEBUG_H
	if (cad!=NULL) {
		fprintf(stdout,_("\nTSLib message:"));
		fprintf(stdout,"\n%s",cad);
		fprintf(stdout,_("\nFile: %s"),filename);
		fprintf(stdout,_("\nLine: %ld\n"),line);
	}
	else {
		fprintf(stdout,_("Invalid string"));
	}
	#endif
}
