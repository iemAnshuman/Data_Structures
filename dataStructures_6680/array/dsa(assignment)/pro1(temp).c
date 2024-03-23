#include <stdio.h>
#include <stdlib.h>

/*void insert_before(int arr[],int num,int elem)
{
    
}*/

void insert_before(int arr[], int num, int elem, int n)
{
    for(int i=1; i<n; i++)
    {
        if(arr[i] == elem)
        {
            arr[i-1] = num;
            return;
        }
    }
    printf("Insertion Not possible\n");
}


void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element:");
        scanf("%d", &arr[i]);
    }
    int num;
    printf("Enter a number to enter: ");
    scanf("%d",&num);
    int elem;
    printf("Enter the element to search:");
    scanf("%d",&elem);
    insert_before(arr,num,elem,n);
    print(arr,n);
    return 0;
}
