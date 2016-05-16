/*
 * prabsyn.c - Print Abstract Syntax data structures. Most functions
 *           handle an instance of an abstract syntax rule.
 */

#include <stdio.h>
#include "util.h"
#include "symbol.h" /* symbol table data structures */
#include "absyn.h"  /* abstract syntax data structures */
#include "prabsyn.h" /* function prototype */

 /* local function prototypes */
static void pr_var(FILE *out, A_var v, int d);
static void pr_dec(FILE *out, A_dec v, int d);
static void pr_ty(FILE *out, A_ty v, int d);
static void pr_tyfield(FILE *out, A_tyfield tf, int d);
static void pr_tyfieldList(FILE *out, A_tyfieldList tfl, int d);
static void pr_expList(FILE *out, A_expList v, int d);
//static void pr_fundec(FILE *out, A_fundec v, int d);
//static void pr_fundecList(FILE *out, A_fundecList v, int d);
static void pr_decList(FILE *out, A_decList v, int d);
//static void pr_namety(FILE *out, A_namety v, int d);
//static void pr_nametyList(FILE *out, A_nametyList v, int d);
static void pr_assignfield(FILE *out, A_assignfield af, int d);
static void pr_assignfieldList(FILE *out, A_assignfieldList afl, int d);

static void indent(FILE *out, int d) {
	int i;
	for (i = 0; i <= d; i++) fprintf(out, " ");
}

/* Print A_var types. Indent d spaces. */
static void pr_var(FILE *out, A_var v, int d) {
	indent(out, d);
	switch (v->kind) {
	case A_simpleVar:
		fprintf(out, "simpleVar(%s)", S_name(v->u.simple));
		break;
	case A_fieldVar:
		fprintf(out, "%s\n", "fieldVar(");
		pr_var(out, v->u.field.var, d + 1); fprintf(out, "%s\n", ",");
		indent(out, d + 1); fprintf(out, "%s)", S_name(v->u.field.id));
		break;
	case A_subscriptVar:
		fprintf(out, "%s\n", "subscriptVar(");
		pr_var(out, v->u.subscript.var, d + 1); fprintf(out, "%s\n", ",");
		pr_exp(out, v->u.subscript.exp, d + 1); fprintf(out, "%s", ")");
		break;
	default:
		assert(0);
	}
}

static char str_binop[][12] = {
   "PLUS", "MINUS", "TIMES", "DIVIDE",
   "EQUAL", "NOTEQUAL", "LESSTHAN", "LESSEQ", "GREAT", "GREATEQ","AND","OR" };

static void pr_binop(FILE *out, A_binop d) {
	fprintf(out, "%s", str_binop[d]);
}

