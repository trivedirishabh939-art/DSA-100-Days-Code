#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

int main() {
    int n, m, value;

    // Adding prompts helps you know the program is alive
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) break;
        push(value);
    }

    if (scanf("%d", &m) != 1) return 0;

    for (int i = 0; i < m; i++) {
        pop();
    }

    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n"); // Flushes the output buffer
    }

    return 0;
}