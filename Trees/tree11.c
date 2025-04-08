// C program to delete a node in a binary tree
// using level order traversal
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void findAndDeleteDeepest(struct node* root, struct node* del_node) {
    if (root == NULL) return;

    if (root->left) {
        if (root->left == del_node) {
            free(root->left);
            root->left = NULL;
            return;
        } else findAndDeleteDeepest(root->left, del_node);
    }

    if (root->right) {
        if (root->right == del_node) {
            free(root->right);
            root->right = NULL;
            return;
        } else findAndDeleteDeepest(root->right, del_node);
    }
}

struct node* deleteBT(struct node* root, int key) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        }
        return root;
    }

    struct node* key_node = NULL;
    struct node* temp = NULL;
    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];

        if (temp->data == key)
            key_node = temp;

        if (temp->left)
            queue[rear++] = temp->left;

        if (temp->right)
            queue[rear++] = temp->right;
    }

    if (key_node) {
        key_node->data = temp->data; // Replace with deepest node
        findAndDeleteDeepest(root, temp);
    }

    return root;
}

