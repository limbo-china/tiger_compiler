%{
#include <string.h>
#include "util.h"
#include "absyn.h"
#include "symbol.h"
#include "tiger.tab.h"
#include "errormsg.h"

int charPos=1;

int yywrap(void)
{
 charPos=1;
 return 1;
}


void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
}
string quoteString(char *s)
{
	int len=strlen(s);
	int i;
	string p = checked_malloc(len-1);
	for(i=0;i<len-2;i++)
		p[i]=s[i+1];
	p[i]='\0';
	return p;
}
%}
%x COMMENT
%s NOCOMMENT

%%
" "	 	{adjust(); continue;}
"\t" 	{adjust();continue;}
"\n"	{adjust(); EM_newline(); continue;}
","	 	{adjust(); return COMMA;}
":"		{adjust(); return COLON ;}
";"		{adjust();return SEMICOLON;}
"(" 	{adjust();return LPAREN;}
")" 	{adjust(); return RPAREN;}
"[" 	{adjust(); return LBRACK;}
"]" 	{adjust();return RBRACK;}
"{" 	{adjust();return LBRACE;}
"}" 	{adjust(); return RBRACE;}
"." 	{adjust(); return DOT;}
"+" 	{adjust(); return PLUS;}
"-" 	{adjust(); return MINUS;}
"*" 	{adjust(); return TIMES;}
"/" 	{adjust(); return DIVIDE;}
"=" 	{adjust(); return EQ;}
"<>"	{adjust (); return NEQ;}
"<" 	{adjust(); return LT;}
">" 	{adjust(); return GT;}
"<=" 	{adjust(); return LE;}
">=" 	{adjust(); return GE;}
"&" 	{adjust(); return AND;}
"|" 	{adjust(); return OR;}
":=" 	{adjust(); return ASSIGN;}


while 	{adjust(); return WHILE;}
for  	{adjust(); return FOR;}
to 		{adjust(); return TO;}
break 	{adjust(); return BREAK;}
let 	{adjust(); return LET;}
in 		{adjust(); return IN;}
end 	{adjust(); return END;} 
function {adjust(); return FUNCTION;}
var 	{adjust(); return VAR;}
type  	{adjust(); return TYPE;}
array 	{adjust(); return ARRAY ;}
if 		{adjust(); return IF; } 
then 	{adjust(); return THEN;}
else 	{adjust(); return ELSE;}
do  	{adjust(); return DO;}
of 		{adjust(); return OF;}
nil		{adjust(); return NIL;}

[a-zA-Z_][a-zA-Z0-9_]* 		{adjust(); yylval.sval=String(yytext); return ID;}		
\"[a-zA-Z0-9(" ")]*\"  			{adjust(); yylval.sval=quoteString(yytext); return STRING;}
[0-9]+	 					{adjust(); yylval.ival=atoi(yytext); return INT;}

"/*"                {adjust(); BEGIN COMMENT;}
<COMMENT>"*/"       {adjust(); BEGIN NOCOMMENT;}
<COMMENT>"\n"		{adjust(); EM_newline(); continue;}
<COMMENT>(.)      	{adjust(); continue;}
.	 				{adjust(); EM_error(EM_tokPos,"illegal token");}


