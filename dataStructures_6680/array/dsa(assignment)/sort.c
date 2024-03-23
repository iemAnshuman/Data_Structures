#include <stdio.h>
#include <stdlib.h>

void bubble(int arr[], int n) 
{
    int i;int j;int temp;
    for (i = 0; i < n-1; i++) 
    {       
        for (j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print(int arr[], int n)
{
    for(int i=0; i<n; i++) 
    {
        printf("%d ",arr[i]);
    }
    return;
}

int main()
{
    int n;
    printf("Enter size of an array: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter the elements: ");
        scanf("%d",&arr[i]);
    }

    bubble(arr,n);
    print(arr,n);
    return 0;
}