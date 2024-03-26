#include <stdio.h>

void print(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        printf("%d",arr[i]);
    }
}


void selection(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int min = arr[i];
        int pos=i; 
        for(int j=i+1; j<n; j++)
        {
            if(min > arr[j])
            {
                min = arr[j];
                pos = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[pos] = temp;
    }
}

int main(){
    //input
    int n; 
    printf("Enter size: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    /*for debugging purpose, you can print the input */

    //output
    selection(arr,n);
    print(n,arr);
}