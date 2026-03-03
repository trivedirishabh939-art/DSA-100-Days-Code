#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        // Stack Overflow (not required in output, but good practice)
        return;
    }
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

// Display operation
void display() {
    if (top == -1) {
        return;  // If stack is empty, print nothing
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);

        if (operation == 1) {
            int value;
            scanf("%d", &value);
            push(value);
        }
        else if (operation == 2) {
            pop();
        }
        else if (operation == 3) {
            display();
        }
    }

    return 0;
}