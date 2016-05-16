#include "frame.h" 

static const int F_WORD_SIZE = 4;
static const int F_MAX_REG = 6;

static F_access InFrame(int offset);
static F_access InReg(Temp_temp reg);
static F_accessList MakeFormalsAccessList(U_boolList formals);
static F_accessList F_AccessList(F_access head, F_accessList tail);

F_frame F_NewFrame(Temp_label name, U_boolList formals) {
	F_frame f = checked_malloc(sizeof(*f));
	f->name = name;
	f->formals = MakeFormalsAccessList(formals);
	f->count = 0;
	return f;
}
Temp_label F_name(F_frame f) {
	return f->name;
}
F_accessList F_formals(F_frame f) {
	return f->formals;
}
F_access F_allocLocal(F_frame f, bool escape) {
	f->count++;
	if (escape) { return InFrame(-1 * F_WORD_SIZE*f->count); }   ///从0从1开始和机器有关
	return InReg(Temp_newtemp());
}
F_accessList MakeFormalsAccessList(U_boolList formals) {
	F_accessList head = NULL, tail = NULL;
	F_access a = NULL;
	for (int i = 0;formals;formals = formals->tail, i++) {
		if (i < F_MAX_REG && !formals->head)  //注意是 i < F_Max_REG, 不管前面有没有逃逸的
			a = InReg(Temp_newtemp());   
		else
			a = InFrame(i*F_WORD_SIZE);		///从0从1开始和机器有关
		if (head) {
			tail = F_AccessList(a, NULL);
			tail = tail->tail;
		}
		else {
			head = F_AccessList(a, NULL);
			tail = head->tail;
		}
	}
	return head;
}
F_accessList F_AccessList(F_access head, F_accessList tail) {
	F_accessList al = checked_malloc(sizeof(*al));
	al->head = head; al->tail = tail;
	return al;
}
F_access InFrame(int offset) {
	F_access a = checked_malloc(sizeof(*a));
	a->kind = inFrame;
	a->u.offset = offset;
	return a;
}
static F_access InReg(Temp_temp reg) {
	F_access a = checked_malloc(sizeof(*a));
	a->kind = inReg;
	a->u.reg = reg;
	return a;
}
