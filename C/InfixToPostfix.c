
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

unsigned short POP(char a)
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
		case '(':
			ap = 999;
			break;
	}

	return ap;

}

short checkOP(char a,char b)
{
	unsigned short ap,bp;
	ap = POP(a);
	bp = POP(b);

	if(ap > bp)
		return 1;
	if(ap == bp)
		return 0;
	if(ap < bp)
		return -1;

}

void append(char *a,char b,char next)
{
	strcat(a,(char[2]){b,'\0'});

	if((next >39 && next < 48) || next == 94 )
		strcat(a,(char[2]){' ','\0'});

}

char *InfixToPostfix(char *infix)
{

	uint size = strlen(infix);
	char *postfix = 0 ;
	postfix = malloc(sizeof(char)*size*2);
	strcpy(postfix,"");

	Stack stack ;
	init(&stack);

	for(int i =0;i<size-1;i++)
	{
		char ch = infix[i];

		if( !((ch >39 && ch < 48) || ch== 94 ))
//			strcat(postfix,(char[2]){ch,'\0'});
			append(postfix,ch,infix[i+1]);
		else
		{
			if(!stack.size)
				push(&stack,ch);
			else
			{
				if(ch == ')')
				{
					while(1)
					{
						if(peek(&stack) == '(')
						{
							pop(&stack);
							goto outermost;

						}
						strcat(postfix,(char[2]){pop(&stack),'\0'});
						if(!stack.size)
							goto outermost;
					}
				}
				short status = checkOP(peek(&stack),ch);
				while(status == 1 || status == 0)
				{
					if(peek(&stack) == '(')
						break;
					strcat(postfix,(char[2]){pop(&stack),'\0'});
					if(!stack.size)
						break;
					status = checkOP(peek(&stack),ch);
				}
				push(&stack,ch);
			}
		}
		outermost:
		;
	}

	while(stack.size)
		strcat(postfix,(char[2]){pop(&stack),'\0'});

	return postfix;

}
