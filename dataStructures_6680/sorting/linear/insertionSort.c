/*
this algo is always beneficial for small set of data
this algo is efficient for substainsiably sorted array
it is 40 percent faster then selection sort
and twice faster than bubble sort
it requires less memory space O(1)
*/
#include <stdio.h>

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//fixing in progress
void insertion_sort(int n, int arr[])
{
    // if only one element
    if(n == 1)
    {
        print(n,arr);
        return;
    }
    for(int i=1; i<n; i++)
    {
        // compare 
        int j=i-1;
        while(arr[i] < arr[j])
        {
            j--;
        }
        j++;
        //swap and adjust
        int temp = arr[i];
        for(int k=i; k>j; k--)
        {
            arr[k] = arr[k-1];
        }
        arr[j] = temp;
    }
    print(n,arr);
}

int main()
{
    //input
    int n;
    printf("Enter size: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    //output 
    insertion_sort(n,arr);
    return 0;
}