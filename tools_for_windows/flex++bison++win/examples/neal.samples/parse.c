#include "parse.h"
#include <stdio.h>
#include "config.h"
#include "param.h"
#include "PROTO.h"
#include <errno.h>
#include "epsy.h"

int FoundPrinter = 0;

/* return 0 if not found, 1 if found, -1 if parse error */
int FindPrinter() {
  FILE* in = fopen( CONFIG_FILE, "r" );
  if( !in ) {
    error(0, errno, "can't open %s", CONFIG_FILE);
    return 0;
  }
  parse Parser( in );
  if( Parser.yyparse() )
    return -1;
  else
    return FoundPrinter;
}

