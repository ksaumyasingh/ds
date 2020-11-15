#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	char data;
	struct node *right;
};

struct node *create();
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);

int main()
{
	struct node *root;
	root=create();
	printf("\nThe tree via inorder traversal\n");
	inorder(root);
	printf("\nThe tree via preorder traversal\n");
	preorder(root);
	printf("\nThe tree via postorder traversal\n");
	postorder(root);
	return 0;
}

struct node *create()
{
	struct node *nn;
	int ch;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf(" %c",&nn->data);
	nn->left=NULL;
	nn->right=NULL;
	printf("press 1 if node %c has left node else 0\n",nn->data);
    scanf("%d",&ch);
    if(ch)
        nn->left=create();
    printf("press 1 if node %c has Right node else 0\n",nn->data);
    scanf("%d",&ch);
    if(ch)
        nn->right=create();
    return nn;
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		printf(" %c ", root->data);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		printf(" %c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf(" %c ", root->data);
	}
}
