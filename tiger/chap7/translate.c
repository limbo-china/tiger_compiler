#include "translate.h" 

////frame
static Tr_access Tr_Access(Tr_level l, F_access access);
static Tr_accessList MakeFormalsAccessList(Tr_level l);

Tr_level Tr_NewLevel(Tr_level parent, Temp_label name, U_boolList formals) {
	Tr_level l = checked_malloc(sizeof(*l));
	l->parent = parent;
	l->frame = F_NewFrame(name, U_BoolList(TRUE, formals));  //创新一个新帧栈,第一个位置为静态链，为逃逸的（为啥还要? parent做啥？）
	l->formals = MakeFormalsAccessList(l);      //// Tr_accessList 和 帧栈 关系 不太清楚？？？？
	return l;
}

static Tr_level outermost = NULL;
Tr_level Tr_outermost() {
	if (!outermost) { return Tr_NewLevel(NULL, Temp_newlabel(), NULL); }
	//为啥是Temp_newlabel()不是NULL??
	return outermost;
}

Tr_accessList Tr_formals(Tr_level l) {
	return l->formals;
}

Tr_access Tr_Access(Tr_level l, F_access access) {
	Tr_access a = checked_malloc(sizeof(*a));
	a->level = l;a->access = access;
	return a;
}
Tr_accessList Tr_AccessList(Tr_access head, Tr_accessList tail) { //为啥这又不是静态了?
	Tr_accessList al = checked_malloc(sizeof(*al));
	al->head = head;al->tail = tail;
	return al;
}

Tr_accessList MakeFormalsAccessList(Tr_level l) {
	Tr_accessList head = NULL, tail = NULL;
	Tr_access a = NULL;
	F_accessList al = l->frame->formals->tail; //忽略第一个参数即静态链，即最后的Tr_accessList 不含静态链，///为啥？？？？？
	while (al) {
		a = Tr_Access(l, al->head);
		if (head) {
			tail = Tr_AccessList(a, NULL);
			tail = tail->tail;
		}
		else {
			head = Tr_AccessList(a, NULL);
			tail = head->tail;
		}
		al = al->tail;
	}
	return head;
}
Tr_access Tr_allocLocal(Tr_level l, bool escape) {
	F_access F_a = F_allocLocal(l->frame, escape);
	return Tr_Access(l, F_a);
}
////frame

////intermediate representation
static Tr_exp Tr_Ex(T_exp exp);
static Tr_exp Tr_Nx(T_stm stm);
static Tr_exp Tr_Cx(patchList trues, patchList falses, T_stm stm);

static void DoPatch(patchList pl, Temp_label label);
static patchList PatchList(Temp_label *head, patchList tail);
static T_expList T_ConvertEl(Tr_expList el);///将Tr_expList 转换为 T_expList;




Tr_expList Tr_ExpList(Tr_exp head, Tr_expList tail) {
	Tr_expList el = checked_malloc(sizeof(*el));
	el->head = head;el->tail = tail;
	return el;
}
Tr_exp Tr_DONE() {
	return Tr_Ex(T_Name(Temp_newlabel()));  //用于while中 break跳转 和 正常结束跳转 的统一
}

Tr_exp Tr_Ex(T_exp exp) {
	Tr_exp e = checked_malloc(sizeof(*e));
	e->kind = Tr_ex;e->u.ex = exp;
	return e;
}
Tr_exp Tr_Nx(T_stm stm) {
	Tr_exp e = checked_malloc(sizeof(*e));
	e->kind = Tr_nx;e->u.nx = stm;
	return e;
}
Tr_exp Tr_Cx(patchList trues, patchList falses, T_stm stm) {
	Tr_exp e = checked_malloc(sizeof(*e));
	e->kind = Tr_cx;e->u.cx->trues = trues;e->u.cx->falses = falses;e->u.cx->stm = stm;
	return e;
}
void DoPatch(patchList pl, Temp_label label) {
	while (pl) {
		*(pl->head) = label;
		pl = pl->tail;
	}
}
patchList PatchList(Temp_label *head, patchList tail) {
	patchList pl = checked_malloc(sizeof(*pl));
	pl->head = head;pl->tail = tail;
	return pl;
}

T_expList T_ConvertEl(Tr_expList el) {
	if (!el)
		return NULL;
	return T_ExpList(UnEx(el->head), T_ConvertEl(el->tail));
}

