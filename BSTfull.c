#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left ;
    struct node* right;
   

};
struct node* insertBST(struct node* root , int num){


if(root == NULL)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
newNode->left = NULL;
newNode->right = NULL;
newNode->data = num;
    root = newNode;
    return root;
}

else{
 if(num > root->data){
    root->right = insertBST(root->right , num);
}
 else if(num < root->data){
    root->left = insertBST(root->left , num);
}
else
{
    printf("Duplicates are not allowed\n");

}
return root;

}


}
void displayBST(struct node* root){

if(root != NULL){
 displayBST(root->left);
printf("%d ",root->data);
displayBST(root->right);
}

}

int search(struct node* root , int num){

    if(root == NULL)
    return 0;

    else{
        if(num == root->data)
        return 1;
        else if(num > root->data)
        return search(root->right , num);

        else if(num < root->data)
        return search(root->left , num);
    }
}

struct node* getSucc(struct node* root )
{
    //struct node* curr = root->right;

    if((root != NULL) && (root->left == NULL))
    return root;
    else
    root->left =  getSucc(root->left);

}

struct node* delete(struct node* root , int num ){

if(root == NULL)
return root;

if(num > root->data)
root->right =  delete(root->right , num);

else if(num < root->data)
root->left = delete(root->left , num);

else {
    if(root->left == NULL)
    {
        struct node* temp = root->right;
        free(root);
        return temp;

    }

    else if(root->right == NULL){
        struct node* temp = root->left;
        free(root);
        return temp;
    }

    else{
        struct node* succ = getSucc(root->right);
        root->data = succ->data;
        root->right = delete(root->right , succ->data);
    }
}
return root;
}
int main(){
    struct node* root = NULL;

    int num;
    printf("menu\n");

    while(1){
        printf("1.insert in BST\n");
        printf("2.search in BST\n");
        printf("3.deletion in BST\n");
        printf("4.display in BST\n");
        printf("5.exit\n");

        int ch;
        printf("enter your choice\n");
        scanf("%d" , &ch);

        switch(ch){
            case 1:
            printf("Enter data to insert\n");
            scanf("%d",&num);
           root =  insertBST(root,num);
            break;

            case 2:
            printf("Enter data to search for in BST\n");
            scanf("%d",&num);
          
            if(search(root,num))
            printf("Data found in BST!\n");
            else
            printf("Data not found in BST!\n");
            break;

            case 3:
            printf("Enter data to delete in BST\n");
            scanf("%d",&num);
            root = delete(root,num);
            if(root == NULL)
            printf("BST is empty\n");
            else
            printf("Deleted\n");
            break;

            case 4:
            printf("displaying BST in inorder\n");
            displayBST(root);
            printf("\n");
            break;
            case 5:
            exit(0);
            break;

            default :
            printf("Invalid input\n");

        }
    }


}