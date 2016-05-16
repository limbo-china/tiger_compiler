%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"

#define P(S) printf("%s\n",S);

int yylex(void); /* function prototype */

void yyerror(char *s)
{
 EM_error(EM_tokPos, "%s", s);
}
%}


%union {
	int pos;
	int ival;
	string sval;
	}

%token <sval> ID STRING
%token <ival> INT

%token 
  COMMA COLON SEMICOLON 
  LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE 
  DOT 
  PLUS MINUS TIMES DIVIDE 
  EQ NEQ LT LE GT GE
  AND OR 
  ASSIGN
  ARRAY IF THEN ELSE WHILE FOR TO DO LET IN END OF 
  BREAK NIL
  FUNCTION VAR TYPE

%start program

%nonassoc ASSIGN DO OF ELSE
%left OR
%left AND
%nonassoc EQ NEQ LT LE GT GE
%left PLUS MINUS
%left TIMES DIVIDE
%left UMINUS  	//与%prec相结合，给对应的规则指定优先级，此规则用于规约的优先级高于所有终结符的移进



%%

program:	exp

exp:   	 		
		STRING 	 	{P("string!")}
	|	INT 	
	|	lvalue 	
	|	NIL		
	|	seq		{P("seq!")}
	|	MINUS INT  %prec UMINUS 		//设置规则的优先级
	|	funcall  {P("funcall!")}
	|	exp PLUS exp 	 {P("exp PLUS exp ")}
	|	exp MINUS exp 	{P("exp MINUS exp ")}
	|	exp TIMES exp 	{P("exp TIMES exp ")}
	|	exp DIVIDE exp 	{P("exp DIVIDE exp ")}
	|	exp EQ exp 	    
	|	exp NEQ exp 
	|	exp LT exp 	
	|	exp LE exp 	
	|	exp GT exp 	
	|	exp GE exp 	
	|	exp AND exp
	|	exp OR exp 
	|	record  	{P("record!")}
	|	array		{P("array!")}
	|	lvalue ASSIGN exp	{P("assign!")}
	|	IF exp THEN exp ELSE exp  {P("if then else!")}
///////		|	IF exp THEN exp			{P("if then!")}
	| 	WHILE exp DO exp		{P("while do!")}
	|	FOR ID ASSIGN exp TO exp DO exp {P("for to do!")}
	| 	LET decs IN explist END		{P("let in end!")}
	| 	BREAK  				{P("break!")}
		

	//// 	/*未解决 else 移进规约冲突 ： 先不使用 if exp then exp 语法*/

		
lvalue:	ID 		
	|	lvalue DOT ID	
	|	ID LBRACK exp RBRACK  bracklist {P("array lvalue!")}

bracklist: 	LBRACK exp RBRACK bracklist
		|
		
seq:	LPAREN explist RPAREN 
		

funcall: ID LPAREN args RPAREN

args: 	exp COMMA exp					//这样定义可能有问题
	|	exp
	|

record: ID LBRACE assignfield RBRACE


assignfield: ID EQ exp COMMA assignfield		//这样定义可能有问题
	| 	  ID EQ exp
	|	

array: 	ID LBRACK exp RBRACK OF exp 

explist: exp SEMICOLON explist
	|	 exp
	|	 
	
decs:	dec decs
 	|

dec: 	tydec  {P("tydec!")}
	|	vardec {P("vardec!")}
	|	fundec {P("fundec!")}
	
tydec:	TYPE ID EQ ty

ty: 	ID
	|	LBRACE tyfields RBRACE
	|	ARRAY OF ID

tyfields: ID COLON ID COMMA tyfields   //这样定义可能有问题
	|	  ID COLON ID
	|

vardec:	VAR ID ASSIGN exp
	|	VAR ID COLON ID ASSIGN exp
	
fundec:	FUNCTION ID LPAREN tyfields RPAREN EQ exp
	|	FUNCTION ID LPAREN tyfields RPAREN COLON ID EQ exp
		
		
		
		


	
