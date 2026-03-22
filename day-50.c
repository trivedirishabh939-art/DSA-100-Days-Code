#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// BST Search Function
struct TreeNode* searchBST(struct TreeNode* root, int key) {
    // Base case
    if (root == NULL || root->val == key)
        return root;

    // If key is smaller, search left
    if (key < root->val)
        return searchBST(root->left, key);

    // If key is greater, search right
    return searchBST(root->right, key);
}

// Example usage
int main() {
    // Creating a simple BST manually
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);

    int key = 7;

    struct TreeNode* result = searchBST(root, key);

    if (result != NULL)
        printf("Value found: %d\n", result->val);
    else
        printf("Value not found\n");

    return 0;
}