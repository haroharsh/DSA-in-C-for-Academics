#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

int height(struct node* root) {
    if (root == NULL)
        return -1; // use 0 if you want height in terms of nodes
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int depth(struct node* root, struct node* target, int level) {
    if (root == NULL)
        return -1;

    if (root == target)
        return level;

    int left = depth(root->left, target, level + 1);
    if (left != -1)
        return left;

    return depth(root->right, target, level + 1);
}
int main() {
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;
    root->left = (struct node *)malloc(sizeof(struct node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct node *)malloc(sizeof(struct node));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    int h = height(root);
    printf("Height: %d\n", h); // Height of the tree

    // Find depth of a specific node
int d = depth(root, root->left->right, 0);  // say you're finding depth of node 5
printf("Depth: %d\n", d);

return 0;
}
// Output: Height: 2 Depth: 2