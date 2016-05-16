#include "escape.h"


static void TraverseExp(S_table env, int depth, A_exp exp);
static void TraverseDec(S_table env, int depth, A_dec dec);
static void TraverseVar(S_table env, int depth, A_var var);

static S_table Esc_base_env();

S_table Esc_base_env() {
	return S_empty();
}
void TraverseExp(S_table env, int depth, A_exp exp) {

}
void TraverseDec(S_table env, int depth, A_dec dec) {

}
void TraverseVar(S_table env, int depth, A_var var) {

}

void Esc_findescape(A_exp exp) {
	int depth = 1;
	S_table env = Esc_base_env();
	TraverseExp(env, depth, exp);
}