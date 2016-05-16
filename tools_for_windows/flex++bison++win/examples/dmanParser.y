/* @(#) dmanParser.y YaccSource asterisk 1.14 93/07/05 16:13:06 (SCCS/s.dmanParser.y) */
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
%name DmanParser
%union {
	char theChar;
	char *theString;
	}
%header{
typedef YY_DmanParser_STYPE TokenValue;
typedef
  struct
    { int first_line,last_line,first_column,last_column;
      char *text;
    } TokenLocation;
%}
%{
static char SccsId[]="@(#) dmanParser.y YaccSource asterisk 1.14 93/07/05 16:13:06 (SCCS/s.dmanParser.y)";
%}
%define LSP_NEEDED
%define DEBUG 1
%define LTYPE TokenLocation
%define LLOC theTokenLocation
%define LVAL theTokenValue
%define LEX Scan
%define LEX_BODY =0
%define ERROR_BODY =0
%define ERROR PrintError
%define NERRS errorCount
%define DEBUG_FLAG debugFlag
%define MEMBERS  
%define PARSE Parse 
%define PARSE_PARAM 
%define CONSTRUCTOR_PARAM 
%define CONSTRUCTOR_INIT 
%define CONSTRUCTOR_CODE 

%start man_page
%token CMD_HEADER  CMD_BAD CMD_SECTION CMD_SSECTION
%token TOK_ITEM1 TOK_ITEM2 TOK_ITEM3 TOK_ITEM_BAD
%token TOK_INDENT1 TOK_INDENT2 TOK_INDENT3 TOK_INDENT_BAD
%token TOK_LF TOK_INF TOK_SUP TOK_DQUOTE TOK_SPACE TOK_BEGIN TOK_END
%token TOK_BAD
%token <theChar> TOK_CHAR 
%token <theString> TOK_COMPOSED2 TOK_COMPOSED1
	/* -------------- rules section -------------- */
%%
man_page	: header_page  corps_page 
		;
/* SAUTS DE LIGNE , ESPACES */
sauts_ligne	:	TOK_SPACE TOK_LF
		|	TOK_LF
		|	sauts_ligne TOK_LF
		;

sauts0_ligne	:	sauts_ligne
		|
		;

espaces		: TOK_SPACE
		;

espaces0	: espaces
		|
		;

/* textes */

un_char_symbol	: TOK_CHAR {printf("%c",$<theChar>1);}
		;
un_char_mot	:TOK_CHAR {switch($<theChar>1) 
                             {case '.': case '-': case ' ': printf("\\%c",$<theChar>1); break;
			      case '"': printf("\"");break;
			      case '\\': printf("\\e");break;
                              default:printf("%c",$<theChar>1);}
                           }
		| TOK_COMPOSED2 {printf("%c\\*%s",$<theString>1[0], &$<theString>1[1]);}
		| TOK_COMPOSED1 {printf("\\%s",$<theString>1);}
		;

un_space_texte	: espaces {printf(" ");}
		;
un_char_texte	: un_char_mot
		| un_space_texte
		;
argument_nom	: symbole {printf(" ");}
		;
argument_texte	:  TOK_DQUOTE {printf("\"");} texte_quote TOK_DQUOTE {printf("\" ");}
		;
symbole		: un_char_symbol
		| symbole un_char_symbol
		;
/* texte normal */
un_meta_char : un_char_mot
		| texte_italique
		| texte_bold
		;
meta_mot	:  un_meta_char
		| meta_mot un_meta_char
		;
texte		: un_char_texte
		| texte un_char_texte
		;
texte_riche	: meta_mot
		| texte_riche un_space_texte meta_mot
		;

texte_bold	: TOK_DQUOTE {printf("\\fB");} texte {printf("\\fP");} TOK_DQUOTE
		;
texte_italique	: TOK_INF {printf("\\fI");} texte TOK_SUP {printf("\\fP");}
		;
/* texte quote */
un_space_texte_quote : espaces {printf(" ");}
		;
		
un_char_mot_quote	: TOK_CHAR {switch($<theChar>1) 
                             {case '\\':   printf("\\\\e"); break;
			      case '"': printf("\"\"");break;
			      case '-': case '.': case ' ': printf("\\\\%c",$<theChar>1);break;
                              default:printf("%c",$<theChar>1);}
                           }
		| TOK_COMPOSED2 {printf("%c\\\\*%s",$<theString>1[0], &$<theString>1[1]);}
		| TOK_COMPOSED1 {printf("\\\\%s",$<theString>1);}
		;