/* Print A_var types. Indent d spaces. */
void pr_exp(FILE *out, A_exp e, int d) {
	indent(out, d);
	switch (e->kind) {
	case A_varExp:
		fprintf(out, "varExp(\n"); pr_var(out, e->u.var, d + 1);
		fprintf(out, "%s", ")");
		break;
	case A_nilExp:
		fprintf(out, "nilExp()");
		break;
	case A_intExp:
		fprintf(out, "intExp(%d)", e->u.int_);
		break;
	case A_stringExp:
		fprintf(out, "stringExp(%s)", e->u.string_);
		break;
	case A_callExp:
		fprintf(out, "callExp(%s,\n", S_name(e->u.call.func));
		pr_expList(out, e->u.call.args, d + 1); fprintf(out, ")");
		break;
	case A_opExp:
		fprintf(out, "opExp(\n");
		indent(out, d + 1); pr_binop(out, e->u.op.op); fprintf(out, ",\n");
		pr_exp(out, e->u.op.exp1, d + 1); fprintf(out, ",\n");
		pr_exp(out, e->u.op.exp2, d + 1); fprintf(out, ")");
		break;
	case A_recordExp:
		fprintf(out, "recordExp(%s,\n", S_name(e->u.record.type));
		pr_assignfieldList(out, e->u.record.assignfieldList, d + 1); fprintf(out, ")");
		break;
	case A_seqExp:
		fprintf(out, "seqExp(\n");
		pr_expList(out, e->u.seq, d + 1); fprintf(out, ")");
		break;
	case A_assignExp:
		fprintf(out, "assignExp(\n");
		pr_var(out, e->u.assign.var, d + 1); fprintf(out, ",\n");
		pr_exp(out, e->u.assign.exp, d + 1); fprintf(out, ")");
		break;
	case A_ifelseExp:
		fprintf(out, "ifelseExp(\n");
		pr_exp(out, e->u.ifelse.exp1, d + 1); fprintf(out, ",\n");
		pr_exp(out, e->u.ifelse.exp2, d + 1); fprintf(out, ",\n");
		pr_exp(out, e->u.ifelse.exp3, d + 1); fprintf(out, ")");
		break;
	case A_ifExp:
		fprintf(out, "ifExp(\n");
		pr_exp(out, e->u.if_.exp1, d + 1); fprintf(out, ",\n");
		pr_exp(out, e->u.if_.exp2, d + 1); fprintf(out, ")");
		break;
	case A_whileExp:
		fprintf(out, "whileExp(\n");
		pr_exp(out, e->u.while_.exp1, d + 1); fprintf(out, ",\n");
		pr_exp(out, e->u.while_.exp2, d + 1); fprintf(out, ")\n");
		break;
	case A_forExp:
		fprintf(out, "forExp(%s,\n", S_name(e->u.for_.id));
		pr_exp(out, e->u.for_.exp1, d + 1); fprintf(out, ",\n");
		pr_exp(out, e->u.for_.exp2, d + 1); fprintf(out, "%s\n", ",");
		pr_exp(out, e->u.for_.exp3, d + 1); fprintf(out, ",\n");
		indent(out, d + 1); //fprintf(out, "%s", e->u.for_.escape ? "TRUE)" : "FALSE)");
		break;
	case A_breakExp:
		fprintf(out, "breakExp()");
		break;
	case A_letExp:
		fprintf(out, "letExp(\n");
		pr_decList(out, e->u.let.decList, d + 1); fprintf(out, ",\n");
		pr_expList(out, e->u.let.expList, d + 1); fprintf(out, ")");
		break;
	case A_arrayExp:
		fprintf(out, "arrayExp(%s,\n", S_name(e->u.array.type));
		pr_exp(out, e->u.array.exp1, d + 1); fprintf(out, ",\n");
		pr_exp(out, e->u.array.exp2, d + 1); fprintf(out, ")");
		break;
	default:
		assert(0);
	}
}

static void pr_dec(FILE *out, A_dec v, int d) {
	indent(out, d);
	switch (v->kind) {
	case A_functionDec:
		fprintf(out, "functionDec(%s,\n", S_name(v->u.function.func));
		pr_tyfieldList(out, v->u.function.tyfieldList, d + 1);fprintf(out, ",\n");
		if(v->u.function.type)
			fprintf(out, "%s,\n", S_name(v->u.function.type));
		pr_exp(out, v->u.function.exp, d + 1); fprintf(out, ")");
		break;
	case A_varDec:
		fprintf(out, "varDec(%s,\n", S_name(v->u.var.id));
		if (v->u.var.type) {
			indent(out, d + 1); fprintf(out, "%s,\n", S_name(v->u.var.type));
		}
		pr_exp(out, v->u.var.exp, d + 1); fprintf(out, ",\n");
		indent(out, d + 1); //fprintf(out, "%s", v->u.var.escape ? "TRUE)" : "FALSE)");
		break;
	case A_typeDec:
		fprintf(out, "typeDec(\n");
		fprintf(out, "%s,\n", S_name(v->u.type.name));
		pr_ty(out, v->u.type.ty, d + 1); fprintf(out, ")");
		break;
	default:
		assert(0);
	}
}

