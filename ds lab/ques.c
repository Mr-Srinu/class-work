#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct queue
{
	int items[MAX];
	int rear;
	int front;
};
void enque(struct queue*,int);
int deque(struct queue*);
void display(struct queue*);
int main()
{
	struct queue qp;
	qp.rear=-1;
	qp.front=0;
	int ele,ch;
	while(1)
	{
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("---------MENU----------\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("1.enque\n");
	printf("2.deque\n");
	printf("3.Display \n");	
	printf("4.Exit \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("enter your choice:");
	scanf("%d",&ch);
	switch (ch)
        {
        case 1:
                printf("\nEnter element to insert\n");
                scanf("%d",&ele);
                enque(&qp,ele);
                break;
        case 2:
                ele=deque(&qp);
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
                display(&qp);
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
void enque(struct queue *qpp,int ele)
{
	if (qpp->rear==MAX-1)
	{
		printf("stack overflow");
	}
	else
	{
		qpp->rear=qpp->rear+1;
		qpp->items[qpp->rear]=ele;
	}
}
int deque(struct queue *qpp)
{
    int ele;
    if(qpp->rear<qpp->front)
    {
        return -1;
    }
    else
    {
        ele=qpp->items[qpp->front];
        qpp->front=qpp->front+1;
        return ele;
    }
}
void display(struct queue *qpp)
{
    if(qpp->front>qpp->rear)
    {
        printf("queue is empty");
    }
    else
    {
        for(qpp->front=0;qpp->front<=qpp->rear;qpp->front++)
        {
            printf("|%d|\n",qpp->items[qpp->front]);
        }
    }
}
