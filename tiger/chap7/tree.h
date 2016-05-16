#ifndef _TREE_H
#define _TREE_H

#include "temp.h"

typedef struct T_stm_ *T_stm;
typedef struct T_exp_ *T_exp;
typedef struct T_stmList_ *T_stmList;
typedef struct T_expList_ *T_expList;

typedef enum {
	T_plus, T_minus, T_times, T_divide, T_and, T_or, T_xor, T_lshift, T_rshift, T_arshift
} T_binop;
typedef enum {
	T_eq, T_neq, T_lt, T_gt, T_le, T_ge, T_ult, T_ugt, T_ule, T_uge
} T_relop;

struct T_stm_ {
	enum { T_move, T_expstm, T_jump, T_cjump, T_seq, T_label }kind; //enum 内的元素名不能和已经定义的类型同名
	union {
		struct { T_exp exp1, exp2; } move;
		struct { T_exp exp; } expstm;
		struct { T_exp exp; Temp_labelList labs; } jump;
		struct { T_relop relop; T_exp exp1, exp2; Temp_label true_, false_; } cjump;
		struct { T_stm stm1, stm2; } seq;
		Temp_label label;
	}u;
};
struct T_exp_ {
	enum { T_const, T_name, T_temp, T_binopexp, T_mem, T_call, T_eseq } kind;  //enum 内的元素名不能和已经定义的类型同名
	union {
		int const_;
		Temp_label name;
		Temp_temp temp;
		struct { T_binop op; T_exp exp1, exp2; } binopexp;
		T_exp mem;
		struct { T_exp fun;T_expList args; } call;
		struct { T_stm stm; T_exp exp; } eseq;
	}u;
};

struct T_stmList_ {
	T_stm head; T_stmList tail;
};
struct T_expList_ {
	T_exp head; T_expList tail;
};

T_stm T_Move(T_exp exp1, T_exp exp2);
T_stm T_Exp(T_exp exp);
T_stm T_Jump(T_exp exp, Temp_labelList labs);
T_stm T_Cjump(T_relop relop, T_exp exp1, T_exp exp2, Temp_label true_, Temp_label false_);
T_stm T_Seq(T_stm stm1, T_stm stm2);
T_stm T_Label(Temp_label label);

T_exp T_Const(int i);
T_exp T_Name(Temp_label name);
T_exp T_Temp(Temp_temp temp);
T_exp T_Binopexp(T_binop binop, T_exp exp1, T_exp exp2);
T_exp T_Mem(T_exp mem);
T_exp T_Call(T_exp fun, T_expList args);
T_exp T_Eseq(T_stm stm, T_exp exp);

T_stmList T_StmList(T_stm head, T_stmList tail);
T_expList T_ExpList(T_exp head, T_expList tail);

#endif