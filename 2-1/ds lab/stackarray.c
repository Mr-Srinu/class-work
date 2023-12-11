#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void push(int);
int pop();
int peek();
void display();
int array[MAX];
int top=-1;
int main()
{
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
	switch(ch)
	{
		case 1:
			printf("enter a value to insert:");
			scanf("%d",&ele);
			push(ele);
			break;
		case 2:
			ele=pop();
			if(ele==-1)
			{
				printf("underflow");
			}
			else
			{
			printf("removed element:%d",ele);
			}
			break;
		case 3:
			display();
			break;
		case 4:
			peek();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("invalid choice");
	}
  } 
  return 0;
}
void push(int ele)
{
	if (top==MAX-1)
	{
		printf("stack overflow");
	}
	else
	{
		top=top+1;
		array[top]=ele;
	}
}
int pop()
{
	int ele;
	if(top==-1)
	{
		return -1;
		
	}
	else
	{
		ele=array[top];
		top=top-1;
		return ele;
	}
	
}
int peek()
{
    int ele;
    if(top==-1)
    {
        return -1;
    }
    else
    {
        ele=array[top];
        return ele;
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("|%d|\n",array[i]);
        }
    }
}
