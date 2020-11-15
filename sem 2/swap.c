    #include <stdio.h>  
       
    //Represent a node of the singly linked list  
    struct node{  
        int data;  
        struct node *next;  
    };      
       
    //Represent the head and tail of the singly linked list  
    struct node *head, *tail = NULL;  
       
    //addNode() will add a new node to the list  
    void addNode(int data) {  
        //Create a new node  
        struct node *newNode = (struct node*)malloc(sizeof(struct node));  
        newNode->data = data;  
        newNode->next = NULL;  
          
        //Checks if the list is empty  
        if(head == NULL) {  
            //If list is empty, both head and tail will point to new node  
            head = newNode;  
            tail = newNode;  
        }  
        else {  
            //newNode will be added after tail such that tail's next will point to newNode  
            tail->next = newNode;  
            //newNode will become new tail of the list  
            tail = newNode;  
        }  
    }  
       
    //swap() will swap the given two nodes  
    void swap(int n1, int n2){  
        struct node *prevNode1 = NULL, *prevNode2 = NULL, *node1 = head, *node2 = head, *temp = NULL;  
          
        //Checks if list is empty  
        if(head == NULL) {  
            return;  
        }  
              
        //If n1 and n2 are equal, then list will remain the same  
        if(n1 == n2)  
            return;  
          
        //Search for node1  
        while(node1 != NULL && node1->data != n1){  
            prevNode1 = node1;  
            node1 = node1->next;  
        }  
          
        //Search for node2  
        while(node2 != NULL && node2->data != n2){  
            prevNode2 = node2;  
            node2 = node2->next;  
        }  
          
        if(node1 != NULL && node2 != NULL) {  
              
            //If previous node to node1 is not null then, it will point to node2  
            if(prevNode1 != NULL)  
                prevNode1->next = node2;          
            else  
                head  = node2;  
              
            //If previous node to node2 is not null then, it will point to node1  
            if(prevNode2 != NULL)  
                prevNode2->next = node1;  
            else  
                head  = node1;  
              
            //Swaps the next nodes of node1 and node2  
            temp = node1->next;   
            node1->next = node2->next;   
            node2->next = temp;       
        }      
        else{  
            printf("Swapping is not possible\n");  
        }  
    }  
          
    //display() will display all the nodes present in the list  
    void display() {  
        //Node current will point to head  
        struct node *current = head;  
          
        if(head == NULL) {  
            printf("List is empty\n");  
            return;  
        }  
        while(current != NULL) {  
            //Prints each node by incrementing pointer  
            printf("%d ", current->data);  
            current = current->next;  
        }  
        printf("\n");  
    }  
          
    int main()  
    {  
        //Add nodes to the list  
        addNode(1);  
        addNode(2);  
        addNode(3);  
        addNode(4);  
        addNode(5);  
          
        printf("Original list: \n");  
        display();  
          
        //Swaps the node 2 with node 5  
        swap(2,5);  
          
        printf("List after swapping nodes: \n");  
        display();  
       
        return 0;  
    }  