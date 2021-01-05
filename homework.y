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

%type <intnode> ID 

%left EQ NEQ LWR GTR LEQ GEQ
%left PLUS MINUS
%left MTP DVD MOD
%left AND 
%left OR

%%

progr   :   glb_declarations main_body  {printf("\n Program corect\n");}
        | ;

glb_declarations    : glb_declarations var_decl 
                |  glb_declarations fct_decl
                | ;

var_decl    :   INT variable_list
            | BOOL variable_list
            | STRING variable_list;

variable_list : variable_list ',' ID
              | ID {printf("%s declared\n",$1);}
              | variable_list ',' ID ASGN expression
              | ID ASGN expression 

fct_decl    :   INT ID {printf("Function %s declared! \n",$2);} 
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

statement   :   expression
            |   ID ASGN expression
            |   control
			|   var_decl 
            |   print_call;

expression : INTVAL 
           | ID 
           | expression PLUS expression
           | expression MINUS expression
           | expression MTP expression
           | expression DVD expression
           | expression MOD expression
           | '(' expression ')'
           | binary_expression 
           | fct_call ;

binary_expression : expression LWR expression 
                | expression GTR expression
                | expression LEQ expression 
                | expression GEQ expression 
                | expression NEQ expression 
                | expression EQ expression 
                | expression AND expression 
                | expression OR expression ; 

fct_call : ID '('{printf("Function called");} param_called_list ')'
         | ID '(' ')' ;

param_called_list : param_called_list ',' expression
                  | expression ;



control : WHILE {printf("While called\n");} '(' binary_expression ')' body ENDWHILE 
        | IF {printf("If called\n");} '(' binary_expression ')' body ENDIF

print_call   :   PRINT'(' expression ')'{printf("PRINT CALLED\n");};

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
