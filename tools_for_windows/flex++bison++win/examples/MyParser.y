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

%name MyParser
%define LSP_NEEDED
%define ERROR_BODY =0
%define LEX_BODY =0
%header{
#include <stdio.h>
%}

%union {
	int itype;	/* for count */
	char ctype;	/* for char */
	}
%token <ctype> EOL_TOKEN CHAR_TOKEN
%type <itype> file line lines chars
%start file

/* -------------- rules section -------------- */
/* Sample parser. Does count Chars in a line, and lines in file */
%%
file	: lines
	{printf("nlines=%d\n",$1); /* show line count */}
	;
lines 	: line {$$=1; /* first line of all */}
	| lines line {$$=$1+1;	/* count one more line */}
	;
line 	: chars EOL_TOKEN {$$=$1;printf("nchars=%d\n",$1); /* show char count */}
	;
chars	: CHAR_TOKEN { $$=1;/* first char of line */}
	| chars CHAR_TOKEN {$$=$1+1; /* count one more char */}
	;
%%
/* -------------- body section -------------- */
