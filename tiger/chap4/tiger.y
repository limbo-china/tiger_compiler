%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "absyn.h"
#include "symbol.h"

//#define P(S) printf("%s\n",S);

int yylex(void); /* function prototype */

A_exp absyn_root;

void yyerror(char *s)
{
 EM_error(EM_tokPos, "%s", s);
}
%}


%union {
	int pos;
	int ival;
	string sval;
	A_binop op;
	A_exp exp;
	A_var var;
	A_expList expList;
	A_assignfieldList assignfieldList;
	A_dec dec;
	A_decList decList;
	A_ty ty;
	A_tyfieldList tyfieldList;
	}

%token <sval> ID STRING
%token <ival> INT
%token 
	COMMA COLON SEMICOLON 
	LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE 
	DOT 
%token	<op> PLUS MINUS TIMES DIVIDE EQ NEQ LT LE GT GE AND OR 
%token 
	ASSIGN
	ARRAY IF THEN ELSE WHILE FOR TO DO LET IN END OF 	 
	BREAK NIL
	FUNCTION VAR TYPE
%type <exp> program exp seq funcall record array
%type <var> lvalue
%type <expList> args explist
%type <assignfieldList> assignfields
%type <dec> dec tydec fundec vardec
%type <decList> decs
%type <ty> ty
%type <tyfieldList> tyfields


%start program

%nonassoc ASSIGN DO OF ELSE
%left OR
%left AND
%nonassoc EQ NEQ LT LE GT GE
%left PLUS MINUS
%left TIMES DIVIDE
%left UMINUS  	//与%prec相结合，给对应的规则指定优先级，此规则用于规约的优先级高于所有终结符的移进的优先级

%%

program:	exp		{absyn_root=$1;}

exp:   	 		
		STRING 	 	{$$=A_StringExp(EM_tokPos,$1);}
	|	INT 		{$$=A_IntExp(EM_tokPos,$1);}
	|	lvalue 		{$$=A_VarExp(EM_tokPos,$1);}
	|	NIL			{$$=A_NilExp(EM_tokPos);}
	|	seq			{$$=$1;}
	|	MINUS INT  %prec UMINUS		{$$=A_OpExp(EM_tokPos,A_IntExp(EM_tokPos,0),$1,A_IntExp(EM_tokPos,$2));}	//表示为(0-i)的操作符表达式
	|	funcall		{$$=$1;}
	|	exp PLUS exp	{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp MINUS exp 	{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp TIMES exp 	{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp DIVIDE exp 	{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp EQ exp 	    {$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp NEQ exp		{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp LT exp 		{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp LE exp 		{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp GT exp 		{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp GE exp 		{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp AND exp		{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	exp OR exp		{$$=A_OpExp(EM_tokPos,$1,$2,$3);}
	|	record		{$$=$1;}
	|	array		{$$=$1;}
	|	lvalue ASSIGN exp	{$$=A_AssignExp(EM_tokPos,$1,$3);}
	|	IF exp THEN exp ELSE exp		{$$=A_IfExp(EM_tokPos,$2,$4,$6);}
	|	IF exp THEN exp			{....}
	| 	WHILE exp DO exp	{$$=A_WhileExp(EM_tokPos,$2,$4);}
	|	FOR ID ASSIGN exp TO exp DO exp {$$=A_ForExp(EM_tokPos,S_Symbol($2),$4,$6,$8);}
	| 	LET decs IN explist END			{$$=A_LetExp(EM_tokPos,$2,$4);}
	| 	BREAK  				{$$=A_BreakExp(EM_tokPos);}
		

	//// 	/*未解决 else 移进规约冲突 ： 先不使用 if exp then exp 语法*/

		
lvalue:		ID			{$$=A_SimpleVar(EM_tokPos,S_Symbol($1));}
	|	lvalue DOT ID	{$$=A_FieldVar(EM_tokPos,$1,S_Symbol($3));}
	|	ID LBRACK exp RBRACK	{$$=A_SubscriptVar(EM_tokPos,A_SimpleVar(EM_tokPos,S_Symbol($1)),$3);}
	|	lvalue LBRACK exp RBRACK{$$=A_SubscriptVar(EM_tokPos,$1,$3);}
		
seq:	LPAREN explist RPAREN	{$$=A_SeqExp(EM_tokPos,$2);}
		

funcall: ID LPAREN args RPAREN	{$$=A_CallExp(EM_tokPos,S_Symbol($1),$3);}

args: 	exp COMMA args			{$$=A_ExpList($1,$3);}		//这样定义可能有问题
	|	exp						{$$=A_ExpList($1,NULL);}
	|							{$$=NULL;}

record: ID LBRACE assignfields RBRACE	{$$=A_RecordExp(EM_tokPos,S_Symbol($1),$3);}


assignfields: ID EQ exp COMMA assignfields	{$$=A_AssignfieldList(A_Assignfield(EM_tokPos,S_Symbol($1),$3),$5);}//这样定义可能有问题
	| 	  ID EQ exp				{$$=A_AssignfieldList(A_Assignfield(EM_tokPos,S_Symbol($1),$3),NULL);}
	|							{$$=NULL;}

array:	ID LBRACK exp RBRACK OF exp		{$$=A_ArrayExp(EM_tokPos,S_Symbol($1),$3,$6);}

explist: exp SEMICOLON explist	{$$=A_ExpList($1,$3);}
	|	 exp					{$$=A_ExpList($1,NULL);}
	|							{$$=NULL;}
	
decs:	dec decs				{$$=A_DecList($1,$2);}
 	|							{$$=NULL;}

dec: 	tydec  {$$=$1;}
	|	vardec {$$=$1;}
	|	fundec {$$=$1;}
	
tydec:	TYPE ID EQ ty	{$$=A_TypeDec(EM_tokPos,S_Symbol($2),$4);}

ty: 	ID				{$$=A_IdTy(EM_tokPos,S_Symbol($1));}
	|	LBRACE tyfields RBRACE	{$$=A_TyfieldTy(EM_tokPos,$2);}
	|	ARRAY OF ID		{$$=A_ArrayTy(EM_tokPos,S_Symbol($3));}

tyfields: ID COLON ID COMMA tyfields	{$$=A_TyfieldList(A_Tyfield(EM_tokPos,S_Symbol($1),S_Symbol($3)),$5);} //这样定义可能有问题
	|	  ID COLON ID	{$$=A_TyfieldList(A_Tyfield(EM_tokPos,S_Symbol($1),S_Symbol($3)),NULL);}
	|					{$$=NULL;}

vardec:	VAR ID ASSIGN exp	{$$=A_VarDec(EM_tokPos,S_Symbol($2),NULL,$4);}
	|	VAR ID COLON ID ASSIGN exp	{$$=A_VarDec(EM_tokPos,S_Symbol($2),S_Symbol($4),$6);}
	
fundec:	FUNCTION ID LPAREN tyfields RPAREN EQ exp	{$$=A_FunctionDec(EM_tokPos, S_Symbol($2), $4, NULL,$7);}
	|	FUNCTION ID LPAREN tyfields RPAREN COLON ID EQ exp	{$$=A_FunctionDec(EM_tokPos, S_Symbol($2), $4, S_Symbol($7),$9);}
		