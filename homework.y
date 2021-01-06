%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
extern FILE* yyin;
extern int yylineno;
extern char* yytext;
//char* tab = char* malloc(1);
char tab[100];

struct var_data
{
        char name[100];
        char val[100];          //valoare numerica convertita in char;
        char vartype[6];
        char scope[30];        //global, main, sau numele functiei/clasei in care a fost declarata;

};

struct fct_data
{
        char name[100];
        int nr_param;
        struct var_data parameters[10];   //signature;
        struct var_data variables[50];    //all the other variables declare within the function;
};

struct var_data table[100];
int i=0;

void print_table()
{
        for(int j=0;j<i;j++)
                printf("in tabel: %s %s %s\n",table[j].name,table[j].vartype,table[j].scope);
}
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


%token INT FLOAT CHAR STRING BOOL 
%token ID
%token BEGIN_P END_P
%token STRUC STRUCEND
%token CLAS CLASEND PUBLIC PRIVATE PROTECTED
%token IF THEN ELSE_IF ENDIF ELSE FOR ENDFOR WHILE ENDWHILE
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
%type <intnode> fct_call

%left AND OR
%left EQ NEQ LWR GTR LEQ GEQ
%left PLUS MINUS
%left MTP DVD MOD

%start program
%%



program     :   glb_declarations main_body  {printf("\n Program corect \n"); print_table();}
            ;

glb_declarations    :   glb_declarations var_decl 
                        {
                                strcpy(table[i].scope,"global"); 
                                int j=i-1;
                                while(j>=0 && strcmp(table[j].scope,"global")!=0)
                                {
                                        if(table[j].scope[0]=='\0')
                                                strcpy(table[j].scope,"global");
                                        j--;
                                }
                        }
                    |   glb_declarations fct_decl   
                    |   glb_declarations class_decl
                    |   glb_declarations struct_decl
                    |
                    ;

struct_decl     :  STRUC {printf("structura declarata\n");} ID struct_body STRUCEND
                ;

struct_body     :  struct_body var_decl
                |       
                ;

class_decl      :  CLAS {printf("clasa declarata\n");} ID class_body CLASEND
                ;

class_body      :  class_body acces_modifier var_decl
                |  class_body acces_modifier fct_decl
                |  class_body var_decl  
                |  class_body fct_decl  
                |
                ;
        
acces_modifier  :  PUBLIC       {printf("public ");}
                |  PRIVATE      {printf("private ");}
                |  PROTECTED    {printf("protected ");}
                ;

var_decl    :   var_type variable_list ';'
            ;



variable_list : variable_list ',' ID
                {
                        printf("%s %s declared\n",tab,$3.name);
                        strcpy(table[i].vartype,table[i-1].vartype);
                        strcpy(table[i++].name,$3.name); 
                }
                | ID ASGN expression {printf("%s %s declared and assigned\n",tab,$1.name);}
                | ID 
                {
                        printf("%s %s declared\n",tab,$1.name);
                        strcpy(table[i++].name,$1.name);
                }
                | variable_list ',' ID ASGN expression
                ;

fct_decl    :   var_type ID '(' {printf("Function %s declared! \n",$2.name); strcat(tab,"\t");} param_list ')' {strcpy(tab,tab+1);}  FBEGIN {strcat(tab,"\t");}  body  FEND {strcpy(tab,tab+1);}
            |   var_type ID '(' {printf("Function %s declared! \n",$2.name); strcat(tab,"\t");} ')' {strcpy(tab,tab+1);}  FBEGIN {strcat(tab,"\t");} body FEND {strcpy(tab,tab+1);} 
            ;

param_list  :   param_list ',' param
            |   param
            ;

param   :   var_type ID  {printf("%s parameter declaration \n",tab);}
        ;

var_type :   INT
            {
                    {strcpy(table[i].vartype,"int");}
            }
        |   BOOL
        |   STRING
        ;

main_body   : BEGIN_P {printf("main\n");strcat(tab,"\t");} body {strcpy(tab,tab+1);} END_P 
            ;

body  	:   body  statement 
        |
        ;

statement   :   expression ';'
            |   ID ASGN expression ';'
            |   control {strcpy(tab,tab+1);}
	    |   var_decl 
            |   print_call  ';'
            ;

fct_call : ID '(' {printf("%s Fct call with parameters \n",tab);} param_called_list ')' 
         | ID '(' {printf("%s Fct call \n",tab);} ')' 
         ;
         

param_called_list : param_called_list ',' expression
                  | expression
                  ;


control : WHILE {printf("%s While called\n",tab);strcat(tab,"\t");} '(' binary_expression ')' body ENDWHILE 
        | if2 
        ;

if2     :   {printf("%s if called \n",tab); strcat(tab,"\t");}    if
        ;

if      : IF '(' binary_expression ')' THEN body ENDIF 
        | IF '(' binary_expression ')' THEN body ELSE {printf("%s else called \n",tab+1);} body ENDIF
        | IF '(' binary_expression ')' THEN body {printf("%s else if called \n",tab+1);} eif  ENDIF
        ;

eif     : ELSE_IF '(' binary_expression ')' THEN body 
        | ELSE_IF '(' binary_expression ')' THEN body ELSE {printf("%s else called \n",tab+1);} body
        | ELSE_IF '(' binary_expression ')' THEN body {printf("%s else if called \n",tab+1);} eif
        ;

print_call  :   PRINT'(' expression ')'{printf("%s PRINT CALLED \n",tab);}
            ;


expression : INTVAL 
           | ID 
           | expression PLUS expression
           | expression MINUS expression
           | expression MTP expression
           | expression DVD expression
           | expression MOD expression
           | binary_expression
           | '(' expression ')'
           | fct_call 
           ;

binary_expression : expression LWR expression 
                | expression GTR expression
                | expression LEQ expression 
                | expression GEQ expression 
                | expression NEQ expression 
                | expression EQ expression 
                | expression AND expression 
                | expression OR expression 
                ; 


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
