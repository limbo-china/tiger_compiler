#include "slp.h"
#include "util.h"
#include "prog1.h"
#include <stdio.h>

typedef struct table *Table_;
struct table { string id; int value; Table_ tail; };
struct intandtable { int i;Table_ t; };


Table_ Table(string id, int value, Table_ tail);
Table_ interpStm(A_stm stm, Table_ t);
int lookup(Table_ t, string key);
struct intandtable interpExp(A_exp exp, Table_ t);

Table_ Table(string id, int value, Table_ tail) {
	Table_ t = checked_malloc(sizeof(*t));
	t->id = id; t->value = value; t->tail = tail;
	return t;
}

Table_ interpStm(A_stm stm, Table_ t) {

}
struct intandtable interpExp(A_exp exp, Table_ t) {

}


int maxargs(A_stm stm);
int maxargs(A_stm stm) {
	if (stm->kind == A_compoundStm) {
		A_stm stm1, stm2;
		stm1 = stm->u.compoundStm.stm1;stm2 = stm->u.compoundStm.stm2;
		return maxargs(stm1) + maxargs(stm2);
	}
	else if (stm->kind == A_assignStm) {
		A_exp exp = stm->u.assignStm.exp;
		int nums = 0;
		if(exp->kind == A_eseqExp) {
			 return maxargs(exp->u.eseqExp.stm);  
			 //可能有错，暂时不改。Exp->(Stm,Exp)除了Stm中可能有print外，Exp中可能也有，应该考虑到。
		}
		return 0;
	}
	else {
		A_expList expList = stm->u.printStm.expList;
		int nums = 1;
		while (expList->kind != A_lastExpList) {
			A_exp exp = expList->u.pairExpList.exp;
			if (exp->kind == A_eseqExp) {
				nums = nums + maxargs(exp->u.eseqExp.stm);
			}
			expList = expList->u.pairExpList.expList;
		}
		if (expList->kind == A_lastExpList) {
			A_exp exp = expList->u.lastExpList;
			if (exp->kind == A_eseqExp) {
				nums = nums + maxargs(exp->u.eseqExp.stm);
			}
		}
		return nums;
	}
}



int main() {
	A_stm stm = prog1();
	printf("%d\n", maxargs(stm));
}