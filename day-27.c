#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Get length of list
int getCount(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection node (by address)
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    int d = abs(c1 - c2);

    // Move pointer of longer list
    if (c1 > c2) {
        for (int i = 0; i < d; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < d; i++)
            ptr2 = ptr2->next;
    }

    // Traverse together
    while (ptr1 && ptr2) {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, val;

    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp = NULL, *tail1 = NULL, *tail2 = NULL;

    // First List
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* new_node = newNode(val);

        if (head1 == NULL) {
            head1 = new_node;
            tail1 = new_node;
        } else {
            tail1->next = new_node;
            tail1 = new_node;
        }
    }

    // Second List
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* new_node = newNode(val);

        if (head2 == NULL) {
            head2 = new_node;
            tail2 = new_node;
        } else {
            tail2->next = new_node;
            tail2 = new_node;
        }
    }

    /*
      IMPORTANT:
      Since input does not specify intersection position,
      we manually create intersection for testing.

      Example: connect last node of list2
      to second node of list1 (if possible)
    */

    al intersection
    }if (head1 != NULL && head1->next != NULL) {
    tail2->next = head1->next;
}
    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}