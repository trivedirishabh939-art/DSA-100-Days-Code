#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list (bucket)
typedef struct Node {
    float data;
    struct Node* next;
} Node;

// Function to insert node in sorted order (Insertion Sort in bucket)
Node* insertSorted(Node* head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning or empty list
    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    // Traverse and insert
    Node* temp = head;
    while (temp->next != NULL && temp->next->data <= value) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    // Create n buckets
    Node* buckets[n];

    // Initialize buckets as empty
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  // bucket index
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    // Concatenate all buckets into arr[]
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d numbers in range [0,1):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.4f ", arr[i]);
    }

    return 0;
}