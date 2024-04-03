#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the stack structure
typedef struct Stack {
    char* data;
    int top;
    int capacity;
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to the stack
void push(Stack* stack, char item) {
    stack->data[++stack->top] = item;
}

// Function to remove an item from the stack
char pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->data[stack->top--];
    return '$';
}

// Function to return the top from stack without removing it
char peek(Stack* stack) {
    if (!isEmpty(stack))
        return stack->data[stack->top];
    return '$';
}

// Function to check if parentheses are balanced
int areParenthesesBalanced(char* expr) {
    Stack* stack = createStack(strlen(expr));
    for (unsigned long i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(') {
            push(stack, expr[i]);
        } else if (expr[i] == ')') {
            if (isEmpty(stack)) {
                return 0;
            } else if (peek(stack) == '(') {
                pop(stack);
            }
        }
    }
    return isEmpty(stack);
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);  // read the input from the user

    // remove newline character at the end if it exists
    if (expr[strlen(expr) - 1] == '\n') {
        expr[strlen(expr) - 1] = '\0';
    }

    if (areParenthesesBalanced(expr))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");

    return 0;
}