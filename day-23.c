#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return NULL; // Safety check
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* buildList(int count) {
    if (count <= 0) return NULL;
    
    struct Node *head = NULL, *temp = NULL;
    int val;
    
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &val) != 1) break; // Ensure input is read
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy; 
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
}

void printList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty\n");
        return;
    }
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int n = 0, m = 0;

    // Use a prompt if you are testing manually
    // printf("Enter size of list 1: "); 
    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = buildList(n);

    // printf("Enter size of list 2: ");
    if (scanf("%d", &m) != 1) return 0;
    struct Node* list2 = buildList(m);

    struct Node* mergedHead = mergeLists(list1, list2);
    
    // printf("Merged List: ");
    printList(mergedHead);

    return 0;
}