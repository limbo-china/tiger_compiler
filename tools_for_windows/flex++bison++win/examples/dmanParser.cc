#define YY_DmanParser_h_included

/*  A Bison++ parser, made from dmanParser.y  */

 /* with Bison++ version bison++ Version 1.21-7, adapted from GNU bison by coetmeur@icdc.fr
  */


#line 1 "/u/icdc/rdt/tools/lib/bison.cc"
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* HEADER SECTION */
#ifndef _MSDOS
#ifdef MSDOS
#define _MSDOS
#endif
#endif
/* turboc */
#ifdef __MSDOS__
#ifndef _MSDOS
#define _MSDOS
#endif
#endif

#ifndef alloca
#if defined( __GNUC__)
#define alloca __builtin_alloca

#elif (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)  || defined (__sgi)
#include <alloca.h>

#elif defined (_MSDOS)
#include <malloc.h>
#ifndef __TURBOC__
/* MS C runtime lib */
#define alloca _alloca
#endif

#elif defined(_AIX)
#include <malloc.h>
#pragma alloca

#elif defined(__hpux)
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */

#endif /* not _AIX  not MSDOS, or __TURBOC__ or _AIX, not sparc.  */
#endif /* alloca not defined.  */
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
#ifndef __STDC__
#define const
#endif
#endif
#include <stdio.h>
#define YYBISON 1  

/* #line 77 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 89 "dmanParser.cc"

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
#line 31 "dmanParser.y"

static char SccsId[]="@(#) dmanParser.y YaccSource asterisk 1.14 93/07/05 16:13:06 (SCCS/s.dmanParser.y)";
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

#line 77 "/u/icdc/rdt/tools/lib/bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_DmanParser_BISON 1
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
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_DmanParser_STYPE 
#define YY_DmanParser_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_DmanParser_DEBUG
#define  YY_DmanParser_DEBUG YYDEBUG
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

/* #line 121 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 173 "dmanParser.cc"

#line 121 "/u/icdc/rdt/tools/lib/bison.cc"
/*  YY_DmanParser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 125 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 182 "dmanParser.cc"

#line 125 "/u/icdc/rdt/tools/lib/bison.cc"
/* prefix */
#ifndef YY_DmanParser_DEBUG

/* #line 127 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 189 "dmanParser.cc"

#line 127 "/u/icdc/rdt/tools/lib/bison.cc"
/* YY_DmanParser_DEBUG */
#endif


#ifndef YY_DmanParser_LSP_NEEDED

/* #line 132 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 199 "dmanParser.cc"

#line 132 "/u/icdc/rdt/tools/lib/bison.cc"
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
      /* We used to use `unsigned long' as YY_DmanParser_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

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
#if YY_DmanParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_DmanParser_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_DmanParser_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_DmanParser_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_DmanParser_PURE
#ifndef YYPURE
#define YYPURE YY_DmanParser_PURE
#endif
#endif
#ifdef YY_DmanParser_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_DmanParser_DEBUG 
#endif
#endif
#ifndef YY_DmanParser_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_DmanParser_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_DmanParser_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_DmanParser_LSP_NEEDED YYLSP_NEEDED
#endif
#endif
#endif
#ifndef YY_USE_CLASS
/* TOKEN C */

/* #line 240 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 312 "dmanParser.cc"
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


#line 240 "/u/icdc/rdt/tools/lib/bison.cc"
 /* #defines tokens */
#else
/* CLASS */
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
#ifndef YY_DmanParser_CONSTRUCTOR_CODE
#define YY_DmanParser_CONSTRUCTOR_CODE
#endif
#ifndef YY_DmanParser_CONSTRUCTOR_INIT
#define YY_DmanParser_CONSTRUCTOR_INIT
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

/* #line 284 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 385 "dmanParser.cc"
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


#line 284 "/u/icdc/rdt/tools/lib/bison.cc"
 /* decl const */
