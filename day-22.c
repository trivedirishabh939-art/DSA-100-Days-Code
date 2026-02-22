#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to count nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Helper function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL;

    printf("Enter number of nodes: "); // Added prompt
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Count: 0\n");
        return 0;
    }

    printf("Enter %d integers: ", n); // Added prompt
    for (int i = 0; i < n; i++) {
        if(scanf("%d", &value) != 1) break;
        struct Node* newNode = createNode(value);
        
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    printf("Final Count: %d\n", countNodes(head));

    // Keeps the console open
    printf("\nPress Enter to exit...");
    getchar(); 
    getchar(); 
    return 0;
}