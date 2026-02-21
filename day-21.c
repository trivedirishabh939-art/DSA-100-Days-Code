#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x;
    printf("How many nodes? ");
    if (scanf("%d", &n) != 1) return 1;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL; // Initialize pointers

    for(int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
        if(newNode == NULL) return 1;

        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Your List: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}