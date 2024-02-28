#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int balanced(char exp[]) {
    int i = 0;
    struct Stack* stack = createStack(100);
    
    while (exp[i]) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(stack, exp[i]);
        
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(stack))
                return 0;
            else if (!isMatchingPair(pop(stack), exp[i]))
                return 0;
        }
        i++;
    }
    
    if (isEmpty(stack))
        return 1; // balanced
    else
        return 0; // not balanced
}

int main() {
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);
    if (balanced(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}
