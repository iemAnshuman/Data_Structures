#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

struct Stack {
    int top;
    int item[MAX];
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

void push(struct Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->item[++s->top] = data;
    }
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Error value
    } else {
        return s->item[s->top--];
    }
}

int operate(int op1, int op2, char operator) {
    switch (operator) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default: return 0; // Error case
    }
}

void evaluatePrefix(char* expression) {
    struct Stack s;
    initStack(&s);

    // Start from the right end of the expression
    int length = strlen(expression);
    for (int i = length - 1; i >= 0; i--) {
        // If character is digit, push it to stack
        // Need to handle multi-digit numbers and spaces
        if (isdigit(expression[i])) {
            int num = 0;
            int base = 1;
            while (i >= 0 && isdigit(expression[i])) {
                num += (expression[i] - '0') * base;
                base *= 10;
                i--;
            }
            i++; // Adjust because the loop decreases i extra time
            push(&s, num);
        } else if (isspace(expression[i])) {
            // Skip spaces
            continue;
        } else {
            // Operator encountered, pop two operands, perform operation, and push result
            int op1 = pop(&s);
            int op2 = pop(&s);
            int result = operate(op1, op2, expression[i]);
            push(&s, result);
        }
    }

    // Final result is in stack top
    printf("Result: %d\n", pop(&s));
}

int main() {
    char prefixExpr[MAX];
    printf("Enter prefix expression: ");
    fgets(prefixExpr, MAX, stdin); // Read input

    evaluatePrefix(prefixExpr);
    return 0;
}
