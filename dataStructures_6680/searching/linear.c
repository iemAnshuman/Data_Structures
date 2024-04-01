#include <stdio.h>
#include <limits.h>


long long int linearSearch(int n, int arr[], int x)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == x)
        {
            
            return i;
        }
    }
    printf("Given value is not in the array\n");
    // what should you return here?
    // one way
    return __LONG_LONG_MAX__;
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

    long long int result = linearSearch(n,arr,x);
    if(result != __LONG_LONG_MAX__)
    {
        printf("The position of the given value in the array is: %lld\n",result);
    }

    return 0;
}