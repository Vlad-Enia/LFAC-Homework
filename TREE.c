#include "TREE.h"
#include <stdlib.h>
#include <string.h>

void init_body(AST_BODY_NODE* body)
{
	body->current = 0;
	body->capacity = 1024;
	body->statements = (AST_NODE**)malloc(body->capacity * sizeof(AST_NODE*));
	memset(body->statements, 0, (body->capacity * sizeof(AST_NODE*)));
}

void add_statement(AST_BODY_NODE* body, AST_NODE* statement)
{
	body->statements[body->current++] = statement;
}

AST_NODE* CONST_CREATE(Symbol* value)
{
	AST_NODE* const_node = (AST_NODE*)malloc(sizeof(AST_NODE));
	const_node->type = CONST_NODE;
	const_node->n.const_node.value=*value;
	return const_node;
}
AST_NODE* VAR_CREATE(char* name)
{
	AST_NODE* var_node= (AST_NODE*)malloc(sizeof(AST_NODE));
	var_node->type = VAR_NODE;
	var_node->n.var_node.name = name;
	return var_node;
}

AST_NODE* OP_CREATE(OPERATOR operatr, AST_NODE* left, AST_NODE* right)
{
	AST_NODE* op_node = (AST_NODE*)malloc(sizeof(AST_NODE));
	op_node->type = OP_NODE;
	op_node->n.op_node.operatr=operatr; /* double */
	op_node->n.op_node.current = op_node->n.op_node.capacity = 2;
	op_node->n.op_node.terms= (AST_NODE**)malloc(2 * sizeof(AST_NODE*));
	op_node->n.op_node.terms[0] = left;
	op_node->n.op_node.terms[1] = right;
	return op_node;
}
AST_NODE* ASGN_CREATE(AST_NODE* variable, AST_NODE* expression)
{
	AST_NODE* asgn_node = (AST_NODE*)malloc(sizeof(AST_NODE));
	asgn_node->type = ASGN_NODE;
	asgn_node->n.asgn_node.variable = variable;
	asgn_node->n.asgn_node.expression = expression;
	return asgn_node;
}

AST_NODE* IF_CREATE(AST_NODE* condition, AST_NODE* if_body, AST_NODE* else_body)
{
	AST_NODE* if_node = (AST_NODE*)malloc(sizeof(AST_NODE));
	if_node->type = IF_NODE;
	if_node->n.if_node.condition = condition;
	if_node->n.if_node.if_body = if_body;
	if_node->n.if_node.else_body = else_body;
	return if_node;
}

AST_NODE* WHILE_CREATE(AST_NODE* condition, AST_NODE* body)
{
	AST_NODE* while_node = (AST_NODE*)malloc(sizeof(AST_NODE));
	while_node->type = WHILE_NODE;
	while_node->n.while_node.condition = condition;
	while_node->n.while_node.body = body;
	return while_node;
}

AST_NODE* BODY_CREATE(AST_BODY_NODE* body)
{
	AST_NODE* body_node = (AST_NODE*)malloc(sizeof(AST_NODE));
	body_node->type = BODY_NODE;
	body_node ->n.body_node = *body;
	return body_node;
}
AST_NODE* PRINT_CREATE(AST_NODE* expression)
{
	AST_NODE* print_node = (AST_NODE*)malloc(sizeof(AST_NODE));
	print_node->type = PRINT_NODE;
	print_node->n.print_node.expression = expression;
	return print_node; 
}