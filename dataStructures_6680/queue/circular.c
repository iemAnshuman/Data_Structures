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

void menu() {
    printf("\n1. Enqueue");
    printf("\n2. Dequeue ");
    printf("\n3. Display ");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int choice, value;

    while(1) {
        menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("\nDequeued: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
