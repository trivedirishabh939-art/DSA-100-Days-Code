#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to convert tree into its mirror
struct TreeNode* mirrorTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // Swap left and right
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);

    return root;
}

// Inorder traversal (to verify result)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Example usage
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder before mirror:\n");
    inorder(root);

    mirrorTree(root);

    printf("\nInorder after mirror:\n");
    inorder(root);

    return 0;
}