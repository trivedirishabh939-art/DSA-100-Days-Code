#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if(rear == MAX - 1)
    {
        printf("\nQueue Overflow! Cannot add %d\n", val);
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    queue[rear] = val;
    printf("Inserted %d\n", val);
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("\nQueue Underflow! Nothing to remove.\n");
        return;
    }

    printf("Dequeued: %d\n", queue[front]);
    front++;

    // Resetting indices if the queue becomes empty to reuse space
    if(front > rear)
    {
        front = rear = -1;
    }
}

void display()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Current Queue: ");
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int n, x;

    printf("--- Queue Implementation ---\n");
    printf("How many elements do you want to insert? ");
    if (scanf("%d", &n) != 1) return 1;

    for(int i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &x);
        enqueue(x);
    }

    printf("\n--- Final Results ---\n");
    display();

    // Small test of the dequeue function
    printf("\nPerforming one dequeue operation...\n");
    dequeue();
    display();

    return 0;
}