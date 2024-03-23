#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end 
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

// Deletion from the start
void deleteFromStart(struct Node** head) 
{
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* toDelete = *head;
    *head = (*head)->next;
    free(toDelete);
}

// Deletion from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Deletion of a specific element
void deleteSpecificElement(struct Node** head, int elem) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    if ((*head)->data == elem) {
        deleteFromStart(head);
        return;
    }
    struct Node *temp = *head, *prev = NULL;
    while (temp != NULL && temp->data != elem) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Deletion at a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    if (position == 1) {
        deleteFromStart(head);
        return;
    }
    struct Node *temp = *head, *prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the end\n");
        printf("2. Delete from the start\n");
        printf("3. Delete from the end\n");
        printf("4. Delete a specific element\n");
        printf("5. Delete at a specific position\n");
        printf("6. Print list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printList(head);
                break;
            case 2:
                deleteFromStart(&head);
                printList(head);
                break;
            case 3:
                deleteFromEnd(&head);
                printList(head);
                break;
            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteSpecificElement(&head, data);
                printList(head);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                printList(head);
                break;
            case 6:
                printList(head);
                printList(head);
                break;
            case 0:
                printf("Exiting...\n");
                while (head != NULL) { // Clean up to prevent memory leak
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
