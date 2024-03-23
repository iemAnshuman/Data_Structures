#include <stdio.h>
#include <stdlib.h>

int linear(int arr[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int binary(int arr[], int l, int r, int x)
{
    int m = l+(r-l)/2;
    if(arr[m] == x)
    {
        return m;
    }

    if(arr[m] < x)
    {
        return binary(arr,m,r,x);
    }
    else 
    {
        return binary(arr,l,m,x);
    }
    return -1;
}

int main()
{
    //input
    int n; 
    printf("Enter the size: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter the elements: ");
        scanf("%d",&arr[i]);
    }

    //output
    int x;
    printf("Enter the element to search: ");
    scanf("%d",&x);

    int ans1 = linear(arr,n,x);
    int ans2 = binary(arr,0,n-1,x);
    printf("Linear search: %d\n",ans1);
    printf("Binary search: %d\n",ans2);
    return 0;
}