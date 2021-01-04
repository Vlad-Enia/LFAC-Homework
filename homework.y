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

struct  SND
{
	char name[100];
	char val[100];
} stringnode;

struct  FND
{
	char name[100];
	double val;
} floatnode;

struct BND
{
	char name[100];
	int val;
} boolnode;

struct 
{
	char name[100];
	int nr_inodes;
	int nr_snodes;
	int nr_fnodes;
	int nr_bnodes;
	struct IND intnodes[10];
	struct SND stringnodes[10];
	struct BND boolnodes[10];
	struct FND floatnodes[10];
} intfuncnode;

struct 
{
	char name[100];
	int nr_inodes;
	int nr_snodes;
	int nr_fnodes;
	int nr_bnodes;
	struct IND intnodes[10];
	struct SND stringnodes[10];
	struct BND boolnodes[10];
	struct FND floatnodes[10];
}stringfuncnode;

struct 
{
	char name[100];
	int nr_inodes;
	int nr_snodes;
	int nr_fnodes;
	int nr_bnodes;
	struct IND intnodes[10];
	struct SND stringnodes[10];
	struct BND boolnodes[10];
	struct FND floatnodes[10];
}floatfuncnode;

struct 
{
	char name[100];
	int nr_inodes;
	int nr_snodes;
	int nr_fnodes;
	int nr_bnodes;
	struct IND intnodes[10];
	struct SND stringnodes[10];
	struct BND boolnodes[10];
	struct FND floatnodes[10];
}boolfuncnode;
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
%token control fct_call

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
                |   declarations declaratie
                |       ;

declaratie  :   vars_decl {printf("\n declaratie \n");}
            |   fct_decl;

vars_decl   :   var_decl
            |   vars_decl ',' var_decl;

var_decl    :   INT ID {printf("decl var \n");}
            |   BOOL ID  
            |   STRING ID
            |;

fct_decl    :   INT ID '(' param_list ')' FBEGIN body FEND              
            |   BOOL ID '(' param_list ')' FBEGIN body FEND             
            |   STRING ID '(' param_list ')' FBEGIN body FEND;

param_list  :   
            |   param
            |   param_list ',' param;

param   :   INT ID 
        |   BOOL ID  
        |   STRING ID  ;

main_body   : BEGIN_P body END_P
            |   ;

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