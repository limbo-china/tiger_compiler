/* %Z% %M% %Y% %Q% %I% %E% %U% (%F%) */
/*
 * Nom du Fichier : 	|>nom_fichier<|
 * Titre : 		|>Titre<|
 * Auteur:		|>auteur<|		
 * Date de creation :	|>dateCreation<|
 */
/* Description :
 *	Document de reference : |>doc<|
 *	Objet : |>objet<|
 *
 */
/* 
 * historique :
 * |>date<|	|>auteur<|	|>objet<|
 */
/* -------------- declaration section -------------- */
%name MyScanner
%define IOSTREAM
%define LEX_PARAM YY_MyParser_STYPE *val,YY_MyParser_LTYPE *loc
%define MEMBERS public: int theLine,theColumn;
%define CONSTRUCTOR_INIT : theLine(1),theColumn(1)
%header{ 
#include "MyParserIOS.h"
%}

%{
static char SccsId[]="%Z% %M% %Y% %Q% %I% %E% %U% (%F%)";
%}

/* -------------- rules section -------------- */
SPACES [ \t]+
%%
"\n"	{val->ctype='\n';
         theLine++;theColumn=1;
         return MyParser::EOL_TOKEN; }
.	{
         val->ctype=yytext[0];
         theColumn++;
         return MyParser::CHAR_TOKEN; }
<<EOF>> { yyterminate();}
%%
