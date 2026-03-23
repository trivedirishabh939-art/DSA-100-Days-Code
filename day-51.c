#include <stdio.h>
#include <stdlib.h>

// Definition of BST node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to find LCA
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // If both values are smaller, go left
    if (p < root->val && q < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // If both values are greater, go right
    if (p > root->val && q > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // Otherwise, this is the split point (LCA)
    return root;
}

// Helper function to create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Example usage
int main() {
    /*
            6
           / \
          2   8
         / \ / \
        0  4 7  9
          / \
         3   5
    */

    struct TreeNode* root = createNode(6);
    root->left = createNode(2);
    root->right = createNode(8);
    root->left->left = createNode(0);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);
    root->left->right->left = createNode(3);
    root->left->right->right = createNode(5);

    int p = 2, q = 8;

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        printf("LCA of %d and %d is: %d\n", p, q, lca->val);

    return 0;
}