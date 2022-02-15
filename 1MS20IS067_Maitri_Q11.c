#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

// Create Function 
struct node* create(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Display Function
void display(struct node* root)
{
    if (root != NULL) {
        display(root->left);
        printf("%d \n", root->key);
        display(root->right);
    }
}

//Insert Function 
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return create(key);

    if (key < node->key)
        node->left = insert(node->left, key);


    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}


//A function that finds the minimum node in the tree and 
//this function is needed in the delete operation
struct node* min(struct node* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}


//Delete Function
struct node* delete(struct node* root, int key)
{

    if (root == NULL){
        printf("Element not present\n");
        return root;
    }
 
    if (key < root->key)
        root->left = delete(root->left, key);


    else if (key > root->key)
        root->right = delete(root->right, key);


    else {
      
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

    
        struct node* temp = min(root->right);

        root->key = temp->key;

        root->right = delete(root->right, temp->key);
    }
    return root;
}


//Search Function
void search(struct node *root,int n)
{
   if(root==NULL)
{
    printf("\n%d not present in the tree\n",n);
    return;
} 
else if(n==root->key)
    printf("\nElement %d present in the tree\n",n);
else if(n<root->key)
    search(root->left,n);
else
    search(root->right,n);
}

void main()
{
    struct node* root = NULL;
    int choice;
    int element;
    while(1)
    {
        printf("Enter:\n1.Insert a node  2.Delete a node  3.Display  4.Search an element  5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: printf("Enter the element to be inserted: ");
                scanf("%d",&element);
                root=insert(root,element); 
                break;

        case 2:printf("\nEnter the element to be deleted: ");
                scanf("%d",&element);
                root=delete(root,element);
                break;

        case 3: printf("The contents of the tree are: \n");
                display(root);
                break;

        case 4:printf("Enter the element to be searhed: ");
                scanf("%d",&element);
                search(root,element);
                break;

        case 5: exit(0);

        default:printf("Please enter a valid choice");
                break;
        }
    }
}
