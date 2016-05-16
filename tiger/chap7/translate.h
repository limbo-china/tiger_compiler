#ifndef _TRANS_H
#define _TRANS_H

#include "temp.h"
#include "frame.h"
#include "tree.h"
#include "absyn.h"

///frame
typedef struct Tr_level_ *Tr_level;
typedef struct Tr_access_ *Tr_access;
typedef struct Tr_accessList_ *Tr_accessList;

struct Tr_level_ {
	Tr_level parent;
	F_frame frame; //为啥要这个????????? ----- 保存局部变量，frame中有count,用于抽象
	Tr_accessList formals; //和上面冲突多余?
};
struct Tr_access_ {
	Tr_level level; F_access access;
};
struct Tr_accessList_ {
	Tr_access head; Tr_accessList tail;
};

Tr_level Tr_outermost(); //不用参数...

Tr_accessList Tr_AccessList(Tr_access head, Tr_accessList tail);  //为啥这又不是静态了?
Tr_level Tr_NewLevel(Tr_level parent, Temp_label name, U_boolList formals);
Temp_label Tr_name(Tr_level l);    ///书上没有这个？？？？？？？？？
Tr_accessList Tr_formals(Tr_level l);
Tr_access Tr_allocLocal(Tr_level l, bool escape);
////frame

////intermediate representation
typedef struct Tr_exp_ *Tr_exp;
typedef struct Tr_expList_* Tr_expList;
typedef struct Cx_ *Cx;
typedef struct patchList_ *patchList;

struct Tr_exp_ {
	enum { Tr_ex, Tr_nx, Tr_cx } kind;
	union {
		T_exp ex;
		T_stm nx;
		Cx cx;
	}u;
};
struct Tr_expList_ {
	Tr_exp head;Tr_expList tail;
};
struct Cx_ {
	patchList trues;
	patchList falses;
	T_stm stm;
};
struct patchList_ {
	Temp_label *head; patchList tail;  /////标号的指针，用于之后往里面放标号
};

Tr_expList Tr_ExpList(Tr_exp head, Tr_expList tail); 
Tr_exp Tr_DONE();

T_exp UnEx(Tr_exp exp);
T_stm UnNx(Tr_exp exp);
Cx UnCx(Tr_exp exp);   //暂时设为可被外部文件调用

Tr_exp Tr_SimpleVar(Tr_access access, Tr_level thislevel);
Tr_exp Tr_FieldVar(Tr_exp base, int offset); //为了防止在semant.c中调用TREE中的函数T_Const，直接用Int. (var.id)的id不能直接被翻译
Tr_exp Tr_SubscriptVar(Tr_exp base, Tr_exp offset); //var[exp]中exp本来就可以在semant.c中被翻译，可直接返回Tr_exp类型，也避免了调用TREE中的函数

Tr_exp Tr_NilExp();
Tr_exp Tr_IntExp(int i);
Tr_exp Tr_StringExp(string s);
Tr_exp Tr_CallExp(Tr_level origine, Tr_level thislevel, Tr_expList el);
Tr_exp Tr_OpExp(A_binop a_op, Tr_exp exp1, Tr_exp exp2);
Tr_exp Tr_RecordExp(Tr_expList el);
Tr_exp Tr_SeqExp(Tr_expList el);
Tr_exp Tr_AssignExp(Tr_exp lvalue, Tr_exp exp);
Tr_exp Tr_IfElseExp(Tr_exp exp1, Tr_exp exp2, Tr_exp exp3);
Tr_exp Tr_IfExp(Tr_exp exp1, Tr_exp exp2);
Tr_exp Tr_WhileExp(Tr_exp exp1, Tr_exp exp2, Tr_exp break_);
Tr_exp Tr_BreakExp(Tr_exp break_);
Tr_exp Tr_ForExp(A_var var, Tr_exp exp1, Tr_exp exp2, Tr_exp exp3, Tr_exp break_);
/////////不需要 Tr_exp Tr_LetExp() 多余的，直接在翻译时返回最后一个表达式的结果即可
Tr_exp Tr_ArrayExp(Tr_exp exp1, Tr_exp exp2);



////intermediate representation
#endif