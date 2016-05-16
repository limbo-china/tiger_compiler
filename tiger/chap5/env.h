#ifndef _ENV_H
#define _ENV_H

#include "types.h"
#include "table.h"
#include <stdio.h>

typedef struct E_envEntry_ *E_envEntry;

struct E_envEntry_ {
	enum { E_varEntry, E_funEntry } kind;
	union {
		struct { Ty_ty ty; } var;
		struct { Ty_tyList args; Ty_ty result; } fun;
	}u;
};

E_envEntry E_VarEntry(Ty_ty ty);
E_envEntry E_FunEntry(Ty_tyList args, Ty_ty result);

S_table E_base_tenv(); 
S_table E_base_venv();

void desPr_venv(S_table venv);

#endif	