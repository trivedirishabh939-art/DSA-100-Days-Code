#include <stdio.h>
#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue operation
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue operation
int dequeue() {
    return queue[front++];
}

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

int main() {
    int n, x;

    // Input size
    scanf("%d", &n);

    // Input queue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue elements to stack
    for (int i = 0; i < n; i++) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Move stack elements back to queue
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}