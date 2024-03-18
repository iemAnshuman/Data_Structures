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

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = ndata;

    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position exceeds the size of the doubly linked list.\n");
        free(newNode);
        return;
    }

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
        if (temp->next != NULL) {
            temp->next->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < pos; i++) {
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

void replace(struct Node** head, int ndata, int pos) {
    deletePos(head, pos);
    insertPos(head, ndata, pos);
}

struct Node* connect(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) return *head2;
    if (*head2 == NULL) return *head1;

    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head2;
    (*head2)->prev = temp;

    return *head1;
}

void printList(struct Node* head) {
    struct Node* last;
    printf("Forward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        last = head;
        head = head->next;
    }
    printf("\n");

    printf("Backward: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
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

    replace(&head, -9999, 2);

    printList(head);

    return 0;
}
