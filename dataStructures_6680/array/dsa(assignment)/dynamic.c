#include <stdio.h>
#include <stdlib.h>

int *insert_end(int n, int *arr, int elem)
{
    // dynamic memory size change to n+1
    arr = (int*)realloc(arr, (n+1)*sizeof(int));
    // insert at end
    arr[n] = elem;
    // return the arr to update the dynamic_arr
    return arr;
}

int *insert_start(int n, int *arr, int elem)
{
    // dynamic memory size change to n+1
    arr = (int*)realloc(arr, (n+1)*sizeof(int));
    // shifting
    for(int i=n-1; i>=0; i--)
    {
        arr[i+1] = arr[i];
    }
    // insertion
    arr[0] = elem;
    // updating dynamic_arr
    return arr;
}

int *insert_after(int n, int *arr, int elem, int key)
{
    // dynamic memory size change to n+1
    arr = (int*)realloc(arr, (n+1)*sizeof(int));
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
    return arr;
}

int *insert_before(int *arr, int n, int elem, int key)
{
    // dynamic memory size change to n+1
    arr = (int*)realloc(arr, (n+1)*sizeof(int));

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
    return arr;
}

int *insert_at(int *arr, int n, int pos, int elem)
{
    // dynamic memory size change to n+1
    arr = (int*)realloc(arr, (n+1) * sizeof(int));

    for(int i=n; i>pos; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = elem;
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

    while(1)
    {
    int menu;
    printf("Menu:\n");
    printf("1. Insert at the end\n");
    printf("2. Insert at the start\n");
    printf("3. Insert after an elem\n");
    printf("4. Insert before an element\n");
    printf("5. Insert at a pos\n");
    printf("6. Terminate\n");
    scanf("%d",&menu);

    if(menu==1)
    {
    printf("Enter the elem to insert at the end: ");
    int elem; scanf("%d",&elem);
    dynamic_array = insert_end(n,dynamic_array,elem);
    n++;
    print(dynamic_array,n);
    }
    else if(menu==2)
    {
    printf("Enter the elem to insert at the start: ");
    int elem1; 
    scanf("%d",&elem1);
    dynamic_array = insert_start(n,dynamic_array,elem1);
    n++;
    print(dynamic_array,n);
    }
    else if(menu==3)
    {
    printf("Enter the elem to insert: ");
    int elem2; 
    scanf("%d",&elem2);
    int key;
    printf("Enter the elem after which you want to enter your elem: ");
    scanf("%d",&key);
    dynamic_array = insert_after(n,dynamic_array,elem2,key);
    n++;
    print(dynamic_array,n);
    }
    else if(menu==4)
    {
    printf("Enter the elem to insert: ");
    int elem2, key;
    scanf("%d",&elem2);
    printf("Enter the elem before which you want to enter your elem: ");
    scanf("%d",&key);
    dynamic_array = insert_before(dynamic_array,n,elem2,key);
    n++;
    print(dynamic_array,n);
    }
    else if(menu==5)
    {
    printf("Enter the elem to insert: ");
    int elem2;
    scanf("%d",&elem2);
    printf("Enter the pos: ");
    int pos;
    scanf("%d",&pos);
    dynamic_array = insert_at(dynamic_array,n,pos,elem2);
    n++;
    print(dynamic_array,n);
    }
    else if(menu==6)
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