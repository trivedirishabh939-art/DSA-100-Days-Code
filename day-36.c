#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = 0, rear = 0, count = 0;
    int n, m, val;

    // Input: Number of elements to enqueue
    if (scanf("%d", &n) != 1) return 0;

    // Enqueue operations
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        queue[rear] = val;
        rear = (rear + 1) % MAX;
        count++;
    }

    // Input: Number of dequeue operations
    if (scanf("%d", &m) != 1) return 0;

    // Dequeue operations (simply moving the front pointer)
    for (int i = 0; i < m; i++) {
        if (count > 0) {
            front = (front + 1) % MAX;
            count--;
        }
    }

    // Output: Print remaining elements
    for (int i = 0; i < count; i++) {
        int index = (front + i) % MAX;
        printf("%d%c", queue[index], (i == count - 1 ? '\n' : ' '));
    }

    return 0;
}