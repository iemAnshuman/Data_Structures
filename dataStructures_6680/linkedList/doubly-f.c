#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;
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
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->next = head;
                newNode->prev = NULL;
                if (head != NULL) head->prev = newNode;
                head = newNode;
                break;
            case 2: // Insert at position
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &pos);
                if (pos == 0) {
                    newNode = (struct Node*)malloc(sizeof(struct Node));
                    newNode->data = data;
                    newNode->next = head;
                    newNode->prev = NULL;
                    if (head != NULL) head->prev = newNode;
                    head = newNode;
                } else {
                    temp = head;
                    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
                        temp = temp->next;
                    }
                    if (temp == NULL) {
                        printf("Position exceeds the size of the doubly linked list.\n");
                    } else {
                        newNode = (struct Node*)malloc(sizeof(struct Node));
                        newNode->data = data;
                        newNode->next = temp->next;
                        newNode->prev = temp;
                        if (temp->next != NULL) temp->next->prev = newNode;
                        temp->next = newNode;
                    }
                }
                break;
            case 3: // Delete at position
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                if (head == NULL) break;
                if (pos == 0) {
                    temp = head;
                    head = head->next;
                    if (head != NULL) head->prev = NULL;
                    free(temp);
                } else {
                    temp = head;
                    for (int i = 0; i < pos && temp != NULL; i++) {
                        temp = temp->next;
                    }
                    if (temp == NULL) {
                        printf("Position exceeds the size of the doubly linked list.\n");
                    } else {
                        if (temp->next != NULL) temp->next->prev = temp->prev;
                        if (temp->prev != NULL) temp->prev->next = temp->next;
                        free(temp);
                    }
                }
                break;
            case 4: // Print list
                printf("Forward: ");
                for (temp = head; temp != NULL; temp = temp->next) {
                    printf("%d ", temp->data);
                }
                printf("\nBackward: ");
                for (temp = head; temp != NULL && temp->next != NULL; temp = temp->next); // Move to last
                for (; temp != NULL; temp = temp->prev) {
                    printf("%d ", temp->data);
                }
                printf("\n");
                break;
            case 5: // Exit
                while (head != NULL) { // Clean up to prevent memory leak
                    temp = head;
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
