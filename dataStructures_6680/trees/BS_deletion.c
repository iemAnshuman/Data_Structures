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

void insert(struct Node** root, int ndata)
{
    struct Node* temp = *root;
    struct Node* parent = NULL;
    if(*root == NULL)
    {
        *root = createNode(ndata);
        return;
    }
    while(temp != NULL)
    {
        parent = temp;
        if(temp->data > ndata)
        {
            temp = temp->left;
        }
        else if(temp->data < ndata)
        {
            temp = temp->right;
        }
        else
        {
            return;
        }
    }

    if(parent->data > ndata)
    {
        parent->left = createNode(ndata);
    }
    else 
    {
        parent->right = createNode(ndata);
    }
    
}

void delete(int data, struct Node** root)
{
    struct Node* temp = *root;  
    if(temp->data > data)
    {
        delete(data, &(temp->left));
        return;
    }
    else if(temp->data < data)
    {
        delete(data, &(temp->right));
        return;
    }
    else
    {
        // both children doesn't exist
        if(temp->left == NULL && temp->right == NULL)
        {
            free(temp);
            return;
        }
        else if(temp->left == NULL) // if left doesn't exists
        {
            free(temp);
            return;
        }
        else if(temp->right == NULL) // if right doesn't exists
        {
            free(temp);
            return;
        }
        else // both exists
        {
            temp = temp->right;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            free(temp);
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
    printf("1. Insertion using double pointer\n");
    printf("2. Deletion using double pointer\n");
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