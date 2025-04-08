//Recursively search for a node in a binary search tree 
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

struct node *insertNode(struct node *root, int data)
{
    if(root == NULL){
        return createNode(data);
    }
    else if (data <= root->data){
        root->left = insertNode(root->left, data);
    }
    else{
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct node *searchNode(struct node *root, int data) {
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data){
        return searchNode(root->left, data);
    }
    else 
    return searchNode(root->right, data);
}

int main(){
    struct node *root = NULL;
    root = createNode(50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);
    if (searchNode(root, 40) != NULL) {
        printf("Node with data 40 found in the tree.\n");
    } else {
        printf("Node with data 40 not found in the tree.\n");
    }
    return 0;
}