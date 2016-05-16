#ifndef YY_DmanParser_h_included
#define YY_DmanParser_h_included

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
#line 21 "dmanParser.h"

#line 19 "dmanParser.y"
typedef union {
	char theChar;
	char *theString;
	} yy_DmanParser_stype;
#define YY_DmanParser_STYPE yy_DmanParser_stype
#line 23 "dmanParser.y"

typedef YY_DmanParser_STYPE TokenValue;
typedef
  struct
    { int first_line,last_line,first_column,last_column;
      char *text;
    } TokenLocation;
#define YY_DmanParser_LSP_NEEDED 
#define YY_DmanParser_DEBUG  1
#define YY_DmanParser_LTYPE  TokenLocation
#define YY_DmanParser_LLOC  theTokenLocation
#define YY_DmanParser_LVAL  theTokenValue
#define YY_DmanParser_LEX  Scan
#define YY_DmanParser_LEX_BODY  =0
#define YY_DmanParser_ERROR_BODY  =0
#define YY_DmanParser_ERROR  PrintError
#define YY_DmanParser_NERRS  errorCount
#define YY_DmanParser_DEBUG_FLAG  debugFlag
#define YY_DmanParser_MEMBERS   
#define YY_DmanParser_PARSE  Parse 
#define YY_DmanParser_PARSE_PARAM  
#define YY_DmanParser_CONSTRUCTOR_PARAM  
#define YY_DmanParser_CONSTRUCTOR_INIT  
#define YY_DmanParser_CONSTRUCTOR_CODE  

#line 14 "/u/icdc/rdt/tools/lib/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_DmanParser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_DmanParser_COMPATIBILITY 1
#else
#define  YY_DmanParser_COMPATIBILITY 0
#endif
#endif

#if YY_DmanParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_DmanParser_LTYPE
#define YY_DmanParser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_DmanParser_STYPE 
#define YY_DmanParser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_DmanParser_DEBUG
#define  YY_DmanParser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
#endif
#endif
#ifdef YY_DmanParser_STYPE
#ifndef yystype
#define yystype YY_DmanParser_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_DmanParser_USE_GOTO
#define YY_DmanParser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_DmanParser_USE_GOTO
#define YY_DmanParser_USE_GOTO 0
#endif

#ifndef YY_DmanParser_PURE

/* #line 63 "/u/icdc/rdt/tools/lib/bison.h" */
#line 107 "dmanParser.h"

#line 63 "/u/icdc/rdt/tools/lib/bison.h"
/* YY_DmanParser_PURE */
#endif

/* #line 65 "/u/icdc/rdt/tools/lib/bison.h" */
#line 114 "dmanParser.h"

#line 65 "/u/icdc/rdt/tools/lib/bison.h"
/* prefix */
#ifndef YY_DmanParser_DEBUG

/* #line 67 "/u/icdc/rdt/tools/lib/bison.h" */
#line 121 "dmanParser.h"

#line 67 "/u/icdc/rdt/tools/lib/bison.h"
/* YY_DmanParser_DEBUG */
#endif
#ifndef YY_DmanParser_LSP_NEEDED

/* #line 70 "/u/icdc/rdt/tools/lib/bison.h" */
#line 129 "dmanParser.h"

#line 70 "/u/icdc/rdt/tools/lib/bison.h"
 /* YY_DmanParser_LSP_NEEDED*/
#endif
/* DEFAULT LTYPE*/
#ifdef YY_DmanParser_LSP_NEEDED
#ifndef YY_DmanParser_LTYPE
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

#define YY_DmanParser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
#ifndef YY_DmanParser_STYPE
#define YY_DmanParser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_DmanParser_PARSE
#define YY_DmanParser_PARSE yyparse
#endif
#ifndef YY_DmanParser_LEX
#define YY_DmanParser_LEX yylex
#endif
#ifndef YY_DmanParser_LVAL
#define YY_DmanParser_LVAL yylval
#endif
#ifndef YY_DmanParser_LLOC
#define YY_DmanParser_LLOC yylloc
#endif
#ifndef YY_DmanParser_CHAR
#define YY_DmanParser_CHAR yychar
#endif
#ifndef YY_DmanParser_NERRS
#define YY_DmanParser_NERRS yynerrs
#endif
#ifndef YY_DmanParser_DEBUG_FLAG
#define YY_DmanParser_DEBUG_FLAG yydebug
#endif
#ifndef YY_DmanParser_ERROR
#define YY_DmanParser_ERROR yyerror
#endif

#ifndef YY_DmanParser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_DmanParser_PARSE_PARAM
#ifndef YY_DmanParser_PARSE_PARAM_DEF
#define YY_DmanParser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_DmanParser_PARSE_PARAM
#define YY_DmanParser_PARSE_PARAM void
#endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_DmanParser_PURE
extern YY_DmanParser_STYPE YY_DmanParser_LVAL;
#endif


/* #line 143 "/u/icdc/rdt/tools/lib/bison.h" */
#line 207 "dmanParser.h"
#define	CMD_HEADER	258
#define	CMD_BAD	259
#define	CMD_SECTION	260
#define	CMD_SSECTION	261
#define	TOK_ITEM1	262
#define	TOK_ITEM2	263
#define	TOK_ITEM3	264
#define	TOK_ITEM_BAD	265
#define	TOK_INDENT1	266
#define	TOK_INDENT2	267
#define	TOK_INDENT3	268
#define	TOK_INDENT_BAD	269
#define	TOK_LF	270
#define	TOK_INF	271
#define	TOK_SUP	272
#define	TOK_DQUOTE	273
#define	TOK_SPACE	274
#define	TOK_BEGIN	275
#define	TOK_END	276
#define	TOK_BAD	277
#define	TOK_CHAR	278
#define	TOK_COMPOSED2	279
#define	TOK_COMPOSED1	280


