#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int is_empty(struct Node* head)
{
    if(head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert_front(struct Node** head, int ndata)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Failed to allocate memory\n");
    }
    newNode -> data = ndata;
    newNode -> next = NULL;

    struct Node* temp = *head;
    if(temp == NULL)
    {
        *head = newNode;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
        *head = newNode;
    }
}

void print(struct Node* head)
{
    if(is_empty(head))
    {
        printf("List is empty!");
    }
    else
    {
        while(head != NULL)
        {
            printf("%d ",head->data);
        }
    }
}

void insert_back(struct Node** head, int ndata)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = ndata;
    newNode -> next = *head;
    *head = newNode;
}

int main()
{
    struct Node* head = NULL;
    while(1)
    {
    int choice;
    printf("Menu: \n");
    printf("1. insert at front\n");
    printf("2. insert back\n");
    printf("3. delete from front\n");
    printf("4. delete at pos\n");
    printf("0. EXIT\n");

    printf("Enter choice: ");
    scanf("%d",&choice);
    int ndata;
    switch(choice)
    {
        case 1:
            printf("Enter data: ");
            scanf("%d",&ndata);
            insert_front(&head,ndata);
        case 2: 
            printf("Enter data: ");
            scanf("%d",&ndata);
            insert_back(&head,ndata);
        case 0:
            return 0;
    }
    }

}