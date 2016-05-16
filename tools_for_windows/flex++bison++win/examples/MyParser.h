#ifndef YY_MyParser_h_included
#define YY_MyParser_h_included

#line 1 "/u/icdc/rdt/tools/lib/bison.h"
/* before anything */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#endif
#include <stdio.h>

/* #line 14 "/u/icdc/rdt/tools/lib/bison.h" */
#line 21 "MyParser.h"
#define YY_MyParser_LSP_NEEDED 
#define YY_MyParser_ERROR_BODY  =0
#define YY_MyParser_LEX_BODY  =0
#line 23 "MyParser.y"

#include <stdio.h>

#line 27 "MyParser.y"
typedef union {
	int itype;	/* for count */
	char ctype;	/* for char */
	} yy_MyParser_stype;
#define YY_MyParser_STYPE yy_MyParser_stype

#line 14 "/u/icdc/rdt/tools/lib/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_MyParser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_MyParser_COMPATIBILITY 1
#else
#define  YY_MyParser_COMPATIBILITY 0
#endif
#endif

#if YY_MyParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_MyParser_LTYPE
#define YY_MyParser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_MyParser_STYPE 
#define YY_MyParser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_MyParser_DEBUG
#define  YY_MyParser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
#endif
#endif
#ifdef YY_MyParser_STYPE
#ifndef yystype
#define yystype YY_MyParser_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_MyParser_USE_GOTO
#define YY_MyParser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_MyParser_USE_GOTO
#define YY_MyParser_USE_GOTO 0
#endif

#ifndef YY_MyParser_PURE

/* #line 63 "/u/icdc/rdt/tools/lib/bison.h" */
#line 88 "MyParser.h"

#line 63 "/u/icdc/rdt/tools/lib/bison.h"
/* YY_MyParser_PURE */
#endif

/* #line 65 "/u/icdc/rdt/tools/lib/bison.h" */
#line 95 "MyParser.h"

#line 65 "/u/icdc/rdt/tools/lib/bison.h"
/* prefix */
#ifndef YY_MyParser_DEBUG

/* #line 67 "/u/icdc/rdt/tools/lib/bison.h" */
#line 102 "MyParser.h"

#line 67 "/u/icdc/rdt/tools/lib/bison.h"
/* YY_MyParser_DEBUG */
#endif
#ifndef YY_MyParser_LSP_NEEDED

/* #line 70 "/u/icdc/rdt/tools/lib/bison.h" */
#line 110 "MyParser.h"

#line 70 "/u/icdc/rdt/tools/lib/bison.h"
 /* YY_MyParser_LSP_NEEDED*/
#endif
/* DEFAULT LTYPE*/
#ifdef YY_MyParser_LSP_NEEDED
#ifndef YY_MyParser_LTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YY_MyParser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
#ifndef YY_MyParser_STYPE
#define YY_MyParser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_MyParser_PARSE
#define YY_MyParser_PARSE yyparse
#endif
#ifndef YY_MyParser_LEX
#define YY_MyParser_LEX yylex
#endif
#ifndef YY_MyParser_LVAL
#define YY_MyParser_LVAL yylval
#endif
#ifndef YY_MyParser_LLOC
#define YY_MyParser_LLOC yylloc
#endif
#ifndef YY_MyParser_CHAR
#define YY_MyParser_CHAR yychar
#endif
#ifndef YY_MyParser_NERRS
#define YY_MyParser_NERRS yynerrs
#endif
#ifndef YY_MyParser_DEBUG_FLAG
#define YY_MyParser_DEBUG_FLAG yydebug
#endif
#ifndef YY_MyParser_ERROR
#define YY_MyParser_ERROR yyerror
#endif

#ifndef YY_MyParser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_MyParser_PARSE_PARAM
#ifndef YY_MyParser_PARSE_PARAM_DEF
#define YY_MyParser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_MyParser_PARSE_PARAM
#define YY_MyParser_PARSE_PARAM void
#endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_MyParser_PURE
extern YY_MyParser_STYPE YY_MyParser_LVAL;
#endif


/* #line 143 "/u/icdc/rdt/tools/lib/bison.h" */
#line 188 "MyParser.h"
#define	EOL_TOKEN	258
#define	CHAR_TOKEN	259


#line 143 "/u/icdc/rdt/tools/lib/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
#ifndef YY_MyParser_CLASS
#define YY_MyParser_CLASS MyParser
#endif

#ifndef YY_MyParser_INHERIT
#define YY_MyParser_INHERIT
#endif
#ifndef YY_MyParser_MEMBERS
#define YY_MyParser_MEMBERS 
#endif
#ifndef YY_MyParser_LEX_BODY
#define YY_MyParser_LEX_BODY  
#endif
#ifndef YY_MyParser_ERROR_BODY
#define YY_MyParser_ERROR_BODY  
#endif
#ifndef YY_MyParser_CONSTRUCTOR_PARAM
#define YY_MyParser_CONSTRUCTOR_PARAM
#endif
/* choose between enum and const */
#ifndef YY_MyParser_USE_CONST_TOKEN
#define YY_MyParser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */ 
#endif
#if YY_MyParser_USE_CONST_TOKEN != 0
#ifndef YY_MyParser_ENUM_TOKEN
#define YY_MyParser_ENUM_TOKEN yy_MyParser_enum_token
#endif
#endif

class YY_MyParser_CLASS YY_MyParser_INHERIT
{
public: 
#if YY_MyParser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 182 "/u/icdc/rdt/tools/lib/bison.h" */
#line 235 "MyParser.h"
static const int EOL_TOKEN;
static const int CHAR_TOKEN;


#line 182 "/u/icdc/rdt/tools/lib/bison.h"
 /* decl const */
#else
enum YY_MyParser_ENUM_TOKEN { YY_MyParser_NULL_TOKEN=0

/* #line 185 "/u/icdc/rdt/tools/lib/bison.h" */
#line 246 "MyParser.h"
	,EOL_TOKEN=258
	,CHAR_TOKEN=259


#line 185 "/u/icdc/rdt/tools/lib/bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_MyParser_PARSE(YY_MyParser_PARSE_PARAM);
 virtual void YY_MyParser_ERROR(char *msg) YY_MyParser_ERROR_BODY;
#ifdef YY_MyParser_PURE
#ifdef YY_MyParser_LSP_NEEDED
 virtual int  YY_MyParser_LEX(YY_MyParser_STYPE *YY_MyParser_LVAL,YY_MyParser_LTYPE *YY_MyParser_LLOC) YY_MyParser_LEX_BODY;
#else
 virtual int  YY_MyParser_LEX(YY_MyParser_STYPE *YY_MyParser_LVAL) YY_MyParser_LEX_BODY;
#endif
#else
 virtual int YY_MyParser_LEX() YY_MyParser_LEX_BODY;
 YY_MyParser_STYPE YY_MyParser_LVAL;
#ifdef YY_MyParser_LSP_NEEDED
 YY_MyParser_LTYPE YY_MyParser_LLOC;
#endif
 int YY_MyParser_NERRS;
 int YY_MyParser_CHAR;
#endif
#if YY_MyParser_DEBUG != 0
public:
 int YY_MyParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_MyParser_CLASS(YY_MyParser_CONSTRUCTOR_PARAM);
public:
 YY_MyParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_MyParser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_MyParser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_MyParser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_MyParser_DEBUG 
#define YYDEBUG YY_MyParser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "/u/icdc/rdt/tools/lib/bison.h" */
#line 305 "MyParser.h"
#endif