#line 143 "/u/icdc/rdt/tools/lib/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
#ifndef YY_DmanParser_CLASS
#define YY_DmanParser_CLASS DmanParser
#endif

#ifndef YY_DmanParser_INHERIT
#define YY_DmanParser_INHERIT
#endif
#ifndef YY_DmanParser_MEMBERS
#define YY_DmanParser_MEMBERS 
#endif
#ifndef YY_DmanParser_LEX_BODY
#define YY_DmanParser_LEX_BODY  
#endif
#ifndef YY_DmanParser_ERROR_BODY
#define YY_DmanParser_ERROR_BODY  
#endif
#ifndef YY_DmanParser_CONSTRUCTOR_PARAM
#define YY_DmanParser_CONSTRUCTOR_PARAM
#endif
/* choose between enum and const */
#ifndef YY_DmanParser_USE_CONST_TOKEN
#define YY_DmanParser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */ 
#endif
#if YY_DmanParser_USE_CONST_TOKEN != 0
#ifndef YY_DmanParser_ENUM_TOKEN
#define YY_DmanParser_ENUM_TOKEN yy_DmanParser_enum_token
#endif
#endif

class YY_DmanParser_CLASS YY_DmanParser_INHERIT
{
public: 
#if YY_DmanParser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 182 "/u/icdc/rdt/tools/lib/bison.h" */
#line 275 "dmanParser.h"
static const int CMD_HEADER;
static const int CMD_BAD;
static const int CMD_SECTION;
static const int CMD_SSECTION;
static const int TOK_ITEM1;
static const int TOK_ITEM2;
static const int TOK_ITEM3;
static const int TOK_ITEM_BAD;
static const int TOK_INDENT1;
static const int TOK_INDENT2;
static const int TOK_INDENT3;
static const int TOK_INDENT_BAD;
static const int TOK_LF;
static const int TOK_INF;
static const int TOK_SUP;
static const int TOK_DQUOTE;
static const int TOK_SPACE;
static const int TOK_BEGIN;
static const int TOK_END;
static const int TOK_BAD;
static const int TOK_CHAR;
static const int TOK_COMPOSED2;
static const int TOK_COMPOSED1;


#line 182 "/u/icdc/rdt/tools/lib/bison.h"
 /* decl const */
#else
enum YY_DmanParser_ENUM_TOKEN { YY_DmanParser_NULL_TOKEN=0

/* #line 185 "/u/icdc/rdt/tools/lib/bison.h" */
#line 307 "dmanParser.h"
	,CMD_HEADER=258
	,CMD_BAD=259
	,CMD_SECTION=260
	,CMD_SSECTION=261
	,TOK_ITEM1=262
	,TOK_ITEM2=263
	,TOK_ITEM3=264
	,TOK_ITEM_BAD=265
	,TOK_INDENT1=266
	,TOK_INDENT2=267
	,TOK_INDENT3=268
	,TOK_INDENT_BAD=269
	,TOK_LF=270
	,TOK_INF=271
	,TOK_SUP=272
	,TOK_DQUOTE=273
	,TOK_SPACE=274
	,TOK_BEGIN=275
	,TOK_END=276
	,TOK_BAD=277
	,TOK_CHAR=278
	,TOK_COMPOSED2=279
	,TOK_COMPOSED1=280


#line 185 "/u/icdc/rdt/tools/lib/bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_DmanParser_PARSE(YY_DmanParser_PARSE_PARAM);
 virtual void YY_DmanParser_ERROR(char *msg) YY_DmanParser_ERROR_BODY;
#ifdef YY_DmanParser_PURE
#ifdef YY_DmanParser_LSP_NEEDED
 virtual int  YY_DmanParser_LEX(YY_DmanParser_STYPE *YY_DmanParser_LVAL,YY_DmanParser_LTYPE *YY_DmanParser_LLOC) YY_DmanParser_LEX_BODY;
#else
 virtual int  YY_DmanParser_LEX(YY_DmanParser_STYPE *YY_DmanParser_LVAL) YY_DmanParser_LEX_BODY;
#endif
#else
 virtual int YY_DmanParser_LEX() YY_DmanParser_LEX_BODY;
 YY_DmanParser_STYPE YY_DmanParser_LVAL;
#ifdef YY_DmanParser_LSP_NEEDED
 YY_DmanParser_LTYPE YY_DmanParser_LLOC;
#endif
 int YY_DmanParser_NERRS;
 int YY_DmanParser_CHAR;
#endif
#if YY_DmanParser_DEBUG != 0
public:
 int YY_DmanParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_DmanParser_CLASS(YY_DmanParser_CONSTRUCTOR_PARAM);
public:
 YY_DmanParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_DmanParser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_DmanParser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_DmanParser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_DmanParser_DEBUG 
#define YYDEBUG YY_DmanParser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "/u/icdc/rdt/tools/lib/bison.h" */
#line 387 "dmanParser.h"
#endif
