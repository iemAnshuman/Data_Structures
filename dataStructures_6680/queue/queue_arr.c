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
    return (cars->front == cars->rear);
}

int isFull(struct queue* cars)
{
    if(cars->front == -1)
    {
        return 0;
    }
    return (cars->rear - cars->front == MAX - 1);
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
    while(!isEmpty(cars))
    {
        printf("%d\n",cars->items[cars->front]);
        dequeue(cars);
    }
}

int main()
{
    struct queue cars;
    initi(&cars);
    //enqueue()

    return 0;
}