struct var_data
{
        char name[100];
        char val[100];          //valoare numerica convertita in char;
        char vartype[10];
        char scope[30];        //global, main, sau numele functiei/clasei in care a fost declarata;

};

struct fct_data
{
        char name[100];
        char val[100];
        char fcttype[10];
        char scope[30];
        int nr_param;
        char parametersType[30][6];   //tipul parametrilor => signature;
        char parameters[30][30];        //numele parametrilor
};