// Create a tree with root node with left and right child as NULL

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createTree(struct node *root, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

int main(){
    struct node *root = NULL;
    root = createTree(root, 50);
    printf("Root node created with data: %d\n", root->data);
    free(root);
    return 0;
}