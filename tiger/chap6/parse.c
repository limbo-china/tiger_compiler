/*
 * parse.c - Parse source file.
 */

#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "prabsyn.h"
#include "symbol.h"
#include "absyn.h"
#include "errormsg.h"
#include "parse.h"
#include "semant.h"

extern int yyparse(void);
extern A_exp absyn_root;

/* parse source file fname; 
   return abstract syntax data structure */
A_exp parse(string fname) 
{EM_reset(fname);
 if (yyparse() == 0) /* parsing worked */
   return absyn_root;
 else{
	 printf("not pass!\n");
	 return NULL;
	} 
	 
}
int main(int argc, char **argv){
	FILE *fp;
	if((fp=fopen("prabsyn_result.txt","w"))==NULL)
		printf("cannot open file!\n");
	if (argc!=2) {fprintf(stderr,"usage: a.out filename\n"); exit(1);}
	
	A_exp exp = parse(argv[1]);
	if (exp) {
		printf("analyze abstract syntax successfully!\n");
		pr_exp(fp, exp, 0);
		SEM_TransProg(exp);
		printf("semant check end!\n");
	}
	else
		printf("pass the syntax rule to begin semant check!\n");
	return 0;
}