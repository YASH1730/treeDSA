#include<stdio.h>
#include<stdlib.h>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *createNode(int data)
{
    struct tree * newNode = (struct tree *) malloc(sizeof(struct tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct tree *insert(struct tree * root,int data)
{
    if(root == NULL)
    {
        root = createNode(data);
        return root;
    }
    else if (data > root->data){
        if(root!=NULL)
        {
            root->right = insert(root->right,data);
        }
    }
    else if (data < root->data){
        if(root!=NULL)
        {
            root->left = insert(root->left,data);
        }
    }
    else {
        printf("Cannot insert a data brecause {%d} is already exist!!!",root->data);
        printf("Enter the diffrent data :: ");
        scanf("%d",&data);
        insert(root,data);
    }
    return root;
    
}
void inorder(struct tree * root){
    if(root!=NULL)
    {
        inorder(root->left);
        printf("{%d}-",root->data);
        inorder(root->right);
    }
}

int srearch(struct tree *root,int data)
{
    while(root!=NULL)
    {
        // printf("%d->",root->data);
        if(root->data == data)
        {
        printf("DATA :: {%d} is Found",root->data);    
        return 1;
        }
        else if(root->data > data)
        {
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    printf("\nNOt Found");
    return 0;

}


void main(){
    struct tree *root = NULL;
    
    int i = 5,data;

     while (i--) 
     {
         printf("Enter the data :: ");
         scanf("%d",&data);
         root = insert(root,data);
     }
    
     printf("\ntravers\n");
     inorder(root);
     
     printf("\nsearch\n");
        printf("Enter the data for search :: ");
        scanf("%d",&data);
     
     srearch(root,data);


    }