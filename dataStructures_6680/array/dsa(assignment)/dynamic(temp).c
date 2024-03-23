#include <stdio.h>
#include <stdlib.h>

void insert_end(int n, int *arr, int elem)
{
    // dynamic memory size change to n+1
    arr = (int*)realloc(arr, (n+10)*sizeof(int));
    // insert at end
    arr[n] = elem;
    // return the arr
    return;
}

void insert_start(int n, int *arr, int elem)
{
    // dynamic memory reallocation for size n+1
    arr = (int*)realloc(arr, (n+10)*sizeof(int));
    // 
    for(int i=n-1; i>=0; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[0] = elem;
    return;
}

void insert_after(int n, int *arr, int elem, int key)
{
    arr = (int*)realloc(arr, (n+10)*sizeof(int));
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            break;
        }
    }
    for(int j=n-1; j>=i+1; j--)
    {
        arr[j+1] = arr[j];
    }
    arr[i+1] = elem;
    return;
}

void insert_before(int *arr, int n, int elem, int key)
{
    arr = (int*)realloc(arr, (n+10)*sizeof(int));

    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            break;
        }
    }
    for(int j=n-1; j>=i; j--)
    {
        arr[j+1] = arr[j];
    }
    arr[i] = elem;
    return;
}

void insert_at(int *arr, int n, int pos, int elem)
{
    arr = (int*)realloc(arr, (n+10) * sizeof(int));

    for(int i=n; i>pos; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = elem;
    return;
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

    printf("Enter the elem to insert at the end: ");
    int elem; scanf("%d",&elem);
    insert_end(n,dynamic_array,elem);
    n++;
    print(dynamic_array,n);

    printf("Enter the elem to insert at the start: ");
    int elem1; 
    scanf("%d",&elem1);
    insert_start(n,dynamic_array,elem1);
    n++;
    print(dynamic_array,n);

    printf("Enter the elem to insert: ");
    int elem2; 
    scanf("%d",&elem2);
    int key;
    printf("Enter the elem after which you want to enter your elem: ");
    scanf("%d",&key);
    insert_after(n,dynamic_array,elem2,key);
    n++;
    print(dynamic_array,n);

    printf("Enter the elem to insert: ");
    scanf("%d",&elem2);
    printf("Enter the elem before which you want to enter your elem: ");
    scanf("%d",&key);
    insert_before(dynamic_array,n,elem2,key);
    n++;
    print(dynamic_array,n);

    printf("Enter the elem to insert: ");
    scanf("%d",&elem2);
    printf("Enter the pos: ");
    int pos;
    scanf("%d",&pos);
    insert_at(dynamic_array,n,pos,elem2);
    n++;
    print(dynamic_array,n);

    free(dynamic_array);
    return 0;
}