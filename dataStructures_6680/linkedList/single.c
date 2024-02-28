
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; 
};

void insert_front(struct Node** head, int ndata)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = ndata;
    newNode->next = *head;

    *head = newNode;
    return;
}

void insert_pos(struct Node** head, int ndata, int pos)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = ndata;

    pos--;
    while(pos--)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}


void delete_pos(struct Node** head, int pos)
{
    if(*head == NULL) return;

    struct Node* temp = *head;
    if(!pos)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    pos--;
    while(pos--)
    {
        temp = temp->next;
    }
    struct Node* temp1 = (temp->next);
    temp->next = (temp->next)->next;
    free(temp1);
    return;
}

void replace(struct Node** head, int ndata, int pos)
{
    delete_pos(head, pos);
    insert_pos(head, ndata, pos);
    return;
}

struct Node* connect(struct Node** head1, struct Node** head2)
{
    struct Node* temp = *head1;

    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = *head2;
    return *head1;
}

void printList(struct Node* head)
{
    while(head)
    {
        printf("%d ",head->data);
        head = head -> next;
    }
    printf("\n");
    return;
}

int main()
{
    struct Node* head = NULL;


    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int temp;
        printf("Enter num: ");
        scanf("%d",&temp);
        insert_front(&head,temp);
    }

    printList(head);

    delete_pos(&head, 2);
    // pos starts at 0

    printList(head);

    insert_pos(&head, INT16_MAX, 2);

    printList(head);

    replace(&head, INT16_MIN, 2);

    printList(head);
    return 0;
}