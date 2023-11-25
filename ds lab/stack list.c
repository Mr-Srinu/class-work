#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct stack
{
	struct node * top;
};
struct node * getNode();
void push(struct stack*,int);
int pop(struct stack*);
int peek(struct stack*);
void display(struct stack*);
int main()
{
	struct stack st;
	st.top=NULL;
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
struct node* getNode()
{
	struct node * newnode;
	newnode=(struct node*)malloc(sizeof(newnode));
	newnode->data=0;
	newnode->next=NULL;
	return newnode;
}
void push(struct stack *stp,int ele)
{
	struct node * newnode;
	newnode=getNode();
	newnode->data=ele;
	if(stp->top==NULL)
	{
		stp->top=newnode;
	}
	else
	{
		newnode->next=stp->top;
		stp->top=newnode;
	}
}
int pop(struct stack *st)
{
    int ele;
    if(st->top==NULL)
    {
    	return -1;
	}
	else
	{
		ele=st->top->data;
		st->top=st->top->next;
		return ele;
	}
}
int peek(struct stack *st)
{
    int ele;
    if(st->top==NULL)
    {
    	return -1;
	}
	else
	{
		ele=st->top->data;
		return ele;
	}
}
void display(struct stack *st)
{
	struct node *temp;
	temp=st->top;
    if(temp==NULL)
    {
    	printf("stack is empty");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("|%d|\n",temp->data);
			temp=temp->next;
		}
	}
}