T_exp UnEx(Tr_exp exp) {
	switch (exp->kind) {

	case Tr_ex: {
		return exp->u.ex;
	}
	case Tr_nx: {
		return T_Eseq(exp->u.nx, T_Const(0));//// 为啥是返回0????  不是无值??????
	}
	case Tr_cx: {
		Temp_temp r = Temp_newtemp();
		Temp_label t = Temp_newlabel(); Temp_label f = Temp_newlabel();
		DoPatch(exp->u.cx->trues, t); DoPatch(exp->u.cx->falses, f);
		return T_Eseq(T_Move(T_Temp(r), T_Const(1)),
			T_Eseq(exp->u.cx->stm,
				T_Eseq(T_Label(f),
					T_Eseq(T_Move(T_Temp(r), T_Const(0)),
						T_Eseq(T_Label(t),
							T_Temp(r))))));
	}
	default:
		assert(0);
		break;
	}
}
T_stm UnNx(Tr_exp exp) {
	switch (exp->kind) {

	case Tr_ex: {
		return T_Exp(exp->u.ex);
	}
	case Tr_nx: {
		return exp->u.nx;
	}
	case Tr_cx: {   //难点
		Temp_temp r = Temp_newtemp();
		Temp_label t = Temp_newlabel(); Temp_label f = Temp_newlabel();
		DoPatch(exp->u.cx->trues, t); DoPatch(exp->u.cx->falses, f);
		return T_Exp(T_Eseq(T_Move(T_Temp(r), T_Const(1)),
			T_Eseq(exp->u.cx->stm,
				T_Eseq(T_Label(f),
					T_Eseq(T_Move(T_Temp(r), T_Const(0)),
						T_Eseq(T_Label(t),
							T_Temp(r)))))));
	}
	default:
		assert(0);
		break;
	}
}
Cx UnCx(Tr_exp exp) {
	switch (exp->kind) {

	case Tr_ex: {  //难点
		Cx cx = checked_malloc(sizeof(*cx));
		cx->stm = T_Cjump(T_eq, exp->u.ex, T_Const(1), NULL, NULL);
		cx->trues = PatchList(&(cx->stm->u.cjump.true_), NULL);
		cx->falses = PatchList(&(cx->stm->u.cjump.false_), NULL);
		return cx;
	}
	case Tr_nx: {	//不会发生???????
		assert(0);
		break;
	}
	case Tr_cx: {
		return exp->u.cx;
	}
	default:
		assert(0);
		break;
	}
}

Tr_exp Tr_SimpleVar(Tr_access access, Tr_level thislevel) {
	T_exp add = T_Temp(F_FP());
	while (thislevel != access->level) {
		F_access a = thislevel->frame->formals->head;
		add = F_Exp(a, add);
		thislevel = thislevel->parent;
	}
	return Tr_Ex(F_Exp(access->access, add));
}
Tr_exp Tr_FieldVar(Tr_exp base, int offset) {
	//为了防止在semant.c中调用TREE中的函数T_Const，直接用int. (var.id)的id不能直接被翻译
	return Tr_Ex(T_Mem(T_Binopexp(T_plus, UnEx(base), T_Const(offset*F_WORD_SIZE))));
}
Tr_exp Tr_SubscriptVar(Tr_exp base, Tr_exp offset) {
	//var[exp]中exp本来就可以在semant.c中被翻译，可直接返回Tr_exp类型，也避免了调用TREE中的函数
	return Tr_Ex(T_Mem(T_Binopexp(T_plus, UnEx(base), 
		T_Binopexp(T_times, UnEx(offset), T_Const(F_WORD_SIZE)))));  //不能直接和offset乘，可转换为中间表达形式
}

