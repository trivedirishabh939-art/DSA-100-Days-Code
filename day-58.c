#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to find index in inorder
int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct TreeNode* buildTreeHelper(int preorder[], int inorder[], 
                                int preStart, int preEnd,
                                int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];
    struct TreeNode* root = createNode(rootVal);

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);
    int leftSize = inIndex - inStart;

    root->left = buildTreeHelper(preorder, inorder,
                                preStart + 1,
                                preStart + leftSize,
                                inStart,
                                inIndex - 1);

    root->right = buildTreeHelper(preorder, inorder,
                                preStart + leftSize + 1,
                                preEnd,
                                inIndex + 1,
                                inEnd);

    return root;
}

// Main function to call builder
struct TreeNode* buildTree(int* preorder, int preorderSize, 
                        int* inorder, int inorderSize) {
    return buildTreeHelper(preorder, inorder, 
                        0, preorderSize - 1,
                        0, inorderSize - 1);
}

// 🔍 Inorder traversal (to verify tree)
void printInorder(struct TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// 🚀 MAIN FUNCTION
int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[]  = {9, 3, 15, 20, 7};

    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode* root = buildTree(preorder, n, inorder, n);

    printf("Inorder of constructed tree: ");
    printInorder(root);

    return 0;
}