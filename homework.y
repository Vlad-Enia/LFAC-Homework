%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
extern FILE* yyin;
extern int yylineno;
extern char* yytext;
%}
%union{ int intval; char* strval; int boolval;}

%token INT FLOAT CHAR STRING BOOL 
%token ID
%token BEGIN END 
%token IF ENDIF ELSE FOR ENDFOR WHILE ENDWHILE
%token FBEGIN FEND
%token LWR LEQ GTR GEQ EQ NEQ 
%token PLUS MINUS MTP DVD MOD
%token AND OR
%token PRINT
%token ASGN
%token <strval> STRVAL 
%token <intval> INTVAL 
%token <boolval> BOOLVAL 
%token control fct_call

%right '='
%left '+' '-'
%left '*' '/' '%'
%left AND 
%left OR

%start progr

%%

progr   :   declarations main_body  {print("\n Program corect\n");};

declarations    :   declaratie
                |   declarations declaratie;

declaratie  :   vars_decl
            |   fct_decl;

vars_decl   :   var_decl
            |   vars_decl ',' var_decl;

var_decl    :   INT ID 
            |   BOOL ID  
            |   STRING ID  ;

fct_decl    :   INT ID '(' param_list ')' FBEGIN body FEND              
            |   BOOL ID '(' param_list ')' FBEGIN body FEND             
            |   STRING ID '(' param_list ')' FBEGIN body FEND;

param_list  :   
            |   param
            |   param_list ',' param;

param   :   INT ID 
        |   BOOL ID  
        |   STRING ID  ;

main_body   : BEGIN body END;

body    :   statement
        |   body statement;

statement   :   assign
            |   control 
            |   fct_call 
            |   print_call;

print_call   :   PRINT'(' ID ')';

assign  :   ID ASGN INTVAL  
        |   ID ASGN BOOLVAL 
        |   ID ASGN STRVAL;


%%
int yyerror(char * s)
{
    printf("eroare: %s la linia:%d\n",s,yylineno);
    return 0;
}
int main(int argc,char** argv)
{
    yyin = fopen(argv[1],"r");
    yyparse();
}