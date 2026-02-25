#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, x, key;

    // Read number of nodes
    scanf("%d", &n);

    if(n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create linked list dynamically
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Read key to count
    scanf("%d", &key);

    // Count occurrences
    int count = 0;
    temp = head;

    while(temp != NULL) {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }

    // Print result
    printf("%d\n", count);

    // Free memory
    temp = head;
    while(temp != NULL) {
        struct Node *del = temp;
        temp = temp->next;
        free(del);
    }

    return 0;
}