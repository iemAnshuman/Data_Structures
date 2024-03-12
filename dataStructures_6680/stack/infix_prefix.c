#include <stdio.h>
#include <ctype.h> // For isalpha() and isdigit()

#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
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

void push(struct Stack *s, char data) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->arr[++s->top] = data;
    }
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->arr[s->top--];
    }
}

char peek(struct Stack *s) {
    if (isEmpty(s)) {
        return -1; // Return a value indicating the stack is empty
    }
    return s->arr[s->top];
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

void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int i, j = 0;
    char item;
    //char x;

    for (i = 0; infix[i]; i++) {
        item = infix[i];
        if (isalpha(item) || isdigit(item))
        {
            postfix[j++] = item;
        } 
        else if (item == '(') 
        {
            push(&s, '(');
        } 
        else if (item == ')') 
        {
            while (peek(&s) != '(') 
            {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Pop '(' from stack
        } 
        else if (isOperator(item)) 
        {
            while (!isEmpty(&s) && precedence(item) <= precedence(peek(&s))) 
            {
                postfix[j++] = pop(&s);
            }
            push(&s, item);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; // Null-terminate the string
}

void reverse(char *string)
{
    struct Stack s;
    initStack(&s);
    int i=0;
    while(string[i] != '\0')
    {
        push(&s,string[i]);
        i++;
    }
    i = 0;
    while(!isEmpty(&s))
    {
        string[i] = pop(&s);
        i++;
    }
}

void replace(char *string)
{
    int i=0; 
    while(string[i] != '\0')
    {
        if(string[i] == '(')
        {
            string[i] = ')';
        }
        else if(string[i] == ')')
        {
            string[i] = '(';
        }
        i++;
    }
}

void infixToPrefix(char* infix, char* prefix)
{
    reverse(infix);
    replace(infix);

    infixToPostfix(infix, prefix);

    reverse(prefix);
    replace(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    fflush(stdin);
    fgets(infix, MAX, stdin);

    infixToPrefix(infix, prefix);

    printf("Postfix expression: %s\n", prefix);

    return 0;
}
