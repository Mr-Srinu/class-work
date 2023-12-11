#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
 
struct node * getNode();
struct node * create(struct node *);
void insert(struct node *,struct node *);
void inOrder(struct node *);
void preOrder(struct node *);
void postOrder(struct node *);
void delet1(struct node*,struct node*);
void nochild(struct node *, struct node* );
void leftchild(struct node*,struct node*);
void rightchild(struct node*, struct node*);
void twochilds(struct node*,struct node*);
void delete(struct node *, int);
struct node *minValueRST(struct node* );
int search(struct node*,int);

struct node *getNode()
{
    struct node *newnode;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data =0;
    newnode->left =NULL;
    newnode->right=NULL;
    return newnode;
}
struct node * create(struct node * root)
{
   struct node *newnode;
   newnode =getNode();
   printf("Enter the data into the node:");
   scanf("%d",&newnode->data);
   while (newnode->data!=-1)
   {
        if(root == NULL)
        {
            root = newnode;
        }
        else
        {
            insert(root,newnode);
            newnode = getNode();
            printf("Enter the data into the node:");
            scanf("%d",&newnode->data);
        }
   }
   return root;
   
}
void insert(struct node *root,struct node *newnode)
{
    if(newnode->data < root->data)
    {
        if(root->left == NULL)
        {
            root->left = newnode;
        }
        else
        {
            insert(root->left,newnode);
        }
    }
    if(newnode->data > root->data)
    {
        if(root->right == NULL)
        {
            root->right = newnode;
        }
        else
        {
            insert(root->right,newnode);
        }
    }
}

void inOrder(struct node *temp)
{
    if(temp!=NULL)
    {
        inOrder(temp->left);
        printf("%d \t",temp->data);
        inOrder(temp->right);
    }
}
void preOrder(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d \t",temp->data);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}
void postOrder(struct node *temp)
{
    if(temp!=NULL)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        printf("%d \t",temp->data);
    }
}
int search(struct node* root,int k)
{
	if(root==NULL)
	{
		return -1;
	}
	else
	{
		if(k<root->data)
		{
			search(root->left,k);
		}
		else if(k>root->data)
		{
			search(root->right,k);
		}
		else
		{
			return 1;
		}
	}
}

void nochild(struct node* parent,struct node *p)
{
	if(parent->left==p)
	{
		parent->left=NULL;
	}
	else
	{
		parent->right=NULL;
	}
	free(p);
}
void leftchild(struct node* parent, struct node* p)
{
	if(parent->left==p)
	{
		parent->left=p->left;
	}	
	else
	{
		parent->right=p->left;
	}
	p->left=NULL;
	free(p);

}
void rightchild(struct node* parent, struct node* p)
{
	if(parent->left==p)
	{
		parent->left=p->right;
	}
	else
	{
		parent->right=p->right;
	}
	p->right=NULL;
	free(p);
}
void twochilds(struct node* parent,struct node* p)
{
	int k;
	struct node* temp;
	temp=minValueRST(p->right);
	printf("Min in right Sub Tree %d",temp->data);
	k=p->data;
	p->data=temp->data;
	temp->data=k;
	delete(parent->right, temp->data);
}
struct node *minValueRST(struct node* p)
{
	while(p->left!=NULL)
		p=p->left;
	return p;
}
void delete(struct node* p, int k)
{
	int c=0;
	struct node* parent;
	parent=p;
	if(p==NULL)
	{
		printf("\n No elements in BST");
	}
	else
	{
		while(p!=NULL)
		{
			if(p->data==k)
			{
				c++;
				delete1(parent,p);
				break;
			}
			if(k<p->data)
			{
				parent=p;
				p=p->left;
			}
			else
			{
				parent=p;
				p=p->right;
			}
		}
		if(c==0)
		{
			printf("No element found!\n");
		}
		else
		{
			printf("element deleted succesfully!\n");
		}
	}

}
void delete1(struct node* parent,struct node *p)
{
	if(p->left==NULL && p->right==NULL)
	{
		nochild(parent,p);
	}
	else if(p->left!=NULL && p->right==NULL)
	{
		leftchild(parent,p);
	}
	else if(p->left==NULL && p->right!=NULL)
	{
		rightchild(parent,p);
	}
	else if(p->left!=NULL && p->right!=NULL)
	{
		twochilds(parent,p);
	}
}
void main()
{
    struct node *root,*newnode;
    int ch,ele,k;
    root=NULL;
    root=create(root);
    while(1)
    {
        printf("\n1.inorder\n2.preorder\n3.postorder\n4.search\n5.insert\n6.Delete\n7.Exit\n\n");
		printf("Ennter Your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
			printf("\nElement in InOrder : \n");
            inOrder(root);
            break;
        case 2:
			printf("\nElement in PreOrder : \n");
            preOrder(root);
            break;
        case 3:
			printf("\nElement in PostOrder : \n");
            postOrder(root);
            break;
        case 4:
        	printf("\nenter a key value to search: ");
        	scanf("%d",&k);
        	ele=search(root,k);
        	if(ele==-1)
        	{
        		printf("element not found!");
			}
			else
			{
				printf("element found!");
			}
			break;
		case 5:
			newnode = getNode();
            printf("\nEnter the data into the node:");
            scanf("%d",&newnode->data);
			insert(root,newnode);
			inOrder(root);
			break;
		case 6:
			printf("enter element to delete: ");
			scanf("%d",&k);
			delete(root,k);
			printf("\n");
			inOrder(root);
			break;
        case 7:
			exit(0);
            break;
        default: 
			printf("Invalid choice");
            break;
        }
    }
}

