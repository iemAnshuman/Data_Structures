#include <stdio.h>
#include <ctype.h> // For isalpha() and isdigit()

#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

int main() {
    struct Stack s; // Stack initialization inline
    s.top = -1;

    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char item;

    printf("Enter infix expression: ");
    fflush(stdin);
    fgets(infix, MAX, stdin);

    // Converting infix to postfix directly in main
    for (i = 0; infix[i]; i++) {
        item = infix[i];
        if (isalpha(item) || isdigit(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            if (s.top == MAX - 1) printf("Stack is full\n");
            else s.arr[++s.top] = '(';
        } else if (item == ')') {
            while (s.top != -1 && s.arr[s.top] != '(') {
                postfix[j++] = s.arr[s.top--];
            }
            if (s.top != -1) s.top--; // Pop '(' from stack
        } else {
            while (s.top != -1 && ((item == '+' || item == '-') && (s.arr[s.top] == '*' || s.arr[s.top] == '/' || s.arr[s.top] == '%' || s.arr[s.top] == '+' || s.arr[s.top] == '-') || (item == '*' || item == '/' || item == '%') && (s.arr[s.top] == '*' || s.arr[s.top] == '/' || s.arr[s.top] == '%'))) {
                postfix[j++] = s.arr[s.top--];
            }
            if (s.top == MAX - 1) printf("Stack is full\n");
            else s.arr[++s.top] = item;
        }
    }

    while (s.top != -1) {
        postfix[j++] = s.arr[s.top--];
    }
    postfix[j] = '\0'; // Null-terminate the string

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
