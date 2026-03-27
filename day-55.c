#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue structure
struct Queue {
    struct TreeNode* data[1000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

// Function to print right view
void rightView(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = dequeue(&q);

            // Last node of this level
            if (i == size - 1) {
                printf("%d ", curr->val);
            }

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }
    }
}

// MAIN FUNCTION
int main() {
    /*
            1
           / \
          2   3
           \   \
            5   4
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);

    printf("Right View: ");
    rightView(root);

    return 0;
}