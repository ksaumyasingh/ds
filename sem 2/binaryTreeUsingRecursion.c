#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	struct NODE *left;
	char data;
	struct NODE *right;
}node;
node * create();
void inorder(node *);
void postorder(node *);
void preorder(node *);
void main()
{
	node *root=NULL;
	root=create();
	printf("\n though inorder traversal \n");
	inorder(root);
	printf("\n though preorder traversal\n");
	preorder(root);
    printf("\n though postorder traversal\n");
	postorder(root);

}
node* create()
{
	node *newnode;
	int choice;
	newnode=(node *)malloc(sizeof(node));
	printf("enter data\n");
	scanf(" %c",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	printf("press 1 if %c data has left child else 0\n",newnode->data);
	scanf("%d",&choice);
	if(choice)
			newnode->left=create();
	printf("press 1 if %c data has right child else 0\n",newnode->data);
	scanf("%d",&choice);
	if(choice)
			newnode->right=create();
	return newnode;
}
void inorder(node * root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		printf(" %c",root->data);
		inorder(root->right);
	}
}	
void postorder(node * root)
{
	if(root==NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf(" %c",root->data);
	}
}
void preorder(node * root)
{
	if(root==NULL)
		return;
	else
	{
		printf(" %c",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}