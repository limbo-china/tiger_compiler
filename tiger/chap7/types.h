//types.h
#ifndef _TYPES_H
#define _TYPES_H

#include "symbol.h"
#include <stdio.h>

typedef struct Ty_ty_ *Ty_ty;
typedef struct Ty_tyList_ *Ty_tyList;
typedef struct Ty_tyfield_ *Ty_tyfield;
typedef struct Ty_tyfieldList_ *Ty_tyfieldList;

struct Ty_ty_ {
	enum {Ty_record, Ty_array, Ty_name, Ty_nil, Ty_string, Ty_int, Ty_void} kind;
	union {
		Ty_tyfieldList record;
		Ty_ty array;
		struct { S_symbol sym; Ty_ty ty; } name;
	}u;
};
struct Ty_tyList_ {
	Ty_ty head; Ty_tyList tail;
};
struct Ty_tyfield_ {
	S_symbol sym; Ty_ty ty;
};
struct Ty_tyfieldList_ {
	Ty_tyfield head; Ty_tyfieldList tail;
};

Ty_ty Ty_Record(Ty_tyfieldList tyfieldList);
Ty_ty Ty_Array(Ty_ty ty);
Ty_ty Ty_Name(S_symbol sym, Ty_ty ty);
Ty_ty Ty_Nil();
Ty_ty Ty_String();
Ty_ty Ty_Int();
Ty_ty Ty_Void();

Ty_tyList Ty_TyList(Ty_ty head, Ty_tyList tail);
Ty_tyfield Ty_TyField(S_symbol sym, Ty_ty ty);
Ty_tyfieldList Ty_TyFieldList(Ty_tyfield head, Ty_tyfieldList tail);

Ty_ty Actual_Ty(Ty_ty ty);  //追溯到非name的类型，即可以判断其究竟是什么类型（包括记录和数组）

#endif
