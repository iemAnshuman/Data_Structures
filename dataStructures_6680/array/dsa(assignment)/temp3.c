#include <stdio.h>

void delete_pos(int arr[],int pos,int n)
{
    for(int i=pos; i<n-1; i++)
    {
        arr[i] = arr[i+1];
    }
}

void delete_elem_before(int arr[], int elem, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i] == elem)
        {
            if(i <= 0)
            {
                printf("Deletion not possible");
                return;
            }
            else
            {
                i--;
            }
            break;
        }
    }
    delete_pos(arr,i,n);
}

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 5;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        //user input
        printf("Enter elements: ");
        scanf("%d",&arr[i]);
    }

    int elem;
    printf("Enter the element for deletion: ");
    scanf("%d",&elem);
    delete_elem_before(arr, elem, n);
    print(arr,n-1);
    return 0;
}