#ifndef _SEM_H
#define _SEM_H

#include "types.h"
#include "symbol.h"
#include "absyn.h"
#include "env.h"
#include "util.h"
#include "errormsg.h"
#include "types.h"
#include <string.h>


typedef void* Tr_exp;
typedef struct expty_* expty;

struct expty_ {
	Tr_exp exp; Ty_ty ty;
};

expty Expty(Tr_exp exp, Ty_ty ty);
expty TransVar(Tr_level level, S_table venv, S_table tenv, A_var var);
expty TransExp(Tr_level level, S_table venv, S_table tenv, A_exp exp);
void TransDec(Tr_level level, S_table venv, S_table tenv, A_dec dec);
Ty_tyList MakeTyList(S_table tenv, A_tyfieldList args);
Ty_tyfieldList MakeTyFieldList(S_table tenv, A_tyfieldList tfl);
Ty_ty TransTy(S_table tenv, A_ty t);

void SEM_TransProg(A_exp exp);

#endif
