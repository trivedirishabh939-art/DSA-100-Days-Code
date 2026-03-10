#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int count = 0;

void enqueue(int x) {
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    queue[rear] = x;
    count++;
}

void dequeue() {
    if (count == 0) return;

    front = (front + 1) % MAX;
}

void display() {
    int i = front;

    for (int j = 0; j < count; j++) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}