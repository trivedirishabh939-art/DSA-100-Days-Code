#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Rotate list to the right by k positions
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *temp = head;
    int length = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make list circular
    temp->next = head;

    // Handle k greater than length
    k = k % length;
    int stepsToNewHead = length - k;

    struct Node* newTail = temp;

    while (stepsToNewHead--) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n, k, value;
    struct Node *head = NULL, *temp = NULL;

    // Input number of elements
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    // Build linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Input k
    scanf("%d", &k);

    // Rotate
    head = rotateRight(head, k);

    // Print rotated list
    // ... inside main after printing the list ...

// Free the memory
temp = head;
while (temp != NULL) {
    struct Node* next = temp->next;
    free(temp);
    temp = next;

    }

    printf("\n");

    return 0;
}
