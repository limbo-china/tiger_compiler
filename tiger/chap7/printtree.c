/*
 * printtree.c - functions to print out intermediate representation (IR) trees.
 *
 */
#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "temp.h"
#include "tree.h"
#include "printtree.h"

/* local function prototype */


static void indent(FILE *out, int d) {
 int i;
 for (i = 0; i <= d; i++) fprintf(out, " ");
}

static char bin_oper[][12] = {
   "PLUS", "MINUS", "TIMES", "DIVIDE", 
   "AND", "OR", "XOR", "LSHIFT", "RSHIFT", "ARSHIFT"};

static char rel_oper[][12] = {
  "EQ", "NEQ", "LT", "GT", "LE", "GE", "ULT", "UGT", "ULE", "UGE"};
void pr_stm(FILE *out, T_stm stm, int d)
{
  switch (stm->kind) {
  case T_seq:
    indent(out,d);
    fprintf(out, "Seq(\n"); pr_stm(out, stm->u.seq.stm1,d+1);  fprintf(out, ",\n"); 
    pr_stm(out, stm->u.seq.stm2,d+1); fprintf(out, ")");
    break;
  case T_label:
	  indent(out, d); fprintf(out, "Label(%s)", S_name(stm->u.label));
    break;
  case T_jump:
    indent(out,d); fprintf(out, "Jump(\n"); pr_tree_exp(out, stm->u.jump.exp,d+1); 
    fprintf(out, ")");
    break;
  case T_cjump:
    indent(out,d); fprintf(out, "Cjump(%s,\n", rel_oper[stm->u.cjump.relop]);
    pr_tree_exp(out, stm->u.cjump.exp1,d+1); fprintf(out, ",\n"); 
    pr_tree_exp(out, stm->u.cjump.exp2,d+1); fprintf(out, ",\n");
    indent(out,d+1); fprintf(out, "%s,", S_name(stm->u.cjump.true_));
    fprintf(out, "%s", S_name(stm->u.cjump.false_)); fprintf(out, ")");
    break;
  case T_move:
    indent(out,d); fprintf(out, "Move(\n"); pr_tree_exp(out, stm->u.move.exp1,d+1); 
    fprintf(out, ",\n");
    pr_tree_exp(out, stm->u.move.exp2,d+1); fprintf(out, ")");
    break;
  case T_expstm:
    indent(out,d); fprintf(out, "ExpStm(\n"); pr_tree_exp(out, stm->u.expstm.exp,d+1); 
    fprintf(out, ")");
    break;
  }
}

void pr_tree_exp(FILE *out, T_exp exp, int d)
{
  switch (exp->kind) {
  case T_binopexp:
    indent(out,d); fprintf(out, "BinopExp(%s,\n", bin_oper[exp->u.binopexp.op]); 
    pr_tree_exp(out, exp->u.binopexp.exp1,d+1); fprintf(out, ",\n"); 
    pr_tree_exp(out, exp->u.binopexp.exp2,d+1); fprintf(out, ")");
    break;
  case T_mem:
    indent(out,d); fprintf(out, "Mem");
    fprintf(out, "(\n"); pr_tree_exp(out, exp->u.mem,d+1); fprintf(out, ")");
    break;
  case T_temp:
    indent(out,d); fprintf(out, "Temp(%s)", 
			   Temp_look(Temp_name(), exp->u.temp));
    break;
  case T_eseq:
    indent(out,d); fprintf(out, "Eseq(\n"); pr_stm(out, exp->u.eseq.stm,d+1); 
    fprintf(out, ",\n");
    pr_tree_exp(out, exp->u.eseq.exp,d+1); fprintf(out, ")");
    break;
  case T_name:
    indent(out,d); fprintf(out, "Name(%s)", S_name(exp->u.name));
    break;
  case T_const:
    indent(out,d); fprintf(out, "Const(%d)", exp->u.const_);
    break;
  case T_call:
    {T_expList args = exp->u.call.args;
     indent(out,d); fprintf(out, "Call(\n"); pr_tree_exp(out, exp->u.call.fun,d+1);
     for (;args; args=args->tail) {
       fprintf(out, ",\n"); pr_tree_exp(out, args->head,d+2);
     }
     fprintf(out, ")");
     break;
   }
  } /* end of switch */
}

void printStmList (FILE *out, T_stmList stmList) 
{
  for (; stmList; stmList=stmList->tail) {
    pr_stm(out, stmList->head,0); fprintf(out, "\n");
  }
}
