/*
Problems:-
after Dth step it is runnning both B and C 
*/

#include <stdio.h>
#include <stdlib.h>

// structure for node for tree ds
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// function to create node for the given data
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

// insert the data in the tree
void insert(struct Node** root,  int ndata)
{
    struct Node* temp = *root;
    // struct Node* left = temp;
    if(*root == NULL)
    {
        *root = createNode(ndata);
        printf("A\n");
        return;
    }
    else 
    {
        while(1)
        {
            if(temp->left == NULL)
            {
                temp->left = createNode(ndata);
                printf("B\n");
                return;
            }
            else if(temp->right == NULL)
            {
                temp->right = createNode(ndata);
                printf("C\n");
                return;
            }
            printf("D\n");
            printf("left(0) or right(1)?\n");
            int choice;
            scanf("%d",&choice);
            switch (choice)
            {
                case 0:
                    temp = temp->left;
                    insert(&temp, ndata);
                    break;
                case 1:
                    temp = temp->right;
                    insert(&temp, ndata);
                    break;
                default:
                    printf("Invalid choice!\n");
                    return;
            }   
        }
    }
}

// traversing -> pre order
void preorder(struct Node* root)
{
    if(root != NULL)
    {
        printf("X\n");
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
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
    printf("2. preorder\n");
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
            preorder(root);
            printf("\n");
            break;
        default:
            break;
    }
    }
    return 0;
}