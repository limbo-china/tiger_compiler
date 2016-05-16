#ifndef _ABSYN_H
#define _ABSYN_H	//·ÀÖ¹ÖØ¸´°üº¬Í·ÎÄ¼þ

#include "symbol.h"
typedef char* string;
typedef	struct A_var_ *A_var;
typedef struct A_exp_ *A_exp;
typedef struct A_expList_ *A_expList;
typedef struct A_dec_ *A_dec;
typedef struct A_decList_ *A_decList;
typedef struct A_ty_  *A_ty;
typedef struct A_assignfield_ *A_assignfield;
typedef struct A_assignfieldList_ *A_assignfieldList;
typedef struct A_tyfield_ *A_tyfield;
typedef struct A_tyfieldList_ *A_tyfieldList;

typedef int A_pos;

typedef enum { A_plusOp, A_minusOp, A_timesOp, A_divideOp, A_eqOp, A_neqOp, A_ltOp, A_leOp, A_gtOp, A_geOp, A_andOp, A_orOp
} A_binop;

struct A_var_ {
	enum { A_simpleVar, A_fieldVar, A_subscriptVar } kind;
	A_pos pos;
	union {
		S_symbol simple;
		struct { A_var var; S_symbol id; } field;
		struct { A_var var; A_exp exp; } subscript;
	}u;
};

struct A_exp_ {
	enum {
		A_varExp, A_nilExp, A_intExp, A_stringExp, A_callExp, A_opExp, A_recordExp,
		A_seqExp, A_assignExp, A_ifExp, A_whileExp, A_breakExp, A_forExp, A_letExp, A_arrayExp
	} kind;
	A_pos pos;
	union {
		A_var var;
		///  nil??????????
		int int_;  //ÃüÃû·ÀÖ¹³åÍ»
		string string_; //ÃüÃû·ÀÖ¹³åÍ»
		struct { S_symbol func; A_expList args; } call;
		struct { A_exp exp1; A_binop op;A_exp exp2; } op;
		struct { S_symbol type; A_assignfieldList assignfieldList; } record;
		A_expList seq;
		struct { A_var var; A_exp exp; } assign;
		struct { A_exp exp1, exp2, exp3; } if_;  //·ÀÖ¹ÃüÃû³åÍ»
		struct { A_exp exp1, exp2; } while_; //·ÀÖ¹ÃüÃû³åÍ»
		////  break ?????????
		struct { S_symbol id; A_exp exp1, exp2, exp3; } for_; //·ÀÖ¹ÃüÃû³åÍ»
		struct { A_decList decList; A_expList expList; } let;
		struct { S_symbol type; A_exp exp1, exp2; } array;
	}u;
};

struct A_dec_ {
	enum { A_functionDec, A_varDec, A_typeDec } kind;
	A_pos pos;
	union {
		struct { S_symbol func; A_tyfieldList tyfieldList; S_symbol type; A_exp exp; } function;
		struct { S_symbol id; S_symbol type;A_exp exp; } var;
		struct { S_symbol type; A_ty ty; } type;
	}u;
};

struct A_ty_ {
	enum { A_idTy, A_tyfieldTy, A_arrayTy } kind;
	A_pos pos;
	union {
		S_symbol id;
		A_tyfieldList tyfield;
		S_symbol array;
	}u;
};

struct A_expList_ {
	A_exp head; A_expList tail;
};

struct A_assignfield_ {
	A_pos pos; S_symbol id; A_exp exp;
};

struct A_assignfieldList_ {
	A_assignfield head; A_assignfieldList tail;
};

struct A_decList_ {
	A_dec head; A_decList tail;
};

struct A_tyfield_ {
	A_pos pos; S_symbol id; S_symbol type;
};

struct A_tyfieldList_ {
	A_tyfield head; A_tyfieldList tail;
};

A_var A_SimpleVar(A_pos pos, S_symbol id);
A_var A_FieldVar(A_pos pos, A_var var, S_symbol id);
A_var A_SubscriptVar(A_pos pos, A_var var, A_exp exp);

A_exp A_VarExp(A_pos pos, A_var var);
A_exp A_NilExp(A_pos pos);
A_exp A_IntExp(A_pos pos, int i);
A_exp A_StringExp(A_pos pos, string s);
A_exp A_CallExp(A_pos pos, S_symbol func, A_expList args);
A_exp A_OpExp(A_pos pos, A_exp exp1, A_binop op, A_exp exp2);
A_exp A_RecordExp(A_pos pos, S_symbol type, A_assignfieldList aflist);
A_exp A_SeqExp(A_pos pos, A_expList elist);
A_exp A_AssignExp(A_pos pos, A_var var, A_exp exp);
A_exp A_IfExp(A_pos pos, A_exp exp1, A_exp exp2, A_exp exp3);
A_exp A_WhileExp(A_pos pos, A_exp exp1, A_exp exp2);
A_exp A_BreakExp(A_pos pos);
A_exp A_ForExp(A_pos pos, S_symbol id, A_exp exp1, A_exp exp2, A_exp exp3);
A_exp A_LetExp(A_pos pos, A_decList dlist, A_expList elist);
A_exp A_ArrayExp(A_pos pos, S_symbol type, A_exp exp1, A_exp exp2);

A_dec A_FunctionDec(A_pos pos, S_symbol func, A_tyfieldList tflist, S_symbol type, A_exp exp);
A_dec A_VarDec(A_pos pos, S_symbol id, S_symbol type, A_exp exp);
A_dec A_TypeDec(A_pos pos, S_symbol type, A_ty ty);

A_ty A_IdTy(A_pos pos, S_symbol type);
A_ty A_TyfieldTy(A_pos pos, A_tyfieldList tflist);
A_ty A_ArrayTy(A_pos pos, S_symbol type);

A_expList A_ExpList(A_exp head, A_expList tail);
A_assignfield A_Assignfield(A_pos pos, S_symbol id, A_exp exp);
A_assignfieldList A_AssignfieldList(A_assignfield head, A_assignfieldList tail);
A_decList A_DecList(A_dec head, A_decList tail);
A_tyfield A_Tyfield(A_pos pos, S_symbol id, S_symbol type);
A_tyfieldList A_TyfieldList(A_tyfield head, A_tyfieldList tail);

#endif
