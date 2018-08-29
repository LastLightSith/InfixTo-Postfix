/*
 * File stack.cpp
 * created on 23-8-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */
#include "stack.h"

//char
void init(Stack *stack)
{
	stack->bottom = 0;
	stack->top = 0;
	stack->size = 0;
}

void push(Stack *stack,char a)
{
	node *newnode = (node*)malloc(sizeof (node));
	newnode->ch = a;

	if(stack->size == 0)
	{
		stack->bottom = newnode;
		stack->bottom->last = 0;
		stack->top = stack->bottom;
	}
	else if(stack->size == 1)
	{
		newnode->last = stack->top;
		stack->top = newnode;
		stack->top->last = stack->bottom;
	}
	else
	{
		node *temp = stack->top;
		stack->top = newnode;
		stack->top->last = temp;
	}

	stack->size++;
}

char pop(Stack *stack)
{
	if(!stack->size)
		return -1;
	else
	{
		node *temp = stack->top;
		char ch =  stack->top->ch;
		stack->top = stack->top->last;
		stack->size--;
		free(temp);
		return ch;
	}
}

char peek(Stack *stack)
{
	return stack->top->ch;
}

void delete(Stack *stack)
{
	while(stack->size > 0 )
		free(stack->top);
}


//double

void init_ld(Stack_double* stack)
{
	stack->bottom = 0;
	stack->top = 0;
	stack->size = 0;
}

void push_ld(Stack_double*stack,long double a)
{
	node_double *newnode = (node_double*)malloc(sizeof (node_double));
	newnode->ch = a;

	if(stack->size == 0)
	{
		stack->bottom = newnode;
		stack->bottom->last = 0;
		stack->top = stack->bottom;
	}
	else if(stack->size == 1)
	{
		newnode->last = stack->top;
		stack->top = newnode;
		stack->top->last = stack->bottom;
	}
	else
	{
		node_double *temp = stack->top;
		stack->top = newnode;
		stack->top->last = temp;
	}

	stack->size++;
}

long double pop_ld(Stack_double*stack)
{
	if(!stack->size)
		return -1;
	else
	{
		node_double *temp = stack->top;
		long double ch =  stack->top->ch;
		stack->top = stack->top->last;
		stack->size--;
		free(temp);
		return ch;
	}
}

long double peek_ld(Stack_double*stack)
{
	return stack->top->ch;
}

void delete_ld(Stack_double*stack)
{
	while(stack->size > 0 )
		free(stack->top);
}
































