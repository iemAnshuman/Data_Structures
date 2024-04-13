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
    newNode->data = ndata;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(struct Node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
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

void delete(int data, struct Node** root)
{
    struct Node* temp = *root;
    while(temp->data != data)
    {
        if(temp->data > data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    if(temp->left == NULL && temp->right == NULL)
    {
        free(temp);
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
    printf("2. Deletion\n");
    printf("3. Pre-order\n");
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
            break;
        }
        case 2:
        {
            printf("Enter data to remove: ");
            int data;
            scanf("%d",&data);
            delete(data, &root);
            break;
        }
        case 3:
            preorder(root);
            printf("\n");
            break;
    default:
        break;
    }
    }
}