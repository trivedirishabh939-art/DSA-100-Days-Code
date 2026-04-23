#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Min Heap structure
struct MinHeap {
    struct ListNode** arr;
    int size;
};

// Swap function
void swap(struct ListNode** a, struct ListNode** b) {
    struct ListNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify down
void heapifyDown(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->arr[left]->val < heap->arr[smallest]->val)
        smallest = left;

    if (right < heap->size && heap->arr[right]->val < heap->arr[smallest]->val)
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Heapify up
void heapifyUp(struct MinHeap* heap, int i) {
    if (i && heap->arr[(i-1)/2]->val > heap->arr[i]->val) {
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        heapifyUp(heap, (i-1)/2);
    }
}

// Insert into heap
void insertHeap(struct MinHeap* heap, struct ListNode* node) {
    heap->arr[heap->size] = node;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Extract min
struct ListNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0) return NULL;

    struct ListNode* root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);

    return root;
}

// Main function
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->arr = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    heap->size = 0;

    // Insert initial nodes
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            insertHeap(heap, lists[i]);
        }
    }

    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (heap->size > 0) {
        struct ListNode* minNode = extractMin(heap);
        tail->next = minNode;
        tail = tail->next;

        if (minNode->next != NULL) {
            insertHeap(heap, minNode->next);
        }
    }

    free(heap->arr);
    free(heap);

    return dummy.next;
}