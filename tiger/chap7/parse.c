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
#include "printtree.h"

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
	FILE *fp1, *fp2;
	if((fp1=fopen("prabsyn_result.txt","w"))==NULL)
		printf("cannot open file!\n");
	if((fp2 = fopen("prtreeexp_result.txt", "w")) == NULL)
		printf("cannot open file!\n");
	if (argc!=2) {fprintf(stderr,"usage: a.out filename\n"); exit(1);}
	
	A_exp exp = parse(argv[1]);
	if (exp) {
		printf("analyze abstract syntax successfully!\n");
		pr_exp(fp1, exp, 0);
		Tr_exp e= SEM_TransProg(exp);
		printf("semant check end!\n");
		pr_tree_exp(fp2, UnEx(e), 0);//暂时调用UnEx调试，本该不能被外部调用
	}
	else
		printf("pass the syntax rule to begin semant check!\n");
	return 0;
}