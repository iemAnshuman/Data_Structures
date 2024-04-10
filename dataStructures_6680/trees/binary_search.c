#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int ndata)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed");
        // usually happens when there is no stroage left in computer
    }
    newNode->data = ndata;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** root, int data)
{
    if(*root == NULL)
    {
        *root = createNode(data);
        return;
    }
    struct Node* temp = *root;
    while(1)
    {
        if(temp == NULL)
        {
            temp = createNode(data);
            return;
        }
        else if(data < temp->data)
        {
            temp = temp->left;
            return;
        }
        else if(data > temp->data)
        {
            temp = temp -> right;
            return;
        }
    }
}

int main()
{
    struct Node* root = NULL;
    while(1)
    {
    printf("Menu:\n");
    printf("0. Exit\n");
    printf("1. Insertion\n");

    printf("Enter your choice: ");
    int choice;
    //printf("The value of choice is: %d\n",choice);
    scanf("%d",&choice);

    switch (choice)
    {
        case 0:
            return 0;
        case 1:
        {
            printf("Enter data: ");
            int ndata;
            scanf("%d",&ndata);
            insert(&root, ndata);
        }
    default:
        break;
    }
    }
}