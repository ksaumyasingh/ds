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
	node *ptr=NULL;
	if(root->key==element)
	{
		ptr=root;
		return ptr;
	}
	else if(root->key > element)
		    ptr=searchelement(root->left,element);
		else if(root->key < element)
				ptr=searchelement(root->right,element);
	return ptr;
}
node *searchparent(node *root,node *delNode)
{
	if(root==NULL)
		return root;
	else
	{
		if(root->left==delNode||root->right==delNode)
			return root;
		else if(root->key>delNode->key)
				searchparent(root->left,delNode);
			else if(root->key<delNode->key)
					searchparent(root->right,delNode);
	}
}
node *successor(node *root,node *delNode)
{
	node *temp=NULL;
	temp=delNode->right;
	while(temp->left!=NULL)
		temp=temp->left;
	return temp;
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
	node *delNode=NULL,*delParent=NULL,*successorNode=NULL,*successorParent=NULL,*temp=NULL;
	printf("\ngoing to search element\n");
	delNode=searchelement(root,element);
	printf("\n delNode=%d",delNode->key);
	delParent=searchparent(root,delNode);
	printf("delParent=%d",delParent->key);
	if(delNode==NULL)
		printf("element not present in tree");
	else
	{
		if(delNode->right==NULL && delNode->left==NULL)
		{
			if(delParent->left==delNode)
				delParent->left==NULL;
			else
				delParent->right==NULL;
		}
		else if(delNode->left != NULL && delNode->right == NULL)
		{
			if(delParent->left==delNode)
				delParent->left=delNode->left;
			else if(delParent->right==delNode)
					delParent->right=delNode->left;
		}
			else if(delNode->left == NULL && delNode->right != NULL)
				{
					if(delParent->left==delNode)
						delParent->left=delNode->right;
					else
						delParent->right=delNode->right;
				}
				else
				{
					successorNode=successor(root,delNode);
					printf("successor %d",successorNode->key);
					if(successorNode->right != NULL)
					{
						delNode->key = successorNode->key;
						successorNode->key = successorNode->right->key;
						temp= successorNode->right;
						successorNode->right= NULL;
						free(temp);
					}
					else
					{
						
						successorParent= searchparent(root, successorNode);
						delNode->key = successorNode->key;
						if(successorNode != delNode->right)
							successorParent->left = NULL;
						else
							delNode->right = successorNode->right;
						free(successorNode);
					}

				}
	}
	return root;
		
}

/*node* inputData(node * root)
{

		root=insert(root,5);
		root=insert(root,3);
		root=insert(root,7);
		root=insert(root,2);
		root=insert(root,4);
		root=insert(root,6);
		root=insert(root,8);
		return root;

}*/
void main()
{
	node *root=NULL;
	//root = inputData(root);
	int element,choice;
	do
	{
		printf("enter key");
		scanf("%d",&element);
		root=insert(root,element);
		printf("press 1 to enter more else 0 ");
		scanf("%d",&choice);
	}
	while(choice);
	
	inorderTraversal(root);
	printf("\n enter element to be deleted");
	scanf("%d",&element);
	root=deletion(root,element);
	//root=deletion(root,8);
	printf("\n tree after deletion\n");
	inorderTraversal(root);
}