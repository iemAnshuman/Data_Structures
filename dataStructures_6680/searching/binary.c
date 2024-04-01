#include <stdio.h>

long int binarySearchRecursion(int min, int max, int arr[], int x)
{
    int mid = min + (max - min) / 2; 
    // Notice we are not using mid = (max+min)/2;
    if(x == arr[mid])
    {
        return mid;
    }
    else if(x > arr[mid])
    {
        return binarySearchRecursion(mid+1, max, arr, x);
    }
    else if(x < arr[mid])
    {
        return binarySearchRecursion(min, mid-1, arr, x);
    }
    else
    {
        printf("Error");
        return __LONG_MAX__; // now we can do something to handle this error...
    }
}

long int binarySearch(int n, int arr[], int x)
{
    int min = 0;
    int max = n-1;
    // Notice we are not using: mid = (max+min)/2;
    int mid = min + (max - min) / 2;

    while(max >= min)
    {
        if(x == arr[mid])
        {
            return mid;
        }
        else if(x > arr[mid])
        {
            min = mid+1;
        }
        else if(x < arr[mid])
        {
            max = mid-1;
        }
        else
        {
            printf("Error");
            return __LONG_MAX__; // now we can do something to handle this error...
        }
    }
    return __LONG_MAX__;
}

int main()
{
    int n; 
    printf("Enter size: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int x; 
    printf("Enter the number to search: ");
    scanf("%d",&x);

    long int r1 = binarySearch(n,arr,x);
    long int r2 = binarySearchRecursion(0,n-1,arr,x);

    printf("Pos1: %ld\n Pos2: %ld\n",r1, r2);
    return 0;
}