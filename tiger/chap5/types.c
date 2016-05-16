#include "types.h"
#include "util.h"


Ty_ty Ty_Record(Ty_tyfieldList tyfieldList) {
	Ty_ty t = checked_malloc(sizeof(*t));
	t->kind = Ty_record; t->u.record = tyfieldList;
	return t;
}
Ty_ty Ty_Array(Ty_ty ty) {
	Ty_ty t = checked_malloc(sizeof(*t));
	t->kind = Ty_array; t->u.array = ty;
	return t;
}
Ty_ty Ty_Name(S_symbol sym, Ty_ty ty) {
	Ty_ty t = checked_malloc(sizeof(*t));
	t->kind = Ty_name; t->u.name.sym = sym;t->u.name.ty = ty;
	return t;
}
Ty_ty Ty_Nil() {
	Ty_ty t = checked_malloc(sizeof(*t));
	t->kind = Ty_nil;
	return t;
}
Ty_ty Ty_String() {
	Ty_ty t = checked_malloc(sizeof(*t));
	t->kind = Ty_string;
	return t;
}
Ty_ty Ty_Int() {
	Ty_ty t = checked_malloc(sizeof(*t));
	t->kind = Ty_int;
	return t;
}
Ty_ty Ty_Void() {
	Ty_ty t = checked_malloc(sizeof(*t));
	t->kind = Ty_void;
	return t;
}

Ty_tyList Ty_TyList(Ty_ty head, Ty_tyList tail) {
	Ty_tyList tl = checked_malloc(sizeof(*tl));
	tl->head = head;tl->tail = tail;
	return tl;
}
Ty_tyfield Ty_TyField(S_symbol sym, Ty_ty ty) {
	Ty_tyfield f = checked_malloc(sizeof(*f));
	f->sym = sym;f->ty = ty;
	return f;
}
Ty_tyfieldList Ty_TyFieldList(Ty_tyfield head, Ty_tyfieldList tail) {
	Ty_tyfieldList fl = checked_malloc(sizeof(*fl));
	fl->head = head;fl->tail = tail;
	return fl;
}

Ty_ty Actual_Ty(Ty_ty ty) {
	if (!ty)
		return NULL;
	while (ty->kind == Ty_name) {
		ty = ty->u.name.ty;
	}
	return ty;
}
