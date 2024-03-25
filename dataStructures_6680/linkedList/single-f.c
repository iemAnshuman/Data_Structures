#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* newNode = NULL;
    struct Node* temp = NULL;
    struct Node* prev = NULL;
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
            case 1: // Insert at front
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->next = head;
                head = newNode;
                break;
            case 2: // Insert at position
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &pos);
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                if (pos == 0) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    temp = head;
                    pos--; // Adjust for 0-based indexing
                    while (pos-- && temp->next) {
                        temp = temp->next;
                    }
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
                break;
            case 3: // Delete at position
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                if (head != NULL) {
                    if (pos == 0) {
                        temp = head;
                        head = head->next;
                        free(temp);
                    } else {
                        temp = head;
                        pos--; // Adjust for 0-based indexing
                        while (pos-- && temp->next) {
                            prev = temp;
                            temp = temp->next;
                        }
                        if (temp != NULL) {
                            prev->next = temp->next;
                            free(temp);
                        }
                    }
                }
                break;
            case 4: // Replace at position
                printf("Enter new data and position to replace: ");
                scanf("%d %d", &data, &pos);
                // Delete
                if (head != NULL) {
                    if (pos == 0) {
                        temp = head;
                        head = head->next;
                        free(temp);
                    } else {
                        temp = head;
                        pos--; // Adjust for 0-based indexing
                        while (pos-- && temp->next) {
                            prev = temp;
                            temp = temp->next;
                        }
                        if (temp != NULL) {
                            prev->next = temp->next;
                            free(temp);
                        }
                    }
                }
                // Insert
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                if (pos == 0) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    temp = head;
                    pos--; // Re-adjust for insertion
                    while (pos-- && temp->next) {
                        temp = temp->next;
                    }
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
                break;
            case 5: // Print list
                temp = head;
                while (temp) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
                break;
            case 6: // Exit
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
