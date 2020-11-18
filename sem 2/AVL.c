#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
typedef struct NODE
{
	int data,height;
	struct NODE *left,*right;
}node;
int height(node * root)
{
	if(!root)
		return -1;
	else
		return root->height;
}
node * singleRotateLeft(node *x)
{
	node *w=x->left;
	x->left=w->right;
	w->right=x;
	x->height=fmax(height(x->left),height(x->right))+1;
	w->height=fmax(height(w->left),x->height)+1;
	return w;
}
node * singleRotateRight(node *w)
{
	node *x=w->right;
	w->right=x->left;
	x->left=w;
	w->height=fmax(height(w->right),height(w->left))+1;
	x->height=fmax(height(x->right),w->height)+1;
	return x;
}
node * doubleRotationLeft(node *z)
{
	z->left=singleRotateRight(z->left);
	return singleRotateLeft(z); 
}
node * doubleRotationRight(node *z)
{
	z->right=singleRotateLeft(z->right);
	return singleRotateRight(z); 
}
node * insertion(node *root,node *parent,int data)
{
	if(!root)
	{
		root=(node *)malloc(sizeof(node));
		if(!root)
		{
			printf("memory error");
		}
		else
		{
			root->data=data;
			root->left=root->right=NULL;
			root->height=0;
		}
	}
	else if(root->data>data)
		{
			root->left=insertion(root->left,root,data);
			if((height(root->left)-height(root->right))==2)
				if(data < root->left->data)
					root=singleRotateLeft(root);
				else
					root=doubleRotationLeft(root);
		}
		else if(root->data<data)
			{
				root->right=insertion(root->right,root,data);
				if((height(root->right)-height(root->left))==2)
					if(data > root->right->data)
						root=singleRotateRight(root);
					else
						root=doubleRotationRight(root);
			}
	root->height=fmax(height(root->left),height(root->right))+1;
	return root;
}
void inorder(node *root)
{
	if(!root)
		return;
	else
	{
		inorder(root->left);
		printf(" %d ",root->data);
		inorder(root->right);
	}
}
void main()
{
	node *root=NULL,*parent=NULL;
	int data,choice;
	do
	{
		printf("\n enter data\n");
		scanf("%d",&data);
		root=insertion(root,parent,data);
		printf("\n press 1 to enter more else press 0\n");
		scanf("%d",&choice);	
	}
	while(choice);
	printf("\n avl tree \n");
	inorder(root);
}