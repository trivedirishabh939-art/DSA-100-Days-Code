#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of elements: "); // Debug line
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid N\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        // The program will wait here until you type a number
        if(scanf("%d", &value) != 1) break; 
        
        struct Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("Forward List: "); // Help identify the output
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");

    // ... (rest of your memory cleanup)
}