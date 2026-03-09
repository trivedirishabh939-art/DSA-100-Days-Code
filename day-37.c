#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int x) {
    if (size >= MAX) return;
    heap[size] = x;
    size++;
    heapifyUp(size - 1);
}

// Renamed from 'delete' to 'extractMin' to avoid keyword issues
void extractMin() {
    if (size <= 0) {
        printf("-1\n");
        fflush(stdout); // Force output
        return;
    }
    printf("%d\n", heap[0]);
    fflush(stdout); // Force output
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

void peek() {
    if (size <= 0) {
        printf("-1\n");
        fflush(stdout);
        return;
    }
    printf("%d\n", heap[0]);
    fflush(stdout);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[20];
    int val;

    for (int i = 0; i < n; i++) {
        if (scanf("%s", op) != 1) break;
        
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            extractMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}