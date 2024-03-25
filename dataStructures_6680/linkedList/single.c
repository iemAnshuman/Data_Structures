#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_front(struct Node** head, int ndata) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ndata;
    newNode->next = *head;
    *head = newNode;
}

void insert_pos(struct Node** head, int ndata, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = ndata;

    if (pos == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    pos--; // Adjust for 0-based indexing
    while (pos-- && temp->next) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_pos(struct Node** head, int pos) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    if (pos == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    while (pos-- && temp) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void replace(struct Node** head, int ndata, int pos) {
    delete_pos(head, pos);
    insert_pos(head, ndata, pos);
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
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
        printf("4. Replace at position\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insert_front(&head, data);
                break;
            case 2:
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &pos);
                insert_pos(&head, data, pos);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_pos(&head, pos);
                break;
            case 4:
                printf("Enter new data and position to replace: ");
                scanf("%d %d", &data, &pos);
                replace(&head, data, pos);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
