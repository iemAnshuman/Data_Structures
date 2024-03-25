#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertFront(struct Node** head, int ndata) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ndata;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertPos(struct Node** head, int ndata, int pos) {
    if (pos == 0) {
        insertFront(head, ndata);
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position exceeds the size of the doubly linked list.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ndata;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deletePos(struct Node** head, int pos) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    if (pos == 0) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position exceeds the size of the doubly linked list.\n");
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

void printList(struct Node* head) {
    struct Node* last = NULL;
    printf("Forward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        last = head;
        head = head->next;
    }
    printf("\nBackward: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at position\n");
        printf("3. Delete at position\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert at front
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 2: // Insert at position
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &pos);
                insertPos(&head, data, pos);
                break;
            case 3: // Delete at position
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletePos(&head, pos);
                break;
            case 4: // Print list
                printList(head);
                break;
            case 5: // Exit
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
