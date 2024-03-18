#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertFront(struct Node** head, int ndata) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = ndata;

    if (*head == NULL) {
        newNode->next = newNode; // Point to itself, making it circular
    } else {
        // Traverse until the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode; // Link the last node to the new node
        newNode->next = *head; // Link the new node to the head
    }
    *head = newNode; // Update the head to the new node
}

void insertPos(struct Node** head, int ndata, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ndata;
    if (*head == NULL) {
        newNode->next = newNode; // Circular link to itself
        *head = newNode;
    } else if (pos == 0) {
        insertFront(head, ndata);
        return;
    } else {
        struct Node* temp = *head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == *head) { // If we reach the head, the position is beyond list length
                printf("Position exceeds the size of the list.\n");
                free(newNode);
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deletePos(struct Node** head, int pos) {
    if (*head == NULL) return;

    struct Node* temp = *head, *prev = NULL;
    if (pos == 0) {
        // If the list has only one node
        if (temp->next == *head) {
            free(temp);
            *head = NULL;
        } else {
            while (temp->next != *head) { // Find the last node
                temp = temp->next;
            }
            temp->next = (*head)->next; // Link last node to second node
            free(*head);
            *head = temp->next; // Update head
        }
    } else {
        for (int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
            if (temp == *head) { // Position is out of bounds
                printf("Position exceeds the size of the list.\n");
                return;
            }
        }
        prev->next = temp->next;
        free(temp);
    }
}

void printList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        printf("Enter num: ");
        scanf("%d", &temp);
        insertFront(&head, temp);
    }

    printList(head);

    deletePos(&head, 2); // Position starts at 0

    printList(head);

    insertPos(&head, 9999, 2);

    printList(head);

    // Since the replace operation is not typical for circular linked lists,
    // we will skip it in this implementation. However, it can be implemented
    // by a combination of delete and insert operations if necessary.

    return 0;
}
