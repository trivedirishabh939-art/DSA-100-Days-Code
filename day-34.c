#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Top pointer of stack
struct Node* top = NULL;

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function
int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    struct Node* temp = top;
    int value = temp->data;
    
    top = top->next;
    free(temp);
    
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;
    
    while(exp[i] != '\0') {
        
        // If operand, push to stack
        if(isdigit(exp[i])) {
            push(exp[i] - '0');  
        }
        
        // If operator
        else {
            int val1 = pop();
            int val2 = pop();
            int result;
            
            switch(exp[i]) {
                case '+':
                    result = val2 + val1;
                    break;
                    
                case '-':
                    result = val2 - val1;
                    break;
                    
                case '*':
                    result = val2 * val1;
                    break;
                    
                case '/':
                    result = val2 / val1;
                    break;
            }
            
            push(result);
        }
        
        i++;
    }
    
    return pop();
}

int main() {
    char postfix[100];
    
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);
    
    int result = evaluatePostfix(postfix);
    
    printf("Result = %d\n", result);
    
    return 0;
}