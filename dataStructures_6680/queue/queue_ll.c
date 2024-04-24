#include <stdio.h>
#include <stdlib.h>

// Define a node of the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap is full. Cannot allocate memory.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize an empty queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Add an element to the queue
void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to queue\n", data);
}

// Remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        Node* temp = q->front;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int peek(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty.\n");
        return __INT_MAX__;
    }
    printf("%d\n",q->front->data);
    return q->front->data;
}

// Main function to demonstrate queue operations
int main() {
    Queue q;
    initQueue(&q);

    while(1)
    {
    printf("Menu:\n");
    printf("0. Exit\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. peek\n");

    int choice;
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 0:
        return 0;
    case 1:
        printf("Enter data: ");
        int ndata;
        scanf("%d",&ndata);
        enqueue(&q,ndata);
        break;
    case 2:
        dequeue(&q);
        break;
    case 3:
        display(&q);
        break;
    case 4:
        peek(&q);
        break;
    default:
        break;
    }
    }
    return 0;
}
