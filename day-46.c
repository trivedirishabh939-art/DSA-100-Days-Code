#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue structure
struct Queue {
    struct TreeNode* data[10000];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Main function
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int levelIndex = 0;

    while (!isEmpty(&q)) {
        int levelSize = q.rear - q.front;

        result[levelIndex] = (int*)malloc(sizeof(int) * levelSize);
        (*returnColumnSizes)[levelIndex] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(&q);

            result[levelIndex][i] = node->val;

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }

        levelIndex++;
    }

    *returnSize = levelIndex;
    return result;
}