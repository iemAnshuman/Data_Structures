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
    }
    newNode->data = ndata;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** root,  int ndata)
{
    struct Node* temp = *root;
    // struct Node* left = temp;
    if(temp == NULL)
    {
        temp = createNode(ndata);
        return;
    }
    else 
    {
        while(1)
        {
            if(temp->left != NULL)
            {
                temp->left = createNode(ndata);
                return;
            }
            else if(temp->right != NULL)
            {
                temp->right = createNode(ndata);
                return;
            }
            // do something here
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