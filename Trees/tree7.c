//iterative code for inorder,preorder and postorder traversal of binary tree
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderIterative(struct node* root) {
    struct node* stack[100];
    int top = -1;
    struct node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void preorderIterative(struct node* root) {
    if (root == NULL) return;

    struct node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct node* curr = stack[top--];
        printf("%d ", curr->data);

        // Push right first so left is processed first
        if (curr->right) stack[++top] = curr->right;
        if (curr->left)  stack[++top] = curr->left;
    }
}

void postorderIterative(struct node* root) {
    if (root == NULL) return;

    struct node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        struct node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->left)  stack1[++top1] = curr->left;
        if (curr->right) stack1[++top1] = curr->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder: ");
    inorderIterative(root);
    printf("\n");

    printf("Preorder: ");
    preorderIterative(root);
    printf("\n");

    printf("Postorder: ");
    postorderIterative(root);
    printf("\n");

    return 0;
}
