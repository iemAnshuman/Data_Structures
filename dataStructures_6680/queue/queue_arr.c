#include <stdio.h>
#define MAX 100

struct queue{
    int front;
    int rear;
    int items[MAX];
};

void initi(struct queue* cars)
{
    cars->front = -1;
    cars->rear = -1;
}

int isEmpty(struct queue* cars)
{
    return (cars->front > cars->rear || cars->front < 0);
}

int isFull(struct queue* cars)
{
    if(cars->front == -1)
    {
        return 0;
    }
    return (cars->rear == MAX-1);
}

void enqueue(struct queue* cars, int ndata)
{
    if(isFull(cars))
    {
        printf("Overflow!\n");
        return;
    }
    if(cars->front == -1)
    {
        cars->front = 0;

    }
    cars->items[++cars->rear] = ndata;
}

void dequeue(struct queue* cars)
{
    if(isEmpty(cars))
    {
        printf("Underflow!\n");
        return;
    }
    cars->front++;
    if(cars->front > cars->rear) initi(cars);
}

void peek(struct queue* cars)
{
    if(isEmpty(cars))
    {
        printf("Underflow!\n");
        return;
    }
    printf("%d\n",cars->items[cars->front]);
}

void display(struct queue* cars)
{
    if(isEmpty(cars))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    for(int i = cars->front; i <= cars->rear; i++)
    {
        printf("%d\n", cars->items[i]);
    }
}

int main()
{
    struct queue cars;
    initi(&cars);
    
    while(1)
    {
    printf("Menu: \n");
    printf("0. Exit\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. peek\n");
    printf("4. Display\n");

    printf("Enter choice: ");
    int choice; 
    scanf("%d",&choice);

    switch (choice)
    {
        case 0:
            return 0;
        case 1:
            {
            printf("Enter data: ");
            int data; scanf("%d",&data);
            enqueue(&cars,data);
            break;
            }
        case 2: 
            dequeue(&cars); 
            break;
        case 3: 
            peek(&cars); 
            break;
        case 4:
            display(&cars); 
            break;
        default: 
            printf("Invalid choice\n");
            break;
    }
    }
    return 0;
}