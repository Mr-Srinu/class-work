#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct cqueue
{
	int items[MAX];
	int rear;
	int front;
};
void enque(struct cqueue*,int);
int deque(struct cqueue*);
void display(struct cqueue*);
int main()
{
	struct cqueue qp;
	qp.rear=-1;
	qp.front=-1;
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
                	printf("underflow");
				}
				else
				{
					printf("removed element is :%d",ele);
				}
                break;
        case 3:
                printf("displaying...\n");
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
void enque(struct cqueue *qpp,int ele)
{
	if (qpp->front==0 && qpp->rear==MAX-1 || qpp->front==qpp->rear+1)
	{
		printf("queue overflow");
	}
	else{
	
		if(qpp->rear==-1)
		{
			qpp->rear=0;
			qpp->front=0;
		}
		else
		{
			if(qpp->rear==MAX-1)
			{
				qpp->rear=0;
			}
			else
			{
				qpp->rear++;
				
			}
		}
		qpp->items[qpp->rear]=ele; 
	}
}
int deque(struct cqueue *qpp)
{
	int ele;
	if (qpp->front==-1)
	{
		return -1;
	}
	else
	{
		ele=qpp->items[	qpp->front];
	}
	if(qpp->front==MAX-1)
	{
		qpp->front=0;
	}
	else if(qpp->front==qpp->rear)
	{
		qpp->front=-1;
		qpp->rear=-1;
	}
	else
	{
		qpp->front++;
	}
	return ele;
}

void display(struct cqueue *qpp)
{
	int i,j;
	if(qpp->front==-1)
	{
		printf("no elememnts");
	}
	else
	{
		if(qpp->front<=qpp->rear)
		{
			for(i=qpp->front;i<=qpp->rear;i++)
			{
				printf("|%d|\n",qpp->items[i]);
			}
		}
		else
		{
			for(j=0;j<=qpp->rear;j++)
			{
				printf("|%d|\n",qpp->items[i]);
			}
		}
	}
}
