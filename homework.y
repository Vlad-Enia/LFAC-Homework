%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "var_types.h"                  //in var_types sunt structurile var_data si fct_data;
extern FILE* yyin;
extern int yylineno;
extern char* yytext;
//char* tab = char* malloc(1);
char tab[100];

struct var_data table[100];             //tabelul variabilelor
int nrVars=0;                           //nr variabilelor din tabel
void printTable();                      //afiseaza toate elementele din tablou;
void updateTable(int i, int newVal);    //actualizeaza variabila de pe pozitia i cu valoarea newVal
void addVarName(int i, char * newName); //adauga pe pozitia i numele newName
void addVarType(int i, char * newType); //adauga pe pozitia i tipul newType
int findVar(char *newName);             //returneaza pozitia variabilei cu numele NewName
int undeclared(char *newName,char *scope);
int findScope(char* newName,char* scope);                                     //ar trebui eventual si o functie addScope care adauga scope-ul pe pozitia i
char current_scope[100]="global";
%}

%union {
        int intval;
        double floatval;
        char* strval;
        int boolval;
        struct VAR                      //structura VAR reprezinta practic o variabila ce urmeaza a fi adaugata in tabel, si are aceleasi campuri ca var_data, care descrie tabelul
        {
                char name[100];
                char val[100];          //valoare numerica convertita in char; AR FI MAI EFICIENT sa stocam totusi in camp de tip int;
                char vartype[6];
                char scope[30];
        } var;

}


%token INT FLOAT CHAR STRING BOOL 
%token <var> ID
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
%type <var> fct_call                    //trebuie revizuit, am pus asa doar sa nu fie erori
%type <intval> expression binary_expression               //DEOCAMDATA expresiile sunt de tip intval ca sa satisfac doar prima ramura de la expressions, adica atunci cand o expresie ia forma unei valori integer;
                                        //din acest motiv acum exista warning-uri clash type pentru restul ramurilor din expressions;

%left AND OR
%left EQ NEQ LWR GTR LEQ GEQ
%left PLUS MINUS
%left MTP DVD MOD

%start program
%%



program     :   glb_declarations main_body  {printf("\nend main\n\n"); printTable();}
            ;

glb_declarations    :   glb_declarations var_decl 
                        {
                                strcpy(table[nrVars].scope,"global"); 
                                int j=nrVars-1;
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
                        printf("%s%s declared\n",tab,$3.name);
                        addVarType(nrVars,table[nrVars-1].vartype);
                        addVarName(nrVars,$3.name);
                        nrVars++;
                        //strcpy(table[nrVars].vartype,table[nrVars-1].vartype);
                        //strcpy(table[nrVars++].name,$3.name); 
                }
                | ID ASGN expression 
                {
                        printf("%s%s declared and assigned with %d\n",tab,$1.name,$3);
                        addVarName(nrVars,$1.name);
                        updateTable(nrVars,$3);
                        nrVars++;

                }
                | ID 
                {
                        if(undeclared($1.name,current_scope)==-1)
                        {
                                printf("[Error][Line %d]: Variable already declared\n",yylineno);
                                exit(-1);
                        }   
                        printf("%s%s declared\n",tab,$1.name);
                        
                        addVarName(nrVars,$1.name);
                        nrVars++;
                        //strcpy(table[nrVars++].name,$1.name);
                }
                | variable_list ',' ID ASGN expression
                {
                        printf("%s%s declared and assigned with %d\n",tab,$3.name,$5);
                        addVarName(nrVars,$3.name);
                        addVarType(nrVars,table[nrVars-1].vartype);
                        strcpy(table[nrVars].scope,table[nrVars-1].scope);      
                        updateTable(nrVars,$5);
                        nrVars++;
                }
                ;

fct_decl    :   var_type ID '(' {printf("Function %s declared! \n",$2.name); strcat(tab,"\t");strcpy(current_scope,$2.name);} param_list ')' {strcpy(tab,tab+1);}  FBEGIN {strcat(tab,"\t");}  body  FEND {strcpy(tab,tab+1);strcpy(current_scope,"global");}
            |   var_type ID '(' {printf("Function %s declared! \n",$2.name); strcat(tab,"\t");strcpy(current_scope,$2.name);} ')' {strcpy(tab,tab+1);}  FBEGIN {strcat(tab,"\t");} body FEND {strcpy(tab,tab+1);strcpy(current_scope,"global");} 
            ;

param_list  :   param_list ',' param
            |   param
            ;

param   :   var_type ID  
        {
        if(undeclared($2.name,current_scope)==-1)
        {
                printf("[Error][Line %d]: Variable already declared\n",yylineno);
                exit(-1);
        }   
        printf("%s parameter %s declared\n",tab,$2.name); 
        strcpy(table[nrVars].scope,current_scope);           
        addVarName(nrVars,$2.name);
        nrVars++; 
        }
        ;

var_type :   INT
            {
                addVarType(nrVars,"int");
            }
        |   BOOL
        |   STRING
        ;