un_char_texte_quote : un_char_mot_quote
		| un_space_texte_quote
		;
un_meta_char_quote : un_char_mot_quote
		| texte_italique_quote
		| texte_bold_quote
		;

meta_mot_quote	:  un_meta_char_quote
		| meta_mot_quote un_meta_char_quote
		;
texte_quote	: un_char_texte_quote
		| texte_quote un_char_texte_quote
		;
texte_riche_quote	: meta_mot_quote
		| texte_riche_quote un_space_texte_quote meta_mot_quote
		;

texte_bold_quote	: TOK_DQUOTE {printf("\\\\fB");} texte_quote {printf("\\\\fP");} TOK_DQUOTE
		;
texte_italique_quote	: TOK_INF {printf("\\\\fI");} texte_quote TOK_SUP {printf("\\\\fP");}
		;
		

/* HEADER */
header_page	: sauts0_ligne  CMD_HEADER {printf(".TH ");} espaces argument_nom espaces argument_nom espaces0 argument_texte espaces0 argument_texte espaces0 argument_texte sauts_ligne {printf("\n");}
		| sauts0_ligne  CMD_HEADER error sauts_ligne {printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,":HEADER badly formed!\n");}
		;
header_section	: CMD_SECTION {printf(".SH ");}  espaces0 argument_texte sauts_ligne {printf("\n");}
		| CMD_SSECTION {printf(".SS ");}  espaces0 argument_texte sauts_ligne {printf("\n");}
		| CMD_SECTION error sauts_ligne {printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,":SECTION badly formed!\n");}
		| CMD_SSECTION error sauts_ligne {printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,":SSECTION badly formed!\n");}
		;

/* DOCUMENT */

corps_page	: liste_section
		;
liste_section	: section
		| liste_section section
		;
section : header_section corps_section
		;

corps_section	: bloc0
		|
		;

paragraphe	:  espaces0   texte_riche sauts_ligne {printf("\n");}
		|  espaces0 error sauts_ligne {printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,"Paragraph badly formed!\n");}
		;
paragraphe_opt  :   sauts_ligne
		|  paragraphe
		;
paragraphe_relatif : {printf(".IP\n");}  paragraphe  
		;
label_item	: espaces0  TOK_BEGIN espaces0 texte_riche_quote espaces0 TOK_END
		| espaces0  TOK_BEGIN error TOK_END {printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,"Label badly formed!\n");}
		;
un_item		: {printf(".IP \"");} label_item {printf("\"\n");} paragraphe_opt
		| error sauts_ligne {printf("\n.\\\"ERROR\n");yyerrok;fprintf(stderr,"Labeled paragraph badly formed!\n");}
		;

bloc0		: bloc0b
		| bloc0i
		;
bloc0b		:  {printf(".\\\"bloc1[\n");} bloc1 {printf(".\\\"bloc1]\n");}
		| bloc0i {printf(".\\\"bloc1[\n");} bloc1 {printf(".\\\"bloc1]\n");}
		;
bloc0i		: paragraphe
		| bloc0  {printf(".PP\n");} paragraphe
		;

bloc1		: bloc1i
		| bloc1b
		;
bloc1i		: item1
		| bloc1 item1
		;
bloc1b		: bloc1i {printf(".RS\n.\\\"bloc2[\n");} bloc2 {printf(".RE\n.\\\"bloc2]\n");}
		;
item1		: TOK_ITEM1     un_item   
		| TOK_INDENT1 paragraphe_relatif
		;

bloc2		: bloc2i
		| bloc2b
		;
bloc2i		: item2
		| bloc2 item2
		;
bloc2b		: bloc2i {printf(".RS\n.\\\"bloc3[\n");} bloc3 {printf(".RE\n.\\\"bloc3]\n");}
		;
item2		: TOK_ITEM2 un_item
		| TOK_INDENT2 paragraphe_relatif
		;
bloc3		: item3
		| bloc3 item3
		;
item3		: TOK_ITEM3 un_item
		| TOK_INDENT3 paragraphe_relatif
		;

%%
/* -------------- body section -------------- */
