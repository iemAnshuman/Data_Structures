/* not able to eliminate the pointer use while using functions 
but this is the closest we can get */

#include <stdio.h>
#include <ctype.h> // For isalpha() and isdigit()

#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
} s;

void initStack() {
    s.top = -1;
}

int isEmpty() {
    return s.top == -1;
}

int isFull() {
    return s.top == MAX - 1;
}

void push(char data) {
    if (isFull()) {
        printf("Stack is full\n");
    } else {
        s.arr[++s.top] = data;
    }
}

char pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1; // Indicating the stack is empty
    } else {
        return s.arr[s.top--];
    }
}

char peek() {
    if (isEmpty()) {
        return -1; // Indicating the stack is empty
    }
    return s.arr[s.top];
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
    }
    return -1;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

void infixToPostfix(char infix[], char postfix[]) {
    initStack();
    int i, j = 0;
    char item;

    for (i = 0; infix[i]; i++) {
        item = infix[i];
        if (isalpha(item) || isdigit(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            push('(');
        } else if (item == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop '(' from stack
        } else if (isOperator(item)) {
            while (!isEmpty() && precedence(item) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(item);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fflush(stdin);
    fgets(infix, MAX, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
