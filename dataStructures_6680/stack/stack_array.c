#include <stdio.h>
#define MAX_SIZE 100

struct stack{
    int items[MAX_SIZE];
    int top;
};

void insti_stack(struct stack *s, int top)
{
    s->top = -1;
}

int full(struct stack *s, int top)
{
    if(s->top == MAX_SIZE-1)
    {
        return 1;
    }
    return 0;
}

int empty(struct stack *s, int top)
{
    if(s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, int top, int data)
{
    if(full(s,top))
    {
        printf("Overflow\n");
        return;
    }
    (s->top)++;
    s->items[top] = data;
    return;
}

void peek(struct stack *s, int top)
{
    if(empty(s,top))
    {
        prinf("Underflow\n");
        return;
    }
    printf("%d ",s->items[top]);
}

int pop(struct stack *s, int top)
{
    if(empty(s,top))
    {
        printf("Underflow\n");
        return -1;
    }
    printf("%d ",s->items[top]);
    return s->items[top];
}

int main()
{
    struct stack s;
    while(1)
    {
        printf("Menu: \n");
        printf("1. Push an element");
        printf("2. Pop an element");
        printf("3. Peek an element");
        return 0;
    }
}