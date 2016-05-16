#ifndef _PRTREE_H
#define _PRTREE_H
/* function prototype from printtree.c */
void printStmList (FILE *out, T_stmList stmList) ;
void pr_tree_exp(FILE *out, T_exp exp, int d);
void pr_stm(FILE *out, T_stm stm, int d);

//void printTreeExp(T_exp e, FILE * out);
//void printTreeStm(T_stm s, FILE * out);
#endif