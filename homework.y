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
void updateTable(int i, char* newVal);    //actualizeaza variabila de pe pozitia i cu valoarea newVal
void addVarName(int i, char * newName); //adauga pe pozitia i numele newName
void addVarType(int i, char * newType); //adauga pe pozitia i tipul newType
int findVar(char *newName);             //returneaza pozitia variabilei cu numele NewName
int undeclared(char *newName,char *scope);      //cauta in tablelul de variabile un nume si un scope 
int findScope(char* newName,char* scope);       //cam la fel da nu prea
void PRINT_EVAL();                                    //ar trebui eventual si o functie addScope care adauga scope-ul pe pozitia i
char current_scope[100]="global";
int Eval_calls[100],nr_calls=0;

struct fct_data fct_table[100];
int nrFct=0;
void printFctTable();
void addFctName(int i, char * newName);
void addFctType(int i, char * newType);
int findFct(char *newName);
int findScope(char *newName, char* scope);
char current_fct_scope[100];
char current_var_type[6];

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
                char vartype[10];
                char scope[30];
        } var;

        struct FCT
        {
                char name[100];
                char val[100];
                char fcttype[10];
                char scope[30];
                int nr_param;
                char parametersType[30][6];   //lista tipurilor la parametri => signatura;
                char parameters[30][30];      //numele parametrilor;
        } fct;
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
%token EVAL_FCT
%token CALL
%token ASGN
%token <strval> STRVAL 
%token <intval> INTVAL 
%token <boolval> BOOLVAL 
%type <var> fct_call                    //trebuie revizuit, am pus asa doar sa nu fie erori
%type <var> expression binary_expression               //DEOCAMDATA expresiile sunt de tip intval ca sa satisfac doar prima ramura de la expressions, adica atunci cand o expresie ia forma unei valori integer;
                                        //din acest motiv acum exista warning-uri clash type pentru restul ramurilor din expressions;
%type <var> var_type
%type <fct> fct_decl
%left AND OR
%left EQ NEQ LWR GTR LEQ GEQ
%left PLUS MINUS
%left MTP DVD MOD

%start program
%%



program     :   glb_declarations main_body  {printf("\nend main\n\n"); printTable(); printf("\n"); printFctTable(); printf("\n"); printf("PROGRAM CORECT SINTACTIC\n"); PRINT_EVAL();}
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

var_decl    :   var_type  variable_list ';'
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
                | ID ASGN  expression 
                {
                        strcpy($1.vartype,current_var_type);
                        if(strcmp($1.vartype,$3.vartype)!=0)
                        {
                                printf("[Error][Line %d]: Assignment between two different types: %s != %s",yylineno,$1.vartype,$3.vartype);
                                exit(-1);
                        }
                        printf("%s%s declared and assigned with %s\n",tab,$1.name,$3.val);
                        addVarName(nrVars,$1.name);
                        updateTable(nrVars,$3.val);
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
                        strcpy($3.vartype,current_var_type);
                        
                        if(strcmp($3.vartype,$5.vartype)!=0)
                        {
                                printf("[Error][Line %d]: Assignment between two different types: %s != %s",yylineno,$3.vartype,$5.vartype);
                                exit(-1);
                        }
                        printf("%s%s declared and assigned with %d\n",tab,$3.name,$5);
                        addVarName(nrVars,$3.name);
                        addVarType(nrVars,table[nrVars-1].vartype);
                        strcpy(table[nrVars].scope,table[nrVars-1].scope);      
                        updateTable(nrVars,$5.val);
                        nrVars++;
                }
                ;

