#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    Node* temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int N, op, x;

    scanf("%d", &N);

    while (N--) {
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &x);
            enqueue(x);
        }
        else if (op == 2) {
            dequeue();
        }
    }

    return 0;
}