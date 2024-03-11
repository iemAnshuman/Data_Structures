#include <stdio.h>
#define MAX_SIZE 100

struct stack {
    char items[MAX_SIZE];
    int top;
};

void push(struct stack* ps, char item) {
    if (ps->top == MAX_SIZE - 1) {
        printf("Stack is Full\n");
        return;
    }
    ps->top++;
    ps->items[ps->top] = item;
}

char pop(struct stack* ps) {
    char item;
    if (ps->top == -1) {
        printf("Stack is Empty\n");
        return '\0';
    }
    item = ps->items[ps->top];
    ps->top--;
    return item;
}

int is_balanced(char exp[]) {
    int i = 0;
    struct stack s;
    s.top = -1;
    
    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&s, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.top == -1) {
                return 0;
            } else {
                char temp = pop(&s);
                if (exp[i] == ')' && (temp == '{' || temp == '[')) {
                    return 0;
                }
                if (exp[i] == '}' && (temp == '(' || temp == '[')) {
                    return 0;
                }
                if (exp[i] == ']' && (temp == '(' || temp == '{')) {
                    return 0;
                }
            }
        }
        i++;
    }
    
    if (s.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(exp, MAX_SIZE, stdin);
    if (is_balanced(exp)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}
