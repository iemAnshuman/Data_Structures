
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

void insert_end(struct Node** head, int ndata)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = ndata;
    struct Node* temp = *head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
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

void insert_after(struct Node** head, int ndata, int elem)
{
    struct Node* temp = *head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = ndata;

    while (temp != NULL) 
    {
        if (temp->data == elem) 
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next; 
    }
}

void insert_before(struct Node** head, int ndata, int elem)
{
    struct Node* temp = *head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = ndata;

    while(temp != NULL)
    {
        if((temp->next)->data == elem)
        {
            newNode -> next = temp -> next;
            temp -> next = newNode;
            return;
        }
        temp = temp -> next;
    }
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
    delete_pos(&head, pos);
    insert_pos(&head, ndata, pos);
    return;
}

/*
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
*/

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
        printf("Enter elements: ");
        scanf("%d",&temp);
        insert_front(&head,temp);
    }
    printList(head);
    while(1)
    {
    printf("Menu:\n");
    printf("1. Insert at the end\n");
    printf("2. Insert at the start\n");
    printf("3. Insert after an elem\n");
    printf("4. Insert before an element\n");
    printf("5. Insert at a pos\n");
    printf("6. replace");
    printf("7. Terminate\n");
    int choice; int elem; int ndata; int pos;
    printf("Enter choice: ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        printf("Enter data you want to enter at end: ");
        scanf("%d",&elem);
        insert_end(&head,elem);
        printList(head);
    }
    else if(choice == 2)
    {
        printf("Enter data you want to enter at start: ");
        scanf("%d",&elem);
        insert_front(&head,elem);
        printList(head);
    }
    else if(choice == 3)
    {
        printf("Enter elem: ");
        scanf("%d",&elem);
        printf("Enter data: ");
        scanf("%d",&ndata);
        insert_after(&head,ndata,elem);
        printList(head);
    }
    else if(choice == 4)
    {
        printf("Enter elem: ");
        scanf("%d",&elem);
        printf("Enter data: ");
        scanf("%d",&ndata);
        insert_before(&head,ndata,elem);
        printList(head);
    }
    else if(choice == 5)
    {
        printf("Enter pos: ");
        scanf("%d",&pos);
        printf("Enter data: ");
        scanf("%d",&ndata);
        insert_pos(&head,ndata,pos);
        printList(head);
    }
    else if(choice == 6)
    {
        printf("Enter pos to change data: ");
        scanf("%d",&pos);
        printf("Enter data: ");
        scanf("%d",&ndata);
        replace(&head,ndata,pos);
        printList(head);
    }
    else if(choice == 7)
    {
        return 0;
    }
    else
    {
        printf("Enter valid choice");
    }
    }
    return 0;
}