#include<stdio.h>
#include<stdlib.h>


struct tree{
int data;
struct tree * left;
struct tree * right;
};

void pretravers(struct tree * root){
    if(root != NULL)
    {
        printf("{%d}->",root->data);
        pretravers(root->left);  
        pretravers(root->right);  
    }

}
void posttravers(struct tree * root){
    if(root != NULL)
    {
        posttravers(root->left);  
        posttravers(root->right);  
        printf("{%d}->",root->data);
    }

}
void intravers(struct tree * root){
    if(root != NULL)
    {
        intravers(root->left);  
        printf("{%d}->",root->data);
        intravers(root->right);  
    }

}

struct tree * createNode(int n)
{
    struct tree *newNode = (struct tree *) malloc(sizeof(struct tree));
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct tree * insertNode(struct tree * root,int data)
{
    if(root == NULL)
    {
        root = createNode(data);
    }
    else if(data >= root->data) {
        
        if (root != NULL)
        {
            root->right = insertNode(root->right,data);
        }
    }
    else{
        if (root != NULL)
        {
            root->left = insertNode(root->left,data);
        }
    }

    return root;

}

void main(){

    struct tree *root = NULL;
    int i = 5;
    int n;
    while (i>0)
    {
        printf("Enter the number :: ");
        scanf("%d",&n);
        root = insertNode(root,n);
        i--;
    }
    printf("\n\tpre\t\n");
    pretravers(root);
    printf("\n\tpost\t\n");
    posttravers(root);
    printf("\n\tin\t\n");
    intravers(root);
    }
