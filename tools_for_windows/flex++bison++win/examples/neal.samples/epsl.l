%{
#include "param.h"
/* Need epsy.h to get values of tokens, and yystype */
#include "epsy.h"
%}
%define CONSTRUCTOR_PARAM FILE* in
/* We cannot use CONSTRUCTOR_INIT for yyin, because yy_initialize will set yyin=0 */
%define CONSTRUCTOR_CODE  yyin = in; LineNo = 1;
%define MEMBERS int LineNo;
%define LEX_PARAM YY_parse_STYPE &yylval

ID	[a-zA-Z0-9_-]+

%%

engine { return parse::ENGINE; }

vpins { return parse::VPINS; }

dpih { return parse::DPIH; }

dpiv { return parse::DPIV; }

graphicsmode { return parse::GRAPHICSMODE; }

vskip { return parse::VSKIP; }

vinterleave { return parse::VINTERLEAVE; }

xoff { return parse::XOFF; }

yoff { return parse::YOFF; }

width { return parse::WIDTH; }

height { return parse::HEIGHT; }

fastspace { return parse::FASTSPACE; }

\"[^"\n]*\" {
	  yylval.strval = (char *)malloc(yyleng-1); /* should check result! */
	  strncpy(yylval.strval,&(yytext[1]),yyleng-2);
	  (yylval.strval)[yyleng-2] = 0;
	  return(parse::STRING);
	}

{ID}	{
	  yylval.strval = strdup( yytext );
	  return(parse::STRING);
	}

[ \t]+ ;

[\n]  { LineNo++; }

. {  return yytext[0]; }
%%