fct_decl    :   var_type ID '(' {strcat(tab,"\t"); strcpy(current_fct_scope,current_scope);strcpy(current_scope,$2.name);}
                param_list ')' 
                {
                        strcpy(tab,tab+1);
                        strcpy($<fct>$.name, $2.name);
                        strcpy($<fct>$.fcttype,$1.vartype);
                        addFctName(nrFct,$2.name);
                        addFctType(nrFct,$1.vartype);
                        strcpy(fct_table[nrFct].scope,current_fct_scope);

                        int j = findFct($2.name);
                        if(j!=nrFct)
                        {
                                if(fct_table[j].nr_param == fct_table[nrFct].nr_param)
                                {
                                        int ok=0;
                                        for(int i=0;i<fct_table[j].nr_param;i++)
                                        {
                                                if(strcmp(fct_table[j].parametersType[i],fct_table[nrFct].parametersType[i])!=0)
                                                {
                                                        ok=1;//gasit
                                                        break;
                                                }
                                        }
                                        if(ok==0)
                                        {
                                                printf("[Error][Line: %d] Function with the same signature alerady declared;\n",yylineno);\
                                                exit(-1);
                                        }
                                }
                        }
                        printf("Function %s declared! \n",$2.name);                        
                        nrFct++;
                }  FBEGIN {strcat(tab,"\t");}  body  FEND {strcpy(tab,tab+1);strcpy(current_scope,"global");}
            |   var_type ID '(' 
                {
                        printf("Function %s declared! \n",$2.name); 
                        strcpy($<fct>$.name, $2.name);
                        strcpy($<fct>$.fcttype,$1.vartype);
                        strcat(tab,"\t");
                        
                        addFctName(nrFct,$2.name);
                        addFctType(nrFct,$1.vartype);
                        strcpy(fct_table[nrFct].scope,current_scope);
                        strcat(tab,"\t");strcpy(current_scope,$2.name);
                }
                ')' {strcpy(tab,tab+1);nrFct++;}  FBEGIN {strcat(tab,"\t");} body FEND {strcpy(tab,tab+1);strcpy(current_scope,"global");} 
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

                strcpy(fct_table[nrFct].parameters[fct_table[nrFct].nr_param],$2.name);
                strcpy(fct_table[nrFct].parametersType[fct_table[nrFct].nr_param],$1.vartype);
                fct_table[nrFct].nr_param++;
                
        }
        ;

var_type :   INT
            {
                addVarType(nrVars,"int");
                strcpy($$.vartype, "int");
                strcpy(current_var_type, "int");
            }

        |   BOOL
            {
                strcpy($$.vartype, "bool");
                strcpy(current_var_type, "bool");
            }

        |   STRING
            {
                strcpy($$.vartype, "string");
                strcpy(current_var_type, "string");

            }

        |   FLOAT
            {
                strcpy($$.vartype, "float");
                strcpy(current_var_type, "float");
            }
        ;

main_body   : BEGIN_P {printf("\nmain\n");strcat(tab,"\t");strcpy(current_scope,"main");} body {strcpy(tab,tab+1);} END_P 
            ;

body  	:   body  statement 
        |
        ;

statement   :   expression ';'
            |   ID ASGN expression ';'
                {  
                        if(strcmp($1.vartype,$3.vartype)!=0)
                        {
                                printf("[Error][Line %d]: Assignment between two different types: %s != %s",yylineno,$1.vartype,$3.vartype);
                                exit(-1);
                        }
                        printf("%s%s assigned with %d\n",tab,$1.name,$3);
                        int j = findVar($1.name);
                        if(j==-1)
                                {
                                        printf("[Error][Line: %d]: variable with the name \"%s\" was not declared!\n",yylineno,$1.name);
                                        exit(-1);
                                } 
                        else
                        {
                                updateTable(j,$3.val);
                        }
                }
            |   control {strcpy(tab,tab+1);}
	    |   var_decl {
                            int j=nrVars-1;      
                            strcpy(table[j].scope,current_scope); 
                         }
                                 
            |   print_call  ';'
            | EVAL_FCT '(' expression ')' ';' {Eval_calls[nr_calls++]=atoi($3.val);}
            ;

fct_call : ID '(' 
         {
                int j = findFct($1.name);
                if(j==-1)
                {
                        printf("[Error][Line: %d]: Function with name \"%s\" is not neclared!\n",yylineno,$1.name);
                        exit(-1);
                }

                printf("%sFct call with parameters \n",tab);
         } param_called_list ')' 

         | ID '(' ')' 
         {
                int j = findFct($1.name);
                if(j==-1)
                {
                        printf("[Error][Line: %d]: Function with name \"%s\" is not neclared!\n",yylineno,$1.name);
                        exit(-1);
                }
                 printf("%sFct call \n",tab);
         }
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


