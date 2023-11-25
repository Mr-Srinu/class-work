#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct queue
{	
	struct node *rear;
	struct node *front;
};
struct node *getNode();
void enque(struct queue*,int);
int deque(struct queue*);
void display(struct queue*);
int main()
{
	struct queue qp;
	qp.rear=NULL;
	qp.front=NULL;
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
struct node* getNode()
{
	struct node * newnode;
	newnode=(struct node*)malloc(sizeof(newnode));
	newnode->data=0;
	newnode->next=NULL;
	return newnode;
}
void enque(struct queue *qp,int ele)
{
	struct node *newnode;
	newnode=getNode();
	newnode->data=ele; 
	if(qp->rear==NULL && qp->front==NULL)
	{
		qp->rear=newnode;
		qp->front=newnode;
	}
	else
	{
		qp->rear->next=newnode;
		qp->rear=newnode;
	}
}
int deque(struct queue *qpp)
{
    int ele;
    if(qpp->front==NULL)
    {
    	return -1;
	}
	else
	{
		ele=qpp->front->data;
		qpp->front=qpp->front->next;
		return ele;
	}
}
void display(struct queue *qpp)
{
	struct node *temp;
	temp=qpp->front;
    if(temp==NULL)
    {
    	printf("queue is empty");
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
