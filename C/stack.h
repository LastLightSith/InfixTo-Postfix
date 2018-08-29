/*
 * File stack.h
 * created on 23-8-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

//char
typedef struct _node
{
	char ch;
	struct _node* last;
} node;

typedef struct
{
	node *top , *bottom ;
	uint size;
} Stack;

void init(Stack *stack);
void push(Stack *stack,char a);
char pop(Stack *stack);
char peek(Stack *stack);
void clean(Stack *stack);
void delete(Stack *stack);

//double
typedef struct _node_double
{
	long double ch;
	struct _node_double*last;
} node_double;

typedef struct
{
	node_double *top , *bottom ;
	uint size;
} Stack_double;

void init_ld(Stack_double*stack);
void push_ld(Stack_double*stack, long double a);
long double pop_ld(Stack_double*stack);
long double peek_ld(Stack_double*stack);
void clean_ld(Stack_double*stack);
void delete_ld(Stack_double*stack);

#endif // STACK_H
