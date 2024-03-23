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
    newNode->next = newNode; // Circular link to itself
    return newNode;
}

// Function to insert at the end (for testing purposes)
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

// Function to delete from the start
void deleteFromStart(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) { // Only one node
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    struct Node* toDelete = *head;
    temp->next = (*head)->next;
    *head = (*head)->next;
    free(toDelete);
}

// Function to delete a specific element
void deleteSpecificElement(struct Node** head, int elem) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    struct Node* prev = NULL;
    do {
        if (temp->data == elem) {
            if (prev == NULL) { // Deleting the head
                deleteFromStart(head);
                return;
            }
            prev->next = temp->next;
            if (temp == *head) { // If we're deleting the head
                *head = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != *head);
    printf("Element not found\n");
}

// Further deletion operations (after a specific element, before a specific element, at a specific position) 
// would follow a similar pattern to deleteSpecificElement, adjusting the traversal and deletion logic accordingly.

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    
    printf("Initial list: ");
    printList(head);
    
    deleteFromStart(&head);
    printf("After deleting from start: ");
    printList(head);
    
    deleteSpecificElement(&head, 3);
    printf("After deleting element 3: ");
    printList(head);
    
    // Add more delete operations as needed for demonstration
    
    return 0;
}