main_body   : BEGIN_P {printf("\nmain\n");strcat(tab,"\t");strcpy(current_scope,"main");} body {strcpy(tab,tab+1);} END_P 
            ;

body  	:   body  statement 
        |
        ;

statement   :   expression ';'
            |   ID ASGN expression ';'
                {  
                        {
                                printf("%s%s assigned with %d\n",tab,$1.name,$3);
                                int j = findVar($1.name);
                                if(j==-1)
                                        {
                                               printf("[Error][Line: %d]: variable with the name \"%s\" was not declared!\n",yylineno,$1.name);
                                               exit(-1);
                                        } 
                                else
                                {
                                        updateTable(j,$3);
                                }

                        }
                }
            |   control {strcpy(tab,tab+1);}
	    |   var_decl {
                            int j=nrVars-1;      
                            strcpy(table[j].scope,current_scope); 
                         }
                                 
            |   print_call  ';'
            ;

fct_call : ID '(' {printf("%sFct call with parameters \n",tab);} param_called_list ')' 
         | ID '(' {printf("%sFct call \n",tab);} ')' 
         ;
         

param_called_list : param_called_list ',' expression
                  | expression
                  ;


control : WHILE {printf("%sWhile called\n",tab);strcat(tab,"\t");} '(' binary_expression ')' body ENDWHILE 
        | if2 
        ;

if2     :   {printf("%sif called \n",tab); strcat(tab,"\t");}    if
        ;

if      : IF '(' binary_expression ')' THEN body ENDIF 
        | IF '(' binary_expression ')' THEN body ELSE {printf("%selse called \n",tab+1);} body ENDIF
        | IF '(' binary_expression ')' THEN body {printf("%selse if called \n",tab+1);} eif  ENDIF
        ;

eif     : ELSE_IF '(' binary_expression ')' THEN body 
        | ELSE_IF '(' binary_expression ')' THEN body ELSE {printf("%s else called \n",tab+1);} body
        | ELSE_IF '(' binary_expression ')' THEN body {printf("%s else if called \n",tab+1);} eif
        ;

print_call  :   PRINT'(' expression ')'{printf("%sprint() called \n",tab);}
            ;


expression : INTVAL {$$ = $1;}
           | ID { 
                   int j=findScope($1.name,current_scope);
                   if(j==-1) 
                        {
                              printf("[Error][Line: %d]: variable with the name \"%s\" was not declared!\n",yylineno,$1.name);
                              exit(-1);
                        }
                   if(strcmp(table[j].val,"NULL")==0)
                        {
                                printf("[Error][Line: %d]: variable with the name \"%s\" was not initialised!\n",yylineno,$1.name);
                                exit(-1);        
                        }
                   $$=atoi(table[j].val);
                   }
           | expression PLUS expression {$$=$1+$3;}
           | expression MINUS expression {$$=$1-$3;}
           | expression MTP expression {$$=$1*$3;}
           | expression DVD expression {$$=$1/$3;}
           | expression MOD expression {$$=$1%$3;}
           | binary_expression {$$=$1;}
           | '(' expression ')' {$$=$2;}
           | fct_call {$$=atoi($1.val);}
           ;

binary_expression : expression LWR expression {$$=$1<$3;}
                | expression GTR expression {$$=$1>$3;}
                | expression LEQ expression {$$=$1<=$3;}
                | expression GEQ expression {$$=$1>=$3;}
                | expression NEQ expression {$$=$1!=$3;}
                | expression EQ expression {$$=($1==$3);}
                | expression AND expression {$$=$1&&$3;}
                | expression OR expression {$$=$1||$3;  }
                ; 

%%



int yyerror(char * s) /// Fa eroare ;
{
    printf("eroare: %s la linia:%d\n",s,yylineno);
    return 0;
}

void printTable()
{
        for(int j=0;j<nrVars;j++)
                printf("in tabel:%i %s = %s %s %s\n",j,table[j].name,table[j].val,table[j].vartype,table[j].scope); //MERGE BAAAAAAA!!!!!
}

void updateTable(int i, int newVal)
{
        sprintf(table[i].val,"%d",newVal);
}

void addVarName(int i, char * newName)
{
        strcpy(table[i].name,newName);
        strcpy(table[i].val,"NULL");
}

void addVarType(int i, char * newType)
{
        strcpy(table[i].vartype,newType);
}

int findVar(char *newName)
{
        for(int i=0;i<nrVars;i++)
        {
                if(strcmp(table[i].name,newName)==0)
                        return i;
        }
        return -1;
}

int findScope(char* newName,char* scope)
{
       for(int i=0;i<nrVars;i++)
        {
                if(strcmp(table[i].name,newName)==0&&strcmp(table[i].scope,scope)==0)
                        return i;
        }
        return -1;
}

int undeclared(char *newName,char *scope)
{
        for(int i=0;i<nrVars;i++)
        {
                if(strcmp(table[i].name,newName)==0&&strcmp(table[i].scope,scope)==0)
                        return -1;
        }
        return 0;
}

int main(int argc,char** argv)
{
    yyin = fopen(argv[1],"r");
    yyparse();
	exit(0);
}