static void pr_ty(FILE *out, A_ty v, int d) {
	indent(out, d);
	switch (v->kind) {
	case A_nameTy:
		fprintf(out, "idTy(%s)", S_name(v->u.name));
		break;
	case A_tyfieldTy:
		fprintf(out, "tyfieldTy(\n");
		pr_tyfieldList(out, v->u.tyfield, d + 1); fprintf(out, ")");
		break;
	case A_arrayTy:
		fprintf(out, "arrayTy(%s)", S_name(v->u.array));
		break;
	default:
		assert(0);
	}
}

static void pr_tyfield(FILE *out, A_tyfield v, int d) {
	indent(out, d);
	fprintf(out, "tyfield(%s,\n", S_name(v->id));
	indent(out, d + 1); fprintf(out, "%s,\n", S_name(v->type));
	indent(out, d + 1);// fprintf(out, "%s", v->escape ? "TRUE)" : "FALSE)");
}

static void pr_tyfieldList(FILE *out, A_tyfieldList v, int d) {
	indent(out, d);
	if (v) {
		fprintf(out, "tyfieldList(\n");
		pr_tyfield(out, v->head, d + 1); fprintf(out, ",\n");
		pr_tyfieldList(out, v->tail, d + 1); fprintf(out, ")");
	}
	else fprintf(out, "tyfieldList()");
}

static void pr_expList(FILE *out, A_expList v, int d) {
	indent(out, d);
	if (v) {
		fprintf(out, "expList(\n");
		pr_exp(out, v->head, d + 1); fprintf(out, ",\n");
		pr_expList(out, v->tail, d + 1);
		fprintf(out, ")");
	}
	else fprintf(out, "expList()");

}

//static void pr_fundec(FILE *out, A_fundec v, int d) {
//	indent(out, d);
//	fprintf(out, "fundec(%s,\n", S_name(v->name));
//	pr_fieldList(out, v->params, d + 1); fprintf(out, ",\n");
//	if (v->result) {
//		indent(out, d + 1); fprintf(out, "%s,\n", S_name(v->result));
//	}
//	pr_exp(out, v->body, d + 1); fprintf(out, ")");
//}

//static void pr_fundecList(FILE *out, A_fundecList v, int d) {
//	indent(out, d);
//	if (v) {
//		fprintf(out, "fundecList(\n");
//		pr_fundec(out, v->head, d + 1); fprintf(out, ",\n");
//		pr_fundecList(out, v->tail, d + 1); fprintf(out, ")");
//	}
//	else fprintf(out, "fundecList()");
//}

static void pr_decList(FILE *out, A_decList v, int d) {
	indent(out, d);
	if (v) {
		fprintf(out, "decList(\n");
		pr_dec(out, v->head, d + 1); fprintf(out, ",\n");
		pr_decList(out, v->tail, d + 1);
		fprintf(out, ")");
	}
	else fprintf(out, "decList()");

}

//static void pr_namety(FILE *out, A_namety v, int d) {
//	indent(out, d);
//	fprintf(out, "namety(%s,\n", S_name(v->name));
//	pr_ty(out, v->ty, d + 1); fprintf(out, ")");
//}

//static void pr_nametyList(FILE *out, A_nametyList v, int d) {
//	indent(out, d);
//	if (v) {
//		fprintf(out, "nametyList(\n");
//		pr_namety(out, v->head, d + 1); fprintf(out, ",\n");
//		pr_nametyList(out, v->tail, d + 1); fprintf(out, ")");
//	}
//	else fprintf(out, "nametyList()");
//}

static void pr_assignfield(FILE *out, A_assignfield v, int d) {
	indent(out, d);
	if (v) {
		fprintf(out, "assignfield(%s,\n", S_name(v->id));
		pr_exp(out, v->exp, d + 1); fprintf(out, ")");
	}
	else fprintf(out, "assignfield()");
}

static void pr_assignfieldList(FILE *out, A_assignfieldList v, int d) {
	indent(out, d);
	if (v) {
		fprintf(out, "assignfieldList(\n");
		pr_assignfield(out, v->head, d + 1); fprintf(out, ",\n");
		pr_assignfieldList(out, v->tail, d + 1); fprintf(out, ")");
	}
	else fprintf(out, "assignfieldList()");
}




