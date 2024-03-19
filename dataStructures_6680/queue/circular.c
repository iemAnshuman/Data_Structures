#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Define the Circular Queue structure
typedef struct {
    int items[SIZE];
    int front, rear;
} CircularQueue;

// Initialize the queue
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % SIZE);
}

// Check if the queue is empty
int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

// Adding an element to the queue
void enqueue(CircularQueue *q, int element) {
    if (isFull(q)) {
        printf("\nQueue is full!!\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = element;
        printf("\nInserted -> %d\n", element);
    }
}

// Removing an element from the queue
int dequeue(CircularQueue *q) {
    int element;
    if (isEmpty(q)) {
        printf("\nQueue is empty !!\n");
        return (-1);
    } else {
        element = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } // Queue has only one element
        else {
            q->front = (q->front + 1) % SIZE;
        }
        printf("\nDeleted element -> %d\n", element);
        return (element);
    }
}

// Function to print the queue
void display(CircularQueue *q) {
    int i;
    if (isEmpty(q))
        printf("\nEmpty Queue\n");
    else {
        printf("\nFront -> %d ", q->front);
        printf("\nItems -> ");
        for (i = q->front; i != q->rear; i = (i + 1) % SIZE) {
            printf("%d ", q->items[i]);
        }
        printf("%d ", q->items[i]);
        printf("\nRear -> %d \n", q->rear);
    }
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    // Trying to add elements more than the capacity to show Queue is full
    enqueue(&q, 6);

    display(&q);

    int elem = dequeue(&q);
    if (elem != -1)
        printf("\nDequeued : %d\n", elem);

    display(&q);

    enqueue(&q, 7);
    display(&q);

    return 0;
}
