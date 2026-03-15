#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* constructTree(int arr[], int n) {

    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (front < rear && i < n) {

        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void printInorder(struct Node* root) {

    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {

    int n;

    if(scanf("%d",&n)!=1)
        return 0;

    int *arr = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root = constructTree(arr,n);

    printInorder(root);

    printf("\n");

    free(arr);

    return 0;
}