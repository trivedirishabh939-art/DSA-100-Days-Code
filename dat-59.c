#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
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

// Find index in inorder array
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct TreeNode* buildTreeHelper(int* inorder, int* postorder,
                                int inStart, int inEnd,
                                int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    if (inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    // Important: build right first
    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Main build function
struct TreeNode* buildTree(int* inorder, int inorderSize,
                          int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return buildTreeHelper(inorder, postorder, 0, inorderSize - 1, &postIndex);
}

// Inorder traversal (for checking)
void printInorder(struct TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// MAIN FUNCTION
int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};

    int n = sizeof(inorder) / sizeof(inorder[0]);

    struct TreeNode* root = buildTree(inorder, n, postorder, n);

    printf("Inorder of constructed tree: ");
    printInorder(root);

    return 0;
}