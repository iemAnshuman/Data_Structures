#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp, *newNode, *last;
    int choice, data, pos, i;

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
                if (head == NULL) {
                    head = newNode;
                    newNode->next = head;
                } else {
                    temp = head;
                    while (temp->next != head) temp = temp->next;
                    newNode->next = head;
                    temp->next = newNode;
                    head = newNode;
                }
                break;
            case 2: // Insert at position
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &pos);
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                if (pos == 0 || head == NULL) {
                    if (head != NULL) {
                        for (temp = head; temp->next != head; temp = temp->next);
                        temp->next = newNode;
                    } else {
                        head = newNode;
                    }
                    newNode->next = head;
                    head = newNode;
                } else {
                    temp = head;
                    for (i = 0; i < pos - 1 && temp->next != head; i++) temp = temp->next;
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
                break;
            case 3: // Delete at position
                if (head == NULL) {
                    printf("List is empty.\n");
                    break;
                }
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                if (pos == 0) {
                    temp = head;
                    if (head->next == head) {
                        head = NULL;
                    } else {
                        for (last = head; last->next != head; last = last->next);
                        head = head->next;
                        last->next = head;
                    }
                    free(temp);
                } else {
                    for (temp = head, i = 0; i < pos && temp->next != head; i++, temp = temp->next);
                    if (i == pos) {
                        struct Node* toDelete = temp->next;
                        temp->next = toDelete->next;
                        free(toDelete);
                    }
                }
                break;
            case 4: // Print list
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    temp = head;
                    do {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    } while (temp != head);
                    printf("\n");
                }
                break;
            case 5: // Exit
                temp = head;
                while (temp != NULL && temp->next != head) {
                    struct Node* toDelete = temp;
                    temp = temp->next;
                    free(toDelete);
                }
                if (temp) free(temp);
                head = NULL;
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
