#include <stdio.h>
#include <ctype.h> // For isalpha() and isdigit()

#define MAX 100

int main() {
    struct {
        int top;
        char *arr;
    } s; // Stack declaration using a pointer

    char stackArray[MAX]; // Actual stack storage
    s.arr = stackArray; // Pointing s.arr to the start of stackArray
    s.top = -1; // Initializing stack

    char infix[MAX], postfix[MAX];
    char *inPtr = infix, *postPtr = postfix; // Pointers for infix and postfix expressions

    printf("Enter infix expression: ");
    fflush(stdin);
    fgets(infix, MAX, stdin);

    while (*inPtr) {
        if (isalpha(*inPtr) || isdigit(*inPtr)) {
            *postPtr++ = *inPtr;
        } 
        else if (*inPtr == '(') {
            if (s.top < MAX - 1) {
                *(s.arr + ++s.top) = '('; // Push '(' onto stack
            }
        } 
        else if (*inPtr == ')') {
            while (s.top != -1 && *(s.arr + s.top) != '(') {
                *postPtr++ = *(s.arr + s.top--); // Pop off stack until '('
            }
            if (s.top != -1) s.top--; // Pop '(' from stack
        } 
        else if (*inPtr == '+' || *inPtr == '-' || *inPtr == '*' || *inPtr == '/' || *inPtr == '%') {
            while (s.top != -1 && ((*inPtr == '+' || *inPtr == '-') ? 1 : 2) <= 
                  ((*(s.arr + s.top) == '+' || *(s.arr + s.top) == '-') ? 1 : 2)) {
                *postPtr++ = *(s.arr + s.top--); // Pop higher or equal precedence ops
            }
            if (s.top < MAX - 1) {
                *(s.arr + ++s.top) = *inPtr; // Push current operator
            }
        }
        inPtr++; // Move to the next character in infix expression
    }

    while (s.top != -1) { // Pop any remaining operators
        *postPtr++ = *(s.arr + s.top--);
    }
    *postPtr = '\0'; // Null-terminate the postfix expression

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
