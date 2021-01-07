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