Tr_exp Tr_NilExp() {
	return Tr_Ex(T_Const(0));
}
Tr_exp Tr_IntExp(int i) {
	return Tr_Ex(T_Const(i));
}
Tr_exp Tr_StringExp(string s) {
	///////////需要片段 //暂时返回空
	return Tr_Ex(T_Const(0));
}
Tr_exp Tr_CallExp(Tr_level origine, Tr_level thislevel, Tr_expList el) {  //要加上静态链?????????????
	return Tr_Ex(T_Call(T_Name(origine->frame->name), T_ConvertEl(el)));
}
Tr_exp Tr_OpExp(A_binop a_op, Tr_exp exp1, Tr_exp exp2) {
	T_binop t_op;
	switch (a_op) {
	case A_plusOp: t_op = T_plus;break;
	case A_minusOp: t_op = T_minus;break;
	case A_timesOp: t_op = T_times;break;
	case A_divideOp: t_op = T_divide;break;
	case A_eqOp: t_op = T_eq;break;
	case A_neqOp: t_op = T_neq;break;
	case A_ltOp: t_op = T_lt;break;
	case A_leOp: t_op = T_le;break;
	case A_gtOp: t_op = T_gt;break;
	case A_geOp: t_op = T_ge;break;
	case A_andOp: t_op = T_and;break;
	case A_orOp: t_op = T_or;break;
	default:
		assert(0);
		break;
	}
	return Tr_Ex(T_Binopexp(t_op, UnEx(exp1), UnEx(exp2)));
}
Tr_exp Tr_RecordExp(Tr_expList el) { //record 是有值的，应该返回 Tr_ex 类型，值为创建记录时返回的寄存器的值,即头指针指向的地址
	Temp_temp r = Temp_newtemp();
	int n = 0;
	Tr_expList el_ = el;
	while (el_) {
		n++;
		el_ = el_->tail;
	}//计算记录中表达式的个数

	T_stm create = T_Move(T_Temp(r), F_externalCall(String("InitRecord"), T_ExpList(T_Const(n*F_WORD_SIZE), NULL)));
	n = 0;
	T_stm assignseq = T_Move(T_Mem(T_Binopexp(T_plus, T_Temp(r), T_Const(n*F_WORD_SIZE))), UnEx(el->head));
	el = el->tail;n++;
	while (el) {
		assignseq = T_Seq(assignseq, T_Move(T_Mem(T_Binopexp(T_plus, T_Temp(r), T_Const(n*F_WORD_SIZE))), UnEx(el->head)));
		el = el->tail;n++;
	}
	return Tr_Ex(T_Eseq(T_Seq(create, assignseq), T_Temp(r)));
}
Tr_exp Tr_SeqExp(Tr_expList el) {
	if (!el->tail)
		return el->head;
	T_exp seqexp = UnEx(el->head);
	while (el->tail) {
		el = el->tail;
		seqexp = T_Eseq(T_Exp(seqexp), UnEx(el->head));
	}
	return Tr_Ex(seqexp);
}
Tr_exp Tr_AssignExp(Tr_exp lvalue, Tr_exp exp) { //无返回值
	return Tr_Nx(T_Move(UnEx(lvalue), UnEx(exp)));
}
Tr_exp Tr_IfElseExp(Tr_exp exp1, Tr_exp exp2, Tr_exp exp3) { ////先默认ifelseexp为无值表达式
	Temp_label t = Temp_newlabel(); Temp_label f = Temp_newlabel();
	Temp_label done = Temp_newlabel();
	Cx cx = UnCx(exp1);
	DoPatch(cx->trues, t);DoPatch(cx->falses, f);
	return Tr_Nx(T_Seq(cx->stm, 
		T_Seq(T_Label(t), 
			T_Seq(UnNx(exp2), 
				T_Seq(T_Jump(T_Name(done),Temp_LabelList(done,NULL)),
					T_Seq(T_Label(f),
						T_Seq(UnNx(exp3),
							T_Label(done))))))));

}
Tr_exp Tr_IfExp(Tr_exp exp1, Tr_exp exp2) {
	Temp_label t = Temp_newlabel(); Temp_label f = Temp_newlabel();
	Cx cx = UnCx(exp1);
	DoPatch(cx->trues, t);DoPatch(cx->falses, f);
	return Tr_Nx(T_Seq(cx->stm, T_Seq(T_Seq(T_Label(t), UnNx(exp2)), T_Label(f)))); //和 T_Seq(T_Label(t), T_Seq(exp2->u.nx, T_Label(f))))); 有区别????
}
Tr_exp Tr_WhileExp(Tr_exp exp1, Tr_exp exp2, Tr_exp break_) {
	Temp_label test = Temp_newlabel(); Temp_label done = UnEx(break_)->u.name;
	Temp_label t = Temp_newlabel();
	Cx cx = UnCx(exp1);
	DoPatch(cx->trues, t);DoPatch(cx->falses, done);
	return Tr_Nx(T_Seq(T_Label(test),
		T_Seq(cx->stm, T_Seq(T_Label(t),
			T_Seq(UnNx(exp2), T_Seq(T_Jump(T_Name(test), 
				Temp_LabelList(test, NULL)), T_Label(done)))))));
}
Tr_exp Tr_BreakExp(Tr_exp break_) { //break_为标号,直接提取出来
	return Tr_Nx(T_Jump(UnEx(break_), Temp_LabelList((UnEx(break_)->u.name), NULL)));
}
//// Tr_ForExp()多余，直接在翻译时调用while翻译
/////////不需要 Tr_exp Tr_LetExp() 多余的，直接在翻译时返回最后一个表达式的结果即可
Tr_exp Tr_ArrayExp(Tr_exp exp1, Tr_exp exp2) {
	return Tr_Ex(F_externalCall("InitArray", T_ExpList(UnEx(exp1), T_ExpList(UnEx(exp2), NULL))));
}
////intermediate representation
