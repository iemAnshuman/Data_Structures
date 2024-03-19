#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the Stack structure using the Node
struct Stack {
    struct Node* top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap is full. Cannot push.\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an error value
    }
    struct Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedData;
}

// Peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; // Return an error value
    }
    return stack->top->data;
}

// Function to display the stack elements
void display(struct Stack* stack) {
    struct Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    printf("Stack elements after pushing 10, 20, 30: ");
    display(&stack);

    printf("Element popped from stack: %d\n", pop(&stack));
    printf("Stack elements after popping: ");
    display(&stack);

    printf("Element on top of the stack: %d\n", peek(&stack));

    return 0;
}
