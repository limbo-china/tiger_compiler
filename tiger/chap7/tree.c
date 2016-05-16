#include "tree.h"
#include "util.h"

T_stm T_Move(T_exp exp1, T_exp exp2) {
	T_stm s = checked_malloc(sizeof(*s));
	s->kind = T_move;s->u.move.exp1 = exp1;s->u.move.exp2 = exp2;
	return s;
}
T_stm T_Exp(T_exp exp) {
	T_stm s = checked_malloc(sizeof(*s));
	s->kind = T_expstm;s->u.expstm.exp = exp;
	return s;
}
T_stm T_Jump(T_exp exp, Temp_labelList labs) {
	T_stm s = checked_malloc(sizeof(*s));
	s->kind = T_jump;s->u.jump.exp = exp;s->u.jump.labs = labs;
	return s;
}
T_stm T_Cjump(T_relop relop, T_exp exp1, T_exp exp2, Temp_label true_, Temp_label false_) {
	T_stm s = checked_malloc(sizeof(*s));
	s->kind = T_cjump;s->u.cjump.relop = relop;s->u.cjump.exp1 = exp1;s->u.cjump.exp2 = exp2;
	s->u.cjump.true_ = true_;s->u.cjump.false_ = false_;
	return s;
}
T_stm T_Seq(T_stm stm1, T_stm stm2) {
	T_stm s = checked_malloc(sizeof(*s));
	s->kind = T_seq;s->u.seq.stm1 = stm1;s->u.seq.stm2 = stm2;
	return s;
}
T_stm T_Label(Temp_label label) {
	T_stm s = checked_malloc(sizeof(*s));
	s->kind = T_label;s->u.label = label;
	return s;
}

T_exp T_Const(int i) {
	T_exp e = checked_malloc(sizeof(*e));
	e->kind = T_const;e->u.const_ = i;
	return e;
}
T_exp T_Name(Temp_label name) {
	T_exp e = checked_malloc(sizeof(*e));
	e->kind = T_name;e->u.name = name;
	return e;
}
T_exp T_Temp(Temp_temp temp) {
	T_exp e = checked_malloc(sizeof(*e));
	e->kind = T_temp;e->u.temp = temp;
	return e;
}
T_exp T_Binopexp(T_binop binop, T_exp exp1, T_exp exp2) {
	T_exp e = checked_malloc(sizeof(*e));
	e->kind = T_binopexp; e->u.binopexp.op = binop;e->u.binopexp.exp1 = exp1;
	e->u.binopexp.exp2 = exp2;
	return e;
}
T_exp T_Mem(T_exp mem) {
	T_exp e = checked_malloc(sizeof(*e));
	e->kind = T_mem;e->u.mem = mem;
	return e;
}
T_exp T_Call(T_exp fun, T_expList args) {
	T_exp e = checked_malloc(sizeof(*e));
	e->kind = T_call;e->u.call.fun = fun;e->u.call.args = args;
	return e;
}
T_exp T_Eseq(T_stm stm, T_exp exp) {
	T_exp e = checked_malloc(sizeof(*e));
	e->kind = T_eseq;e->u.eseq.stm = stm;e->u.eseq.exp = exp;
	return e;
}

T_stmList T_StmList(T_stm head, T_stmList tail) {
	T_stmList sl = checked_malloc(sizeof(*sl));
	sl->head = head;sl->tail = tail;
	return sl;
}
T_expList T_ExpList(T_exp head, T_expList tail) {
	T_expList el = checked_malloc(sizeof(*el));
	el->head = head;el->tail = tail;
	return el;
}
