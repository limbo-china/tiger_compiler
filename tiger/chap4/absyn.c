#include "absyn.h"
#include "symbol.h"
#include "util.h"

A_var A_SimpleVar(A_pos pos, S_symbol id) {
	A_var v = checked_malloc(sizeof(*v));
	v->kind = A_simpleVar;v->pos = pos;v->u.simple = id;
	return v;
}
A_var A_FieldVar(A_pos pos, A_var var, S_symbol id) {
	A_var v = checked_malloc(sizeof(*v));
	v->kind = A_fieldVar;v->pos = pos;v->u.field.var = var;v->u.field.id = id;
	return v;
}
A_var A_SubscriptVar(A_pos pos, A_var var, A_exp exp) {
	A_var v = checked_malloc(sizeof(*v));
	v->kind = A_subscriptVar;v->pos = pos;v->u.subscript.var = var;v->u.subscript.exp = exp;
	return v;
}
A_exp A_VarExp(A_pos pos, A_var var) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_varExp;e->pos = pos;e->u.var = var;
	return e;
}
A_exp A_NilExp(A_pos pos) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_nilExp;e->pos = pos;
	return e;
}
A_exp A_IntExp(A_pos pos, int i) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_intExp;e->pos = pos;e->u.int_ = i;
	return e;
}
A_exp A_StringExp(A_pos pos, string s) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_stringExp;e->pos = pos;e->u.string_ = s;
	return e;
}
A_exp A_CallExp(A_pos pos, S_symbol func, A_expList args) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_callExp;e->pos = pos;e->u.call.func = func;e->u.call.args = args;
	return e;
}
A_exp A_OpExp(A_pos pos, A_exp exp1, A_binop op, A_exp exp2) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_opExp;e->pos = pos;e->u.op.exp1 = exp1;e->u.op.exp2 = exp2;e->u.op.op = op;
	return e;
}
A_exp A_RecordExp(A_pos pos, S_symbol type, A_assignfieldList aflist) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_recordExp;e->pos = pos;e->u.record.type = type;e->u.record.assignfieldList = aflist;
	return e;
}
A_exp A_SeqExp(A_pos pos, A_expList elist) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_seqExp;e->pos = pos;e->u.seq = elist;
	return e;
}
A_exp A_AssignExp(A_pos pos, A_var var, A_exp exp) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_assignExp;e->pos = pos;e->u.assign.var = var;e->u.assign.exp = exp;
	return e;
}
A_exp A_IfExp(A_pos pos, A_exp exp1, A_exp exp2, A_exp exp3) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_ifExp;e->pos = pos;e->u.if_.exp1 = exp1;e->u.if_.exp2 = exp2;e->u.if_.exp3 = exp3;
	return e;
}
A_exp A_WhileExp(A_pos pos, A_exp exp1, A_exp exp2) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_whileExp;e->pos = pos;e->u.while_.exp1 = exp1;e->u.while_.exp2 = exp2;
	return e;
}
A_exp A_BreakExp(A_pos pos) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_breakExp;e->pos = pos;
	return e;
}
A_exp A_ForExp(A_pos pos, S_symbol id, A_exp exp1, A_exp exp2, A_exp exp3) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_forExp;e->pos = pos;e->u.for_.id = id;e->u.for_.exp1 = exp1;
	e->u.for_.exp2 = exp2;e->u.for_.exp3 = exp3;
	return e;
}
A_exp A_LetExp(A_pos pos, A_decList dlist, A_expList elist) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_letExp;e->pos = pos;e->u.let.decList = dlist;e->u.let.expList = elist;
	return e;
}
A_exp A_ArrayExp(A_pos pos, S_symbol type, A_exp exp1, A_exp exp2) {
	A_exp e = checked_malloc(sizeof(*e));
	e->kind = A_arrayExp;e->pos = pos;e->u.array.type = type;
	e->u.array.exp1 = exp1;e->u.array.exp2 = exp2;
	return e;
}

A_dec A_FunctionDec(A_pos pos, S_symbol func, A_tyfieldList tflist, S_symbol type, A_exp exp) {
	A_dec d = checked_malloc(sizeof(*d));
	d->kind = A_functionDec;d->pos = pos;d->u.function.func = func;
	d->u.function.tyfieldList = tflist;d->u.function.type = type;d->u.function.exp = exp;
	return d;
}
A_dec A_TypeDec(A_pos pos, S_symbol type, A_ty ty) {
	A_dec d = checked_malloc(sizeof(*d));
	d->kind = A_typeDec;d->pos = pos;d->u.type.type = type;d->u.type.ty = ty;
	return d;
}
A_dec A_VarDec(A_pos pos, S_symbol id, S_symbol type, A_exp exp){
	A_dec d = checked_malloc(sizeof(*d));
	d->kind =A_varDec; d->pos= pos;d->u.var.id=id;d->u.var.type=type;d->u.var.exp=exp;
	return d;
}

A_ty A_IdTy(A_pos pos, S_symbol type) {
	A_ty t = checked_malloc(sizeof(*t));
	t->kind = A_idTy;t->pos = pos;t->u.id = type;
	return t;
}
A_ty A_TyfieldTy(A_pos pos, A_tyfieldList tflist) {
	A_ty t = checked_malloc(sizeof(*t));
	t->kind = A_tyfieldTy;t->pos = pos;t->u.tyfield = tflist;
	return t;
}
A_ty A_ArrayTy(A_pos pos, S_symbol type) {
	A_ty t = checked_malloc(sizeof(*t));
	t->kind = A_arrayTy;t->pos = pos;t->u.array = type;
	return t;
}

A_expList A_ExpList(A_exp head, A_expList tail) {
	A_expList el = checked_malloc(sizeof(*el));
	el->head = head;el->tail = tail;
	return el;
}
A_assignfield A_Assignfield(A_pos pos, S_symbol id, A_exp exp){
	A_assignfield af = checked_malloc(sizeof(*af));
	af->pos = pos;af->id = id;af->exp = exp;
	return af;
}
A_assignfieldList A_AssignfieldList(A_assignfield head, A_assignfieldList tail) {
	A_assignfieldList afl = checked_malloc(sizeof(*afl));
	afl->head = head;afl->tail = tail;
	return afl;
}
A_decList A_DecList(A_dec head, A_decList tail) {
	A_decList dl = checked_malloc(sizeof(*dl));
	dl->head = head;dl->tail = tail;
	return dl;
}
A_tyfield A_Tyfield(A_pos pos, S_symbol id, S_symbol type) {
	A_tyfield tf = checked_malloc(sizeof(*tf));
	tf->pos = pos;tf->id = id;tf->type = type;
	return tf;
}
A_tyfieldList A_TyfieldList(A_tyfield head, A_tyfieldList tail) {
	A_tyfieldList tfl = checked_malloc(sizeof(*tfl));
	tfl->head = head;tfl->tail = tail;
	return tfl;
}
