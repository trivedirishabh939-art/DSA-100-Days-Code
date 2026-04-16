#include <stdio.h>
#include <stdlib.h>

// Structure for hash map node
typedef struct Node {
    int sum;
    int index;
    struct Node* next;
} Node;

#define SIZE 1000

Node* hashTable[SIZE];

// Hash function
int hash(int sum) {
    return abs(sum) % SIZE;
}

// Insert into hash table
void insert(int sum, int index) {
    int h = hash(sum);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

// Search in hash table
int search(int sum) {
    int h = hash(sum);
    Node* temp = hashTable[h];
    while (temp) {
        if (temp->sum == sum)
            return temp->index;
        temp = temp->next;
    }
    return -1;
}

// Function to find longest subarray with sum = 0
int maxLen(int arr[], int n) {
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum is zero from start
        if (prefixSum == 0)
            maxLength = i + 1;

        // Case 2: sum seen before
        int prevIndex = search(prefixSum);
        if (prevIndex != -1) {
            int length = i - prevIndex;
            if (length > maxLength)
                maxLength = length;
        } else {
            insert(prefixSum, i);
        }
    }

    return maxLength;
}

// Driver code
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest subarray with sum 0: %d\n", maxLen(arr, n));

    return 0;
}