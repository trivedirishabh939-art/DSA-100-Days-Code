#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if two trees are mirror of each other
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL)
        return true;

    if (t1 == NULL || t2 == NULL)
        return false;

    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Function to check if tree is symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}

// Main function
int main() {
    /*
        Creating this symmetric tree:

                1
              /   \
             2     2
            / \   / \
           3   4 4   3
    */

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);

    root->left->left = createNode(3);
    root->left->right = createNode(4);

    root->right->left = createNode(4);
    root->right->right = createNode(3);

    // Check symmetry
    if (isSymmetric(root))
        printf("Tree is Symmetric\n");
    else
        printf("Tree is NOT Symmetric\n");

    return 0;
}