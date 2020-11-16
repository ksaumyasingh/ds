#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int key;
    struct node *left, *right;
};
  

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d,", root->key);
        inorder(root->right);
    }
}
  

struct node* insert(struct node* node, int key)
{
  
    if (node == NULL) return newNode(key);
 
  
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    return node;
}
struct node * search_node(struct node *root, int ele) //root 5  , 2, 3
{
	struct node *ptr=NULL;
	

	if( root->key == ele)
	{
		ptr=root;
		return ptr;	
	}
	else if(root->key > ele)
	{
		ptr = search_node(root->left, ele);
	}
	else if(root->key < ele)
	{
		ptr = search_node(root->right, ele);
	}
	return ptr;
}
struct node * find_parent(struct node *root, struct node * ptr)
{
	if(root == NULL)
		return root;
	else
	{
		if(root->left == ptr || root->right == ptr) 
		{
			return root;
		}
		else if(root->key > ptr->key)
		{
			root= find_parent(root->left, ptr);	
		}
		else if(root->key < ptr->key)
		{
			root=find_parent(root->right, ptr);
		}
	}
	return root;
}
struct node *findSuccessor(struct node *root, struct node *ptr)
{
	struct node *temp;
	temp = ptr->right;
	while(temp->left != NULL)
	{
		temp= temp->left;
	}
	return temp;
}
int main()
{
	int ele,choice,delnode;
    struct node *root = NULL, *ptr=NULL, *parent=NULL, *successor=NULL, *temp= NULL;
    do
    {
    	printf("Enter data");
    	scanf("%d",&ele);
    	root = insert(root, ele);
    	printf("Enter more data 1.Yes 0. No");
    	scanf("%d",&choice);
	}while(choice ==1);
	
    
    // print inoder traversal of the BST
    inorder(root);
    
    printf("\nEnter the node to be deleted");
    scanf("%d",&delnode);
    ptr=search_node(root, delnode);
    printf("\nThe element found is %d",ptr->key);
    
	parent = find_parent(root, ptr);
    printf("\nParent of %d is %d",ptr->key, parent->key);
  	
  	//Check if the node to be deleted is a leaf node/has one child/has 2 children i.e. case 1 or case 2 or case 3
  	//CASE 1
	if(ptr->left == NULL && ptr->right == NULL) //Check if ptr is a leaf node
  	{
  		if(parent->left ==	ptr)	//Check if ptr is left child of it's parent 
  			parent->left = NULL;
  			
  		else if(parent->right == ptr) //Check if ptr is right child of it's parent 
  			parent->right = NULL;
	}
	
	//CASE 2: ptr has one child node
	else if(ptr->left != NULL && ptr->right == NULL) // check if ptr has a left child and right child is absent
	{
		if(parent->left == ptr) 		// ptr is a left child of its parent
		{
			parent->left = ptr->left;			
		}
		
		if(parent->right== ptr)		// ptr is a right child of its parent
		{
			parent->right = ptr-> left;
		}
		
	}
	else if(ptr->left == NULL && ptr->right != NULL) // check if ptr has a right child and left child is absent
	{
		if(parent->left->key == ptr->key) 		// ptr is a left child of its parent
		{
			parent->left = ptr->right;			
		}
		
		if(parent->right->key == ptr->key)		// ptr is a right child of its parent
		{
			parent->right = ptr-> right;
		}
	}
	else if (ptr->left != NULL && ptr->right != NULL) //CASE 3
	{
		successor = findSuccessor(root, ptr);
		printf("Successor of %d is %d", ptr->key, successor->key);
		if(successor->right != NULL)
		{
			ptr->key = successor->key;
			successor->key = successor->right->key;
			temp= successor->right;
			successor->right= NULL;
			free(temp);
		}
		else
		{
			
			parent= find_parent(root, successor);
			ptr->key = successor->key;
			if(successor != ptr->right)
				parent->left = NULL;
			else
				ptr->right = successor->right;
			free(successor);
		}
	}
	//free(ptr);
	printf("\n After deletion, the elements in the list are: ");
	inorder(root);
	
    
    return 0;
}