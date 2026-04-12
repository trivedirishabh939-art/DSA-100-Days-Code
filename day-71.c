#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// Initialize table
void init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;  // -1 means empty
    }
}

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert using Quadratic Probing
void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;

        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }

        i++;
    }

    printf("Hash Table is full, cannot insert %d\n", key);
}

// Search using Quadratic Probing
int search(int key) {
    int index = hash(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;

        if (hashTable[newIndex] == key) {
            return newIndex;
        }

        if (hashTable[newIndex] == -1) {
            return -1; // Not found
        }

        i++;
    }

    return -1;
}

// Display table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: Empty\n", i);
    }
}

// Main function
int main() {
    init();

    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);

    display();

    int key = 25;
    int result = search(key);

    if (result != -1)
        printf("\nKey %d found at index %d\n", key, result);
    else
        printf("\nKey %d not found\n", key);

    return 0;
}