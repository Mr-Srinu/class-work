#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
	struct node * prev;
};
struct node * getNode();
struct node * create();
void travesal(struct node*);
struct node* insert(struct node*,int);
struct node* delete(struct node*);
void reverse(struct node*);
int search(struct node*);
void main()
{
	
	struct node* first;
	int ele,ch;
	first=create();
	travesal(first);
	while(1)
	{
	printf("\n 1.insert\n 2.delete\n 3.display\n 4.reverse\n 5.search\n 6.exit");
	printf("\nenter your choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("enter element to insert:");
			scanf("%d",&ele);
			first=insert(first,ele);
			travesal(first);
			break;
		case 2:
			first=delete(first);
			travesal(first);
			break;
		case 3:
			travesal(first);
			break;
		case 4:
			reverse(first);
			break;
		case 5:
			ele=search(first);
			if(ele==-1)
			{
				printf("element not found");
			}
			else
			{
				printf("element found at position %d :",ele);
			}
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("invalid choice");
			break;
	}
 }
 
}
struct node* getNode()
{
	struct node * newnode;
	newnode=(struct node*)malloc(sizeof(newnode));
	newnode->data=0;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
struct node * create()
{
	struct node* first,*head,*newnode;
	first=getNode();
	head=first;
	newnode=getNode();
	printf("enter value into node:");
	scanf("%d",&newnode->data);
	while(newnode->data!=-1)
	{
		first->next=newnode;
		first=newnode->prev;
		first=newnode;
		newnode=getNode();
		printf("enter value into node:");
		scanf("%d",&newnode->data);
	}
	return head->next;
}
void travesal(struct node *head)
{
	struct node* temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d<-->",temp->data);
		temp=temp->next;
	}
}
struct node * insert(struct node* head,int ele)
{
	struct node *temp,*newnode;
	temp=head;
	int ch,pos,i;
	newnode=getNode();
	newnode->data=ele;
	printf("\n1. insert at beginig\n 2.insert at end\n 3.insert at position\n");
	printf("\nenter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			newnode->next=head;
			head->prev=newnode;
			newnode->prev=NULL;
			head=newnode;
			return head;
			break;
		case 2:
			while(temp->next!=NULL)
			{
				temp=temp->next;      			
			}
			temp->next=newnode;
			newnode->next=NULL;
			newnode->prev=temp;
			return head;
			break;
		case 3:
			printf("enter position:");
			scanf("%d",&pos);
			for(i=0;i<pos-1;i++)
			{
				temp=temp->next;
			}
			newnode->next=temp->next;
			temp->next=newnode;
			newnode->prev=temp;
			return head;
			break;	
		default:
			printf("\n invalid choice");
			break;
	}
}
struct node* delete(struct node* head)
{
	struct node *temp,*newnode;
	temp=head;
	int i,ch,pos;
	printf("\n 1.delete at begining\n 2.delete at position\n 3.delete at end\n");
	printf("enter your choice:");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			head=head->next;
			head->prev=NULL;
			temp->next=NULL;
			return head;
			break;
		case 2:
			printf("enter position:");
			scanf("%d",&pos);
			if(pos==1)
			{
				head=head->next;
				head->prev=NULL;
				temp->next=NULL;
				return head;
			}
			for(i=0;i<pos-1;i++)
			{
				temp=temp->next;
			}
			temp->next=temp->next->next;
			temp=temp->next->prev; 
			return head;
			break;
		case 3:
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}	
			temp->next=NULL;
			return head;
			break;
	}
}
void reverse(struct node *head)
{
	struct node *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp->prev!=NULL)
	{
		printf("%d<-->",temp->data);
	}
}
int search(struct node* head)
{
	struct node *temp;
	temp=head;
	int ele,i=0;
	printf("enter element to search:");
	scanf("%d",&ele);
	while(temp!=NULL)
	{
		i=i+1;
		if(temp->data==ele)
		{
			return i;
		}
		temp=temp->next;
	}
	return -1;
}
