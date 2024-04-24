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
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        printf("\nDeleted element -> %d\n", element);
        return element;
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

// Display the menu and get the user's choice
int getMenuChoice() {
    int choice;
    printf("\nMenu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    CircularQueue q;
    int choice, value;

    initQueue(&q);

    while (1) {
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                if (isFull(&q)) {
                    printf("\nCannot enqueue: Queue is full!\n");
                } else {
                    printf("Enter the value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                }
                break;
            case 2:
                if (isEmpty(&q)) {
                    printf("\nCannot dequeue: Queue is empty!\n");
                } else {
                    value = dequeue(&q);
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
