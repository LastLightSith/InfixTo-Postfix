#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"


unsigned short POP_(char a)
{
	unsigned short ap = 0;
	switch (a)
	{
		case '+':
		case '-':
			ap = 1;
			break;
		case '/':
		case '*':
			ap = 2;
			break;
		case '^':
			ap = 3;
			break;
	}

	return ap;

}

short checkOP_(char a,char b)
{
	unsigned short ap,bp;
	ap = POP_(a);
	bp = POP_(b);

	if(ap > bp)
		return 1;
	if(ap == bp)
		return 0;
	if(ap < bp)
		return -1;
	return -911;

}

long double evaluate(long double a,char OP,long double b)
{
	switch (OP)
	{
		case '-':
			return a-b;
		case '+':
			return a+b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '^':
			return powl(a,b);

	}
}


long double EvaluatePostfix(char *postfix)
{
	Stack_double stack;
	uint size = strlen(postfix);
	init_ld(&stack);

	for(uint i = 0; i<size; i++)
	{
		char ch = postfix[i];
		char *temp = malloc(strlen(postfix));
		strcpy(temp,"");

		while( !((ch >39 && ch < 48) || ch== 94 || ch == ' ' ))
		{
			strcat(temp,(char[2]){ch,'\0'});
			i++;
			ch = postfix[i];
		}

		if(strlen(temp))
			push_ld(&stack,strtold(temp,0));
		free(temp);

		if((ch >39 && ch < 48) || ch== 94 )
		{
			long double a,b;
			a = pop_ld(&stack);
			b = pop_ld(&stack);

			push_ld(&stack,evaluate(b,ch,a));
		}

	}

	long double re = pop_ld(&stack);
	return re;
}
