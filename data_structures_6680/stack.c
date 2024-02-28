#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct stack {
    struct Node* top;
};

void init(struct stack *s) {
    s->top = NULL;
}

int isEmpty(struct stack *s) {
    if (s->top == NULL) {
        printf("Underflow\n");
        return 1;
    }
    return 0;
}

void push(struct stack *s, int ndata) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ndata;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(struct stack *s)
{
    struct Node* temp = s->top;
    s->top = s->top->next;
    int td = temp->data;
    free(temp);
    return td;
}

void peek(struct stack *s)
{
    printf("Top most data is %d\n",s->top->data);

}

void print(struct stack *s) {
    if (!isEmpty(s)) {
        struct Node* temp = s->top;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct stack s; // Use stack variable instead of pointer
    init(&s);
    // input
    printf("Enter size of stack: ");
    int n; 
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int temp;
        printf("Enter data: ");
        scanf("%d",&temp);
        push(&s, temp);
    }

    printf("Menu:\n ");
    printf("1. pop\n");
    int choice;
    scanf("%d",&choice);
    int rd;
    switch(choice)
    {
        case 1:
            rd = pop(&s);
            printf("%d\n",rd);
            break;
        default: 
            printf("Enter a valid choice");
            break;
    }
    print(&s);
    peek(&s);
    return 0;
}

/* applications: 
    reverse
    paranthesis check
    infix to postfix
    infix to prefix
    evaluation of postfix and prefix
    recurssion
    tower of hanoi
    */