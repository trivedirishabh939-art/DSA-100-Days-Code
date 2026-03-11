#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// Check if deque is empty
int empty() {
    if(front == -1)
        return 1;
    return 0;
}

// Return size
int size() {
    if(front == -1)
        return 0;
    return rear - front + 1;
}

// Insert at front
void push_front(int value) {
    if(front == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        printf("Deque Overflow\n");
        return;
    }
    else {
        front--;
    }
    deque[front] = value;
}

// Insert at rear
void push_back(int value) {
    if(front == -1) {
        front = rear = 0;
    }
    else if(rear == MAX-1) {
        printf("Deque Overflow\n");
        return;
    }
    else {
        rear++;
    }
    deque[rear] = value;
}

// Delete from front
void pop_front() {
    if(empty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Removed from front: %d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

// Delete from rear
void pop_back() {
    if(empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed from rear: %d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

// Return front element
int get_front() {
    if(empty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[front];
}

// Return rear element
int get_back() {
    if(empty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[rear];
}

// Display deque
void display() {
    if(empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

// Clear deque
void clear() {
    front = rear = -1;
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();

    printf("Front element: %d\n", get_front());
    printf("Rear element: %d\n", get_back());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    display();

    clear();
    if(empty())
        printf("Deque is empty after clear()\n");

    return 0;
}