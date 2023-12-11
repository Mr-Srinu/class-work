#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct stack
{
	int items[MAX];
	int top;
};
void push(struct stack*,int);
int pop(struct stack*);
int peek(struct stack*);
void display(struct stack*);
int main()
{
	struct stack st;
	st.top=-1;
	int ele,ch;
	while(1)
	{
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("---------MENU----------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("1.Push \n");
	printf("2.Pop \n");
	printf("3.Display \n");	
	printf("4.Peek \n");
	printf("5.Exit \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("enter your choice:");
	scanf("%d",&ch);
	switch (ch)
        {
        case 1:
                printf("\nEnter element to insert\n");
                scanf("%d",&ele);
                push(&st,ele);
                break;
        case 2:
                ele=pop(&st);
                if(ele==-1)
                {
                    printf("Stack is empty");
                }
                else
                {
                    printf("Removed element is %d\n",ele);
                }
                break;
        case 3:
                display(&st);
                break;
        case 4:
                ele=peek(&st);
                if(ele==-1)
                {
                    printf("Stack is empty");
                }
                else
                {
                    printf("First element is %d\n",ele);
                }
                break;
        case 5:
                exit(0);
                break;
        default:
                printf("Invalid Choice");  
                break;
        }
    }
  return 0;
}
void push(struct stack *stp,int ele)
{
	if (stp->top==MAX-1)
	{
		printf("stack overflow");
	}
	else
	{
		stp->top=stp->top+1;
		stp->items[stp->top]=ele;
	}
}
int pop(struct stack *st)
{
    int ele;
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        ele=st->items[st->top];
        st->top=st->top-1;
        return ele;
    }
}
int peek(struct stack *st)
{
    int ele;
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        ele=st->items[st->top];
        return ele;
    }
}
void display(struct stack *st)
{
    int i;
    if(st->top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(i=st->top;i>=0;i--)
        {
            printf("|%d|\n",st->items[i]);
        }
    }
}
