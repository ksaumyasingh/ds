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
node *searchelement(node *root,int element)
{
	if(root==NULL)
		return root;
	else
	{
		searchelement(root->left,element);
		if(root && root->key==element)
			return root;
		searchelement(root->right,element);
	}
}
node *searchparent(node *root,int element)
{
	if(root==NULL)
		return root;
	else
	{
		searchparent(root->left,element);
		if((root && root->left && (root->left)->key==element)||(root && root->right && (root->right)->key==element))
			return root;
		searchparent(root->right,element);
	}
}
node *successor(node *parent,int element)
{
	if(!parent)
		return NULL;
	if(parent->left==NULL)
		return parent;
	else
	{
		while(parent->right && ((parent->right)->left)!=NULL)
			parent->right=(parent->right)->left;
		return parent->right;
	}
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
node * deletion(node *root,int element)	
{
	node *delNode,*delParent,*successorNode,*successorParent;
	printf("\ngoing to search element\n");
	delNode=searchelement(root,element);
	printf("\n delNode=%d",delNode->key);
	delParent=searchparent(root,element);
	printf("delParent=%d",delParent->key);
	if(delNode==NULL)
		printf("element not present in tree");
	else
	{
		if(delNode->right==NULL && delNode->left==NULL)
		{
			if((delParent)->left && ((delParent)->left)->key==element)
				delParent->left==NULL;
			else
				delParent->right==NULL;
			free(delNode);
		}
		else if((delNode->left)->left==NULL && (delNode->left)->right==NULL)
			{
				if(((delParent)->left)->key==element)
					delParent->left==delNode->left;
				else
					delParent->right==delNode->left;
				free(delNode);
			}
			else if((delNode->right)->left==NULL && (delNode->right)->right==NULL)
				{
					if(((delParent)->left)->key==element)
						delParent->left==delNode->right;
					else
						delParent->right==delNode->right;
					free(delNode);
				}
				else
				{
					successorNode=successor(delNode,element);
					if(((delParent)->left)->key==element)
						delParent->left==successorNode;
					else
						delParent->right==successorNode;
					if(successorNode->right!=NULL)
					{
						successorParent=searchparent(root,successorNode->key);
						if((successorParent->left)->key==successorNode->key)
							successorParent->left==successorNode->right;
						else
							successorParent->right==successorNode->right;
					}
					successorNode->left=delNode->left;
					successorNode->right=delNode->right;
					free(delNode);
				}		
	}
	return root;
		
}

node* inputData(node * root){

		root=insert(root,5);
		root=insert(root,3);
		root=insert(root,7);
		root=insert(root,2);
		root=insert(root,4);
		root=insert(root,6);
		root=insert(root,8);
		return root;

}
void main()
{
	node *root=NULL;
	root = inputData(root);
	
	/*int element,choice;
	do
	{
		printf("enter key");
		scanf("%d",&element);
		root=insert(root,element);
		printf("press 1 to enter more else 0 ");
		scanf("%d",&choice);
	}
	while(choice);*/
	
	inorderTraversal(root);
	printf("\n enter element to be deleted");
	
	/*scanf("%d",element);
	root=deletion(root,element);	*/
	
	root=deletion(root,8);
	//inorderTraversal(root);
}