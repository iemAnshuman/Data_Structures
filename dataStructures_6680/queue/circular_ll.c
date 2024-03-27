#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularQueue {
    Node* front;
    Node* rear;
} CircularQueue;

void init(CircularQueue* cq) {
    cq->front = cq->rear = NULL;
}

Node* create_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(CircularQueue* cq) {
    return cq->front == NULL;
}

void enqueue(CircularQueue* cq, int data) {
    Node* newNode = create_node(data);
    if (isEmpty(cq)) {
        cq->front = cq->rear = newNode;
        newNode->next = cq->front; // Making it circular
    } else {
        cq->rear->next = newNode;
        cq->rear = newNode;
        cq->rear->next = cq->front; // Maintaining circularity
    }
    printf("%d enqueued to queue\n", data);
}

int dequeue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = cq->front->data;
    if (cq->front == cq->rear) { // Only one element
        free(cq->front);
        cq->front = cq->rear = NULL;
    } else {
        Node* temp = cq->front;
        cq->front = cq->front->next;
        cq->rear->next = cq->front; // Maintaining circularity
        free(temp);
    }
    return data;
}

void display(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    Node* temp = cq->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != cq->front);
    printf("\n");
}

int main() {
    CircularQueue cq;
    init(&cq);

    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);

    printf("Initial queue:\n");
    display(&cq);

    printf("%d dequeued from queue\n", dequeue(&cq));

    printf("Queue after one dequeue:\n");
    display(&cq);

    return 0;
}
