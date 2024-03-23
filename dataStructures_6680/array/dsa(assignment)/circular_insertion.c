#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself, making it circular
    return newNode;
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = (*head)->next;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert at the start
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert after a specific element
void insertAfterElem(struct Node** head, int data, int elem) {
    if (*head == NULL) return;
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    do {
        if (temp->data == elem) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    printf("Element not found\n");
}

// Function to insert before a specific element (more complex due to circular nature)
void insertBeforeElem(struct Node** head, int data, int elem) {
    if (*head == NULL) return;
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    struct Node* prev = NULL;
    do {
        if (temp->data == elem) {
            if (prev == NULL) { // Inserting before the head
                insertAtStart(head, data);
                return;
            }
            newNode->next = temp;
            prev->next = newNode;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != *head);
    printf("Element not found\n");
}

// Function to print the circular list
void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtStart(&head, 5);
    insertAfterElem(&head, 20, 10);
    insertBeforeElem(&head, 2, 5);
    printList(head); // Expected output: 2 5 10 20
    return 0;
}
