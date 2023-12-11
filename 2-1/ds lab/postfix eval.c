#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct stack
{
	double items[MAX];
	double top;
};
void push(struct stack *,int);
int pop(struct stack *);
void operator(char);
double eval(char);
void is_operand(struct stack *st,char sym);
int main()
{
	struct stack s;
	s.top=-1;
	char sym,infix;
	char exp[MAX];
	printf("enter an expression:");
	scanf("%s",&infix);
	printf("original prefix expression",exp);
	printf("evaluated expression:",eval(exp));
	is_operand(&s,exp);
}
double eval(char exp)
{
	int i;
	char c;
	double op1,op2
	for(i=0;(c=expr[i])!='\0';i++)
	{
		if(isdigit(c))
		{
			push(&s,(double)c-'0');
		}
		else
		{
			printf("\n%c",c);
			op2=pop(&s);
			op1=pop(&s);
			value=oper(c,op1,op2);
			push(&s,value);
		}
}
void is_operand(struct stack *st,char sym)
{
	int i;
	if(sym>='0' && sym<='9')
	{
		st->top=st->top+1;
		st->items[st->top]=sym;
		for(i=st->top;i>=0;i--)
        {
            printf("|%d|\n",st->items[i]);
        }
	}
}
void pop(struct stack*)
{
	
}