#else
enum YY_DmanParser_ENUM_TOKEN { YY_DmanParser_NULL_TOKEN=0

/* #line 287 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 417 "dmanParser.cc"
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


#line 287 "/u/icdc/rdt/tools/lib/bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_DmanParser_PARSE (YY_DmanParser_PARSE_PARAM);
 virtual void YY_DmanParser_ERROR(char *msg) YY_DmanParser_ERROR_BODY;
#ifdef YY_DmanParser_PURE
#ifdef YY_DmanParser_LSP_NEEDED
 virtual int  YY_DmanParser_LEX (YY_DmanParser_STYPE *YY_DmanParser_LVAL,YY_DmanParser_LTYPE *YY_DmanParser_LLOC) YY_DmanParser_LEX_BODY;
#else
 virtual int  YY_DmanParser_LEX (YY_DmanParser_STYPE *YY_DmanParser_LVAL) YY_DmanParser_LEX_BODY;
#endif
#else
 virtual int YY_DmanParser_LEX() YY_DmanParser_LEX_BODY;
 YY_DmanParser_STYPE YY_DmanParser_LVAL;
#ifdef YY_DmanParser_LSP_NEEDED
 YY_DmanParser_LTYPE YY_DmanParser_LLOC;
#endif
 int   YY_DmanParser_NERRS;
 int    YY_DmanParser_CHAR;
#endif
#if YY_DmanParser_DEBUG != 0
 int YY_DmanParser_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_DmanParser_CLASS(YY_DmanParser_CONSTRUCTOR_PARAM);
public:
 YY_DmanParser_MEMBERS 
};
/* other declare folow */
#if YY_DmanParser_USE_CONST_TOKEN != 0

/* #line 318 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 477 "dmanParser.cc"
const int YY_DmanParser_CLASS::CMD_HEADER=258;
const int YY_DmanParser_CLASS::CMD_BAD=259;
const int YY_DmanParser_CLASS::CMD_SECTION=260;
const int YY_DmanParser_CLASS::CMD_SSECTION=261;
const int YY_DmanParser_CLASS::TOK_ITEM1=262;
const int YY_DmanParser_CLASS::TOK_ITEM2=263;
const int YY_DmanParser_CLASS::TOK_ITEM3=264;
const int YY_DmanParser_CLASS::TOK_ITEM_BAD=265;
const int YY_DmanParser_CLASS::TOK_INDENT1=266;
const int YY_DmanParser_CLASS::TOK_INDENT2=267;
const int YY_DmanParser_CLASS::TOK_INDENT3=268;
const int YY_DmanParser_CLASS::TOK_INDENT_BAD=269;
const int YY_DmanParser_CLASS::TOK_LF=270;
const int YY_DmanParser_CLASS::TOK_INF=271;
const int YY_DmanParser_CLASS::TOK_SUP=272;
const int YY_DmanParser_CLASS::TOK_DQUOTE=273;
const int YY_DmanParser_CLASS::TOK_SPACE=274;
const int YY_DmanParser_CLASS::TOK_BEGIN=275;
const int YY_DmanParser_CLASS::TOK_END=276;
const int YY_DmanParser_CLASS::TOK_BAD=277;
const int YY_DmanParser_CLASS::TOK_CHAR=278;
const int YY_DmanParser_CLASS::TOK_COMPOSED2=279;
const int YY_DmanParser_CLASS::TOK_COMPOSED1=280;


#line 318 "/u/icdc/rdt/tools/lib/bison.cc"
 /* const YY_DmanParser_CLASS::token */
#endif
/*apres const  */
YY_DmanParser_CLASS::YY_DmanParser_CLASS(YY_DmanParser_CONSTRUCTOR_PARAM) YY_DmanParser_CONSTRUCTOR_INIT
{
#if YY_DmanParser_DEBUG != 0
YY_DmanParser_DEBUG_FLAG=0;
#endif
YY_DmanParser_CONSTRUCTOR_CODE;
};
#endif

/* #line 329 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 517 "dmanParser.cc"


#define	YYFINAL		166
#define	YYFLAG		-32768
#define	YYNTBASE	26

#define YYTRANSLATE(x) ((unsigned)(x) <= 280 ? yytranslate[x] : 95)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25
};

#if YY_DmanParser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     6,     8,    11,    13,    14,    16,    18,    19,
    21,    23,    25,    27,    29,    31,    33,    35,    36,    41,
    43,    46,    48,    50,    52,    54,    57,    59,    62,    64,
    68,    69,    70,    76,    77,    82,    84,    86,    88,    90,
    92,    94,    96,    98,   100,   102,   105,   107,   110,   112,
   116,   117,   118,   124,   125,   130,   131,   146,   151,   152,
   158,   159,   165,   169,   173,   175,   177,   180,   183,   185,
   186,   190,   194,   196,   198,   199,   202,   209,   214,   215,
   216,   221,   224,   226,   228,   229,   232,   233,   237,   239,
   240,   244,   246,   248,   250,   253,   254,   258,   261,   264,
   266,   268,   270,   273,   274,   278,   281,   284,   286,   289,
   292
};

static const short yyrhs[] = {    60,
    65,     0,    19,    15,     0,    15,     0,    27,    15,     0,
    27,     0,     0,    19,     0,    29,     0,     0,    23,     0,
    23,     0,    24,     0,    25,     0,    29,     0,    32,     0,
    33,     0,    38,     0,     0,    18,    37,    53,    18,     0,
    31,     0,    38,    31,     0,    32,     0,    46,     0,    43,
     0,    39,     0,    40,    39,     0,    34,     0,    41,    34,
     0,    40,     0,    42,    33,    40,     0,     0,     0,    18,
    44,    41,    45,    18,     0,     0,    16,    47,    41,    17,
     0,    29,     0,    23,     0,    24,     0,    25,     0,    49,
     0,    48,     0,    49,     0,    58,     0,    55,     0,    51,
     0,    52,    51,     0,    50,     0,    53,    50,     0,    52,
     0,    54,    48,    52,     0,     0,     0,    18,    56,    53,
    57,    18,     0,     0,    16,    59,    53,    17,     0,     0,
    28,     3,    61,    29,    35,    29,    35,    30,    36,    30,
    36,    30,    36,    27,     0,    28,     3,     1,    27,     0,
     0,     5,    63,    30,    36,    27,     0,     0,     6,    64,
    30,    36,    27,     0,     5,     1,    27,     0,     6,     1,
    27,     0,    66,     0,    67,     0,    66,    67,     0,    62,
    68,     0,    77,     0,     0,    30,    42,    27,     0,    30,
     1,    27,     0,    27,     0,    69,     0,     0,    72,    69,
     0,    30,    20,    30,    54,    30,    21,     0,    30,    20,
     1,    21,     0,     0,     0,    75,    73,    76,    70,     0,
     1,    27,     0,    78,     0,    81,     0,     0,    79,    83,
     0,     0,    81,    80,    83,     0,    69,     0,     0,    77,
    82,    69,     0,    84,     0,    85,     0,    87,     0,    83,
    87,     0,     0,    84,    86,    88,     0,     7,    74,     0,
    11,    71,     0,    89,     0,    90,     0,    92,     0,    88,
    92,     0,     0,    89,    91,    93,     0,     8,    74,     0,
    12,    71,     0,    94,     0,    93,    94,     0,     9,    74,
     0,    13,    71,     0
};

#endif

#if YY_DmanParser_DEBUG != 0
static const short yyrline[] = { 0,
    62,    65,    66,    67,    70,    71,    74,    77,    78,    83,
    85,    91,    92,    95,    97,    98,   100,   102,   102,   104,
   105,   108,   109,   110,   112,   113,   115,   116,   118,   119,
   122,   122,   123,   124,   124,   127,   130,   136,   137,   139,
   140,   142,   143,   144,   147,   148,   150,   151,   153,   154,
   157,   157,   158,   159,   159,   164,   164,   165,   167,   167,
   168,   168,   169,   170,   175,   177,   178,   180,   183,   184,
   187,   188,   190,   191,   193,   194,   195,   196,   198,   198,
   199,   199,   202,   203,   205,   205,   206,   206,   208,   209,
   210,   212,   213,   215,   216,   218,   218,   220,   221,   224,
   225,   227,   228,   230,   230,   232,   233,   235,   236,   238,
   239
};

static const char * const yytname[] = {   "$","error","$illegal.","CMD_HEADER",
"CMD_BAD","CMD_SECTION","CMD_SSECTION","TOK_ITEM1","TOK_ITEM2","TOK_ITEM3","TOK_ITEM_BAD",
"TOK_INDENT1","TOK_INDENT2","TOK_INDENT3","TOK_INDENT_BAD","TOK_LF","TOK_INF",
"TOK_SUP","TOK_DQUOTE","TOK_SPACE","TOK_BEGIN","TOK_END","TOK_BAD","TOK_CHAR",
"TOK_COMPOSED2","TOK_COMPOSED1","man_page","sauts_ligne","sauts0_ligne","espaces",
"espaces0","un_char_symbol","un_char_mot","un_space_texte","un_char_texte","argument_nom",
"argument_texte","@1","symbole","un_meta_char","meta_mot","texte","texte_riche",
"texte_bold","@2","@3","texte_italique","@4","un_space_texte_quote","un_char_mot_quote",
"un_char_texte_quote","un_meta_char_quote","meta_mot_quote","texte_quote","texte_riche_quote",
"texte_bold_quote","@5","@6","texte_italique_quote","@7","header_page","@8",
"header_section","@9","@10","corps_page","liste_section","section","corps_section",
"paragraphe","paragraphe_opt","paragraphe_relatif","@11","label_item","un_item",
"@12","@13","bloc0","bloc0b","@14","@15","bloc0i","@16","bloc1","bloc1i","bloc1b",
"@17","item1","bloc2","bloc2i","bloc2b","@18","item2","bloc3","item3",""
};
#endif

static const short yyr1[] = {     0,
    26,    27,    27,    27,    28,    28,    29,    30,    30,    31,
    32,    32,    32,    33,    34,    34,    35,    37,    36,    38,
    38,    39,    39,    39,    40,    40,    41,    41,    42,    42,
    44,    45,    43,    47,    46,    48,    49,    49,    49,    50,
    50,    51,    51,    51,    52,    52,    53,    53,    54,    54,
    56,    57,    55,    59,    58,    61,    60,    60,    63,    62,
    64,    62,    62,    62,    65,    66,    66,    67,    68,    68,
    69,    69,    70,    70,    72,    71,    73,    73,    75,    76,
    74,    74,    77,    77,    79,    78,    80,    78,    81,    82,
    81,    83,    83,    84,    84,    86,    85,    87,    87,    88,
    88,    89,    89,    91,    90,    92,    92,    93,    93,    94,
    94
};

static const short yyr2[] = {     0,
     2,     2,     1,     2,     1,     0,     1,     1,     0,     1,
     1,     1,     1,     1,     1,     1,     1,     0,     4,     1,
     2,     1,     1,     1,     1,     2,     1,     2,     1,     3,
     0,     0,     5,     0,     4,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     2,     1,     2,     1,     3,
     0,     0,     5,     0,     4,     0,    14,     4,     0,     5,
     0,     5,     3,     3,     1,     1,     2,     2,     1,     0,
     3,     3,     1,     1,     0,     2,     6,     4,     0,     0,
     4,     2,     1,     1,     0,     2,     0,     3,     1,     0,
     3,     1,     1,     1,     2,     0,     3,     2,     2,     1,
     1,     1,     2,     0,     3,     2,     2,     1,     2,     2,
     2
};

static const short yydefact[] = {     6,
     3,     0,     5,     0,     0,     2,     4,     0,     0,     0,
     9,     1,    65,    66,     0,     0,     0,     9,     0,     9,
     7,     8,     0,    68,    89,    90,    83,     0,    84,    67,
    58,     0,    63,     0,    64,     0,     0,    34,    31,    11,
    12,    13,    22,    25,    29,     0,    24,    23,     9,     0,
    75,    86,    92,    93,    94,     0,    10,    20,     0,    17,
    18,     0,     0,    72,     0,     0,    26,     7,    71,    14,
     0,    91,     0,    98,     9,    99,     9,    95,     0,    88,
     0,    21,     0,    60,    62,    15,    16,    27,     0,    32,
    30,    82,     0,    80,    76,     0,    75,    97,   100,   101,
   102,     9,    37,    38,    39,    36,    41,    40,    47,     0,
    35,    28,     0,     0,     9,   106,   107,   103,     0,     0,
    19,    48,    33,     0,     0,    73,    74,    81,     0,    75,
   105,   108,     9,    78,    54,    51,    42,    45,    49,     9,
    44,    43,   110,   111,   109,     0,     0,     0,    46,    36,
     0,     0,     9,     0,    52,    77,    50,     0,    55,     0,
     0,    53,    57,     0,     0,     0
};

static const short yydefgoto[] = {   164,
     3,     4,    22,    23,    58,    43,    87,    88,    59,    62,
    83,    60,    44,    45,    89,    46,    47,    66,   113,    48,
    65,   107,   108,   109,   138,   139,   110,   140,   141,   148,
   160,   142,   147,     5,    16,    11,    18,    20,    12,    13,
    14,    24,    25,   128,    76,    77,    94,    74,    75,   115,
    26,    27,    28,    56,    29,    49,    52,    53,    54,    79,
    55,    98,    99,   100,   119,   101,   131,   132
};

static const short yypact[] = {     0,
-32768,    -1,    39,    27,    22,-32768,-32768,    19,    31,    44,
    96,-32768,    22,-32768,     0,    40,     0,    40,     0,    40,
-32768,-32768,    70,-32768,-32768,    18,-32768,    10,    57,-32768,
    39,    43,    39,    90,    39,    90,     0,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    94,    54,-32768,-32768,    40,    15,
-32768,    10,    77,-32768,-32768,    10,-32768,-32768,    40,    43,
-32768,     0,     0,    39,    59,    59,-32768,    -1,    39,-32768,
    94,-32768,     0,-32768,    40,-32768,    40,-32768,    79,    10,
    43,-32768,   142,    39,    39,-32768,-32768,-32768,   128,    59,
    94,    39,    91,-32768,-32768,    15,-32768,    79,   100,-32768,
-32768,    40,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   139,
-32768,-32768,   102,    56,    54,-32768,-32768,-32768,   112,    90,
-32768,-32768,-32768,    93,   108,    39,-32768,-32768,    15,-32768,
   112,-32768,    40,-32768,-32768,-32768,-32768,-32768,   108,    40,
-32768,-32768,-32768,-32768,-32768,    90,   142,   142,-32768,   101,
   115,   108,    40,   131,   142,-32768,   108,    90,-32768,   111,
     0,-32768,    39,   137,   138,-32768
};

static const short yypgoto[] = {-32768,
   -15,-32768,   -13,   -10,    80,   -29,    98,     9,    58,   -30,
-32768,-32768,   -40,    78,   103,-32768,-32768,-32768,-32768,-32768,
-32768,    20,  -113,   -99,  -114,     7,   -42,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   155,-32768,   -48,-32768,   -90,-32768,-32768,   -87,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   114,-32768,-32768,-32768,
   -39,-32768,-32768,-32768,-32768,    73,-32768,    41
};


#define	YYLAST		172


static const short yytable[] = {    31,
    72,    33,    32,    35,    67,    63,   117,    34,   116,    36,
   122,   137,    78,     6,     1,    73,    50,   -69,     2,    15,
    51,    64,   -69,   -69,   149,   137,     9,    10,    95,     8,
    69,    17,    70,   -79,   -79,    86,    86,   -56,   137,   144,
    78,   143,   149,   137,    19,    81,    84,    85,   -59,   -59,
    67,    70,    70,     7,   122,   122,   124,    92,    21,    86,
    86,   -61,   -61,   -87,    93,    57,   127,   -87,     1,   106,
    37,    -9,    68,    -9,    21,    70,    70,    21,    -9,    -9,
    -9,    40,    41,    42,   -96,    38,    96,    39,   -96,   133,
    97,   120,    40,    41,    42,   -70,   106,   112,   112,   126,
   -70,   -70,   -85,   125,   154,   155,   -85,    61,  -104,    38,
   114,    39,  -104,   134,    21,   153,    40,    41,    42,   123,
   129,    -8,   146,   135,   130,   136,   150,   161,   162,   151,
   103,   104,   105,   106,   106,   156,   165,   166,   102,    82,
   106,   106,   158,    71,   111,   163,    21,   159,    91,    21,
    40,    41,    42,   103,   104,   105,   121,    21,   157,   152,
    21,   103,   104,   105,   103,   104,   105,    30,    90,    80,
   118,   145
};

static const short yycheck[] = {    15,
    49,    17,    16,    19,    45,    36,    97,    18,    96,    20,
   110,   125,    52,    15,    15,     1,     7,     0,    19,     1,
    11,    37,     5,     6,   139,   139,     5,     6,    77,     3,
    46,     1,    46,    19,    20,    65,    66,    19,   152,   130,
    80,   129,   157,   157,     1,    59,    62,    63,    18,    19,
    91,    65,    66,    15,   154,   155,     1,    73,    19,    89,
    90,    18,    19,     7,    75,    23,   115,    11,    15,    83,
     1,    16,    19,    18,    19,    89,    90,    19,    23,    24,
    25,    23,    24,    25,     8,    16,     8,    18,    12,   120,
    12,   102,    23,    24,    25,     0,   110,    89,    90,   115,
     5,     6,     7,   114,   147,   148,    11,    18,     9,    16,
    20,    18,    13,    21,    19,   146,    23,    24,    25,    18,
     9,    21,   133,    16,    13,    18,   140,   158,    18,   140,
    23,    24,    25,   147,   148,    21,     0,     0,    81,    60,
   154,   155,   153,    46,    17,   161,    19,    17,    71,    19,
    23,    24,    25,    23,    24,    25,    18,    19,   152,   140,
    19,    23,    24,    25,    23,    24,    25,    13,    66,    56,
    98,   131
};

#line 329 "/u/icdc/rdt/tools/lib/bison.cc"
 /* fattrs + tables */

/* parser code folow  */


/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: dollar marks section change
   the next  is replaced by the list of actions, each action
   as one case of the switch.  */ 

#if YY_DmanParser_USE_GOTO != 0
/* 
 SUPRESSION OF GOTO : on some C++ compiler (sun c++)
  the goto is strictly forbidden if any constructor/destructor
  is used in the whole function (very stupid isn't it ?)
 so goto are to be replaced with a 'while/switch/case construct'
 here are the macro to keep some apparent compatibility
*/
#define YYGOTO(lb) {yy_gotostate=lb;continue;}
#define YYBEGINGOTO  enum yy_labels yy_gotostate=yygotostart; \
                     for(;;) switch(yy_gotostate) { case yygotostart: {
#define YYLABEL(lb) } case lb: {
#define YYENDGOTO } } 
#define YYBEGINDECLARELABEL enum yy_labels {yygotostart
#define YYDECLARELABEL(lb) ,lb
#define YYENDDECLARELABEL  };
#else
/* macro to keep goto */
#define YYGOTO(lb) goto lb
#define YYBEGINGOTO 
#define YYLABEL(lb) lb:
#define YYENDGOTO
#define YYBEGINDECLARELABEL 
#define YYDECLARELABEL(lb)
#define YYENDDECLARELABEL 
#endif
/* LABEL DECLARATION */
YYBEGINDECLARELABEL
  YYDECLARELABEL(yynewstate)
  YYDECLARELABEL(yybackup)
/* YYDECLARELABEL(yyresume) */
  YYDECLARELABEL(yydefault)
  YYDECLARELABEL(yyreduce)
  YYDECLARELABEL(yyerrlab)   /* here on detecting error */
  YYDECLARELABEL(yyerrlab1)   /* here on error raised explicitly by an action */
  YYDECLARELABEL(yyerrdefault)  /* current state does not do anything special for the error token. */
  YYDECLARELABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */
  YYDECLARELABEL(yyerrhandle)  
YYENDDECLARELABEL

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (YY_DmanParser_CHAR = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        return(0)
#define YYABORT         return(1)
#define YYERROR         YYGOTO(yyerrlab1)
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          YYGOTO(yyerrlab)
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (YY_DmanParser_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_DmanParser_CHAR = (token), YY_DmanParser_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_DmanParser_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_DmanParser_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_DmanParser_PURE
/* UNPURE */
#define YYLEX           YY_DmanParser_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_DmanParser_CHAR;                      /*  the lookahead symbol        */
YY_DmanParser_STYPE      YY_DmanParser_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_DmanParser_NERRS;                 /*  number of parse errors so far */
#ifdef YY_DmanParser_LSP_NEEDED
YY_DmanParser_LTYPE YY_DmanParser_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_DmanParser_LSP_NEEDED
#define YYLEX           YY_DmanParser_LEX(&YY_DmanParser_LVAL, &YY_DmanParser_LLOC)
#else
#define YYLEX           YY_DmanParser_LEX(&YY_DmanParser_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_DmanParser_DEBUG != 0
int YY_DmanParser_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif
#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif


#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)       __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */

#ifdef __cplusplus
static void __yy_bcopy (char *from, char *to, int count)
#else
#ifdef __STDC__
static void __yy_bcopy (char *from, char *to, int count)
#else
static void __yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
#endif
#endif
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}
#endif

int
#ifdef YY_USE_CLASS
 YY_DmanParser_CLASS::
#endif
     YY_DmanParser_PARSE(YY_DmanParser_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_DmanParser_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_DmanParser_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_DmanParser_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_DmanParser_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_DmanParser_LSP_NEEDED
  YY_DmanParser_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_DmanParser_LTYPE *yyls = yylsa;
  YY_DmanParser_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_DmanParser_PURE
  int YY_DmanParser_CHAR;
  YY_DmanParser_STYPE YY_DmanParser_LVAL;
  int YY_DmanParser_NERRS;
#ifdef YY_DmanParser_LSP_NEEDED
  YY_DmanParser_LTYPE YY_DmanParser_LLOC;
#endif
#endif

  YY_DmanParser_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_DmanParser_DEBUG != 0
  if (YY_DmanParser_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_DmanParser_NERRS = 0;
  YY_DmanParser_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_DmanParser_LSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
YYLABEL(yynewstate)

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YY_DmanParser_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_DmanParser_LSP_NEEDED
      YY_DmanParser_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_DmanParser_LSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YY_DmanParser_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_DmanParser_ERROR("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YY_DmanParser_STYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YY_DmanParser_LSP_NEEDED
      yyls = (YY_DmanParser_LTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_DmanParser_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_DmanParser_DEBUG != 0
      if (YY_DmanParser_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_DmanParser_DEBUG != 0
  if (YY_DmanParser_DEBUG_FLAG)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  YYGOTO(yybackup);
YYLABEL(yybackup)

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* YYLABEL(yyresume) */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yydefault);

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (YY_DmanParser_CHAR == YYEMPTY)
    {
#if YY_DmanParser_DEBUG != 0
      if (YY_DmanParser_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_DmanParser_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_DmanParser_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_DmanParser_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_DmanParser_DEBUG != 0
      if (YY_DmanParser_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_DmanParser_CHAR);

#if YY_DmanParser_DEBUG != 0
      if (YY_DmanParser_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_DmanParser_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_DmanParser_CHAR, YY_DmanParser_LVAL);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    YYGOTO(yydefault);

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrlab);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrlab);

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YY_DmanParser_DEBUG != 0
  if (YY_DmanParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_DmanParser_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_DmanParser_CHAR != YYEOF)
    YY_DmanParser_CHAR = YYEMPTY;

  *++yyvsp = YY_DmanParser_LVAL;
#ifdef YY_DmanParser_LSP_NEEDED
  *++yylsp = YY_DmanParser_LLOC;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  YYGOTO(yynewstate);

/* Do the default action for the current state.  */
YYLABEL(yydefault)

  yyn = yydefact[yystate];
  if (yyn == 0)
    YYGOTO(yyerrlab);

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
YYLABEL(yyreduce)
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YY_DmanParser_DEBUG != 0
  if (YY_DmanParser_DEBUG_FLAG)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


/* #line 783 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 1234 "dmanParser.cc"

  switch (yyn) {

case 10:
#line 83 "dmanParser.y"
{printf("%c",yyvsp[0].theChar);;
    break;}
case 11:
#line 85 "dmanParser.y"
{switch(yyvsp[0].theChar) 
                             {case '.': case '-': case ' ': printf("\\%c",yyvsp[0].theChar); break;
			      case '"': printf("\"");break;
			      case '\\': printf("\\e");break;
                              default:printf("%c",yyvsp[0].theChar);}
                           ;
    break;}
case 12:
#line 91 "dmanParser.y"
{printf("%c\\*%s",yyvsp[0].theString[0], &yyvsp[0].theString[1]);;
    break;}
case 13:
#line 92 "dmanParser.y"
{printf("\\%s",yyvsp[0].theString);;
    break;}
case 14:
#line 95 "dmanParser.y"
{printf(" ");;
    break;}
case 17:
#line 100 "dmanParser.y"
{printf(" ");;
    break;}
case 18:
#line 102 "dmanParser.y"
{printf("\"");;
    break;}
case 19:
#line 102 "dmanParser.y"
{printf("\" ");;
    break;}
case 31:
#line 122 "dmanParser.y"
{printf("\\fB");;
    break;}
case 32:
#line 122 "dmanParser.y"
{printf("\\fP");;
    break;}
case 34:
#line 124 "dmanParser.y"
{printf("\\fI");;
    break;}
case 35:
#line 124 "dmanParser.y"
{printf("\\fP");;
    break;}
case 36:
#line 127 "dmanParser.y"
{printf(" ");;
    break;}
case 37:
#line 130 "dmanParser.y"
{switch(yyvsp[0].theChar) 
                             {case '\\':   printf("\\\\e"); break;
			      case '"': printf("\"\"");break;
			      case '-': case '.': case ' ': printf("\\\\%c",yyvsp[0].theChar);break;
                              default:printf("%c",yyvsp[0].theChar);}
                           ;
    break;}
case 38:
#line 136 "dmanParser.y"
{printf("%c\\\\*%s",yyvsp[0].theString[0], &yyvsp[0].theString[1]);;
    break;}
case 39:
#line 137 "dmanParser.y"
{printf("\\\\%s",yyvsp[0].theString);;
    break;}
case 51:
#line 157 "dmanParser.y"
{printf("\\\\fB");;
    break;}
case 52:
#line 157 "dmanParser.y"
{printf("\\\\fP");;
    break;}
case 54:
#line 159 "dmanParser.y"
{printf("\\\\fI");;
    break;}
case 55:
#line 159 "dmanParser.y"
{printf("\\\\fP");;
    break;}
case 56:
#line 164 "dmanParser.y"
{printf(".TH ");;
    break;}
case 57:
#line 164 "dmanParser.y"
{printf("\n");;
    break;}
case 58:
#line 165 "dmanParser.y"
{printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,":HEADER badly formed!\n");;
    break;}
case 59:
#line 167 "dmanParser.y"
{printf(".SH ");;
    break;}
case 60:
#line 167 "dmanParser.y"
{printf("\n");;
    break;}
case 61:
#line 168 "dmanParser.y"
{printf(".SS ");;
    break;}
case 62:
#line 168 "dmanParser.y"
{printf("\n");;
    break;}
case 63:
#line 169 "dmanParser.y"
{printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,":SECTION badly formed!\n");;
    break;}
case 64:
#line 170 "dmanParser.y"
{printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,":SSECTION badly formed!\n");;
    break;}
case 71:
#line 187 "dmanParser.y"
{printf("\n");;
    break;}
case 72:
#line 188 "dmanParser.y"
{printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,"Paragraph badly formed!\n");;
    break;}
case 75:
#line 193 "dmanParser.y"
{printf(".IP\n");;
    break;}
case 78:
#line 196 "dmanParser.y"
{printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,"Label badly formed!\n");;
    break;}
case 79:
#line 198 "dmanParser.y"
{printf(".IP \"");;
    break;}
case 80:
#line 198 "dmanParser.y"
{printf("\"\n");;
    break;}
case 82:
#line 199 "dmanParser.y"
{printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,"Labeled paragraph badly formed!\n");;
    break;}
case 85:
#line 205 "dmanParser.y"
{printf(".\\\"bloc1[\n");;
    break;}
case 86:
#line 205 "dmanParser.y"
{printf(".\\\"bloc1]\n");;
    break;}
case 87:
#line 206 "dmanParser.y"
{printf(".\\\"bloc1[\n");;
    break;}
case 88:
#line 206 "dmanParser.y"
{printf(".\\\"bloc1]\n");;
    break;}
case 90:
#line 209 "dmanParser.y"
{printf(".PP\n");;
    break;}
case 96:
#line 218 "dmanParser.y"
{printf(".RS\n.\\\"bloc2[\n");;
    break;}
case 97:
#line 218 "dmanParser.y"
{printf(".RE\n.\\\"bloc2]\n");;
    break;}
case 104:
#line 230 "dmanParser.y"
{printf(".RS\n.\\\"bloc3[\n");;
    break;}
case 105:
#line 230 "dmanParser.y"
{printf(".RE\n.\\\"bloc3]\n");;
    break;}
}

#line 783 "/u/icdc/rdt/tools/lib/bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_DmanParser_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_DmanParser_DEBUG != 0
  if (YY_DmanParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_DmanParser_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_DmanParser_LLOC.first_line;
      yylsp->first_column = YY_DmanParser_LLOC.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  YYGOTO(yynewstate);

YYLABEL(yyerrlab)   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++YY_DmanParser_NERRS;

#ifdef YY_DmanParser_ERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      YY_DmanParser_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_DmanParser_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_DmanParser_ERROR_VERBOSE */
	YY_DmanParser_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_DmanParser_CHAR == YYEOF)
	YYABORT;

#if YY_DmanParser_DEBUG != 0
      if (YY_DmanParser_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_DmanParser_CHAR, yytname[yychar1]);
#endif

      YY_DmanParser_CHAR = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  YYGOTO(yyerrhandle);

YYLABEL(yyerrdefault)  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) YYGOTO(yydefault);
#endif

YYLABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YY_DmanParser_LSP_NEEDED
  yylsp--;
#endif

#if YY_DmanParser_DEBUG != 0
  if (YY_DmanParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

YYLABEL(yyerrhandle)

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yyerrdefault);

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    YYGOTO(yyerrdefault);

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrpop);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrpop);

  if (yyn == YYFINAL)
    YYACCEPT;

#if YY_DmanParser_DEBUG != 0
  if (YY_DmanParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_DmanParser_LVAL;
#ifdef YY_DmanParser_LSP_NEEDED
  *++yylsp = YY_DmanParser_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

/* #line 982 "/u/icdc/rdt/tools/lib/bison.cc" */
#line 1632 "dmanParser.cc"
#line 242 "dmanParser.y"

/* -------------- body section -------------- */
