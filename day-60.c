#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Count total nodes
int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if tree is complete
bool isComplete(struct TreeNode* root, int index, int totalNodes) {
    if (root == NULL)
        return true;

    if (index >= totalNodes)
        return false;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check Min-Heap property
bool isMinHeap(struct TreeNode* root) {
    if (root == NULL)
        return true;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // Only left child
    if (root->right == NULL)
        return (root->val <= root->left->val) && isMinHeap(root->left);

    // Both children
    return (root->val <= root->left->val &&
            root->val <= root->right->val &&
            isMinHeap(root->left) &&
            isMinHeap(root->right));
}

// Main function to check heap
bool isHeap(struct TreeNode* root) {
    int totalNodes = countNodes(root);

    if (!isComplete(root, 0, totalNodes))
        return false;

    return isMinHeap(root);
}

// ----------- MAIN FUNCTION -----------
int main() {
    /*
            Example Tree:
                  10
                 /  \
               15    20
              /  \
            30   40
    */

    struct TreeNode* root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(20);
    root->left->left = createNode(30);
    root->left->right = createNode(40);

    if (isHeap(root))
        printf("The given binary tree is a Min-Heap.\n");
    else
        printf("The given binary tree is NOT a Min-Heap.\n");

    return 0;
}