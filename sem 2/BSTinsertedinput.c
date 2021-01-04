#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	struct NODE *left;
	int key;
	struct NODE *right;
}node;
node * createNode(int item)
{
	node *newnode;
	newnode=(node *)malloc(sizeof(node));
	newnode->key=item;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;	
}
node* insert(node *root,int element)
{
	if(root==NULL)
		return createNode(element);
	else
	{
	
		if(root->key>element)
			root->left=insert(root->left,element);
		else if(root->key<element)
			root->right=insert(root->right,element);
			else
				printf("element already exist");
	}
	return root;
}
void inorderTraversal(node * root)
{
	if(root==NULL)
		return;
	else
	{
		inorderTraversal(root->left);
		printf(" %d ",root->key);
		inorderTraversal(root->right);
	}
}	

void main()
{
	node *root=NULL;
	int element,choice;
	root=insert(root,10);
	root=insert(root,6);
	root=insert(root,11);
	root=insert(root,5);
	root=insert(root,7);
	while(choice);	
	inorderTraversal(root);
}