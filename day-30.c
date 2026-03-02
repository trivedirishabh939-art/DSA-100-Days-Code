#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial node
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
struct Node* insert(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print polynomial in standard form
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    int first = 1;

    while (temp != NULL) {
        if (temp->coeff != 0) {

            if (!first)
                printf(" + ");

            if (temp->exp == 0)
                printf("%d", temp->coeff);
            else if (temp->exp == 1)
                printf("%dx", temp->coeff);
            else
                printf("%dx^%d", temp->coeff, temp->exp);

            first = 0;
        }
        temp = temp->next;
    }

    if (first)  // If all coefficients were 0
        printf("0");

    printf("\n");
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insert(head, coeff, exp);
    }

    printPolynomial(head);

    return 0;
}