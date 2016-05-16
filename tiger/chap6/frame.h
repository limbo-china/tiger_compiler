#ifndef _FRAME_H
#define _FRAME_H

#include "temp.h"  

typedef struct F_frame_ *F_frame;
typedef struct F_access_ *F_access;
typedef struct F_accessList_ *F_accessList;

struct F_frame_ {
	Temp_label name;
	F_accessList formals;
	int count;
};
struct F_access_ {
	enum { inFrame, inReg } kind;
	union {
		int offset;
		Temp_temp reg;
	}u;
};
struct F_accessList_ {
	F_access head; F_accessList tail;
};

F_frame F_NewFrame(Temp_label name, U_boolList formals);
Temp_label F_name(F_frame f);
F_accessList F_formals(F_frame f);
F_access F_allocLocal(F_frame f, bool escape);

#endif