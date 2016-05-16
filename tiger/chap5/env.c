#include "env.h"
#include "util.h"

E_envEntry E_VarEntry(Ty_ty ty) {
	E_envEntry env = checked_malloc(sizeof(*env));
	env->kind = E_varEntry;env->u.var.ty = ty;
	return env;
}
E_envEntry E_FunEntry(Ty_tyList args, Ty_ty result) {
	E_envEntry env = checked_malloc(sizeof(*env));
	env->kind = E_funEntry; env->u.fun.args = args; env->u.fun.result = result;
	return env;
}

S_table E_base_tenv(){
	S_table table = S_empty();
	S_enter(table, S_Symbol("int"), Ty_Int());
	S_enter(table, S_Symbol("string"), Ty_String());
	return table;
}
S_table E_base_venv() {
	S_table table = S_empty();
	S_enter(table, S_Symbol("print"), 
		E_FunEntry(Ty_TyList(Ty_String(),NULL),Ty_Void()));
	S_enter(table, S_Symbol("flush"),
		E_FunEntry(Ty_TyList(Ty_Void(), NULL), Ty_Void()));
	S_enter(table, S_Symbol("getchar"),
		E_FunEntry(Ty_TyList(Ty_Void(), NULL), Ty_String()));
	S_enter(table, S_Symbol("ord"),
		E_FunEntry(Ty_TyList(Ty_String(), NULL), Ty_Int()));
	S_enter(table, S_Symbol("chr"),
		E_FunEntry(Ty_TyList(Ty_Int(), NULL), Ty_String()));
	S_enter(table, S_Symbol("size"),
		E_FunEntry(Ty_TyList(Ty_String(), NULL), Ty_Int()));
	S_enter(table, S_Symbol("substring"),
		E_FunEntry(Ty_TyList(Ty_String(), Ty_TyList(Ty_Int(), Ty_TyList(Ty_Int(), NULL))), Ty_String()));
	S_enter(table, S_Symbol("concat"),
		E_FunEntry(Ty_TyList(Ty_String(), Ty_TyList(Ty_String(), NULL)), Ty_String()));
	S_enter(table, S_Symbol("not"),
		E_FunEntry(Ty_TyList(Ty_Int(), NULL), Ty_Int()));
	S_enter(table, S_Symbol("exit"),
		E_FunEntry(Ty_TyList(Ty_Int(), NULL), Ty_Void()));
	return table;
}
void desPr_venv(S_table venv) {
	while (venv->top) {
		printf("%s,", S_name(TAB_pop(venv)));
	}
}
