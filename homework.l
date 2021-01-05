%{ 
#include <stdio.h>
#include "homework.tab.h"
#include <stdlib.h>
%}

%option noyywrap
%%

"int" {return INT;}
"float" {return FLOAT;}
"char" {return CHAR;}
"string" {return STRING;}
"bool" {return BOOL;}
"begin" {return BEGIN_P;}
"end" {return END_P;}
"eif" {return ELSE_IF;}
"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"endif" {return ENDIF;}
"for" {return FOR;}
"endfor" {return ENDFOR;}
"while" {return WHILE;}
"endwhile" {return ENDWHILE;}
"fbegin" {return FBEGIN;}
"fend" {return FEND;}
"print" {return PRINT;}
"<" {return LWR;}
"<=" {return LEQ;}
">" {return GTR;}
">=" {return GEQ;}
"==" {return EQ;}
"!=" {return NEQ;}
"=" {yylval.strval=strdup(yytext); return ASGN;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MTP;}
"/" {return DVD;}
"%" {return MOD;}
"||" {return OR;}
"&&" {return AND;}
[0-9]+ {yylval.intval=atoi(yytext); return INTVAL;}

"true"|"false" {if(strcmp(yytext,"true")==0)yylval.boolval=1; else yylval.boolval=0; return BOOLVAL;}
[_a-zA-Z][_a-zA-Z0-9]* {strcpy(yylval.intnode.name,strdup(yytext)); return ID;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
