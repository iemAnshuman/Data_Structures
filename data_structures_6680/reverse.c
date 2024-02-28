/*
time complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Stack
{
    struct Node* top;
};

void push(struct Stack *s, int ndata)
{
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode -> data = ndata;
    newNode -> next = s->top;
    s->top = newNode;
}

void print(struct Stack *s)
{
    while(s->top != NULL)
    {
        printf("%d ",s->top->data);
        s->top = s->top->next;
    }
    printf("\n");
}

int main()
{
    struct Stack s;
    s.top = NULL;
    int n;

    //inputs
    printf("Enter the size: "); 
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("Enter element: ");
        int t; 
        scanf("%d",&t);
        push(&s,t);
    }
    print(&s);
    return 0;
}


