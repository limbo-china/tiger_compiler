#include <stdio.h>
#include "semant.h"


expty Expty(Tr_exp exp, Ty_ty ty) {
	expty et = checked_malloc(sizeof(*et));
	et->exp = exp; et->ty = ty;
	return et;
}

expty TransVar(Tr_level level,S_table venv, S_table tenv, A_var var) { //对变量进行类型检查
	switch (var->kind) {

	case A_simpleVar: {
		E_envEntry e = S_look(venv, var->u.simple);
		if (e && e->kind == E_varEntry)
			return Expty(NULL, Actual_Ty(e->u.var.ty));
		else {
			EM_error(var->pos, "var '%s' undefined", S_name(var->u.simple));
			return Expty(NULL, Ty_Void());  /////书上返回Ty_Int()???
		}
		break;
	}
	case A_fieldVar: {    //有难度，想了好久，未测试
		expty et = TransVar(level,venv, tenv, var->u.field.var);
		Ty_ty ty = et->ty;
		if (ty->kind == Ty_record) {
			Ty_tyfieldList fl = ty->u.record;
			while (fl && fl->head->sym != var->u.field.id) {
				fl = fl->tail;
			}
			if (fl == NULL) {
				EM_error(var->pos, "there is not '%s' var in the field", S_name(var->u.field.id));
				return Expty(NULL, Ty_Void());
			}
			else
				return Expty(NULL, Actual_Ty(fl->head->ty));
		}
		else {
			EM_error(var->pos, "there must be a record var before '.%s'", S_name(var->u.field.id));
			return Expty(NULL, Ty_Void());
		}
		break;
	}
	case A_subscriptVar: { //类似 A_fieldVar 只是检查前面是不是数组类型的变量, 还需要检查 [] 内的是不是整数类型
		expty et1 = TransVar(level, venv, tenv, var->u.subscript.var);
		expty et2 = TransExp(level, venv, tenv, var->u.subscript.exp);
		Ty_ty ty1 = et1->ty, ty2 = et2->ty;
		if (ty1->kind == Ty_array) {    //未实现检查是否越界
			if (ty2->kind == Ty_int) {
				return Expty(NULL, Actual_Ty(ty1->u.array));
			}
			else {
				EM_error(var->u.subscript.exp->pos, "the expression in '[]' is not an integer");
				return Expty(NULL, Ty_Void());
			}
		}
		else {
			EM_error(var->u.subscript.var->pos, "there must be an array var before '['");
			return Expty(NULL, Ty_Void());
		}
		break;
	}
	default:
		return Expty(NULL, Ty_Void());
		break;
	}
}
expty TransExp(Tr_level level,S_table venv, S_table tenv, A_exp exp) { //对表达式进行类型检查
	switch (exp->kind) {

	case A_varExp: {
		return TransVar(level, venv, tenv, exp->u.var);
	}
	case A_nilExp: {
		return Expty(NULL, Ty_Nil());
	}
	case A_intExp: {
		return Expty(NULL, Ty_Int());
	}
	case A_stringExp: {
		return Expty(NULL, Ty_String());
	}
	case A_callExp: {  //函数的类型检查有难度
		E_envEntry e = S_look(venv, exp->u.call.func);
		if (e && e->kind == E_funEntry) {
			A_exp exp_ = NULL;
			A_expList el = exp->u.call.args;
			Ty_ty t = NULL;
			Ty_tyList tl = e->u.fun.args;
			while (tl) {  ///函数的类型检查的关键部分 →  
				if (el == NULL) {
					EM_error(exp->pos, "not enough arguments in function call '%s'", S_name(exp->u.call.func));
					return Expty(NULL, Actual_Ty(e->u.fun.result));
				}

				exp_ = el->head;	t = tl->head;
				if (TransExp(level, venv, tenv, exp_)->ty->kind != Actual_Ty(t)->kind) {
					EM_error(exp_->pos, "type of the argument doesnot fit");
					return Expty(NULL, Actual_Ty(e->u.fun.result));
				}
				tl = tl->tail;
				el = el->tail;
			}
			if (el != NULL) {
				EM_error(exp->pos, "too many arguments in function call '%s'", S_name(exp->u.call.func));
				return Expty(NULL, Actual_Ty(e->u.fun.result));
			}
			return Expty(NULL, Actual_Ty(e->u.fun.result)); ///函数的类型检查的关键部分 ←
		}
		else {
			EM_error(exp->pos, "var '%s' undefined or not a funciton var", S_name(exp->u.call.func));
			return Expty(NULL, Ty_Void());
		}
	}
	case A_opExp: {  //可以检查记录和数组类型
		expty et1 = TransExp(level, venv, tenv, exp->u.op.exp1);
		expty et2 = TransExp(level, venv, tenv, exp->u.op.exp2);
		if (exp->u.op.op == A_eqOp || exp->u.op.op == A_neqOp) {
			if ((et1->ty->kind == Ty_array && et2->ty->kind == Ty_array) || (et1->ty->kind == Ty_record && et2->ty->kind == Ty_record))
				return Expty(NULL, Ty_Int());
			if (et1->ty->kind == Ty_nil || et2->ty->kind == Ty_nil) {
				if (et1->ty->kind == Ty_nil && et2->ty->kind == Ty_nil)
					EM_error(exp->pos, "cannot compare two nil exp");
				return Expty(NULL, Ty_Int());
			}
		}
		if (et1->ty->kind != Ty_int) {
			EM_error(exp->u.op.exp1->pos, "integer required");
		}
		if (et2->ty->kind != Ty_int) {
			EM_error(exp->u.op.exp2->pos, "integer required");
		}
		return Expty(NULL, Ty_Int());
	}
	case A_recordExp: { //有难度，和函数类型检查类似
		Ty_ty ty = S_look(tenv, exp->u.record.type);
		if (ty && ty->kind == Ty_record) {
			A_assignfield af = NULL;
			A_assignfieldList afl = exp->u.record.assignfieldList;
			Ty_tyfield tf = NULL;
			Ty_tyfieldList tfl = ty->u.record;
			while (tfl) {  ///记录的类型检查的关键部分 →  
				if (afl == NULL) {
					EM_error(exp->pos, "not enough fields in record '%s'", S_name(exp->u.record.type));
					return Expty(NULL, ty);
				}

				af = afl->head;	tf = tfl->head;
				if (strcmp(S_name(af->id), S_name(tf->sym)) != 0)
					EM_error(af->pos, "there is not var '%s' in the record", S_name(af->id));
				else if (TransExp(level, venv, tenv, af->exp)->ty->kind != Actual_Ty(tf->ty)->kind)
					EM_error(af->pos, "type of the field doesnot fit");
				afl = afl->tail;
				tfl = tfl->tail;
			}
			if (afl != NULL)
				EM_error(exp->pos, "too many fields in record '%s'", S_name(exp->u.record.type));
			return Expty(NULL, ty);
		}
		else {
			EM_error(exp->pos, "type '%s' undefined or not a record type", S_name(exp->u.record.type));
			return Expty(NULL, Ty_Void());
		}
	}
	case A_seqExp: {  //需要检查其中的每一个exp
		A_exp exp_ = NULL;
		A_expList el = exp->u.seq;
		expty et = NULL;
		if (el) {
			while (el) {
				exp_ = el->head;
				et = TransExp(level, venv, tenv, exp_);
				el = el->tail;
			}
			return Expty(NULL, et->ty);
		}
		else
			return Expty(NULL, Ty_Void());
	}
	case A_assignExp: {
		expty et1 = TransVar(level, venv, tenv, exp->u.assign.var);
		expty et2 = TransExp(level, venv, tenv, exp->u.assign.exp);
		if (et2->ty->kind != Ty_nil && et1->ty->kind != et2->ty->kind)
			EM_error(exp->u.assign.exp->pos, "exp cannot be assigned to var in different type");
		return Expty(NULL, Ty_Void());
	}
	case A_ifelseExp: {
		if (TransExp(level, venv, tenv, exp->u.ifelse.exp1)->ty->kind != Ty_int)
			EM_error(exp->u.ifelse.exp1->pos, "exp after 'if' must be an integer");
		expty et1 = TransExp(level, venv, tenv, exp->u.ifelse.exp2);
		expty et2 = TransExp(level, venv, tenv, exp->u.ifelse.exp3);
		if (et1->ty->kind != et2->ty->kind)
			EM_error(exp->u.ifelse.exp2->pos, "exp after 'then' and 'else' must be of the same type");
		return Expty(NULL, et1->ty);
	}
	case A_ifExp: {
		if (TransExp(level, venv, tenv, exp->u.if_.exp1)->ty->kind != Ty_int)
			EM_error(exp->u.if_.exp1->pos, "exp after 'if' must be an integer");
		if (TransExp(level, venv, tenv, exp->u.if_.exp2)->ty->kind != Ty_void)
			EM_error(exp->u.if_.exp2->pos, "exp after 'then' must be a void var");
		return Expty(NULL, Ty_Void());
	}
	case A_whileExp: {   ///while 表达式的返回值是什么类型?
		if (TransExp(level, venv, tenv, exp->u.while_.exp1)->ty->kind != Ty_int)
			EM_error(exp->u.while_.exp1->pos, "exp after 'while' must be an integer");
		if (TransExp(level, venv, tenv, exp->u.while_.exp2)->ty->kind != Ty_void)
			EM_error(exp->u.while_.exp2->pos, "exp after 'do' must be void type");
		return Expty(NULL, Ty_Void());
	}
	case A_breakExp: {
		return Expty(NULL, Ty_Void());
	}
	case A_forExp: {  ///有隐藏声明，有点特殊，需要修改

		if (TransExp(level, venv, tenv, exp->u.for_.exp1)->ty->kind != Ty_int)
			EM_error(exp->u.for_.exp1->pos, "exp must be an integer");
		if (TransExp(level, venv, tenv, exp->u.for_.exp2)->ty->kind != Ty_int)
			EM_error(exp->u.for_.exp2->pos, "exp must be an integer");

		S_beginScope(venv);
		S_enter(venv, exp->u.for_.id, E_VarEntry(Tr_allocLocal(level,TRUE),Ty_Int()));
		if (TransExp(level, venv, tenv, exp->u.for_.exp3)->ty->kind != Ty_void)
			EM_error(exp->u.for_.exp3->pos, "exp after 'do' must be void type");
		S_endScope(venv);
		return Expty(NULL, Ty_Void());
	}
	case A_letExp: { //有点特殊，因为包含的声明在类型检查时有些不同
		A_decList dl;
		S_beginScope(venv);
		S_beginScope(tenv);
		for (dl = exp->u.let.decList;dl;dl = dl->tail) {
			TransDec(level, venv, tenv, dl->head);
		}

		A_expList el = exp->u.let.expList;
		A_exp e = NULL; expty et = NULL;

		if (el == NULL)
			return Expty(NULL, Ty_Void());
		while (el) {
			e = el->head;
			et = TransExp(level, venv, tenv, e);
			el = el->tail;
		}
		S_endScope(venv);
		S_endScope(tenv);
		return Expty(NULL, et->ty);
	}
	case A_arrayExp: {
		Ty_ty ty = Actual_Ty(S_look(tenv, exp->u.array.type));
		if (ty->kind == Ty_array) {
			if (TransExp(level, venv, tenv, exp->u.array.exp1)->ty->kind != Ty_int)
				EM_error(exp->u.array.exp1->pos, "exp in '[]' must be an integer");
			if (TransExp(level, venv, tenv, exp->u.array.exp2)->ty->kind != Actual_Ty(ty->u.array)->kind)
				EM_error(exp->u.array.exp2->pos, "type of exp after 'of' must be the same as type of array ");
			//返回值的类型为Ty_array
			return Expty(NULL, ty);
		}
		else {
			EM_error(exp->pos, "there must be an array var before '['");
			return Expty(NULL, Ty_Void());
		}
	}
	default:
		return Expty(NULL, Ty_Void());
		break;
	}
}
void TransDec(Tr_level level,S_table venv, S_table tenv, A_dec dec) {  //所有声明表达式均没有返回值类型
	switch (dec->kind) {

	case A_varDec: {
		expty et = TransExp(level, venv, tenv, dec->u.var.exp);
		if (dec->u.var.type == NULL) {
			if (et->ty->kind == Ty_nil)
				EM_error(dec->pos, "there must be a type reference to a nil exp");
			else
				S_enter(venv, dec->u.var.id, E_VarEntry(Tr_allocLocal(level,dec->u.var.escape),et->ty));
		}
		else {
			Ty_ty ty = Actual_Ty(S_look(tenv, dec->u.var.type));
			if (!ty)
				EM_error(dec->pos, "type '%s' undefined", S_name(dec->u.var.type));
			else if ((et->ty->kind == Ty_nil) || (ty->kind == et->ty->kind))
				S_enter(venv, dec->u.var.id, E_VarEntry(Tr_allocLocal(level, dec->u.var.escape), ty));
			else
				EM_error(dec->u.var.exp->pos, "exp doesnot fit the type given");
		}
		break;
	}
	case A_typeDec: {  ///还不能处理递归类型声明
		if (dec->u.type.ty->kind == A_nameTy)
			S_enter(tenv, dec->u.type.name, Ty_Name(dec->u.type.name, TransTy(tenv, dec->u.type.ty)));
		else
			S_enter(tenv, dec->u.type.name, TransTy(tenv, dec->u.type.ty));
		break;
	}
	case A_functionDec: { //还不能处理递归函数声明
		Ty_tyList tl = MakeTyList(tenv, dec->u.function.tyfieldList);
		Ty_ty ty = S_look(tenv, dec->u.function.type);
		Tr_level l = Tr_NewLevel(level, Temp_namedlabel(S_name(dec->u.function.func)), dec->u.function.formals);
		S_enter(venv, dec->u.function.func, E_FunEntry(l, tl, ty));
		S_beginScope(venv);
		A_tyfieldList tfl = dec->u.function.tyfieldList;
		while (tfl && tl) {
			S_enter(venv, tfl->head->id, E_VarEntry(Tr_allocLocal(level,TRUE),tl->head));
			tfl = tfl->tail; tl = tl->tail;
		}
		expty et = TransExp(level, venv, tenv, dec->u.function.exp);
		if(ty)
			if (et->ty->kind != Actual_Ty(ty)->kind)
				EM_error(dec->u.function.exp->pos, "exp must be the same type as result in function call '%s'", S_name(dec->u.function.func));
		S_endScope(venv);
		break;
	}
	default:
		break;
	}
}
Ty_tyList MakeTyList(S_table tenv, A_tyfieldList args) {  //直接递归生成
	if (args == NULL)
		return NULL;
	return Ty_TyList(S_look(tenv, args->head->type), MakeTyList(tenv, args->tail));
}
Ty_tyfieldList MakeTyFieldList(S_table tenv, A_tyfieldList A_tfl) {   //直接递归生成
	if (A_tfl == NULL)
		return NULL;
	Ty_ty ty = S_look(tenv, A_tfl->head->type);
	if (ty == NULL)
		EM_error(A_tfl->head->pos, "type '%s' undefined", S_name(A_tfl->head->type));
	return Ty_TyFieldList(Ty_TyField(A_tfl->head->id, S_look(tenv, A_tfl->head->type)),
		MakeTyFieldList(tenv, A_tfl->tail));
}

Ty_ty TransTy(S_table tenv, A_ty t) { ///what fuck is this function??????????

	Ty_ty ty = NULL;
	switch (t->kind) {

	case A_nameTy: {
		ty = S_look(tenv, t->u.name);
		if (!ty) {
			EM_error(t->pos, "type '%s' undefined", S_name(t->u.name));
			return Ty_Void();
		}
		return ty;
	}
	case A_tyfieldTy: {
		return Ty_Record(MakeTyFieldList(tenv, t->u.tyfield));
	}
	case A_arrayTy: {
		ty = S_look(tenv, t->u.array);
		if (!ty) {
			EM_error(t->pos, "type '%s' undefined", S_name(t->u.array));
			return Ty_Void();
		}
		return Ty_Array(ty);
	}
	default:
		return Ty_Void();
		break;
	}
}

void SEM_TransProg(A_exp exp) {
	S_table venv = E_base_venv();
	S_table tenv = E_base_tenv();
	TransExp(Tr_outermost(), venv, tenv, exp);
}