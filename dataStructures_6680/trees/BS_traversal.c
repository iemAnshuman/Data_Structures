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
        exit(0);
        // usually happens when there is no stroage left in computer
    }
    newNode->data = ndata;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// with recursion
void preorder(struct Node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// without recursion
/*
void preorder2(struct Node* root)
{
    
}
*/
// with recursion
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

// with recursion
void postorder(struct Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void insert(struct Node** root, int data)
{
    struct Node* newNode = createNode(data);
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }
    struct Node* temp = *root;
    struct Node* parent = NULL;
    while (temp != NULL)
    {
        parent = temp;
        if (data < temp->data)
            temp = temp->left;
        else if (data > temp->data)
            temp = temp->right;
        else
            return; 
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}


int main()
{
    struct Node* root = NULL;
    while(1)
    {
    printf("Menu:\n");
    printf("0. Exit\n");
    printf("1. Insertion\n");
    printf("2. Pre-order\n");
    printf("3. In-order\n");
    printf("4. Post order\n");
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
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4: 
            postorder(root);
            printf("\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
    }
    }
}