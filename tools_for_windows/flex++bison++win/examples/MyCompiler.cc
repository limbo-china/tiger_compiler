static char SccsId[]="%Z% %M% %Y% %Q% %I% %E% %U% (%F%)";
//
// Nom du Fichier : 	|>nom_fichier<|
// Titre : 		|>Titre<|
// Auteur:		|>auteur<|		
// Date de creation :	|>dateCreation<|
//
// Description :
//	Document de reference : |>doc<|
//	Objet : |>objet<|
//
//
// 
// historique :
// |>date<|	|>auteur<|	|>objet<|
//
#include "MyScanner.h"
#include "MyParser.h"

class MyCompiler : public MyParser
{private:
 MyScanner theScanner;
 public:
 virtual int yylex();
 virtual void yyerror(char *m);
 MyCompiler() 
  {};
};

int MyCompiler::yylex()
{
 yylloc.first_line=theScanner.theLine;
 yylloc.first_column=theScanner.theColumn;
 int token=theScanner.yylex(&yylval,&yylloc);
 yylloc.last_line=theScanner.theLine;
 yylloc.last_column=theScanner.theColumn;
 yylloc.text=(char *)theScanner.yytext;
 return token;
}

void MyCompiler::yyerror(char *m)
{ fprintf(stderr,"%d: %s at token '%s'\n",yylloc.first_line, m,yylloc.text);
}

int main(int argc,char **argv)
{
 MyCompiler aCompiler;
 int result=aCompiler.yyparse();
 printf("Resultat Parsing=%s\n",result?"Erreur":"OK");
 return 0;
};

