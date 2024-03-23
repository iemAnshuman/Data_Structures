#include <stdio.h>
#include <stdlib.h>

int position(int *arr, int n, int elem)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

int* delete_at(int *arr, int n, int pos)
{
    for(int i=pos; i<n-1; i++)
    {
        arr[i] = arr[i+1];
    }

    n--;

    int *temp = (int*)realloc(arr, n * sizeof(int));
    if (temp == NULL && n > 0) {
        printf("Memory reallocation failed!\n");
        return arr; 
    }
    return temp;
}

int* delete_elem(int *arr, int n, int elem)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i] == elem)
        {
            break;
        }
    }
    arr = delete_at(arr,n,i);
    return arr;
}

int* delete_start(int *arr, int n)
{
    if(arr == NULL)
    {
        printf("Deletion failed");
        return NULL;
    }
    arr = delete_at(arr,n,0);
    return arr;
}

int* delete_end(int *arr, int n)
{
    if(arr == NULL)
    {
        printf("Deletion failed");
    }
    arr = delete_at(arr,n,n-1);
    return arr;
}

int* delete_after(int *arr, int n, int elem)
{   
    if(arr == NULL || n <= 0)
    {
        printf("Deletion Failed");
    }
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i] == elem)
        {
            break;
        }
    }
    if(i == n-1)
    {
        return arr;
    }
    arr = delete_at(arr, n, i+1);
    return arr;
}

int* delete_before(int *arr, int n, int elem)
{
    if(arr == NULL || n <= 0)
    {
        printf("Deletion Failed");
    }
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i] == elem)
        {
            break;
        }
    }
    if(i <= 0)
    {
        return arr;
    }
    arr = delete_at(arr, n, i-1);
    return arr;
}

void print(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int n; 
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *dynamic_array = (int*)malloc(n * sizeof(int));

    for(int i=0; i<n; i++)
    {
        printf("Enter elements: ");
        scanf("%d",&dynamic_array[i]);
    }
    print(dynamic_array,n);

    while(1)
    {
    printf("Menu:\n");
    printf("1. Delete at a pos\n");
    printf("2. Delete starting element\n");
    printf("3. Delete ending element\n");
    printf("4. Delete element (intput:elem)\n");
    printf("5. Delete after an element\n");
    printf("6. Delete before an element\n");
    printf("7. Terminate\n");
    int choice;
    printf("Enter choice: ");
    scanf("%d",&choice);

    if(choice == 1)
    {
    printf("Enter pos to delete: ");
    int pos; 
    scanf("%d",&pos);
    dynamic_array = delete_at(dynamic_array, n, pos);
    n--;
    print(dynamic_array,n);
    }
    else if(choice == 2)
    {
    printf("Delete start? y/n: ");
    char choice;
    scanf(" %c",&choice);
    if(choice == 'y')
    {
        dynamic_array = delete_start(dynamic_array, n);
    }
    printf("\n");
    n--;
    print(dynamic_array,n);
    }
    else if(choice == 3)
    {
    printf("Delete end? y/n: ");
    char ch;
    scanf(" %c",&ch);
    if(ch == 'y')
    {
        dynamic_array = delete_end(dynamic_array, n);
    }
    printf("\n");
    n--;
    print(dynamic_array,n);
    }
    else if(choice == 4)
    {
    printf("Enter elem to delete: ");
    int elem; 
    scanf("%d",&elem);
    dynamic_array = delete_elem(dynamic_array, n, elem);
    n--;
    print(dynamic_array,n);
    }
    else if(choice == 5)
    {
    printf("Enter elem to delete after one: ");
    int elem; scanf("%d",&elem);
    dynamic_array = delete_after(dynamic_array, n, elem);
    int t = position(dynamic_array,n,elem);
    if(t >= 0 && t < n-1)
    {
        n--;
    }
    print(dynamic_array,n);
    }
    else if(choice == 6)
    {
    printf("Enter elem to delete before one: ");
    int elem; scanf("%d",&elem);
    dynamic_array = delete_before(dynamic_array, n, elem);
    int t = position(dynamic_array,n,elem);
    if(t < n && t > 0)
    {
        n--;
    }
    print(dynamic_array,n);
    }
    else if(choice == 7)
    {
        return 0;
    }
    else
    {
        printf("Invalid choice");
    }
    }
    free(dynamic_array);
    return 0;
}