#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* getNode();
struct node* create();
void traversal(struct node*);
struct node *enque(struct node *);
struct node *deque(struct node *);

int main()
{
    int ch;
    struct node *first;
    first = create();
    traversal(first);
    while (1)
    {
        printf("\n**************\nMENU\n***********\n");
        printf("\n1.insert\n2.display\n3.Delete\n4.Exit\n");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = enque(first);
            traversal(first);
            break;
        case 2:
            traversal(first);
            break;
        case 3:
            first = deque (first);
            traversal(first);
            break;
        case 4:
            exit(0);

        default:printf("Invalid Choice");
        }
    }
    return 0;
}
struct node * getNode()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=0;
    newnode->next =NULL;
    return newnode;
}
struct node * create()
{
    struct node *head,*first,*newnode;
    first=getNode();
    head=first;
    newnode = getNode();
    printf("Enter value");
    scanf("%d",&newnode->data);
    while (newnode->data!=-1)
    {
        first->next = newnode;
        first=newnode;
        newnode=getNode();
        printf("Enter value");
        scanf("%d",&newnode->data);
        newnode->next = head->next;

    }
    
    return head->next;
}

struct node *enque(struct node *head)
{
    struct node *temp , *newnode;
    int ch,pos,i;
    temp = head;
    newnode = getNode();
    printf("enter value:");
    scanf("%d",&newnode->data);
    while(1)
    {
        printf("\n1.at begining\n2. at end\n3. at given position\n");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                    while(temp->next!=head)
                    {
                        temp=temp->next;
                    }
                    newnode->next=head;
                    temp->next = newnode;
                    head=newnode;
                    return head;
                    break;
            case 2:
                    while(temp->next!=head)
                    {
                        temp=temp->next;
                    }
                    newnode->next=head;
                    temp->next = newnode;
                    return head;
                    break;
            case 3: 
                    printf("enter which position");
                    scanf("%d",&pos);
                    if(pos==1)
					{
                        while(temp->next!=head)
                        {
                            temp=temp->next;
                        }
                        newnode->next=head;
                        temp->next = newnode;
                        head=newnode;
                        return head;
                    }
                    else
					 {
                        for(i=1;i<pos-1;i++)
                        {
                            temp=temp->next;
                        }
                        newnode->next=temp->next;
                        temp->next=newnode;
                        return head;
                    }
            default:
				printf("Invalid Choice");
     }

    }
}
void traversal(struct node *head)
{
    struct node *temp;
    temp=head;
    if(head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        while (temp->next!=head)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d->",temp->data);
    }
    
}

struct node *deque(struct node *head){
    int ch,pos,i;
    struct node *temp,*temp2;
    temp = head;

    if (temp==NULL){
        printf("list is empty");
    }
    else{
        printf("\n1.at begining\n2. at end\n3. at given position");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(temp->next==head)
                {
                    head=NULL;
                    return head;
                }
                else
                {
                    while(temp->next!=head)
                    {
                        temp=temp->next;
                    }
                    temp2=head->next;
                    temp->next = temp2;
                    head->next=NULL;
                    return temp2;
                }
                break;
            case 2:
                    if(temp->next==head)
                    {
                        head=NULL;
                        return head;
                    }
                    else
                    {
                        while(temp->next->next!=head)
                        {
                            temp=temp->next;
                        }
                        temp->next=head;
                        return head;
                    }
                break;
            case 3 :
                printf("enter which position");
                scanf("%d",&pos);
                if(pos==1)
                {
                    if(temp->next==head)
                        {
                            head=NULL;
                            return head;
                        }
                        else
                        {
                            while(temp->next!=head)
                            {
                                temp=temp->next;
                            }
                            temp2=head->next;
                            temp->next = temp2;
                            head->next=NULL;
                            return temp2;
                        }
                }
                else{
                    for(i=1;i<pos-1;i++)
                    {
                        temp=temp->next;

                    }
                    temp->next=temp->next->next;
                    return head;
                }
                break;
        }       
    }
}
