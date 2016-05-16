#ifndef _ENV_H
#define _ENV_H

#include "types.h"
#include "table.h"
#include <stdio.h>
#include "translate.h"

typedef struct E_envEntry_ *E_envEntry;

struct E_envEntry_ {
	enum { E_varEntry, E_funEntry } kind;
	union {
		struct { Tr_access access;Ty_ty ty; } var;
		struct { Tr_level level; //Temp_label label; ∂‡”‡?????????????
		Ty_tyList args; Ty_ty result; } fun;
	}u;
};

E_envEntry E_VarEntry(Tr_access access,Ty_ty ty);
E_envEntry E_FunEntry(Tr_level level, Ty_tyList args, Ty_ty result);

S_table E_base_tenv(); 
S_table E_base_venv();

void desPr_venv(S_table venv);

#endif	