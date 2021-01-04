%{ 
#include <stdio.h>
#include "homework.tab.h"
#include <stdlib.h>
%}

id [_A-Za-z][_A-Za-z0-9]*
nr (-?[1-9][0-9]*)|0
str [a-zA-Z]+

%option noyywrap
%%

"int" {return INT;}
"float" {return FLOAT;}
"char" {return CHAR;}
"string" {return STRING;}
"bool" {return BOOL;}
id {strcpy(yylval.intnode.name,strdup(yytext)); return ID;}
"beginm" {return BEGIN_P;}
"endm" {return END_P;}
"if" {return IF;}
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
nr {yylval.intval=atoi(yytext); return INTVAL;}
str {yylval.strval=strdup(yytext); yylval.strval[strlen(yylval.strval)-1]='\0'; return STRVAL;}
"true"|"false" {if(strcmp(yytext,"true")==0)yylval.boolval=1; else yylval.boolval=0; return BOOLVAL;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}


