%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
extern FILE* yyin;
extern int yylineno;
extern char* yytext;
%}

%union {
int intval;
double floatval;
char* strval;
int boolval;
struct  IND
{
	char name[100];
	int val;
} intnode;

}

%start progr
%token INT FLOAT CHAR STRING BOOL 
%token ID
%token BEGIN_P END_P
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
%token fct_call

%type <intnode> ID 

%right '='
%left '+' '-'
%left '*' '/' '%'
%left AND 
%left OR

%%

progr   :   declarations main_body  {printf("\n Program corect\n");}
        |       ;

declarations    :   declaratie 
                |   declarations declaratie;

declaratie  :   var_decl 
            |   fct_decl ;

var_decl    :   var_decl ',' var_decl 
			|   INT assign
			|   INT ID {printf("Variable int declaration %s\n",$2);}
            |   BOOL ID  
            |   STRING ID;

fct_decl    :   INT ID {printf("Int function %s declaration! \n",$2);} 
				'(' param_list ')' FBEGIN body FEND              
            |   BOOL ID '(' param_list ')' FBEGIN body FEND             
            |   STRING ID '(' param_list ')' FBEGIN body FEND;

param_list  :   
            |   param
            |   param_list ',' param;

param   :   INT ID {printf("Parameter int declaration %s\n",$2);}
        |   BOOL ID  
        |   STRING ID  ;

main_body   : BEGIN_P body END_P
            |   ;

body    :
		|   statement
        |   body statement;

statement   :   assign
            |   control
			|  var_decl 
            |   fct_call 
            |   print_call;

control: WHILE {printf("While called\n");} '(' statement ')' body ENDWHILE 

print_call   :   PRINT'(' ID ')'{printf("PRINT CALLED\n");};

assign  :   ID ASGN INTVAL {printf("Value assignation %s\n",$1);} 
        |   ID ASGN BOOLVAL 
        |   ID ASGN STRVAL
		| 	ID ASGN ID {printf("Value of another declared data assignated\n");};

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
	exit(0);
}