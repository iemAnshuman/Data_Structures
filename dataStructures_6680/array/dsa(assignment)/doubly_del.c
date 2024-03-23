#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end (helper function for demonstration)
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Deletion from the start
void deleteFromStart(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* toDelete = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(toDelete);
}

// Deletion from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Deletion of a specific element
void deleteSpecificElement(struct Node** head, int elem) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->data == elem) {
        deleteFromStart(head);
        return;
    }
    while (temp != NULL && temp->data != elem) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

// Deletion after a specific element
void deleteAfterSpecificElement(struct Node** head, int elem) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->data != elem) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Element not found or no element after the specified element.\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = temp;
    }
    free(toDelete);
}

// Deletion before a specific element
void deleteBeforeSpecificElement(struct Node** head, int elem) {
    if (*head == NULL || (*head)->data == elem || (*head)->next == NULL) {
        printf("The list is empty or no element before the specified element.\n");
        return;
    }
    struct Node* temp = (*head)->next; // Start from the second node
    while (temp != NULL && temp->data != elem) {
        temp = temp->next;
    }
    if (temp == NULL || temp->prev == *head) {
        deleteFromStart(head);
        return;
    } else if (temp != NULL) {
        struct Node* toDelete = temp->prev;
        temp->prev = toDelete->prev;
        toDelete->prev->next = temp;
        free(toDelete);
    } else {
        printf("Element not found.\n");
    }
}

// Deletion at a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL || position <= 0) {
        printf("Invalid position or the list is empty.\n");
        return;
    }
    if (position == 1) {
        deleteFromStart(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position exceeds the size of the list.\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

// Function to print the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, elem, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the end\n");
        printf("2. Delete from the start\n");
        printf("3. Delete from the end\n");
        printf("4. Delete a specific element\n");
        printf("5. Delete after a specific element\n");
        printf("6. Delete before a specific element\n");
        printf("7. Delete at a specific position\n");
        printf("8. Print list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at the end: ");
                scanf("%d", &elem);
                insertAtEnd(&head, elem);
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
                scanf("%d", &elem);
                deleteSpecificElement(&head, elem);
                printList(head);
                break;
            case 5:
                printf("Enter the element after which to delete: ");
                scanf("%d", &elem);
                deleteAfterSpecificElement(&head, elem);
                printList(head);
                break;
            case 6:
                printf("Enter the element before which to delete: ");
                scanf("%d", &elem);
                deleteBeforeSpecificElement(&head, elem);
                printList(head);
                break;
            case 7:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                printList(head);
                break;
            case 8:
                printList(head);
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
