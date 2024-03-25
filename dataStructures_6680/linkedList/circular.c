#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertFront(struct Node** head, int ndata) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ndata;

    if (*head == NULL) {
        newNode->next = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

void insertPos(struct Node** head, int ndata, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ndata;

    if (*head == NULL || pos == 0) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
            if (temp->next == *head) {
                break; // If we've circled back to the head, stop
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deletePos(struct Node** head, int pos) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    if (pos == 0) {
        if ((*head)->next == *head) {
            free(*head);
            *head = NULL;
        } else {
            struct Node* last = *head;
            while (last->next != *head) {
                last = last->next;
            }
            *head = (*head)->next;
            last->next = *head;
            free(temp);
        }
    } else {
        struct Node* prev = NULL;
        for (int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
            if (temp == *head) break; // Stop if we've circled back to the head
        }
        if (temp != *head) {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
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
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 2:
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &pos);
                insertPos(&head, data, pos);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletePos(&head, pos);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                // Free memory before exiting
                while (head != NULL) {
                    struct Node* temp = head->next;
                    if (head == temp) {
                        free(head);
                        break;
                    }
                    head->next = temp->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
