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
    newNode->next = newNode; // Initially, node points to itself
    return newNode;
}

// Function to find the node before a specified node
struct Node* findPrevious(struct Node* head, struct Node* target) {
    struct Node* temp = head;
    // Circular list: loop will terminate
    while (temp->next != target && temp->next != head) {
        temp = temp->next;
    }
    return temp;
}

// Insert at end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = (*head)->next;
    while (last->next != *head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = *head;
}

// Insert at start
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    newNode->next = *head;
    *head = newNode;
    last->next = *head;
}

// Insert at position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 1) {
        insertAtStart(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; temp->next != *head && i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert after element
void insertAfterElement(struct Node** head, int data, int elem) {
    struct Node* temp = *head;
    do {
        if (temp->data == elem) {
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    printf("Element not found.\n");
}

// Insert before element
void insertBeforeElement(struct Node** head, int data, int elem) {
    if (*head == NULL || (*head)->data == elem) {
        insertAtStart(head, data);
        return;
    }
    struct Node* current = (*head)->next;
    struct Node* prev = *head;
    do {
        if (current->data == elem) {
            struct Node* newNode = createNode(data);
            newNode->next = current;
            prev->next = newNode;
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head);
    printf("Element not found.\n");
}

// Delete from start
void deleteFromStart(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    struct Node* toDelete = *head;
    *head = (*head)->next;
    temp->next = *head;
    free(toDelete);
}

// Delete from end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    free(temp);
}

// Delete at position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) return;
    if (position == 1) {
        deleteFromStart(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 1; temp->next != *head && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == *head) {
        printf("Position out of bounds.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Delete a specific element
void deleteSpecificElement(struct Node** head, int elem) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    struct Node* prev = NULL;
    do {
        if (temp->data == elem) {
            if (temp == *head) {
                deleteFromStart(head);
            } else {
                prev->next = temp->next;
                free(temp);
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != *head);
    printf("Element not found.\n");
}

// Delete after element
void deleteAfterElement(struct Node** head, int elem) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    do {
        if (temp->data == elem) {
            if (temp->next == *head) { // If next element is head, delete head
                deleteFromStart(head);
            } else {
                struct Node* toDelete = temp->next;
                temp->next = toDelete->next;
                free(toDelete);
            }
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    printf("Element not found.\n");
}

// Delete before element 
void deleteBeforeElement(struct Node** head, int elem) {
    if (*head == NULL || (*head)->data == elem || (*head)->next == *head) {
        printf("Operation not possible.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    struct Node* beforePrev = NULL;
    do {
        if (temp->data == elem) {
            if (prev == NULL || prev == *head) { // If the element is head or next to head
                deleteFromEnd(head);
            } else {
                beforePrev->next = temp;
                free(prev);
            }
            return;
        }
        beforePrev = prev;
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->next != *head);
    printf("Element not found.\n");
}

// Print the circular list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, elem, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the end\n");
        printf("2. Insert at the start\n");
        printf("3. Insert at position\n");
        printf("4. Insert after element\n");
        printf("5. Insert before element\n");
        printf("6. Delete from the start\n");
        printf("7. Delete from the end\n");
        printf("8. Delete at position\n");
        printf("9. Delete a specific element\n");
        printf("10. Delete after element\n");
        printf("11. Delete before element\n");
        printf("12. Print list\n");
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
                printf("Enter data to insert at the start: ");
                scanf("%d", &data);
                insertAtStart(&head, data);
                printList(head);
                break;
            case 3:
                printf("Enter position and data to insert: ");
                scanf("%d %d", &position, &data);
                insertAtPosition(&head, data, position);
                printList(head);
                break;
            case 4:
                printf("Enter element after which to insert and data: ");
                scanf("%d %d", &elem, &data);
                insertAfterElement(&head, data, elem);
                printList(head);
                break;
            case 5:
                printf("Enter element before which to insert and data: ");
                scanf("%d %d", &elem, &data);
                insertBeforeElement(&head, data, elem);
                printList(head);
                break;
            case 6:
                deleteFromStart(&head);
                printList(head);
                break;
            case 7:
                deleteFromEnd(&head);
                printList(head);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                printList(head);
                break;
            case 9:
                printf("Enter element to delete: ");
                scanf("%d", &elem);
                deleteSpecificElement(&head, elem);
                printList(head);
                break;
            case 10:
                printf("Enter element after which to delete: ");
                scanf("%d", &elem);
                deleteAfterElement(&head, elem);
                printList(head);
                break;
            case 11:
                printf("Enter element before which to delete: ");
                scanf("%d", &elem);
                deleteBeforeElement(&head, elem);
                printList(head);
                break;
            case 12:
                printList(head);
                break;
            case 0:
                printf("Exiting...\n");
                while (head != NULL && head->next != head) {
                    deleteFromStart(&head);
                }
                free(head);
                head = NULL;
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
