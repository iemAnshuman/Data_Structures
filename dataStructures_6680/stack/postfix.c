#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

struct Stack {
    int top;
    int item[MAX];
};

void initia(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

void push(struct Stack *s, int data) { // Changed data type to int
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->item[++s->top] = data;
    }
}

int pop(struct Stack *s) { // Changed return type to int
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Indicates an error
    } else {
        return s->item[s->top--];
    }
}

void op_encounter(struct Stack *s, char op) {
    
    int a = pop(s);
    int b = pop(s);

    switch (op) {
        case '+': push(s, b + a); break;
        case '-': push(s, b - a); break;
        case '*': push(s, b * a); break;
        case '/': push(s, b / a); break;
        case '%': push(s, b % a); break;
    }
}

void evaluate(char* postfix) {
    struct Stack s;
    initia(&s);

    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(&s, num);
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%') {
            op_encounter(&s, postfix[i]);
            i++;
        } else {
            i++; // Skip non-numeric and non-operator characters
        }
    }

    printf("%d\n", s.item[s.top]); // Print the top of the stack as integer
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    fgets(postfix, MAX, stdin); // fgets is safer than gets

    evaluate(postfix);
    return 0;
}
