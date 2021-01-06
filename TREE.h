typedef enum
{
	INT_TYPE,
	FLOAT_TYPE,
	CHAR_TYPE,
	STRING_TYPE,
	FUNCTION_TYPE
}SYMBOL_TYPE;

typedef enum
{
	CONST_NODE,
	VAR_NODE,
	OP_NODE,
	ASGN_NODE,
	IF_NODE,
	WHILE_NODE,
	BODY_NODE,
	PRINT_NODE,
}NODE_TYPE;

typedef enum
{
	PLUS1,
	MINUS1,
	MTP1,
	DVD1,
	MOD1,
	LWR1,
	LEQ1,
	GTR1,
	GEQ1,
	EQ1,
	NEQ1,
	OR1,
	AND1
}OPERATOR;

typedef struct
{
	SYMBOL_TYPE type;
	union
	{
		int int_val;
		float float_val;
		char char_val;
		char* string_val;
		void* function_val;
	};
} Symbol;

typedef struct
{
	Symbol value;
}AST_CONST_NODE;

typedef struct
{
	char* name; 
}AST_VAR_NODE;

typedef struct
{
	OPERATOR operatr;   //operator reserved name
	int current, capacity;
	struct AST_NODE** terms;
}AST_OP_NODE;

typedef struct
{
	struct AST_NODE* variable, * expression;
}AST_ASGN_NODE;

typedef struct
{
	struct AST_NODE* condition, * if_body, *else_body;
}AST_IF_NODE;

typedef struct
{
	struct AST_NODE* condition, * body;
}AST_WHILE_NODE;

typedef struct
{
	int current, capacity;
	struct ASTNode** statements;
}AST_BODY_NODE;

typedef struct
{
	struct ASTNode* expression;
}AST_PRINT_NODE;

typedef struct AST_NODE
{
	NODE_TYPE type;
	union
	{
		AST_CONST_NODE const_node;
		AST_VAR_NODE var_node;
		AST_OP_NODE op_node;
		AST_ASGN_NODE asgn_node;
		AST_IF_NODE if_node;
		AST_WHILE_NODE while_node;
		AST_BODY_NODE body_node;
		AST_PRINT_NODE print_node;
	} n;
	union
	{
		int int_val;
		float float_val;
		char char_val;
		char* string_val;
	}node_result;
}AST_NODE;

void init_body(AST_BODY_NODE* body);
void add_statement(AST_BODY_NODE* body, AST_NODE* statement);
AST_NODE* CONST_CREATE(Symbol* value);
AST_NODE* VAR_CREATE(char* name);
AST_NODE* OP_CREATE(OPERATOR operatr, AST_NODE* left, AST_NODE* right);
AST_NODE* ASGN_CREATE(AST_NODE* var, AST_NODE* expression);
AST_NODE* IF_CREATE(AST_NODE* condition, AST_NODE* if_body, AST_NODE* else_body);
AST_NODE* WHILE_CREATE(AST_NODE* condition, AST_NODE* body);
AST_NODE* BODY_CREATE(AST_BODY_NODE* body_node);
AST_NODE* PRINT_CREATE(AST_NODE* expression);