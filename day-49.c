#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to create a new TreeNode
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // If tree is empty, create new node
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Insert into left subtree
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    // Insert into right subtree
    else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
int main() {
    struct TreeNode* root = NULL;

    root = insertIntoBST(root, 5);
    insertIntoBST(root, 3);
    insertIntoBST(root, 7);
    insertIntoBST(root, 2);
    insertIntoBST(root, 4);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}