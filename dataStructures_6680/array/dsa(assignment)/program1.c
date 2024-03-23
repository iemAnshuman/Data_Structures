/*
1)creation: static array creation and dynamic array creation
2)traversing
3)insertion: beginning, end, at a pos, after or before an element
4)deletion: similar to insertion
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* First we create a pointer to store a dynamic array */
    int *dynamic_array = NULL;
    /* Create a variable for size and take user input */
    int n;
    scanf("%d",&n);
    /* dynamic memory allocation */
    dynamic_array = (int*)malloc(n * sizeof(int));

    // Initialize the dynamic array
    for(int i=0; i<n; i++)
    {
        scanf("%d",&dynamic_array[i]);
    }

    // print the dynamic array
    for(int i=0; i<n; i++)
    {
        printf("%d",dynamic_array[i]);
    }
    printf("\n");
    // free the dynamic array to avoid memory leak
    free(dynamic_array);

    return 0;
}