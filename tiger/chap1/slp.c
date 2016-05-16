#include "util.h"
#include "slp.h"

A_stm A_CompoundStm(A_stm stm1, A_stm stm2) {
	A_stm s= checked_malloc(sizeof (*s));
	s->kind = A_compoundStm ; s->u.compoundStm.stm1 = stm1; s->u.compoundStm.stm2 = stm2;
	return s;
}
A_stm A_AssignStm(string id,A_exp exp ){
	A_stm s = checked_malloc(sizeof(*s));
	s->kind = A_assignStm; s->u.assignStm.id = id; s->u.assignStm.exp = exp;
	return s;
}
A_stm A_PrintStm(A_expList expList) {
	A_stm s = checked_malloc(sizeof(*s));
	s->kind = A_printStm; s->u.printStm.expList = expList;
	return s;
}
A_exp A_IdExp(string id) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_idExp; e->u.id = id;
	return e;
}
A_exp A_NumExp(int num) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_numExp;e->u.num = num;
	return e;
}
A_exp A_OpExp(A_exp exp1, A_binop op, A_exp exp2) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_opExp;e->u.opExp.exp1 = exp1;e->u.opExp.exp2 = exp2;e->u.opExp.op = op;
	return e;
}
A_exp A_EseqExp(A_stm stm, A_exp exp) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_eseqExp;e->u.eseqExp.stm = stm;e->u.eseqExp.exp = exp;
	return e;
}
A_expList A_PairExpList(A_exp exp, A_expList expList) {
	A_expList el = checked_malloc(sizeof(*el));
	el->kind = A_pairExpList;el->u.pairExpList.exp = exp;el->u.pairExpList.expList = expList;
	return el;
}
A_expList A_LastExpList(A_exp exp) {
	A_expList el = checked_malloc(sizeof(*el));
	el->kind = A_lastExpList;el->u.lastExpList = exp;
	return el;
}
