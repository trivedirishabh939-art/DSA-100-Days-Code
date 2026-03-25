#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue structure
struct QueueNode {
    struct TreeNode* node;
    int hd;
    struct QueueNode* next;
};

// Enqueue
void enqueue(struct QueueNode** front, struct QueueNode** rear, struct TreeNode* node, int hd) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;

    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }

    (*rear)->next = temp;
    *rear = temp;
}

// Dequeue
struct QueueNode* dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front == NULL)
        return NULL;

    struct QueueNode* temp = *front;
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    return temp;
}

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root) {
    if (root == NULL)
        return;

    int offset = 100;
    int map[200][100] = {0};
    int count[200] = {0};

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    enqueue(&front, &rear, root, 0);

    int minHD = 0, maxHD = 0;

    while (front != NULL) {
        struct QueueNode* temp = dequeue(&front, &rear);
        struct TreeNode* node = temp->node;
        int hd = temp->hd;

        int index = hd + offset;

        if (count[index] < 100)
            map[index][count[index]++] = node->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            enqueue(&front, &rear, node->left, hd - 1);
        if (node->right)
            enqueue(&front, &rear, node->right, hd + 1);

        free(temp);
    }

    for (int i = minHD; i <= maxHD; i++) {
        int index = i + offset;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", map[index][j]);
        }
        printf("\n");
    }
}

// ✅ MAIN FUNCTION (FIX)
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}