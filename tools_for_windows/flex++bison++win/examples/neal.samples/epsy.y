%{
#include "param.h"
#include <stdlib.h> /* for atoi, etc. */
extern char* PrinterName;
extern param PrintParam;
extern int FoundPrinter;
%}
/* This union must be before include epsl.h, cause yylex needs yystype */
%union {
  char* strval;
  param* pval; /* would be nice to use a struct instead of a pointer */
	       /* but can't be a member of a union */
  int ival;
  double dval;
}
%header{
/* this include must be before class lex is referenced (below) */
#include "epsl.h"
%}
%define CONSTRUCTOR_PARAM FILE* in
%define CONSTRUCTOR_INIT : Lexer( in )
%define LEX_BODY { return Lexer.yylex( yylval ); }
%define MEMBERS lex Lexer;
  
%token STRING ENGINE VPINS DPIH DPIV GRAPHICSMODE VSKIP VINTERLEAVE
       XOFF YOFF WIDTH HEIGHT FASTSPACE

%type <strval> STRING pname engine
%type <pval> params
%type <ival> vpins dpih dpiv graphicsmode vskip vinterleave xoff yoff
	pnames fast
%type <dval> width height

%%

entries	:	entry
	|	entries entry
	;

entry	:	pnames '{' params '}' {
		  if( $1 ) {
		    PrintParam = * $3;
		    delete $3;
		    FoundPrinter++;
		    YYACCEPT;
		  }
		  else
		    delete $3;
		}
	;

pnames	:	pname { $$ = ( strcmp( $1, PrinterName ) == 0 ) ? 1 : 0; }
	| 	pnames '|' pname { 
		  if( $1 ) $$ = 1;
		  else $$ = ( strcmp( $3, PrinterName ) == 0 ) ? 1 : 0;
		}
	;

pname	:	STRING
	;

params	:	/* empty */	{ $$ = new param() ; }
	|	params engine	{ $$->Engine = $2; }
	|	params vpins	{ $$->VPins = $2; }
	|	params dpih	{ $$->DPIh = $2; }
	|	params dpiv	{ $$->DPIv = $2; }
	|	params graphicsmode { $$->GraphicsMode = $2; }
	|	params vskip	{ $$->VSkip = $2; }
	|	params vinterleave { $$->VInterleave = $2; }
	|	params xoff { $$->xoff = $2; }
	|	params yoff { $$->yoff = $2; }
	|	params width { $$->Width = $2; }
	|	params height { $$->Height = $2; }
	|	params fast { $$->HasFastSpace = $2; }
	;

engine	:	ENGINE '=' STRING { $$ = $3; }
	;

vpins	:	VPINS '=' STRING { $$ = atoi( $3 ); }
	;

dpih	:	DPIH '=' STRING { $$ = atoi( $3 ); }
	;

dpiv	:	DPIV '=' STRING { $$ = atoi( $3 ); }
	;

graphicsmode	:	GRAPHICSMODE '=' STRING 
			{ $$ = atoi( $3 ); }
	;

vskip	:	VSKIP '=' STRING { $$ = atoi( $3 ); }
	;

vinterleave	:	VINTERLEAVE '=' STRING 
			{ $$ = atoi( $3 ); }
	;

xoff	:	XOFF '=' STRING { $$ = atoi( $3 ); }
	;

yoff	:	YOFF '=' STRING { $$ = atoi( $3 ); }
	;

width	:	WIDTH '=' STRING { $$ = atof( $3 ); }
	;

height	:	HEIGHT '=' STRING { $$ = atof( $3 ); }
	;

fast	:	FASTSPACE '=' STRING { $$ = atoi( $3 ); }
	;

%%
virtual void parse::yyerror( char *s) {
  fprintf(stderr, "%s\n", s );
  fprintf(stderr, "Line No %d, Last token was \"%s\"\n", Lexer.LineNo, Lexer.yytext );
}