expression : INTVAL 
           {
                char buffer[20];
                sprintf(buffer,"%d",$1);
                strcpy($$.val,buffer);
                //$$ = $1;
                strcpy($$.vartype,"int");
           }

           | STRVAL
           {
                strcpy($$.val,$1);
                strcpy($$.vartype,"string");

           }

           | ID 
           { 
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
                //$$=atoi(table[j].val);
                strcpy($$.val,table[j].val);
                strcpy($$.vartype,table[j].vartype);
           }
           | expression PLUS expression 
           {
                if(strcmp($1.vartype,$3.vartype)!=0)
                {
                        printf("[Error][Line %d]: %s + %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                        exit(-1);
                }
                strcpy($$.vartype,$1.vartype);
                if(strcmp($$.vartype,"int")==0 || strcmp($$.vartype,"float")==0 )
                {
                        int op1=atoi($1.val);
                        int op2=atoi($3.val);
                        char buffer[20];
                        sprintf(buffer,"%d",op1+op2);
                        strcpy($$.val,buffer);
                        //$$=$1+$3;
                }
                else if(strcmp($$.vartype,"bool")==0)
                {
                        int op1=atoi($1.val);
                        int op2=atoi($3.val);
                        char buffer[20];
                        sprintf(buffer,"%d",(op1+op2)%2);
                        strcpy($$.val,buffer);
                }
                else if(strcmp($$.vartype,"string")==0)
                {
                        char buffer[200];
                        strcpy(buffer,$1.val);
                        strcat(buffer,$3.val);
                        strcpy($$.val,buffer);
                }

           }
           | expression MINUS expression 
           {
                if(strcmp($1.vartype,$3.vartype)!=0)
                {
                        printf("[Error][Line %d]: %s - %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                        exit(-1);
                }
                strcpy($$.vartype,$1.vartype);
                if(strcmp($$.vartype,"int")==0 || strcmp($$.vartype,"float")==0)      
                {
                        int op1=atoi($1.val);
                        int op2=atoi($3.val);
                        char buffer[20];
                        sprintf(buffer,"%d",op1-op2);
                        strcpy($$.val,buffer);
                }
                if(strcmp($$.vartype,"bool")==0)      
                {
                        int op1=atoi($1.val);
                        int op2=atoi($3.val);
                        char buffer[20];
                        sprintf(buffer,"%d",(op1-op2)%2);
                        strcpy($$.val,buffer);
                }
                else
                {
                        printf("Error][Line %d]: string - string is not possible!\n",yylineno);
                        exit(-1);
                }
                //$$=$1-$3;
           }
           | expression MTP expression 
           {
                if(strcmp($1.vartype,$3.vartype)!=0)
                {
                        printf("[Error][Line %d]: %s * %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                        exit(-1);
                }
                strcpy($$.vartype,$1.vartype);
                if(strcmp($$.vartype,"string")!=0)      //daca nu e string e float, int sau bool;
                {
                        int op1=atoi($1.val);
                        int op2=atoi($3.val);
                        char buffer[20];
                        sprintf(buffer,"%d",op1*op2);
                        strcpy($$.val,buffer);
                }
                else            //putem implementa * ca + in c (str+3 de la pozitia 3)
                {
                        printf("Error][Line %d]: string * string is not possible!\n",yylineno);
                        exit(-1);
                }
           }
           | expression DVD expression 
           {
                if(strcmp($1.vartype,$3.vartype)!=0)
                {
                        printf("[Error][Line %d]: %s / %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                        exit(-1);
                }
                strcpy($$.vartype,$1.vartype);
                if(strcmp($$.vartype,"int")==0 || strcmp($$.vartype,"float")==0 )      //daca nu e string e float, int sau bool;
                {
                        int op1=atoi($1.val);
                        int op2=atoi($3.val);
                        if(op2==0)
                        {
                                printf("[Error][Line %d]: division by 0 is not possible!\n",yylineno);
                                exit(-1);
                        }
                        char buffer[20];
                        sprintf(buffer,"%d",op1/op2);
                        strcpy($$.val,buffer);
                }
                else           
                {
                        printf("[Error][Line %d]: %s / %s is not possible!\n",yylineno,$1.vartype,$3.vartype);
                        exit(-1);
                }
           }
           | expression MOD expression 
           {
                
                if(strcmp($1.vartype,$3.vartype)!=0)
                {
                        printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                        exit(-1);
                }
                strcpy($$.vartype,$1.vartype);
                if(strcmp($$.vartype,"int")==0)      
                {
                        int op1=atoi($1.val);
                        int op2=atoi($3.val);
                        if(op2==0)
                        {
                                printf("[Error][Line %d]: modulus by 0 is not possible!\n",yylineno);
                                exit(-1);
                        }
                        char buffer[20];
                        sprintf(buffer,"%d",op1%op2);
                        strcpy($$.val,buffer);
                }
                else            
                {
                        printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,$1.vartype,$3.vartype);
                        exit(-1);
                }
           }
           | binary_expression {strcpy($$.val,$1.val);strcpy($$.vartype,"int");}
           | '(' expression ')' {$$=$2;}
           | CALL fct_call {strcpy($$.val,$2.val);strcpy($$.vartype,$2.vartype);}//tip
           ;

binary_expression 
                : expression LWR expression 
                {
                        if(strcmp($1.vartype,$3.vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                                exit(-1);
                        }
                        if(strcmp($$.vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi($1.val);
                                int op2=atoi($3.val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1<op2);
                                strcpy($$.val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp($1.val,$3.val)<0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy($$.val,buffer);
                        }
                        //$$=$1<$3;
                }
                | expression GTR expression 
                {
                        if(strcmp($1.vartype,$3.vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                                exit(-1);
                        }
                        if(strcmp($$.vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi($1.val);
                                int op2=atoi($3.val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1>op2);
                                strcpy($$.val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp($1.val,$3.val)>0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy($$.val,buffer);
                        }
                        //$$=$1>$3;
                }
                | expression LEQ expression 
                {
                        if(strcmp($1.vartype,$3.vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                                exit(-1);
                        }
                        if(strcmp($$.vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi($1.val);
                                int op2=atoi($3.val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1<=op2);
                                strcpy($$.val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp($1.val,$3.val)<=0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy($$.val,buffer);
                        }
                        //$$=$1<=$3;
                }
                | expression GEQ expression 
                {
                        if(strcmp($1.vartype,$3.vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                                exit(-1);
                        }
                        if(strcmp($$.vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi($1.val);
                                int op2=atoi($3.val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1>=op2);
                                strcpy($$.val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp($1.val,$3.val)>=0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy($$.val,buffer);
                        }
                        //$$=$1>=$3;
                }
                | expression NEQ expression 
                {
                        if(strcmp($1.vartype,$3.vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                                exit(-1);
                        }
                        if(strcmp($$.vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi($1.val);
                                int op2=atoi($3.val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1!=op2);
                                strcpy($$.val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp($1.val,$3.val)!=0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy($$.val,buffer);
                        }
                        //$$=$1!=$3;
                }
                | expression EQ expression 
                {
                        if(strcmp($1.vartype,$3.vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,$1.vartype,$3.vartype);      
                                exit(-1);
                        }
                        if(strcmp($$.vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi($1.val);
                                int op2=atoi($3.val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1=op2);
                                strcpy($$.val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp($1.val,$3.val)==0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy($$.val,buffer);
                        }
                        //$$=($1==$3);
                }
                | expression AND expression 
                {
                        int op1=atoi($1.val);
                        if(op1==0)
                                strcpy($<var>$.val,"0");
                        else 
                        {
                                int op2=atoi($3.val);
                                if(op2==0)
                                        strcpy($<var>$.val,"0");
                                else
                                        strcpy($<var>$.val,"1");

                        }
                        //$$=$1&&$3;
                }
                expression OR expression 
                {
                        int op1=atoi($1.val);
                        if(op1==1)
                                strcpy($<var>$.val,"1");
                        else
                        {
                                int op2=atoi($3.val);
                                if(op2==0)
                                        strcpy($<var>$.val,"0");
                                else
                                        strcpy($<var>$.val,"1");
                                strcpy($<var>$.val,$3.val);
                        }
                        //$$=$1||$3;  
                }
                ; 

%%



int yyerror(char * s) /// Fa eroare ;
{
    printf("eroare: %s la linia:%d\n",s,yylineno);
    return 0;
}

void printTable()
{
        printf("Tabel variabile: \n");
        for(int j=0;j<nrVars;j++)
                printf("%i. %s = %s %s %s\n",j,table[j].name,table[j].val,table[j].vartype,table[j].scope); //MERGE BAAAAAAA!!!!!
}

void updateTable(int i, char* newVal)
{

        strcpy(table[i].val,newVal);
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

void PRINT_EVAL()
{
        for(int i=0;i<nr_calls;++i)
        {
                printf("Value of eval function for call %d:=%d\n",i+1,Eval_calls[i]);
        }
}

void printFctTable()
{
        printf("Tabel functii: \n");
        for(int i=0;i<nrFct;i++)
        {
                printf("%s %s %s (",fct_table[i].name,fct_table[i].fcttype,fct_table[i].scope);
                for(int j=0;j<fct_table[i].nr_param-1;j++)
                        printf("%s %s, ",fct_table[i].parametersType[j],fct_table[i].parameters[j]);
                printf("%s %s",fct_table[i].parametersType[fct_table[i].nr_param-1],fct_table[i].parameters[fct_table[i].nr_param-1]);
                printf(")\n");
        }
}

void addFctName(int i, char * newName)
{
        strcpy(fct_table[i].name,newName);
}

void addFctType(int i, char * newType)
{
        strcpy(fct_table[i].fcttype,newType);
}

int findFct(char *newName)
{
        for(int i=0;i<nrFct;i++)
                if(strcmp(fct_table[i].name,newName)==0)
                        return i;
        return -1;
}

int findfctScope(char *newName, char* scope)
{
        for(int i=0;i<nrFct;i++)
                if(strcmp(fct_table[i].name,newName)==0 && strcmp(fct_table[i].scope,scope)==0)
                        return i;
        return -1;
}

int main(int argc,char** argv)
{
    yyin = fopen(argv[1],"r");
    yyparse();
	exit(0);
}