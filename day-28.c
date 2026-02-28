#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Point to itself to stay circular
            temp = head;
        } else {
            temp->next = newNode;
            newNode->next = head; // Always point the new last node to head
            temp = newNode;
        }
    }

    // Traversal
    printf("\nCircular Linked List: ");
    struct Node* ptr = head;
    if (head != NULL) {
        do {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
        printf("(back to head: %d)\n", head->data);
    }

    return 0;
}